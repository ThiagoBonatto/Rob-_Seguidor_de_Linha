#ifndef PWM_
#define PWM_

#include <avr/io.h>         //Incluindo biblioteca
#include <stdbool.h>

#define pinHorario PB3  // pino digital 11
#define pinAntiHorario PB4  // pino digital 12

void iniciaPWM();
void escreveAnalogicoD9(int valorPWM);
void escreveAnalogicoD10(int valorPWM);

// valores aceitos sentidoMotor("sentido1") ou sentidoMotor("sentido2")
// void sentidoMotor(char *sentido);
// valores aceitos sentidoMotor(1) ou sentidoMotor(0)
void sentidoMotor(bool sentido);



#endif 
