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
     tonos();
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
