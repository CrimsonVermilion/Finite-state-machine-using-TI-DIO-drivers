#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "bits.h"


void DIOInt(char port,char pins, char direction)
{
  switch(port){

      case'A':
      SYSCTL_RCGCGPIO_R |= 0x00000001;
      while((SYSCTL_PRGPIO_R&0x00000001) == 0){};
      GPIO_PORTA_DIR_R = direction;
      GPIO_PORTA_PUR_R = ~direction;
      GPIO_PORTA_DEN_R = pins;
      break;
      
      case'B':
      SYSCTL_RCGCGPIO_R |= 0x00000002;
      while((SYSCTL_PRGPIO_R&0x00000002) == 0){};
      GPIO_PORTB_DIR_R = direction;
      GPIO_PORTB_PUR_R = ~direction;
      GPIO_PORTB_DEN_R = pins;
      break;
      
      case'C':
      SYSCTL_RCGCGPIO_R |= 0x00000004;
      while((SYSCTL_PRGPIO_R&0x00000004) == 0){};
      GPIO_PORTC_LOCK_R = 0x4C4F434B;
      GPIO_PORTC_CR_R = pins;
      GPIO_PORTC_DIR_R = direction;
      GPIO_PORTC_PUR_R = ~direction;
      GPIO_PORTC_DEN_R = pins;
      break;
      
      case'D':
      SYSCTL_RCGCGPIO_R |= 0x00000008;
      while((SYSCTL_PRGPIO_R&0x00000008) == 0){};
      GPIO_PORTD_LOCK_R = 0x4C4F434B;
      GPIO_PORTD_CR_R = pins;
      GPIO_PORTD_DIR_R = direction;
      GPIO_PORTD_PUR_R = ~direction;
      GPIO_PORTD_DEN_R = pins;
      break;
      
      case'E':
      SYSCTL_RCGCGPIO_R |= 0x00000010;
      while((SYSCTL_PRGPIO_R&0x00000010) == 0){};
      GPIO_PORTE_DIR_R = direction;
      GPIO_PORTE_PUR_R = ~direction;
      GPIO_PORTE_DEN_R = pins;
      break;
      
      case'F':
      SYSCTL_RCGCGPIO_R |= 0x00000020;
      while((SYSCTL_PRGPIO_R&0x00000020) == 0){};
      GPIO_PORTF_LOCK_R = 0x4C4F434B;
      GPIO_PORTF_CR_R = pins;
      GPIO_PORTF_DIR_R = direction;
      GPIO_PORTF_PUR_R = ~direction;
      GPIO_PORTF_DEN_R = pins;
      break;
  }
}



void DIOWritePin(char port,char pin, char value)
{
  if(value == 1){
  switch (port){
    case'A':
            set_bit(GPIO_PORTA_DATA_R,pin);

    break;
        case'B':
             set_bit(GPIO_PORTB_DATA_R,pin);

    break;
        case'C':
            set_bit(GPIO_PORTC_DATA_R,pin);

    break;
        case'D':
            set_bit(GPIO_PORTD_DATA_R,pin);

    break;
        case'E':
            set_bit(GPIO_PORTE_DATA_R,pin);
       
    break;
        case'F':
            set_bit(GPIO_PORTF_DATA_R,pin);
    break;
  }   
}
  else if (value ==0)
  {
    switch (port){
    case'A':
        clr_bit(GPIO_PORTA_DATA_R,pin);
    break;
        case'B':
        clr_bit(GPIO_PORTB_DATA_R,pin);
    break;
        case'C':
        clr_bit(GPIO_PORTC_DATA_R,pin);
    break;
        case'D':
        clr_bit(GPIO_PORTD_DATA_R,pin);
    break;
        case'E':
        clr_bit(GPIO_PORTE_DATA_R,pin);
    break;
        case'F':
        clr_bit(GPIO_PORTF_DATA_R,pin);
    break;
  }
}
}


void DIOWritePort(char port,char value)
{
  switch (port){
    case'A':
        GPIO_PORTA_DATA_R = value;
    break;
        case'B':
        GPIO_PORTB_DATA_R = value;
    break;
        case'C':
        GPIO_PORTC_DATA_R = value;
    break;
        case'D':
        GPIO_PORTD_DATA_R = value;
    break;
        case'E':
        GPIO_PORTE_DATA_R = value;
    break;
        case'F':
        GPIO_PORTF_DATA_R = value;
    break;
  }   
}

void delay(int n)
{
  int i,j;
  for(i=0 ; i<n; i++)
  {
    for(j=0;j<3180;j++){}
  }
}