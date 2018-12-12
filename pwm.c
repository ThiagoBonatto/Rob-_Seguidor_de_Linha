#include "pwm.h"
#include "utilidades.h"

void iniciaPWM(){	// para os pinos digitais 9 e 10
	TCCR1A = ((1 << COM0A1) | (1 << COM0B1) | (1 << WGM11) | (1 << WGM10));
	TCCR1B = ((1 << CS11) | (1 << CS10)); 
}

void escreveAnalogicoD9(int valorPWM){
	OCR1A = valorPWM;     // PWM pino 9
}

void escreveAnalogicoD10(int valorPWM){
	OCR1B = valorPWM;     // PWM pino 9
}

void sentidoMotor(bool sentido){
	modoPinoB(pinHorario,1);	// 1 saida
	modoPinoB(pinAntiHorario,1);	// 1 saida
  if(sentido == 1) PORTB = PORTB | (1<<pinAntiHorario) & (~(1<<pinHorario));
  else if(sentido == 0) PORTB = PORTB | (1<<pinHorario) & (~(1<<pinAntiHorario));  
	/*if(sentido == "sentido1") PORTB = PORTB | (1<<pinAntiHorario) & (~(1<<pinHorario));
	else if(sentido == "sentido2") PORTB = PORTB | (1<<pinHorario) & (~(1<<pinAntiHorario));	*/
  //PORTB = (sentido == "sentido1") ? PORTB | (1<<pinAntiHorario) & (~(1<<pinHorario)) :  PORTB | (1<<pinHorario) & (~(1<<pinAntiHorario));
}
