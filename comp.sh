#!/bin/bash
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o main.o main.c
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o utilidades.o utilidades.c
avr-gcc -Os -DF_CPU=16000000UL -mmcu=atmega328p -c -o pwm.o pwm.c
avr-gcc -mmcu=atmega328p main.o utilidades.o pwm.o -o main
avr-objcopy -O ihex -R .eeprom main main.hex
#avrdude -v -p m328p -c arduino -P /dev/ttyACM0 -b 115200 -D -U flash:w:main.hex:i
rm *.o
#rm *.hex
