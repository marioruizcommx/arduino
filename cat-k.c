/* Sweep
 Write by Atlanta Algorithm <http://atlantaalgorithm.com>
 by Mario Ruiz
*/

#include <Servo.h>

Servo sv_cuello;  
Servo sv_piernaDerecha; 
Servo sv_piernaIzquierda;  
Servo sv_hombroIzquierdo;  
Servo sv_hombroDerecho; 
Servo sv_rodillaIzquierda; 
Servo sv_rodillaDerecha;  
Servo sv_codoIzquierdo;  
Servo sv_codoDerecho;  

int e_cuello;
int e_piernaDerecha;
int e_piernaIzquierda;
int e_hombroIzquierdo;
int e_hombroDerecho;
int e_rodillaIzquierda;
int e_rodillaDerecha;
int e_codoIzquierdo;
int e_codoDerecho;
int e_ida_cuello;
int e_vuelta_cuello;
int e_ida_pierna_derecha = 90;
int e_vuelta_pierna_derecha = 160;
int e_ida_rodilla_derecha = 60;
int e_vuelta_rodilla_derecha = 130;
int e_ida_pierna_izquierda = 10;
int e_vuelta_pierna_izquierda = 100;
int e_ida_rodilla_izquierda = 30;
int e_vuelta_rodilla_izquierda = 100;
int e_ida_hombro_derecho = 0;
int e_vuelta_hombro_derecho = 100;
int e_ida_codo_derecho = 60;
int e_vuelta_codo_derecho = 80;
int e_ida_hombro_izquierdo = 70;
int e_vuelta_hombro_izquierdo = 180;
int e_ida_codo_izquierdo = 90;
int e_vuelta_codo_izquierdo = 120;
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


int f_getIdaPiernaDerecha();
void f_setIdaPiernaDerecha(int aValue);
int f_getVueltaPiernaDerecha();
void f_setVueltaPiernaDerecha(int aValue);
int f_getIdaRodillaDerecha();
void f_setIdaRodillaDerecha(int aValue);
int f_getVueltaRodillaDerecha();
void f_setVueltaRodillaDerecha(int aValue);
int f_getIdaPiernaIzquierda();
void f_setIdaPiernaIzquierda(int aValue);
int f_getVueltaPiernaIzquierda();
void f_setVueltaPiernaIzquierda(int aValue);
int f_getIdaRodillaIzquierda();
void f_setIdaRodillaIzquierda(int aValue);
int f_getVueltaRodillaIzquierda();
void f_setVueltaRodillaIzquierda(int aValue);
int f_getIdaHombroDerecho();
void f_setIdaHombroDerecho(int aValue);
int f_getVueltaHombroDerecho();
void f_setVueltaHombroDerecho(int aValue);
int f_getIdaCodoDerecho();
void f_setIdaCodoDerecho(int aValue);
int f_getVueltaCodoDerecho();
void f_setVueltaCodoDerecho(int aValue);
int f_getIdaHombroIzquierdo();
void f_setIdaHombroIzquierdo(int aValue);
int f_getVueltaHombroIzquierdo();
void f_setVueltaHombroIzquierdo(int aValue);
int f_getIdaCodoIzquierdo();
void f_setIdaCodoIzquierdo(int aValue);
int f_getVueltaCodoIzquierdo();
void f_setVueltaCodoIzquierdo(int aValue);

void c_centraCuello();
void c_PasoPiernaDerecha();
void c_PasoHombroDerecho();
void c_PasoPiernaIzquierda();
void c_PasoHombroIzquierdo();

int pos = 0; 


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
   for (pos = ida_cuello; pos <= vuelta_cuello; pos += 1) { 
     sv_cuello.write(pos);              
     f_setEstadoCuello(pos);
     //salida=f_getEstadoCuello();
     //Serial.println("La salida es:");
     //Serial.println(salida);
     delayMicroseconds(300);                       
  }
  for (pos = vuelta_cuello; pos >= ida_cuello; pos -= 1) { 
     sv_cuello.write(pos);              
     f_setEstadoCuello(pos);
     //salida=f_getEstadoCuello();
     //Serial.println("La salida es:");
     //Serial.println(salida);
     //delay(30);                       
    }
  }
  
