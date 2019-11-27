#include <Servo.h>  

/*
*--------------------------------------------*
*          Mario Ruiz Gonzalez               *
*        www.atlantaalgorithm.com            *
*--------------------------------------------*
*  Ayudanos a seguir creando nuevos kits     *
*  simplemente con No compartir este codigo. *
*  esperamos que te diviertas, saludos.      *
*--------------------------------------------*
*/

//Declaracion de variables

long dis;
long tiem;
int salida;

Servo sv_cuello;
Servo sv_piernaDerecha;
Servo sv_piernaIzquierda;
Servo sv_hombroIzquierdo;
Servo sv_hombroDerecho;
Servo sv_rodillaIzquierda;
Servo sv_rodillaDerecha;
Servo sv_codoIzquierdo;
Servo sv_codoDerecho;

//Declaracion de funciones

void f_pruebaComponentes();
void f_caminaPanza();
void f_caminaSigiloso();
void f_escapaPorDerecha();
void f_escapaPorIzquierda();
void f_banner();
void f_posicionAcostado();
void f_posicionAburrido();
void f_posicionAburrido2(); 
void f_posicionAburrido3();
void f_posicionAburrido4();
void f_posicionAburrido5();
////////////////////////////

void setup() {
  
  Serial.begin(9600);
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
                                                      
//m_inicio_operativo();
f_pruebaComponentes();

}

//////////////////////////////

void m_inicio_operativo() {

f_banner();
digitalWrite(13,LOW);//recibimiento del pulso.
delayMicroseconds(5);
digitalWrite(13, HIGH);//envió del pulso.
delayMicroseconds(10);
tiem=pulseIn(12, HIGH);//fórmula para medir el pulso entrante.
dis= long(0.017*tiem);//fórmula para calcular la distancia del sensor ultrasónico.

if(dis>80){ //Si la distancia es mayor a 80cm avanza rapido.
    f_caminaPanza();
}
else
{
    if(dis>30 && dis<80){ //Si la distancia se encuentra entre 30cm y 80cm avanza con cautela .  
        f_caminaSigiloso();
    }
    else
    {
        f_escapaPorDerecha();//Al estar a 30cm o menos de un obstaculo recto comienza a girar a la derecha
    }
}

Serial.println("Distancia para el impacto:");
Serial.println(dis);
Serial.println("cm");
delay(500);
}

//////////////////////////////

void f_pruebaComponentes() {
f_escapaPorIzquierda();
    
    }

//////////////////////////////

void f_posicionZero() {

    //Esta posicion no se encuentra implementado
    //y deja al prototipo con las patas en la siguiente posicion: (derecho) |_ |_ °° _| _|  (izquierdo)
  
    sv_piernaDerecha.write(90);
    sv_piernaIzquierda.write(90);
    sv_hombroIzquierdo.write(90);
    sv_hombroDerecho.write(90);
    sv_rodillaIzquierda.write(0);
    sv_rodillaDerecha.write(180);
    sv_codoIzquierdo.write(0);
    sv_codoDerecho.write(180);
   
}

//////////////////////////////

void f_posicionAcostado() {

    //Esta posicion no se encuentra implementado
  
    sv_piernaDerecha.write(150);
    sv_piernaIzquierda.write(30);
    sv_hombroIzquierdo.write(110);
    sv_hombroDerecho.write(70);
    sv_rodillaIzquierda.write(90);
    sv_rodillaDerecha.write(90);
    sv_codoIzquierdo.write(40);
    sv_codoDerecho.write(140);
   
}

//////////////////////////////

void f_posicionAburrido() {

    //Esta posicion no se encuentra implementado
  
    sv_piernaDerecha.write(180);
    sv_piernaIzquierda.write(0);
    sv_hombroIzquierdo.write(0);
    sv_hombroDerecho.write(180);
    sv_rodillaIzquierda.write(90);
    sv_rodillaDerecha.write(90);
    sv_codoIzquierdo.write(90);
    sv_codoDerecho.write(90);
   
}

//////////////////////////////

void f_posicionAburrido2() {

    //Esta posicion no se encuentra implementado

   for (int pos = 1; pos <= 40; pos += 1) {
    sv_piernaDerecha.write(180);
    sv_piernaIzquierda.write(0);
    sv_hombroIzquierdo.write(0);
    sv_hombroDerecho.write(180);
    sv_rodillaIzquierda.write(90);
    sv_rodillaDerecha.write(90);
    sv_codoIzquierdo.write(90);
    sv_codoDerecho.write(90);
    delay(500);
    sv_piernaDerecha.write(180);
    sv_piernaIzquierda.write(0);
    sv_hombroIzquierdo.write(0);
    sv_hombroDerecho.write(180);
    sv_rodillaIzquierda.write(90);
    sv_rodillaDerecha.write(90);
    sv_codoIzquierdo.write(90);
    sv_codoDerecho.write(120);
    delay(500);
   }
   
}


////////////////////////////////


void f_posicionAburrido3() {

    //Esta posicion no se encuentra implementado

   for (int pos = 1; pos <= 40; pos += 1) {
    sv_piernaDerecha.write(180);
    sv_piernaIzquierda.write(0);
    sv_hombroIzquierdo.write(0);
    sv_hombroDerecho.write(180);
    sv_rodillaIzquierda.write(90);
    sv_rodillaDerecha.write(90);
    sv_codoIzquierdo.write(90);
    sv_codoDerecho.write(90);
    delay(500);
    sv_piernaDerecha.write(180);
    sv_piernaIzquierda.write(0);
    sv_hombroIzquierdo.write(0);
    sv_hombroDerecho.write(180);
    sv_rodillaIzquierda.write(90);
    sv_rodillaDerecha.write(90);
    sv_codoIzquierdo.write(70);
    sv_codoDerecho.write(90);
    delay(500);
   }
   
}

