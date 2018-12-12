#include <avr/io.h>         //Incluindo biblioteca
#include <util/delay.h>       //Incluindo biblioteca
#include <stdbool.h>
#include "utilidades.h"
#include "pwm.h"

#define S1 PD2    // pino digital 2     0 - em cima da linha, 1 - fora da linha
#define S2 PD3    // pino digital 3
#define S3 PD4    // pino digital 4
#define S4 PD5    // pino digital 5
#define S5 PD6    // pino digital 6

#define motor1 PB1  // pino digital 9 
#define motor2 PB2  // pino digital 10

#define led PB5 // pino digital 13

#define kp 80
#define kd 70
#define ki 0
#define velIni 380

bool LS1,LS2,LS3,LS4,LS5; // leitura dos sensores
int D9 , D10;
int sinalControle;
int vel1,vel2;
double erro,erroAnti;
int proporcional,derivativo,integrador;


void leituraSensores(){
    LS1 = leituraDigitalD(S1);
    LS2 = leituraDigitalD(S2);
    LS3 = leituraDigitalD(S3);
    LS4 = leituraDigitalD(S4);
    LS5 = leituraDigitalD(S5);
}
void valorErro(){
  if(LS1 && LS2 && LS3 && LS4 && !LS5){
    erro = 5;
  }
  else if(LS1 && LS2 && LS3 && !LS4 && !LS5){
    erro = 3;
  }
  else if(LS1 && LS2 && LS3 && !LS4 && LS5){
    erro = 3;
  }
  else if(LS1 && LS2 && !LS3 && !LS4 && LS5){
    erro = 1;
  }
  else if(LS1 && LS2 && !LS3 && LS4 && LS5){
    erro = 0;
    
  }
  else if(LS1 && !LS2 && !LS3 && LS4 && LS5){
    erro = -1;
  }
  else if(LS1 && !LS2 && LS3 && LS4 && LS5){
    erro = -3;
  }
  else if(!LS1 && !LS2 && LS3 && LS4 && LS5){
    erro = -3;
  }
  else if(!LS1 && LS2 && LS3 && LS4 && LS5){
    erro = -5;
  }
}

void PID(){ //função controle PD
  
  proporcional = erro;
  derivativo = erro - erroAnti;
  integrador = integrador + erro;
  sinalControle = kp*proporcional + kd*derivativo + ki*integrador;

  if (sinalControle > velIni) {
    sinalControle = velIni;
  }
  if (sinalControle < -velIni) {
    sinalControle = -velIni;
  }  
  if (velIni - sinalControle > 0) { 
    escreveAnalogicoD9(velIni - sinalControle);
  } else {
    escreveAnalogicoD9(0);
  }

  if (velIni + sinalControle < 1023) {
    escreveAnalogicoD10(velIni + sinalControle);
  } else {
    escreveAnalogicoD10(1023);
  }
  erroAnti = erro;
}

int main(){
  
  iniciaPWM();// inicia as configurações do pwm nos pinos D9 e D10

  modoPinoD(S1,0); // 0 entrada 
  modoPinoD(S2,0); // 0 entrada 
  modoPinoD(S3,0); // 0 entrada 
  modoPinoD(S4,0); // 0 entrada 
  modoPinoD(S5,0); // 0 entrada 
  modoPinoB(motor1,1);  // 1 saida
  modoPinoB(motor2,1);  // 1 saida
  modoPinoB(led,1);     // 1 saida 

  sentidoMotor(1); // aceita sentido1 ou sensito2

  erroAnti = 0;
  integrador = 0;

  while(1){
    leituraSensores();
    valorErro();
    PID();
    _delay_ms(15);
  }
}