void c_PasoPiernaDerecha(){
    for (pos = e_ida_pierna_derecha; pos <= e_vuelta_pierna_derecha; pos += 1) { 
      sv_piernaDerecha.write(pos);          
      f_setPiernaDerecha(pos);
      delayMicroseconds(300);                       
    }
    for (pos = e_ida_rodilla_derecha; pos <= e_vuelta_rodilla_derecha; pos += 1) { 
      sv_rodillaDerecha.write(pos);         
      f_setRodillaDerecha(pos);
      delayMicroseconds(300);                       
    }
    for (pos = e_vuelta_pierna_derecha; pos >= e_ida_pierna_derecha; pos -= 1) { 
      sv_piernaDerecha.write(pos); 
      f_setPiernaDerecha(pos);             
      delayMicroseconds(300);                       
    }
    for (pos = e_vuelta_rodilla_derecha; pos >= e_ida_rodilla_derecha; pos -= 1) { 
      sv_rodillaDerecha.write(pos);         
      f_setRodillaDerecha(pos);
      delayMicroseconds(300);                       
    }
   delayMicroseconds(300);
  }
  
void c_PasoPiernaIzquierda(){
    for (pos = e_ida_pierna_izquierda; pos <= e_vuelta_pierna_izquierda; pos += 1) {
      sv_piernaIzquierda.write(pos);      
      f_setPiernaIzquierda(pos);
      delayMicroseconds(300);                       
    }
    for (pos = e_ida_rodilla_izquierda; pos <= e_vuelta_rodilla_izquierda; pos += 1) {
      sv_rodillaIzquierda.write(pos);     
      f_setRodillaIzquierda(pos);
      delayMicroseconds(300);                       
    }
    for (pos = e_vuelta_pierna_izquierda; pos >= e_ida_pierna_izquierda; pos -= 1) {
      sv_piernaIzquierda.write(pos);      
      f_setPiernaIzquierda(pos);
      delayMicroseconds(300);                       
    }
    for (pos = e_vuelta_rodilla_izquierda; pos >= e_ida_rodilla_izquierda; pos -= 1) {
      sv_rodillaIzquierda.write(pos);     
      f_setRodillaIzquierda(pos);
      delayMicroseconds(300);                       
    }
   delayMicroseconds(300);
  }
  
void c_PasoHombroDerecho(){
    for (pos = e_ida_hombro_derecho; pos <= e_vuelta_hombro_derecho; pos += 1) {
      sv_hombroDerecho.write(pos);       
      f_setHombroDerecho(pos);
      delayMicroseconds(300);                      
    }
    for (pos = e_ida_codo_derecho; pos <= e_vuelta_codo_derecho; pos += 1) {
      sv_codoDerecho.write(pos);         
      f_setCodoDerecho(pos);
      delayMicroseconds(300);                       
    }
    for (pos = e_vuelta_hombro_derecho; pos >= e_ida_hombro_derecho; pos -= 1) {
      sv_hombroDerecho.write(pos);       
      f_setHombroDerecho(pos);
      delayMicroseconds(300);                       
    }
    for (pos = e_vuelta_codo_derecho; pos >= e_ida_codo_derecho; pos -= 1) {
      sv_codoDerecho.write(pos);         
      f_setCodoDerecho();
      delayMicroseconds(300);                       
    }
   delayMicroseconds(300);
  }
  
void c_PasoHombroIzquierdo(){
    for (pos = e_ida_hombro_izquierdo; pos <= e_vuelta_hombro_izquierdo; pos += 1) {
      sv_hombroIzquierdo.write(pos);      
      f_setHombroIzquierdo(pos);
      delayMicroseconds(300);                       
    }
    for (pos = e_ida_codo_izquierdo; pos <= e_vuelta_codo_izquierdo; pos += 1) {
      sv_codoIzquierdo.write(pos);        
      f_setCodoIzquierdo(pos);
      delayMicroseconds(300);                       
    }
    for (pos = e_vuelta_hombro_izquierdo; pos >= e_ida_hombro_izquierdo; pos -= 1) {
      sv_hombroIzquierdo.write(pos);      
      f_setHombroIzquierdo(pos);
      delayMicroseconds(300);                        
    }
    for (pos = e_vuelta_codo_izquierdo; pos >= e_ida_codo_izquierdo; pos -= 1) {
      sv_codoIzquierdo.write(pos);        
      f_setCodoIzquierdo(pos);
      delayMicroseconds(300);                       
    }
   delayMicroseconds(300);
  }