////////////////////////////////


void f_posicionAburrido4() {

    //Esta posicion no se encuentra implementado

   for (int pos = 1; pos <= 40; pos += 1) {
    sv_piernaDerecha.write(180);
    sv_piernaIzquierda.write(0);
    sv_hombroIzquierdo.write(0);
    sv_hombroDerecho.write(180);
    sv_rodillaIzquierda.write(90);
    sv_rodillaDerecha.write(90);
    sv_codoIzquierdo.write(90);
    sv_codoDerecho.write(90);
    delay(500);
    sv_piernaDerecha.write(180);
    sv_piernaIzquierda.write(0);
    sv_hombroIzquierdo.write(0);
    sv_hombroDerecho.write(180);
    sv_rodillaIzquierda.write(120);
    sv_rodillaDerecha.write(90);
    sv_codoIzquierdo.write(90);
    sv_codoDerecho.write(90);
    delay(500);
   }
   
}


//////////////////////////////

void f_posicionAburrido5() {

    //Esta posicion no se encuentra implementado

   for (int pos = 1; pos <= 40; pos += 1) {
    sv_piernaDerecha.write(180);
    sv_piernaIzquierda.write(0);
    sv_hombroIzquierdo.write(0);
    sv_hombroDerecho.write(180);
    sv_rodillaIzquierda.write(90);
    sv_rodillaDerecha.write(90);
    sv_codoIzquierdo.write(90);
    sv_codoDerecho.write(90);
    delay(500);
    sv_piernaDerecha.write(180);
    sv_piernaIzquierda.write(0);
    sv_hombroIzquierdo.write(0);
    sv_hombroDerecho.write(180);
    sv_rodillaIzquierda.write(90);
    sv_rodillaDerecha.write(70);
    sv_codoIzquierdo.write(90);
    sv_codoDerecho.write(90);
    delay(500);
   }
   
}
//////////////////////////////

void f_caminaSigiloso(){
      
    sv_piernaDerecha.write(120);
    sv_hombroDerecho.write(45);
    sv_codoDerecho.write(180);
    delay(500);
    sv_rodillaDerecha.write(135);
    delay(500);
    sv_rodillaDerecha.write(90);
    
    delay(500);
    sv_piernaDerecha.write(60);
    sv_hombroDerecho.write(135);
    delay(500);
    sv_codoDerecho.write(135);
    delay(500);
    sv_codoDerecho.write(90);
    sv_rodillaDerecha.write(180);
    delay(500);
      
    sv_piernaIzquierda.write(60);
    sv_hombroIzquierdo.write(135);
    sv_codoIzquierdo.write(0);
    delay(500);
    sv_rodillaIzquierda.write(45);
    delay(500);
    sv_rodillaIzquierda.write(90);
    
    delay(500); 
    sv_piernaIzquierda.write(120);
    sv_hombroIzquierdo.write(45);
    delay(500);
    sv_codoIzquierdo.write(45); 
    delay(500);
    sv_codoIzquierdo.write(90);
    sv_rodillaIzquierda.write(0);
    delay(500);
    
}

//////////////////////////////
    
void f_caminaPanza() {
  
    for (int pos = 1; pos <= 5; pos += 1) {
  
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


//////////////////////////////

void f_escapaPorDerecha() {
  
    for (int pos = 1; pos <= 40; pos += 1) {
    sv_piernaIzquierda.write(90);
    sv_hombroIzquierdo.write(90);
    sv_rodillaIzquierda.write(0);
    sv_codoIzquierdo.write(0);
 
    sv_rodillaDerecha.write(180);
    sv_codoDerecho.write(180);
    delay(400);
    sv_piernaDerecha.write(45);
    sv_hombroDerecho.write(135); 
    delay(400);
    sv_piernaDerecha.write(135);
    sv_hombroDerecho.write(45);
    delay(400);
    }

    
}


//////////////////////////////

void f_escapaPorIzquierda() {
  
    for (int pos = 1; pos <= 40; pos += 1) {
    sv_piernaDerecha.write(90);
    sv_hombroDerecho.write(90);
    sv_rodillaDerecha.write(180);
    sv_codoDerecho.write(180);
 
    sv_rodillaIzquierda.write(0);
    sv_codoIzquierdo.write(180);
    delay(400);
    sv_piernaIzquierda.write(45);
    sv_hombroIzquierdo.write(135); 
    delay(400);
    sv_piernaIzquierda.write(135);
    sv_hombroIzquierdo.write(45);
    delay(400);
    }

} 

///////////////////////////////

void f_banner(){

Serial.println("          _   _             _                   _                  _ _   _               "); 
Serial.println("     /\  | | | |           | |            /\   | |                (_) | | |              ");
Serial.println("    /  \ | |_| | __ _ _ __ | |_ __ _     /  \  | | __ _  ___  _ __ _| |_| |__  _ __ ___  ");
Serial.println("   / /\ \| __| |/ _` | '_ \| __/ _` |   / /\ \ | |/ _` |/ _ \| '__| | __| '_ \| '_ ` _ \ ");
Serial.println("  / ____ \ |_| | (_| | | | | || (_| |  / ____ \| | (_| | (_) | |  | | |_| | | | | | | | |");
Serial.println(" /_/    \_\__|_|\__,_|_| |_|\__\__,_| /_/    \_\_|\__, |\___/|_|  |_|\__|_| |_|_| |_| |_|");
Serial.println("                                                   __/ |                                 ");
Serial.println("                                                  |___/                                  ");
Serial.println("                                                                                         ");
Serial.println("                                         https://www.atlantaalgorithm.com/               ");

}
