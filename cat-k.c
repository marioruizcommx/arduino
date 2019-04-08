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

int pos = 0; 
int ida_cuello;
int vuelta_cuello;
int ida_pierna_derecha;
int vuelta_pierna_derecha;
int ida_rodilla_derecha;
int vuelta_rodilla_derecha;
int ida_pierna_izquierda;
int vuelta_pierna_izquierda;
int ida_rodilla_izquierda;
int vuelta_rodilla_izquierda;
int ida_hombro_derecho;
int vuelta_hombro_derecho;
int ida_codo_derecho;
int vuelta_codo_derecho;

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
     delay(30);                       
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
    for (pos = ida_pierna_derecha; pos <= vuelta_pierna_derecha; pos += 1) { 
      sv_piernaDerecha.write(pos);          
      f_setPiernaDerecha(pos);
      delay(30);                       
    }
    for (pos = ida_rodilla_derecha; pos <= vuelta_rodilla_derecha; pos += 1) { 
      sv_rodillaDerecha.write(pos);         
      f_setRodillaDerecha(pos);
      delay(30);                       
    }
    for (pos = vuelta_pierna_derecha; pos >= ida_pierna_derecha; pos -= 1) { 
      sv_piernaDerecha.write(pos); 
      f_setPiernaDerecha(pos);             
      delay(30);                       
    }
    for (pos = vuelta_rodilla_derecha; pos >= ida_rodilla_derecha; pos -= 1) { 
      sv_rodillaDerecha.write(pos);         
      f_setRodillaDerecha(pos);
      delay(30);                       
    }
   delay(30);
  }
void c_PasoPiernaIzquierda(){
    for (pos = ida_pierna_izquierda; pos <= vuelta_pierna_izquierda; pos += 1) {
      sv_piernaIzquierda.write(pos);      
      f_setPiernaIzquierda(pos);
      delay(30);                       
    }
    for (pos = ida_rodilla_izquierda; pos <= vuelta_rodilla_izquierda; pos += 1) {
      sv_rodillaIzquierda.write(pos);     
      f_setRodillaIzquierda(pos);
      delay(30);                       
    }
    for (pos = vuelta_pierna_izquierda; pos >= ida_pierna_izquierda; pos -= 1) {
      sv_piernaIzquierda.write(pos);      
      f_setPiernaIzquierda(pos);
      delay(30);                       
    }
    for (pos = vuelta_rodilla_izquierda; pos >= ida_rodilla_izquierda; pos -= 1) {
      sv_rodillaIzquierda.write(pos);     
      f_setRodillaIzquierda(pos);
      delay(30);                       
    }
   delay(30);
  }
void c_PasoHombroDerecho(){
    for (pos = ida_hombro_derecho; pos <= vuelta_hombro_derecho; pos += 1) {
      sv_hombroDerecho.write(pos);       
      f_setHombroDerecho(pos);
      delay(30);                      
    }
    for (pos = ida_codo_derecho; pos <= vuelta_codo_derecho; pos += 1) {
      sv_codoDerecho.write(pos);         
      f_setCodoDerecho(pos);
      delay(30);                       
    }
    for (pos = vuelta_hombro_derecho; pos >= ida_hombro_derecho; pos -= 1) {
      sv_hombroDerecho.write(pos);       
      f_setHombroDerecho(pos);
      delay(30);                       
    }
    for (pos = vuelta_codo_derecho; pos >= ida_codo_derecho; pos -= 1) {
      sv_codoDerecho.write(pos);         
      f_setCodoDerecho();
      delay(30);                       
    }
   delay(30);
  }
void c_PasoHombroIzquierdo(){
    for (pos = ida_hombro_izquierdo; pos <= vuelta_hombro_izquierdo; pos += 1) {
      sv_hombroIzquierdo.write(pos);      
      f_setHombroIzquierdo(pos);
      delay(30);                       
    }
    for (pos = ida_codo_izquierdo; pos <= vuelta_codo_izquierdo; pos += 1) {
      sv_codoIzquierdo.write(pos);        
      f_setCodoIzquierdo(pos);
      delay(30);                       
    }
    for (pos = vuelta_hombro_izquierdo; pos >= ida_hombro_izquierdo; pos -= 1) {
      sv_hombroIzquierdo.write(pos);      
      f_setHombroIzquierdo(pos);
      delay(30);                        
    }
    for (pos = vuelta_codo_izquierdo; pos >= ida_codo_izquierdo; pos -= 1) {
      sv_codoIzquierdo.write(pos);        
      f_setCodoIzquierdo(pos);
      delay(30);                       
    }
   delay(30);
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
    delay(30);                       
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
    delay(30);                       
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