void f_pruebaComponentes(){
    for (pos = 0; pos <= 180; pos += 1) { 
    // in steps of 1 degree
    //sv_cuello.write(pos);              
    //sv_piernaDerecha.write(pos);        
    //sv_piernaIzquierda.write(pos);      
    //sv_hombroIzquierdo.write(pos);      
    //sv_hombroDerecho.write(pos);        
    //sv_rodillaIzquierda.write(pos);     
    //sv_rodillaDerecha.write(pos);       
    //sv_codoIzquierdo.write(pos);        
    //sv_codoDerecho.write(pos);          
    delayMicroseconds(300);                       
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    //sv_cuello.write(pos);              
    //sv_piernaDerecha.write(pos);        
    //sv_piernaIzquierda.write(pos);      
    //sv_hombroIzquierdo.write(pos);      
    //sv_hombroDerecho.write(pos);        
    //sv_rodillaIzquierda.write(pos);     
    //sv_rodillaDerecha.write(pos);       
    //sv_codoIzquierdo.write(pos);        
    //sv_codoDerecho.write(pos);          
    delayMicroseconds(300);                       
  }
}

////////////////////////////////////////////////

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

////////////////////////////////////////

int f_getIdaPiernaDerecha(){
    return e_ida_pierna_derecha;
  }
void f_setIdaPiernaDerecha(int aValue){
     e_ida_pierna_derecha = aValue;
}
int f_getVueltaPiernaDerecha(){
    return e_vuelta_pierna_derecha;
  }
void f_setVueltaPiernaDerecha(int aValue){
     e_vuelta_pierna_derecha = aValue;
}
int f_getIdaRodillaDerecha(){
    return e_ida_rodilla_derecha;
  }
void f_setIdaRodillaDerecha(int aValue){
     e_ida_rodilla_derecha = aValue;
}
int f_getVueltaRodillaDerecha(){
    return e_vuelta_rodilla_derecha;
  }
void f_setVueltaRodillaDerecha(int aValue){
     e_vuelta_rodilla_derecha = aValue;
}
int f_getIdaPiernaIzquierda(){
    return e_ida_pierna_izquierda;
  }
void f_setIdaPiernaIzquierda(int aValue){
     e_ida_pierna_izquierda = aValue;
}
int f_getVueltaPiernaIzquierda(){
    return e_vuelta_pierna_izquierda;
  }
void f_setVueltaPiernaIzquierda(int aValue){
     e_vuelta_pierna_izquierda = aValue;
}
int f_getIdaRodillaIzquierda(){
    return e_ida_rodilla_izquierda;
  }
void f_setIdaRodillaIzquierda(int aValue){
     e_ida_rodilla_izquierda = aValue;
}
int f_getVueltaRodillaIzquierda(){
    return e_vuelta_rodilla_izquierda;
  }
void f_setVueltaRodillaIzquierda(int aValue){
     e_vuelta_rodilla_izquierda = aValue;
}
int f_getIdaHombroDerecho(){
    return e_ida_hombro_derecho;
  }
void f_setIdaHombroDerecho(int aValue){
     e_ida_hombro_derecho = aValue;
}
int f_getVueltaHombroDerecho(){
    return e_vuelta_hombro_derecho;
  }
void f_setVueltaHombroDerecho(int aValue){
     e_vuelta_hombro_derecho = aValue;
}
int f_getIdaCodoDerecho(){
    return e_ida_codo_derecho;
  }
void f_setIdaCodoDerecho(int aValue){
     e_ida_codo_derecho = aValue;
}
int f_getVueltaCodoDerecho(){
    return e_vuelta_codo_derecho;
  }
void f_setVueltaCodoDerecho(int aValue){
     e_vuelta_codo_derecho = aValue;
}
int f_getIdaHombroIzquierdo(){
    return e_ida_hombro_izquierdo;
  }
void f_setIdaHombroIzquierdo(int aValue){
     e_ida_hombro_izquierdo = aValue;
}
int f_getVueltaHombroIzquierdo(){
    return e_Vuelta_hombro_izquierdo;
  }
void f_setVueltaHombroIzquierdo(int aValue){
     e_vuelta_hombro_izquierdo = aValue;
}
int f_getIdaCodoIzquierdo(){
    return e_ida_codo_izquierdo;
  }
void f_setIdaCodoIzquierdo(int aValue){
     e_ida_codo_izquierdo = aValue;
}
int f_getVueltaCodoIzquierdo(){
    return e_Vuelta_codo_izquierdo;
  }
void f_setVueltaCodoIzquierdo(int aValue){
     e_vuelta_codo_izquierdo = aValue;
}


