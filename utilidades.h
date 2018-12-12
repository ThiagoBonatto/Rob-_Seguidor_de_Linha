#ifndef UTILIDADES_
#define UTILIDADES_

#include <avr/io.h>         //Incluindo biblioteca
#include <stdbool.h>

bool leituraDigitalB(int pinoBotao);// para botoes em PORTB
void escritaDigitalB(int pinoLed, bool escritaDigitalDesliga);
void modoPinoB(int pinoIO,bool inOut);

bool leituraDigitalD(int pinoBotao);// para botoes em PORTB
void escritaDigitalD(int pinoLed, bool escritaDigitalDesliga);
void modoPinoD(int pinoIO,bool inOut);

#endif