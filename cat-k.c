/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo sv_cuello;  // create servo object to control a servo
Servo sv_piernaDerecha;  // create servo object to control a servo
Servo sv_piernaIzquierda;  // create servo object to control a servo
Servo sv_hombroIzquierdo;  // create servo object to control a servo
Servo sv_hombroDerecho;  // create servo object to control a servo
Servo sv_rodillaIzquierda;  // create servo object to control a servo
Servo sv_rodillaDerecha;  // create servo object to control a servo
Servo sv_codoIzquierdo;  // create servo object to control a servo
Servo sv_codoDerecho;  // create servo object to control a servo

int e_cuello;
int e_piernaDerecha;
int e_piernaIzquierda;
int e_hombroIzquierdo;
int e_hombroDerecho;
int e_rodillaIzquierda;
int e_rodillaDerecha;
int e_codoIzquierdo;
int e_codoDerecho;
int salida;

void f_pruebaComponentes();

int f_getEstadoCuello();
void f_setEstadoCuello(int aValue);
int f_getEstadoCuello();
void f_setEstadoCuello(int aValue);
int f_getPiernaDerecha();
void f_setPiernaDerecha(int aValue);
int f_getPiernaIzquierda();
void f_setPiernaIzquierda(int aValue);
int f_getHombroIzquierdo();
void f_setHombroIzquierdo(int aValue);
int f_getHombroDerecho();
void f_setHombroDerecho(int aValue);
int f_getRodillaIzquierda();
void f_setRodillaIzquierda(int aValue);
int f_getRodillaDerecha();
void f_setRodillaDerecha(int aValue);
int f_getCodoIzquierdo();
void f_setCodoIzquierdo(int aValue);
int f_getCodoDerecho();
void f_setCodoDerecho(int aValue);

void c_centraCuello();
void c_PasoPiernaDerecha();
void c_PasoHombroDerecho();
void c_PasoPiernaIzquierda();
void c_PasoHombroIzquierdo();

int pos = 0;    // variable to store the servo position

void setup() {
  sv_cuello.attach(2);  // attaches the servo on pin 9 to the servo object
  sv_piernaIzquierda.attach(4);  // attaches the servo on pin 9 to the servo object
  sv_piernaDerecha.attach(5);  // attaches the servo on pin 9 to the servo object
  sv_hombroIzquierdo.attach(6);  // attaches the servo on pin 9 to the servo object
  sv_hombroDerecho.attach(7);  // attaches the servo on pin 9 to the servo object
  sv_rodillaIzquierda.attach(8);  // attaches the servo on pin 9 to the servo object
  sv_rodillaDerecha.attach(9);  // attaches the servo on pin 9 to the servo object
  sv_codoIzquierdo.attach(10);  // attaches the servo on pin 9 to the servo object
  sv_codoDerecho.attach(11);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  Serial.begin(9600);
  //f_pruebaComponentes();
  c_movimientoCuello();
  //c_PasoPiernaDerecha();
  //c_PasoHombroDerecho();
  //c_PasoPiernaIzquierda();
  //c_PasoHombroIzquierdo();
}

void c_movimientoCuello(){
   for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
     sv_cuello.write(pos);              // tell servo to go to position in variable 'pos
     f_setEstadoCuello(pos);
     salida=f_getEstadoCuello();
     Serial.println("La salida es:");
     Serial.println(salida);
     delay(30);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
     sv_cuello.write(pos);              // tell servo to go to position in variable 'pos'
     f_setEstadoCuello(pos);
     salida=f_getEstadoCuello();
     Serial.println("La salida es:");
     Serial.println(salida);
     delay(30);                       // waits 15ms for the servo to reach the position
    }
  }
void c_PasoPiernaDerecha(){
    for (pos = 90; pos <= 160; pos += 1) { // goes from 0 degrees to 180 degrees
      sv_piernaDerecha.write(pos);              // tell servo to go to position in variable 'pos'
      delay(30);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 60; pos <= 130; pos += 1) { // goes from 0 degrees to 180 degrees
      sv_rodillaDerecha.write(pos);              // tell servo to go to position in variable 'pos'
      delay(30);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 160; pos >= 90; pos -= 1) { // goes from 0 degrees to 180 degrees
      sv_piernaDerecha.write(pos);              // tell servo to go to position in variable 'pos'
      delay(30);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 130; pos >= 60; pos -= 1) { // goes from 0 degrees to 180 degrees
      sv_rodillaDerecha.write(pos);             // tell servo to go to position in variable 'pos'
      delay(30);                       // waits 15ms for the servo to reach the position
    }
   delay(30);
  }
void c_PasoPiernaIzquierda(){
    for (pos = 10; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees
      sv_piernaIzquierda.write(pos);              // tell servo to go to position in variable 'pos'
      delay(30);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 30; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees
      sv_rodillaIzquierda.write(pos);              // tell servo to go to position in variable 'pos'
      delay(30);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 100; pos >= 10; pos -= 1) { // goes from 0 degrees to 180 degrees
      sv_piernaIzquierda.write(pos);              // tell servo to go to position in variable 'pos'
      delay(30);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 100; pos >= 30; pos -= 1) { // goes from 0 degrees to 180 degrees
      sv_rodillaIzquierda.write(pos);             // tell servo to go to position in variable 'pos'
      delay(30);                       // waits 15ms for the servo to reach the position
    }
   delay(30);
  }
