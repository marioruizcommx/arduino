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
int choque = 1;
int camina = 1;
int corre = 1;

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
void f_caminaSigiloso1();
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
  sv_piernaIzquierda.attach(4, 544, 2400);
  sv_piernaDerecha.attach(5, 544, 2400);
  sv_hombroIzquierdo.attach(6, 544, 2400);
  sv_hombroDerecho.attach(7, 544, 2400);
  sv_rodillaIzquierda.attach(8, 544, 2400);
  sv_rodillaDerecha.attach(9, 544, 2400);
  sv_codoIzquierdo.attach(10, 544, 2400);
  sv_codoDerecho.attach(11, 544, 2400);
  Sensor_A.SetMinMax(10, 1000);
  randomSeed(analogRead(A0));

}

//////////////////////////////

void loop() {
                                                      
//m_inicio_operativo();
f_pruebaComponentes();

}

  //////////////////////////////

void f_pruebaComponentes() {
//f_posicionZero();
//f_caminaSigiloso1();
//f_caminaPanza();
//f_caminaSigiloso();
//f_caminaSigiloso1();
//f_escapaPorDerecha();
//f_posicionAtento();
//f_posicionEspia();
//f_posicionArana();
//f_posicionIncado();
f_posicionInclinadoDerecha();
//f_escapaPorIzquierda();
//f_banner1();
//f_posicionAcostado();
//f_posicionAburrido1();
//f_posicionAburrido2(); 
//f_posicionAburrido3();
//f_posicionAburrido4();
//f_posicionAburrido5();
    
    }

//////////////////////////////

