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

int i,j,;

int c_lecturaDePila:=1;

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

 


//Aqui manejaremos el estado actual del robot

void loop() {

  f_entradaSentidos();

}



//Esta funcion nos sirve para llevar el numero de acciones que realizara el robot dependiendo la cantidad previa mente realizados

int f_controlDeBateria(int cantidadPila){


c_lecturaDePila=cantidadPila+1;


return c_lecturaDePila;

}


int f_lecturaDeBateria(){


return c_lecturaDeBateria;


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

        for (j=140;j>=40;j—){

            piernaDerecha.write(i);

            piernaIzquierda.write(i);

            hombroDerecho.write(j);

            hombroIzquierdo.write(j);

       delay(1000); 

            {

               for (i=40;i<=140;i++){

                  for (j=140;j>=0;j—){

                    rodillaDerecha.write(j); 

                    rodillaIzquierda.write(j);

                    codoDerecho.write(i);

                    codoIzquierdo.write(i);

                    }

                  } 

                

            }

        }

    }

}


void f_pasoIzquierdo(){

    for (i=40;i<=140;i++){

        for (j=140;j>=40;j—){

            piernaDerecha.write(j);

            piernaIzquierda.write(j);

            hombroDerecho.write(i);

            hombroIzquierdo.write(i);

       delay(1000); 

         {

               for (i=40;i<=140;i++){

                  for (j=140;j>=40;j—){

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


//Esta funcionalidad espara el movimiento de la cabeza

void f_mueve_cabeza(){

  cuello.write(0);

  delay(1000);

  cuello.write(180);

  delay(1000);

  cuello.write(90);

  delay(1000);

}
