/* Sweep
  Write by Atlanta Algorithm <http://atlantaalgorithm.com>
  by Mario Ruiz
*/

#include <Servo.h>

//Declaracion de Servomotores

Servo sv_cuello;
Servo sv_piernaDerecha;
Servo sv_piernaIzquierda;
Servo sv_hombroIzquierdo;
Servo sv_hombroDerecho;
Servo sv_rodillaIzquierda;
Servo sv_rodillaDerecha;
Servo sv_codoIzquierdo;
Servo sv_codoDerecho;

int salida;

//Declaracion de funciones

void f_pruebaComponentes();

int pos = 0;
const int pinecho = 12;
const int pintrigger = 13;
unsigned int tiempo, distancia;

void setup() {
  sv_cuello.attach(2);
  sv_piernaIzquierda.attach(4);
  sv_piernaDerecha.attach(5);
  sv_hombroIzquierdo.attach(6);
  sv_hombroDerecho.attach(7);
  sv_rodillaIzquierda.attach(8);
  sv_rodillaDerecha.attach(9);
  sv_codoIzquierdo.attach(10);
  sv_codoDerecho.attach(11);
  pinMode(pinecho, INPUT);
  pinMode(pintrigger, OUTPUT);
}

//////////////////////////////

void loop() {
  Serial.begin(9600);
  f_pruebaComponentes();
}

//////////////////////////////

void m_inicio_operativo() {

          for (pos = 1; pos <= 5; pos += 1) {
            Serial.println("************************ Encendiendo Modulos ************************");
            delayMicroseconds(600);
          }
  // ENVIAR PULSO DE DISPARO EN EL PIN "TRIGGER"
  digitalWrite(pintrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger, HIGH);
  // EL PULSO DURA AL MENOS 10 uS EN ESTADO ALTO
  delayMicroseconds(10);
  digitalWrite(pintrigger, LOW);
  // MEDIR EL TIEMPO EN ESTADO ALTO DEL PIN "ECHO" EL PULSO ES PROPORCIONAL A LA DISTANCIA MEDIDA
  tiempo = pulseIn(pinecho, HIGH);
  // LA VELOCIDAD DEL SONIDO ES DE 340 M/S O 29 MICROSEGUNDOS POR CENTIMETRO
  // DIVIDIMOS EL TIEMPO DEL PULSO ENTRE 58, TIEMPO QUE TARDA RECORRER IDA Y VUELTA UN CENTIMETRO LA ONDA SONORA
  distancia = tiempo / 58;

  if (distancia >= 15) {
          for (pos = 1; pos <= 5; pos += 1) {
            Serial.println("+++++++++++++++++++++++ muevete +++++++++++++++++++++++");
            delayMicroseconds(500);
          }
      Serial.println(distancia);
      Serial.println(" cm");
      delayMicroseconds(500);
      f_pruebaComponentes();
   } else {
          for (pos = 1; pos <= 5; pos += 1) {
            Serial.println("----------------------- alto -----------------------");
            delay(500);
          }
      delay(500);
  }
  delayMicroseconds(200);
}

//////////////////////////////

void f_pruebaComponentes() {
    //posicion cero
    
    /*
    sv_piernaDerecha.write(90);
    sv_piernaIzquierda.write(90);
    sv_hombroIzquierdo.write(90);
    sv_hombroDerecho.write(90);
    sv_rodillaIzquierda.write(0);
    sv_rodillaDerecha.write(180);
    sv_codoIzquierdo.write(0);
    sv_codoDerecho.write(180);
    
        sv_piernaDerecha.write(45);
    sv_piernaIzquierda.write(135);
    sv_hombroIzquierdo.write(135);
    sv_hombroDerecho.write(45);
    delay(500);
    sv_piernaDerecha.write(135);
    sv_piernaIzquierda.write(45);
    sv_hombroIzquierdo.write(45);
    sv_hombroDerecho.write(135);
    delay(500);
*/

    sv_piernaDerecha.write(45);
    sv_piernaIzquierda.write(45);
    sv_hombroIzquierdo.write(45);
    sv_hombroDerecho.write(45);


    sv_piernaDerecha.write(135);
    sv_piernaIzquierda.write(135);
    sv_hombroIzquierdo.write(135);
    sv_hombroDerecho.write(135);


    
    
    /*
    for (pos = 1; pos <= 5; pos += 1) {
    sv_piernaDerecha.write(45);
    sv_piernaIzquierda.write(45);
    sv_hombroIzquierdo.write(45);
    sv_hombroDerecho.write(45);
    sv_rodillaIzquierda.write(0);
    sv_rodillaDerecha.write(180);
    sv_codoIzquierdo.write(0);
    sv_codoDerecho.write(180);

    sv_piernaDerecha.write(135);
    sv_piernaIzquierda.write(135);
    sv_hombroIzquierdo.write(135);
    sv_hombroDerecho.write(135);
    sv_rodillaIzquierda.write(0);
    sv_rodillaDerecha.write(180);
    sv_codoIzquierdo.write(0);
    sv_codoDerecho.write(180);
    }
    */
    
    /*
    for (pos = 1; pos <= 5; pos += 1) {
        
    sv_piernaDerecha.write(135);
    sv_hombroDerecho.write(45);
    sv_codoDerecho.write(180);
    delay(500);
    sv_rodillaDerecha.write(135);
    delay(500);
    sv_rodillaDerecha.write(90);
    
    delay(500);
    sv_piernaDerecha.write(45);
    sv_hombroDerecho.write(135);
    delay(500);
    sv_codoDerecho.write(135);
    delay(500);
    sv_codoDerecho.write(90);
    sv_rodillaDerecha.write(180);
    delay(500);
    
    
    sv_piernaIzquierda.write(45);
    sv_hombroIzquierdo.write(135);
    sv_codoIzquierdo.write(0);
    delay(500);
    sv_rodillaIzquierda.write(45);
    delay(500);
    sv_rodillaIzquierda.write(90);
    
    delay(500); 
    sv_piernaIzquierda.write(135);
    sv_hombroIzquierdo.write(45);
    delay(500);
    sv_codoIzquierdo.write(45); 
    delay(500);
    sv_codoIzquierdo.write(90);
    sv_rodillaIzquierda.write(0);
    delay(500);
    }
*/

}
