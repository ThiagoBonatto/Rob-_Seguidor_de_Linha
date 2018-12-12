#include "utilidades.h"

// ===================LEITURA DE PINOS DIGITAIS PORTB===================
// similar a digitalRead()
bool leituraDigitalB(int pinoBotao){ // para botoes em PORTB
  if(PINB & (1<<pinoBotao)) return 1;
    else return 0;
}
// ===================ESCRITA DE PINOS DIGITAIS PORTB===================
// similar a digitalWrite()
void escritaDigitalB(int pinoLed, bool escritaDigitalDesliga){
  if(escritaDigitalDesliga) PORTB = PORTB | (1<<pinoLed);
  else PORTB = PORTB & (~(1<<pinoLed));
}
// ===================DECLARA PINO COMO ENTRADA OU SAIDA PORTB==========
// similiar a pinMode()
void modoPinoB(int pinoIO,bool inOut){
  DDRB |= (inOut<<pinoIO);
}
// ===================LEITURA DE PINOS DIGITAIS PORTD===================
// similar a digitalRead()
bool leituraDigitalD(int pinoBotao){ // para botoes em PORTB
  if(PIND & (1<<pinoBotao)) return 1;
    else return 0;
}
// ===================ESCRITA DE PINOS DIGITAIS PORTD===================
// similar a digitalWrite()
void escritaDigitalD(int pinoLed, bool escritaDigitalDesliga){
  if(escritaDigitalDesliga) PORTD = PORTD | (1<<pinoLed);
  else PORTD = PORTD & (~(1<<pinoLed));
}
// ===================DECLARA PINO COMO ENTRADA OU SAIDA PORTD==========
// similiar a pinMode()
void modoPinoD(int pinoIO,bool inOut){
  DDRD |= (inOut<<pinoIO);
}