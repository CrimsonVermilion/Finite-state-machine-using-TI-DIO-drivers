#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"


enum light{ white = 0 , red ,green,blue} ;



int main()
{
  enum  light current ;  
  
    //enables the prephieral 
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)){} //waits until the phrephireal is enabled which takes 5 clcks
  GPIOUnlockPin(GPIO_PORTF_BASE,GPIO_PIN_0|GPIO_PIN_4|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
  
  //sets the switch one and switch two as iputs 
  GPIOPinTypeGPIOInput(GPIO_PORTF_BASE,
                       (GPIO_PIN_0|GPIO_PIN_4));
//sets the three leds as output 
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,
                        (GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3));
  
  current = white;
  while(1)
  {
    current%=4;
    switch(current)
    {
    case white :
      GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1,GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1);
      break;
    case red:
      GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1,GPIO_PIN_1);
      break;
    case green:
      GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1,GPIO_PIN_3);
      break;
    case blue:
      GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1,GPIO_PIN_2);
      break;
    }
    
    if( !GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4))
    {
      SysCtlDelay(2000000);
      if ( !GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4))
      {
      current ++;
      }
      while(!GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4))
      SysCtlDelay(2000000);
    }
    
    if (!GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0))
    {
      SysCtlDelay(2000000);
      if (!GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0))
      {
      current --;
      }
      if (current < 0)
      {
        current = 4;
      }
      while(!GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0));
      SysCtlDelay(2000000);
    }
  }
}