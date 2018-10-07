# arduinotrafficlight
code arduino and evidence picture
18/sept/2018

Instituto: Instituto Tecnológico de león

Carrera: Ingeniería en sistemas computacionales. 

Materia: sistemas programables. 

Alumno: Saúl Gutiérrez González

Maestro (A): Ing. Levi rojas carlos rafael







Introducción 
Dentro de este proyecto de investigación se desarrolla un sistema que simule un Semáforo Interactivo usando Arruino. tiene como objetivo monitoreo el uso del semáforo por parte de los peatones y disparar una alarma en caso de que se haya presionado el botón. incluye un botón para interactuar con el usuario (desactivar la alarma). Activando el semáforo de peatones y desactivando el semáforo de automóviles.

Nombre del proyecto:
Sistema alertizador salvaguarda humano-coche

1.1 Descripción del problema

En el contexto de facilitar y sistematizar procesos se necesita hoy en dia del uso de la tecnologia, en cuestion de seguridad muchos de estos circuitos y sensores son de mucha ayuda a la hora de implementar en alarmas como el uso de samoforos. asi que se requiere realizar alertizador salvaguarda humano-coche a bajo costo.

1.2 Objetivo General de la aplicación

Este debe mostrar un conjunto de semáforos que cambiarán de verde a ámbar a rojo, y viceversa, luego de un período de tiempo establecido, utilizando el sistema de cuatro estados de los semáforos en México. Este se extiende para incluir un conjunto de luces y un botón peatonal para solicitar cruzar la calle. Cuando llega el peatón y se dispone a cruzar pulsa el botón que encuentra en la parte baja del semáforo, este reconoce la orden y cierra el paso de los vehículos para que el viandante pueda cruzar con seguridad hasta el otro lado de la calle. Una vez que se acaba el tiempo estipulado para que el peatón cruce, ese semáforo permanecerá abierto para mejorar la movilidad de los vehículos.

El sistema deberá de contener una perilla para controlar el tiempo mínimo en que el semáforo vehicular va a durar en verde.

1.3 Hipótesis

    • Como posible hipótesis se prevé que el circuito no tendrá problemas de instalación y cableado.
    • El alumno no tendrá problemas en la codificación.
    • posiblemente se tenga problemas al momento de mandar el tono del buzzer
    • Posibles fallas en el sistema, al momento de detectar el push button

1.4 Materiales

    • 1 Placa Arduino UNO
    • Cables macho-hembra
    • 1 buzzer
    • 6 leds
    • 8 resistencias 330 Ω 
    • 1 button
    • 1 reed switch
    • 1 potenciometro 10 kΩ

1.5 Diagrama

en el repositorio

1.6 Codigo

/*******************/
/*    Saul Gtz    */
/*******************/

/*******************/
/*    Declaracion de variales   */
/*******************/

int pulsador=0;              //almacena el estado del botón
int estado=0;                //0=led apagado, 1=led encendido
int pulsadorAnt=0;           //almacena el estado anterior del boton
int pinPot = A0;

/*******************/
/*    declaración de Notas    */
/*******************/
int c[5]={131,262,523,1046,2093};       // frecuencias 4 octavas de Do
int cs[5]={139,277,554,1108,2217};      // Do#
int d[5]={147,294,587,1175,2349};       // Re
int ds[5]={156,311,622,1244,2489};    // Re#
int e[5]={165,330,659,1319,2637};      // Mi
int f[5]={175,349,698,1397,2794};       // Fa
int fs[5]={185,370,740,1480,2960};     // Fa#
int g[5]={196,392,784,1568,3136};     // Sol
int gs[5]={208,415,831,1661,3322};   // Sol#
int a[5]={220,440,880,1760,3520};      // La
int as[5]={233,466,932,1866,3729};    // La#
int b[5]={247,494,988,1976,3951};      // Si

void nota(int a, int b);            // declaración de la función nota 
  
 /*******************/
/*  inicializamos los puertos o pines    */
/*******************/

void setup() {
 for (int pin = 2; pin <= 7; pin++) {
   pinMode(pin, OUTPUT);    //declaramos el rango de pines como salida
 }
  pinMode(10, INPUT);       //declaramos el boton como entrada  
  pinMode(12, OUTPUT);        //Buzzer

}

