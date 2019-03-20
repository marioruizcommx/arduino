// Incluímos la librería para poder controlar el servo
#include <Servo.h>

// Declaramos la variable para controlar el servo
Servo sv_cuello;
Servo sv_rodillaDerecha;
Servo sv_rodillaIzquierda;
Servo sv_codoDerecho;
Servo sv_codoIzquierdo;
Servo sv_piernaDerecha;
Servo sv_piernaIzquierda;
Servo sv_hombroDerecho;
Servo sv_hombroIzquierdo;
void f_pasoDerecho();
void f_mueve_cabeza();

void f_pasoIzquierdo();
int i,j;
int li_lecturaDePila=1;
int v_sobranteDeBateria;
int led = 13;
const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el Echo del sensor
long t; //timepo que demora en llegar el eco
long d; //distancia en centimetros


//Inicializamos los Pines
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT); 
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0

  sv_cuello.attach(2); 
  sv_rodillaDerecha.attach(3); 
  sv_rodillaIzquierda.attach(4);
  sv_codoDerecho.attach(5);
  sv_codoIzquierdo.attach(6);
  sv_piernaDerecha.attach(7);
  sv_piernaIzquierda.attach(8);
  sv_hombroDerecho.attach(9);
  sv_hombroIzquierdo.attach(10); 
}

//Aqui manejaremos el estado actual del robot
void loop() {
  f_entradaSentidos();
}

//Esta funcion nos sirve para llevar el numero de acciones que realizara el robot dependiendo la cantidad previa mente realizados
int f_controlDeBateria(int cantidadPila){
    li_lecturaDePila=li_lecturaDePila+1;
    return li_lecturaDePila;
}

int f_lecturaDeBateria(){
return li_lecturaDePila;
}

//Desde esta entrada se manejaran los impactos que el medio o espacio provocara que el robot reacio s
void f_entradaSentidos(){
if (f_lecturaDeBateria()<=100){
        digitalWrite(Trigger, HIGH);
        delayMicroseconds(10);          //Enviamos un pulso de 10us
        digitalWrite(Trigger, LOW);
        t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
        d = t/59;             //escalamos el tiempo a una distancia en cm
      
          while(d >= 20){
           f_pasoDerecho();
           f_pasoIzquierdo();
          }
      
        Serial.print("Distancia: ");
        Serial.print(d);      //Enviamos serialmente el valor de la distancia
        Serial.print("cm");
        Serial.println();
        delay(100);          //Hacemos una pausa de 100ms
      
        //disminuimos la cantidad de moviminetos
        f_controlDeBateria(1);
}else{
  //Se activa el led para dar aviso de bateria baja
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
}


//Esta funcionalidad es para el caminar del robot
void f_pasoDerecho(){
    for (i=40;i<=140;i++){
        for (j=140;j>=40;j--){
            sv_piernaDerecha.write(i);
            sv_piernaIzquierda.write(i);
            sv_hombroDerecho.write(j);
            sv_hombroIzquierdo.write(j);
            {
               for (i=40;i<=140;i++){
                  for (j=140;j>=0;j--){
                    sv_rodillaDerecha.write(j); 
                    sv_rodillaIzquierda.write(j);
                    sv_codoDerecho.write(i);
                    sv_codoIzquierdo.write(i);
                    }
                  } 
            }
        }
    }
}


void f_pasoIzquierdo(){
    for (i=40;i<=140;i++){
        for (j=140;j>=40;j--){
            sv_piernaDerecha.write(j);
            sv_piernaIzquierda.write(j);
            sv_hombroDerecho.write(i);
            sv_hombroIzquierdo.write(i);
          {
               for (i=40;i<=140;i++){
                  for (j=140;j>=40;j--){
                    sv_rodillaDerecha.write(i); 
                    sv_rodillaIzquierda.write(i);
                    sv_codoDerecho.write(j);
                    sv_codoIzquierdo.write(j);
                    }
                  } 
            }
        }
    }
}

//Esta funcionalidad espara el movimiento de la cabeza
void f_mueve_cabeza(){
  sv_cuello.write(0);
  delay(1000);
  sv_cuello.write(180);
  delay(1000);
  sv_cuello.write(90);
  delay(10);
}
