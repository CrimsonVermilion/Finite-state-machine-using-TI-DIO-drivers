#ifndef DIO_H
#define DIO_H
void DIOInt(char port,char pins, char direction);
void DIOWritePin(char port,char pin, char value);
void DIOWritePort(char port,char value);
void delay(int n);

#define pin0 0b00001
#define pin1 0b00010
#define pin2 0b00100
#define pin3 0b01000
#define pin4 0b10000

#define on 1
#define off 0
#endif