/*******************/
/*    ciclo repetitivo del codigo     */
/*******************/

void loop() {
  pulsador = digitalRead(10); //lee si el botón está pulsado
  
  if((pulsador==HIGH)&&(pulsadorAnt==LOW)){   //si el boton es pulsado y antes no lo estaba
    estado=1-estado;
    delay(10);               
  }
  pulsadorAnt=pulsador;      //actualiza el nuevo estado del boton        
  
if(estado==1) {            //si el estado es 1
    digitalWrite(2, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(4, LOW);
     tonosemaforo();
    //se enciende el led
  }
  else{                      //si el estado es 0
    //digitalWrite(2, LOW);
    //digitalWrite(7, LOW);
    //digitalWrite(5, HIGH);
    //digitalWrite(4, HIGH);
     noTone(12);
    Automoviles();
  }  
}


/*******************/
/*     declaracion notas tema star wars     */
/*******************/
void tonosemaforo(){
  nota(g[2],500);noTone(8);delay(100);
nota(g[2],500);noTone(8);delay(100);
nota(g[2],500);noTone(8);delay(100);
nota(ds[2],500);noTone(8);delay(1);
nota(as[2],125);noTone(8);delay(25);
nota(g[2],500);noTone(8);delay(100);
nota(ds[2],500);noTone(8);delay(1);
nota(as[2],125);noTone(8);delay(25);
nota(g[2],500);
noTone(8);delay(2000);
  
  }

/*******************/
/*     declaracion funcion nota     */
/*******************/

void nota(int frec, int t)
{
    tone(12,frec);          // suena la nota frec recibida
    delay(t);                // para despues de un tiempo t
}


/*******************/
/*     declaracion funcion semaforo automoviles    */
/*******************/

void Automoviles() {


   int count = 0;
 while (count < 30) {
   // El ciclo esta en espera mientras el boton no es presionado
   if (digitalRead(pulsador) == HIGH) {
     break;
      
   }

   count++;
   delay(200);
 }
 digitalWrite(2, HIGH);
 // Programamos el cambio entre semaforos. Cuando el LED tiene la posicion LOW estara apagado, mientras que si esta en posicion HIGH estada encendido.

potenciometro= analogRead(pinPot);

vel_parpadeo = map(valorPot, 0, 1023, 0, 500)*9;
Serial.println(vel_parpadeo);
 digitalWrite(2, LOW);
 delay(500);
 digitalWrite(2, HIGH);
 delay(500);
 digitalWrite(2, LOW);
 delay(500);
 digitalWrite(2, HIGH);
 delay(500);
 digitalWrite(2, LOW);
 digitalWrite(3, HIGH);
delay(vel_parpadeo);
 digitalWrite(3, LOW);
 digitalWrite(4, HIGH);
 digitalWrite(7, LOW);
 // Mandamos a llamar al otro semaforo


 Peatones();
}

/*******************/
/*     declaracion funcion semaforo peatones    */
/*******************/
void Peatones() {
  int count = 0;
   while (count < 30) {
   // El ciclo esta en espera mientras el boton no es presionado
   if (digitalRead(pulsador) == HIGH) {
     break;
      
   }

   count++;
   delay(200);
 }
 digitalWrite(5, HIGH);

 digitalWrite(5, LOW);
 delay(500);
 digitalWrite(5, HIGH);
 delay(500);
 digitalWrite(5, LOW);
 delay(500);
 digitalWrite(5, HIGH);
 delay(500);
 digitalWrite(6, HIGH);
delay(vel_parpadeo);
 digitalWrite(6, LOW);
 digitalWrite(7, HIGH);
 digitalWrite(4, LOW);
 // Mandamos a llamar al otro semaforo
 Automoviles();
}

1.7 pruebas / Evidencias

en el repositorio GitHub

1.8 Conclusiones

A la conclusión que se llego es la importancia que tiene una ing. En Sistemas computacionales dentro de los circuitos electronicos. ya que  con la programacion de circuitos realizan procesos computarizados para generar más seguridad  en menos tiempo y con menos recursos económicos y materiales.
