#include <HC_SR04_lib.h>
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

int concurrencia_distancia = 1;
long randomNumber;
const int Triger_Pin = 13;
const int Echo_Pin = 12;
unsigned long Lectura = 0;
unsigned char status_sens = 0;
HC_SR04Dev Sensor_A(Triger_Pin, Echo_Pin,UNITS_METRIC);

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
void f_banner1();
void f_posicionAcostado();
void f_posicionAburrido1();
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
  Sensor_A.SetMinMax(10, 1000);
  randomSeed(analogRead(A0));

}

//////////////////////////////

void loop() {
                                                      
m_inicio_operativo();
//f_pruebaComponentes();

}

  //////////////////////////////

void m_inicio_operativo() {

if(concurrencia_distancia=21){
  concurrencia_distancia=1;
  }

randomNumber = random(1,4);
switch (randomNumber) {
    case (1): {
      f_banner1();
        break;
      }
    case (2): {
      f_banner2();
        break;
      }
    case (3): {
      f_banner3();
        break;
      }
    default:
      break;
  }
  
delay(100);

 status_sens = Sensor_A.Sync();
  switch (status_sens) {
    case (HC_SR04_OFF): {
        break;
      }
    case (HC_SR04_TIMEOUT_READ): {
        break;
      }
    case (HC_SR04_READ_OK): {
        Lectura = Sensor_A.Read();
                if(Lectura>200){ //Si la distancia es mayor a 80cm avanza rapido.
                f_caminaPanza();
                }
                else
                {
                    if(Lectura>30 && Lectura<200){ //Si la distancia se encuentra entre 30cm y 80cm avanza con cautela .  

                      if (concurrencia_distancia >=10 && concurrencia_distancia <=20) {
                        randomNumber = random(1,3);
                        switch (randomNumber) {
                            case (1): {
                              f_caminaSigiloso();
                                break;
                              }
                            case (2): {
                              f_posicionAcostado();
                              delay(100);
                                  randomNumber = random(1,6);
                                  switch (randomNumber) {
                                    case (1): {
                                        f_posicionAburrido1();
                                        delay(100);
                                        f_posicionAburrido2();
                                        break;
                                      }
                                     case (2): {
                                        f_posicionAburrido1();
                                        delay(100);
                                        f_posicionAburrido3();
                                        break;
                                      }
                                     case (3): {
                                        f_posicionAburrido1();
                                        delay(100);
                                        f_posicionAburrido4();
                                        break;
                                      }
                                     case (4): {
                                        f_posicionAburrido1();
                                        delay(100);
                                        f_posicionAburrido5();
                                        break;
                                      }
                                    default:
                                      break;
                                  }
                                   f_posicionAcostado();
                                break;
                              }
                            default:
                              break;
                          }
                          //
                      }else{
                        f_caminaSigiloso();
                        }
                        //
                    }
                    else
                    { 
                        randomNumber = random(1,3);
                        switch (randomNumber) {
                            case (1): {
                              f_escapaPorDerecha();//Al estar a 30cm o menos de un obstaculo recto comienza a girar a la derecha
                                break;
                              }
                            case (2): {
                              f_escapaPorIzquierda();//Al estar a 30cm o menos de un obstaculo recto comienza a girar a la izquierda
                                break;
                              }
                            default:
                              break;
                          }
                        
                    }
                }
        Serial.print("Lectura OK: ");
        Serial.print(Lectura);
        Serial.println(" Centimeters3");
        concurrencia_distancia=concurrencia_distancia+1;
        break;
      }
    case (HC_SR04_UNDER_MIN): {
        break;
      }
    case (HC_SR04_OVER_MAX): {
        break;
      }
    case (HC_SR04_READ_ERR): {
        break;
      }
    default:
      break;
  }
       

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

void f_posicionAburrido1() {

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
   randomNumber = random(1,10);
   for (int pos = 1; pos <= randomNumber; pos += 1) {
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

   randomNumber = random(1,10);
   for (int pos = 1; pos <= randomNumber; pos += 1) {
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

   randomNumber = random(1,10);
   for (int pos = 1; pos <= randomNumber; pos += 1) {
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

   randomNumber = random(1,10);
   for (int pos = 1; pos <= randomNumber; pos += 1) {
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

  randomNumber = random(5,10);
   for (int pos = 1; pos <= randomNumber; pos += 1) {
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
    sv_codoIzquierdo.write(0);
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

void f_banner1(){
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

///////////////////////////////

void f_banner2(){
Serial.println("    ,.   .  .          .          ,.   .                .  .         ");
Serial.println("   / |   |- |  ,-. ,-. |- ,-.    / |   |  ,-. ,-. ,-. . |- |-. ,-,-. ");
Serial.println("  /~~|-. |  |  ,-| | | |  ,-|   /~~|-. |  | | | | |   | |  | | | | | ");
Serial.println(",'   `-' `' `' `-^ ' ' `' `-^ ,'   `-' `' `-| `-' '   ' `' ' ' ' ' ' ");
Serial.println("                                           ,|                        ");
Serial.println("                                           `'                        ");
Serial.println("                             https://www.atlantaalgorithm.com/       ");
}

void f_banner3(){
Serial.println(" +-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+");
Serial.println(" |A|t|l|a|n|t|a| |A|l|g|o|r|i|t|h|m|");
Serial.println(" +-+-+-+-+-+-+-+ +-+-+-+-+-+-+-+-+-+");
Serial.println("                                    ");
Serial.println("   https://www.atlantaalgorithm.com/");
}