void c_PasoHombroDerecho(){
    for (pos = 0; pos <= 100; pos += 1) { // goes from 0 degrees to 180 degrees
      sv_hombroDerecho.write(pos);              // tell servo to go to position in variable 'pos'
      delay(30);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 60; pos <= 80; pos += 1) { // goes from 0 degrees to 180 degrees
      sv_codoDerecho.write(pos);              // tell servo to go to position in variable 'pos'
      delay(30);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 100; pos >= 0; pos -= 1) { // goes from 0 degrees to 180 degrees
      sv_hombroDerecho.write(pos);              // tell servo to go to position in variable 'pos'
      delay(30);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 80; pos >= 60; pos -= 1) { // goes from 0 degrees to 180 degrees
      sv_codoDerecho.write(pos);             // tell servo to go to position in variable 'pos'
      delay(30);                       // waits 15ms for the servo to reach the position
    }
   delay(30);
  }
void c_PasoHombroIzquierdo(){
    for (pos = 70; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
      sv_hombroIzquierdo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(30);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 90; pos <= 120; pos += 1) { // goes from 0 degrees to 180 degrees
      sv_codoIzquierdo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(30);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 180; pos >= 70; pos -= 1) { // goes from 0 degrees to 180 degrees
      sv_hombroIzquierdo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(30);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 120; pos >= 90; pos -= 1) { // goes from 0 degrees to 180 degrees
      sv_codoIzquierdo.write(pos);             // tell servo to go to position in variable 'pos'
      delay(30);                       // waits 15ms for the servo to reach the position
    }
   delay(30);
  }

void f_pruebaComponentes(){
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    //sv_cuello.write(pos);              // tell servo to go to position in variable 'pos
    //sv_piernaDerecha.write(pos);              // tell servo to go to position in variable 'pos'
    //sv_piernaIzquierda.write(pos);              // tell servo to go to position in variable 'pos'
    //sv_hombroIzquierdo.write(pos);              // tell servo to go to position in variable 'pos'
    //sv_hombroDerecho.write(pos);              // tell servo to go to position in variable 'pos'
    //sv_rodillaIzquierda.write(pos);              // tell servo to go to position in variable 'pos'
    //sv_rodillaDerecha.write(pos);              // tell servo to go to position in variable 'pos'
    //sv_codoIzquierdo.write(pos);              // tell servo to go to position in variable 'pos'
    //sv_codoDerecho.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    //sv_cuello.write(pos);              // tell servo to go to position in variable 'pos'
    //sv_piernaDerecha.write(pos);              // tell servo to go to position in variable 'pos'
    //sv_piernaIzquierda.write(pos);              // tell servo to go to position in variable 'pos'
    //sv_hombroIzquierdo.write(pos);              // tell servo to go to position in variable 'pos'
    //sv_hombroDerecho.write(pos);              // tell servo to go to position in variable 'pos'
    //sv_rodillaIzquierda.write(pos);              // tell servo to go to position in variable 'pos'
    //sv_rodillaDerecha.write(pos);              // tell servo to go to position in variable 'pos'
    //sv_codoIzquierdo.write(pos);              // tell servo to go to position in variable 'pos'
    //sv_codoDerecho.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
}

int f_getEstadoCuello(){
    return e_cuello;
  }
void f_setEstadoCuello(int aValue){
     e_cuello = aValue;
}
int f_getPiernaDerecha(){
    return e_piernaDerecha;
  }
void f_setPiernaDerecha(int aValue){
     e_piernaDerecha = aValue;
}
int f_getPiernaIzquierda(){
    return e_piernaIzquierda;
  }
void f_setPiernaIzquierda(int aValue){
     e_piernaIzquierda = aValue;
}
int f_getHombroIzquierdo(){
    return e_hombroIzquierdo;
  }
void f_setHombroIzquierdo(int aValue){
     e_hombroIzquierdo = aValue;
}
int f_getHombroDerecho(){
    return e_hombroDerecho;
  }
void f_setHombroDerecho(int aValue){
     e_hombroDerecho = aValue;
}
int f_getRodillaIzquierda(){
    return e_rodillaIzquierda;
  }
void f_setRodillaIzquierda(int aValue){
     e_rodillaIzquierda = aValue;
}
int f_getRodillaDerecha(){
    return e_rodillaDerecha;
  }
void f_setRodillaDerecha(int aValue){
     e_rodillaDerecha = aValue;
}
int f_getCodoIzquierdo(){
    return e_codoIzquierdo;
  }
void f_setCodoIzquierdo(int aValue){
     e_codoIzquierdo = aValue;
}
int f_getCodoDerecho(){
    return e_codoDerecho;
  }
void f_setCodoDerecho(int aValue){
     e_codoDerecho = aValue;
}
