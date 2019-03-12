 // Incluímos la librería para poder controlar el servo
#include <Servo.h>
 
// Declaramos la variable para controlar el servo
Servo cuello;
Servo rodillaDerecha;
Servo rodillaIzquierda;
Servo codoDerecho;
Servo codoIzquierdo;
Servo piernaDerecha;
Servo piernaIzquierda;
Servo hombroDerecho;
Servo hombroIzquierdo;
void f_camina_adelante();
void f_mueve_cabeza();
int i,j;

void setup() {
  // Iniciamos el monitor serie para mostrar el resultado
  Serial.begin(9600);
 
  // Iniciamos el servo para que empiece a trabajar con el pin 9
  cuello.attach(2); 
  rodillaDerecha.attach(3); 
  rodillaIzquierda.attach(4);
  codoDerecho.attach(5);
  codoIzquierdo.attach(6);
  piernaDerecha.attach(7);
  piernaIzquierda.attach(8);
  hombroDerecho.attach(9);
  hombroIzquierdo.attach(10); 
  
}
 
void loop() {
  f_camina_adelante();
  f_mueve_cabeza();
}

void f_camina_adelante(){

    for (i=40;i<=140;i++){
        for (j=140;j>=40;j--){
            piernaDerecha.write(i);
            piernaIzquierda.write(i);
            hombroDerecho.write(j);
            hombroIzquierdo.write(j);
       delay(1000); 
            {
               for (i=40;i<=140;i++){
                  for (j=140;j>=0;j--){
                    rodillaDerecha.write(j); 
                    rodillaIzquierda.write(j);
                    codoDerecho.write(i);
                    codoIzquierdo.write(i);
                    }
                  } 
                
            }
        }
    }
    for (i=40;i<=140;i++){
        for (j=140;j>=40;j--){
            piernaDerecha.write(j);
            piernaIzquierda.write(j);
            hombroDerecho.write(i);
            hombroIzquierdo.write(i);
       delay(1000); 
         {
               for (i=40;i<=140;i++){
                  for (j=140;j>=40;j--){
                    rodillaDerecha.write(i); 
                    rodillaIzquierda.write(i);
                    codoDerecho.write(j);
                    codoIzquierdo.write(j);
                    }
                  } 
                
            }
        }
    }
}

void f_mueve_cabeza(){
  
  cuello.write(0);
  delay(1000);
  cuello.write(180);
  delay(1000);
  cuello.write(90);
  delay(1000);

}
