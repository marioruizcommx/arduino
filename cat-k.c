
#include <Servo.h>	

//Declaracion de Servomotores


long dis;
long tiem;

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
void f_caminaPanza();
void f_caminaSigiloso();


void setup() {
  
  Serial.begin(9600);//iniciailzamos la comunicación
  sv_cuello.attach(2);
  sv_piernaIzquierda.attach(4);
  sv_piernaDerecha.attach(5);
  sv_hombroIzquierdo.attach(6);
  sv_hombroDerecho.attach(7);
  sv_rodillaIzquierda.attach(8);
  sv_rodillaDerecha.attach(9);
  sv_codoIzquierdo.attach(10);
  sv_codoDerecho.attach(11);
  
pinMode(13, OUTPUT); //salida del pulso generado por el sensor ultrasónico
pinMode(12, INPUT);//entrada del pulso generado por el sensor ultrasónico

}

//////////////////////////////

void loop() {
m_inicio_operativo();

}

//////////////////////////////

void m_inicio_operativo() {
  digitalWrite(13,LOW);//recibimiento del pulso.
delayMicroseconds(5);
digitalWrite(13, HIGH);//envió del pulso.
delayMicroseconds(10);
tiem=pulseIn(12, HIGH);//fórmula para medir el pulso entrante.
dis= long(0.017*tiem);//fórmula para calcular la distancia del sensor ultrasónico.

if(dis>80){ //comparativo para la alarma se ingresa la distancia en la que encenderá o apagara.
f_caminaSigiloso();
}
else
{
    if(dis>30 && dis<100){ //comparativo para la alarma se ingresa la distancia en la que encenderá o apagara.
    f_caminaPanza();
    }
    else
    {
    f_posicionZero();
    }
}

Serial.println("LA DISTANCIA MEDIDA ES:");
Serial.println(dis);
Serial.println("cm");
delay(500);
}

//////////////////////////////

void f_pruebaComponentes() {

f_posicionZero;
    
    }
    
void f_posicionZero() {

    sv_piernaDerecha.write(90);
    sv_piernaIzquierda.write(90);
    sv_hombroIzquierdo.write(90);
    sv_hombroDerecho.write(90);
    sv_rodillaIzquierda.write(0);
    sv_rodillaDerecha.write(180);
    sv_codoIzquierdo.write(0);
    sv_codoDerecho.write(180);
    
    
}

void f_caminaSigiloso(){
    for (int pos = 1; pos <= 2; pos += 1) {
        
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

}
    
void f_caminaPanza() {
  
    for (int pos = 1; pos <= 2; pos += 1) {
    sv_rodillaIzquierda.write(0);
    sv_rodillaDerecha.write(180);
    sv_codoIzquierdo.write(0);
    sv_codoDerecho.write(180);
    delay(400);
    sv_piernaDerecha.write(45);
    sv_piernaIzquierda.write(135);
    sv_hombroIzquierdo.write(45);
    sv_hombroDerecho.write(135); 
    delay(400);
    sv_piernaDerecha.write(135);
    sv_piernaIzquierda.write(45);
    sv_hombroIzquierdo.write(135);
    sv_hombroDerecho.write(45);
    delay(400);
    }
    
}