void m_inicio_operativo() {
Serial.print("Consurrencia inicial: ");
Serial.println(concurrencia_distancia );
if(concurrencia_distancia==21){
  concurrencia_distancia=1;
  }


randomNumber = random(1,4);
Serial.print("Banner a mostrar: ");
Serial.println(randomNumber );
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
        
        if(corre==4 || camina==4 || choque==4){
          corre=0;
          camina=0;
          choque=0;
        }
        
        if(Lectura>200 ){
          corre++;
        }
        if (Lectura <=15 ) {
          choque++;
        }
        if(Lectura>15 && Lectura<200){
          camina++;
        }

        Serial.print("++++++++++Lectura: ");
        Serial.println(Lectura);
        Serial.print("++++++++++choque: ");
        Serial.println(choque);
        Serial.print("++++++++++camina: ");
        Serial.println(camina);
        Serial.print("++++++++++corre: ");
        Serial.println(corre);

        
                if(Lectura>200 && corre ==3 ){ //Si la distancia es mayor a 80cm avanza rapido.

                f_caminaPanza();
                }
                else
                {
                    if(Lectura>30 && Lectura<200 && camina ==3 ){ //Si la distancia se encuentra entre 30cm y 80cm avanza con cautela .  

                      if (concurrencia_distancia >=40 && concurrencia_distancia <=50) {
                        Serial.print("----------------------------------------------------------------Entro");
                        randomNumber = random(1,3);
                        switch (randomNumber) {
                            case (1): {
                              f_caminaSigiloso();
                                break;
                              }
                            case (2): {
                              delay(5000);
                              f_posicionAcostado();
                              delay(5000);
                                  randomNumber = random(1,6);
                                  switch (randomNumber) {
                                    case (1): {
                                        delay(500);
                                        f_posicionAburrido1();
                                        delay(5000);
                                        f_posicionAburrido2();
                                        break;
                                      }
                                     case (2): {
                                        f_posicionAburrido1();
                                        delay(5000);
                                        f_posicionAburrido3();
                                        break;
                                      }
                                     case (3): {
                                        f_posicionAburrido1();
                                        delay(5000);
                                        f_posicionAburrido4();
                                        break;
                                      }
                                     case (4): {
                                        f_posicionAburrido1();
                                        delay(5000);
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
                      }
                        //
                    }
                    else
                    { 
                       f_caminaSigiloso();
                        
                       if (Lectura <=15  && choque == 3) {
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
                }

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
       
        concurrencia_distancia++;
        Serial.print("Consurrencia de salida: ");
        Serial.println(concurrencia_distancia );

}



void f_posicionZero() {

    //Esta posicion no se encuentra implementado
    //y deja al prototipo con las patas en la siguiente posicion: (derecho) |_ |_ °° _| _|  (izquierdo)

    Serial.print("En este momento: PosicionZero");
    sv_piernaDerecha.write(90);
    sv_piernaIzquierda.write(90);
    sv_hombroIzquierdo.write(90);
    sv_hombroDerecho.write(90);
    sv_rodillaIzquierda.write(90);
    sv_rodillaDerecha.write(90);
    sv_codoIzquierdo.write(90);
    sv_codoDerecho.write(90);
   
}

//////////////////////////////

void f_posicionAtento() {

    //Esta posicion no se encuentra implementado
    //y deja al prototipo con las patas en la siguiente posicion: (derecho) |_ |_ °° _| _|  (izquierdo)

    Serial.print("En este momento: PosicionZero");
    sv_piernaDerecha.write(45);
    sv_piernaIzquierda.write(135);
    sv_hombroIzquierdo.write(135);
    sv_hombroDerecho.write(45);
    sv_rodillaIzquierda.write(10);
    sv_rodillaDerecha.write(170);
    sv_codoIzquierdo.write(10);
    sv_codoDerecho.write(170);
   
}

//////////////////////////////

void f_posicionEspia() {

    //Esta posicion no se encuentra implementado
    //y deja al prototipo con las patas en la siguiente posicion: (derecho) |_ |_ °° _| _|  (izquierdo)

    Serial.print("En este momento: PosicionZero");
    sv_piernaDerecha.write(135);
    sv_piernaIzquierda.write(45);
    sv_hombroIzquierdo.write(135);
    sv_hombroDerecho.write(45);
    sv_rodillaIzquierda.write(170);
    sv_rodillaDerecha.write(10);
    sv_codoIzquierdo.write(10);
    sv_codoDerecho.write(170);
}

//////////////////////////////

void f_posicionInclinado() {

    //Esta posicion no se encuentra implementado
    //y deja al prototipo con las patas en la siguiente posicion: (derecho) |_ |_ °° _| _|  (izquierdo)

    Serial.print("En este momento: PosicionZero");
    sv_piernaDerecha.write(135);
    sv_piernaIzquierda.write(45);
    sv_hombroIzquierdo.write(135);
    sv_hombroDerecho.write(45);
    sv_rodillaIzquierda.write(170);
    sv_rodillaDerecha.write(10);
    sv_codoIzquierdo.write(10);
    sv_codoDerecho.write(170);
}

//////////////////////////////

void f_posicionInclinadoDerecha() {

    //Esta posicion no se encuentra implementado
    //y deja al prototipo con las patas en la siguiente posicion: (derecho) |_ |_ °° _| _|  (izquierdo)

    Serial.print("En este momento: PosicionZero");
    sv_piernaDerecha.write(135);
    sv_piernaIzquierda.write(90);
    sv_hombroIzquierdo.write(90);
    sv_hombroDerecho.write(45);
    sv_rodillaIzquierda.write(135);
    sv_rodillaDerecha.write(10);
    sv_codoIzquierdo.write(45);
    sv_codoDerecho.write(170);
}

//////////////////////////////
void f_posicionArana() {

    //Esta posicion no se encuentra implementado
    //y deja al prototipo con las patas en la siguiente posicion: (derecho) |_ |_ °° _| _|  (izquierdo)

    Serial.print("En este momento: PosicionZero");
    
    sv_hombroIzquierdo.write(45);
    sv_hombroDerecho.write(135);
    delay(900);
    sv_piernaDerecha.write(45);
    sv_piernaIzquierda.write(135);
    sv_rodillaIzquierda.write(10);
    sv_rodillaDerecha.write(170);
    sv_codoIzquierdo.write(170);
    sv_codoDerecho.write(10);
}

//////////////////////////////

void f_posicionIncado() {

    //Esta posicion no se encuentra implementado
    //y deja al prototipo con las patas en la siguiente posicion: (derecho) |_ |_ °° _| _|  (izquierdo)

    Serial.print("En este momento: PosicionZero");
    sv_piernaDerecha.write(90);
    sv_piernaIzquierda.write(90);
    delay(900);
    sv_hombroIzquierdo.write(90);
    sv_hombroDerecho.write(90);
    sv_rodillaIzquierda.write(0);
    sv_rodillaDerecha.write(180);
    sv_codoIzquierdo.write(180);
    sv_codoDerecho.write(0);
}

//////////////////////////////

void f_posicionAcostado() {

    //Esta posicion no se encuentra implementado
    Serial.print("En este momento: PosicionAcostado");
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
    Serial.print("En este momento: PosicionAburrido1");
    sv_piernaDerecha.write(170);
    sv_piernaIzquierda.write(10);
    sv_hombroIzquierdo.write(10);
    sv_hombroDerecho.write(170);
    sv_rodillaIzquierda.write(90);
    sv_rodillaDerecha.write(90);
    sv_codoIzquierdo.write(90);
    sv_codoDerecho.write(90);
   
}

//////////////////////////////

void f_posicionAburrido2() {

    //Esta posicion no se encuentra implementado
   Serial.print("En este momento: PosicionAburrido2"); 
   randomNumber = random(1,10);
   for (int pos = 1; pos <= randomNumber; pos += 1) {
    sv_piernaDerecha.write(170);
    sv_piernaIzquierda.write(10);
    sv_hombroIzquierdo.write(10);
    sv_hombroDerecho.write(170);
    sv_rodillaIzquierda.write(10);
    sv_rodillaDerecha.write(90);
    sv_codoIzquierdo.write(90);
    sv_codoDerecho.write(90);
    delay(500);
    sv_piernaDerecha.write(170);
    sv_piernaIzquierda.write(10);
    sv_hombroIzquierdo.write(10);
    sv_hombroDerecho.write(170);
    sv_rodillaIzquierda.write(90);
    sv_rodillaDerecha.write(90);
    sv_codoIzquierdo.write(90);
    sv_codoDerecho.write(90);
    delay(500);
   }
   
}


////////////////////////////////


void f_posicionAburrido3() {

    //Esta posicion no se encuentra implementado
   Serial.print("En este momento: PosicionAburrido3");
   randomNumber = random(1,10);
   for (int pos = 1; pos <= randomNumber; pos += 1) {
    sv_piernaDerecha.write(170);
    sv_piernaIzquierda.write(10);
    sv_hombroIzquierdo.write(10);
    sv_hombroDerecho.write(170);
    sv_rodillaIzquierda.write(90);
    sv_rodillaDerecha.write(90);
    sv_codoIzquierdo.write(90);
    sv_codoDerecho.write(90);
    delay(500);
    sv_piernaDerecha.write(170);
    sv_piernaIzquierda.write(10);
    sv_hombroIzquierdo.write(10);
    sv_hombroDerecho.write(170);
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
   Serial.print("En este momento: PosicionAburrido4");
   randomNumber = random(1,10);
   for (int pos = 1; pos <= randomNumber; pos += 1) {
    sv_piernaDerecha.write(170);
    sv_piernaIzquierda.write(10);
    sv_hombroIzquierdo.write(10);
    sv_hombroDerecho.write(170);
    sv_rodillaIzquierda.write(90);
    sv_rodillaDerecha.write(90);
    sv_codoIzquierdo.write(90);
    sv_codoDerecho.write(90);
    delay(500);
    sv_piernaDerecha.write(170);
    sv_piernaIzquierda.write(10);
    sv_hombroIzquierdo.write(10);
    sv_hombroDerecho.write(170);
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
   Serial.print("En este momento: PosicionAburrido5");
   randomNumber = random(1,10);
   for (int pos = 1; pos <= randomNumber; pos += 1) {
    sv_piernaDerecha.write(170);
    sv_piernaIzquierda.write(10);
    sv_hombroIzquierdo.write(10);
    sv_hombroDerecho.write(170);
    sv_rodillaIzquierda.write(90);
    sv_rodillaDerecha.write(90);
    sv_codoIzquierdo.write(90);
    sv_codoDerecho.write(90);
    delay(500);
    sv_piernaDerecha.write(170);
    sv_piernaIzquierda.write(10);
    sv_hombroIzquierdo.write(10);
    sv_hombroDerecho.write(170);
    sv_rodillaIzquierda.write(90);
    sv_rodillaDerecha.write(70);
    sv_codoIzquierdo.write(90);
    sv_codoDerecho.write(90);
    delay(500);
   }
   
}
//////////////////////////////

void f_caminaSigiloso(){
    Serial.print("En este momento: CaminaSigiloso");
    sv_piernaDerecha.write(120);
    sv_hombroDerecho.write(45);
    sv_codoDerecho.write(170);
    delay(200);
    sv_rodillaDerecha.write(135);
    delay(200);
    sv_rodillaDerecha.write(90);
    
    delay(200);
    sv_piernaDerecha.write(60);
    sv_hombroDerecho.write(135);
    delay(200);
    sv_codoDerecho.write(135);
    delay(200);
    sv_codoDerecho.write(90);
    sv_rodillaDerecha.write(170);
    delay(200);
      
    sv_piernaIzquierda.write(60);
    sv_hombroIzquierdo.write(135);
    sv_codoIzquierdo.write(10);
    delay(200);
    sv_rodillaIzquierda.write(45);
    delay(200);
    sv_rodillaIzquierda.write(90);
    
    delay(200); 
    sv_piernaIzquierda.write(120);
    sv_hombroIzquierdo.write(45);
    delay(200);
    sv_codoIzquierdo.write(45); 
    delay(200);
    sv_codoIzquierdo.write(90);
    sv_rodillaIzquierda.write(10);
    delay(200);
    
}

void f_caminaSigiloso1(){
    Serial.print("En este momento: CaminaSigiloso1");
    sv_piernaDerecha.write(120);
    sv_hombroDerecho.write(45);
    sv_codoDerecho.write(170);
    delay(500);
    sv_rodillaDerecha.write(135);
    delay(500);
    sv_rodillaDerecha.write(100);
    
    delay(500);
    sv_piernaDerecha.write(60);
    sv_hombroDerecho.write(135);
    delay(500);
    sv_codoDerecho.write(135);
    delay(500);
    sv_codoDerecho.write(90);
    sv_rodillaDerecha.write(170);
    delay(500);
      
    sv_piernaIzquierda.write(60);
    sv_hombroIzquierdo.write(135);
    sv_codoIzquierdo.write(10);
    delay(500);
    sv_rodillaIzquierda.write(45);
    delay(500);
    sv_rodillaIzquierda.write(70);
    
    delay(500); 
    sv_piernaIzquierda.write(120);
    sv_hombroIzquierdo.write(45);
    delay(500);
    sv_codoIzquierdo.write(45); 
    delay(500);
    sv_codoIzquierdo.write(90);
    sv_rodillaIzquierda.write(10);
    delay(500);
    
}

//////////////////////////////

    
void f_caminaPanza() {
  Serial.print("En este momento: CaminaPanza");
  randomNumber = random(5,10);
   for (int pos = 1; pos <= randomNumber; pos += 1) {
        sv_rodillaIzquierda.write(10);
        sv_rodillaDerecha.write(170);
        sv_codoIzquierdo.write(10);
        sv_codoDerecho.write(170);
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
    Serial.print("En este momento: EscapaDerecha");
    for (int pos = 1; pos <= 10; pos += 1) {
    sv_piernaIzquierda.write(90);
    sv_hombroIzquierdo.write(90);
    sv_rodillaIzquierda.write(10);
    sv_codoIzquierdo.write(10);
 
    sv_rodillaDerecha.write(170);
    sv_codoDerecho.write(170);
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
    Serial.print("En este momento: EscapaIzquierda");
    for (int pos = 1; pos <= 5; pos += 1) {
    sv_piernaDerecha.write(90);
    sv_hombroDerecho.write(90);
    sv_rodillaDerecha.write(170);
    sv_codoDerecho.write(170);
 
    sv_rodillaIzquierda.write(10);
    sv_codoIzquierdo.write(10);
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
