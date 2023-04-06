/**************************************************/
/* Author  : Mustafa Mohammed Abdou               */
/* Date    : 4 April , 2023                       */
/* Version : V01                                  */
/**************************************************/


/** INCLUDE LIBRARIES  **/
#include "standard_types.h"
#include "common_macros.h"

/** INCLUDE INTERFACE FILES OF LOWER LAYERS **/
#include "DIO_interface.h"
#include "LED_interface.h"
#include "INT_interface.h"

#include "LED_config.h"
#include "INT_config.h"
#include "INT_private.h"

#include <avr/interrupt.h>

uint8_t press = 0 ;

int main(void)
{
	
	DIO_SETPINDIR(DIO_PORTD , DIO_PIN2 , DIO_PIN_INPUT); /** SET INT0 PIN AS INPUT PIN **/
	
	DIO_SETPINVAL(DIO_PORTD , DIO_PIN2 , DIO_PIN_LOW);
	
	/** CONFIGURE THE PINS **/
	LED_INIT(LED1_PORT , LED1_PIN);
	LED_INIT(LED2_PORT , LED2_PIN);
	LED_INIT(LED3_PORT , LED3_PIN);
	LED_INIT(LED4_PORT , LED4_PIN);
	
	/** LEDS ARE INITIALLY OFF **/
	LED_OFF(LED1_PORT , LED1_PIN);
	LED_OFF(LED2_PORT , LED2_PIN);
	LED_OFF(LED3_PORT , LED3_PIN);
	LED_OFF(LED4_PORT , LED4_PIN);
	
	
	INT0_INIT();
	
    /* Replace with your application code */
    while (1) 
    {
		if (press == 1)
		{
			LED_ON(LED1_PORT , LED1_PIN);
			LED_OFF(LED2_PORT , LED2_PIN);
			LED_OFF(LED3_PORT , LED3_PIN);
			LED_OFF(LED4_PORT , LED4_PIN);
		}
		
		else if (press == 2 )
		{
			LED_ON(LED1_PORT , LED1_PIN);
			LED_ON(LED2_PORT , LED2_PIN);
			LED_OFF(LED3_PORT , LED3_PIN);
			LED_OFF(LED4_PORT , LED4_PIN);
		}
		
		else if (press == 3)
		{
			LED_ON(LED1_PORT , LED1_PIN);
			LED_ON(LED2_PORT , LED2_PIN);
			LED_ON(LED3_PORT , LED3_PIN);
			LED_OFF(LED4_PORT , LED4_PIN);
		}
		
		else if (press == 4)
		{
			LED_ON(LED1_PORT , LED1_PIN);
			LED_ON(LED2_PORT , LED2_PIN);
			LED_ON(LED3_PORT , LED3_PIN);
			LED_ON(LED4_PORT , LED4_PIN);
		}
		
		else if (press == 5)
		{
			LED_OFF(LED1_PORT , LED1_PIN);
			LED_ON(LED2_PORT , LED2_PIN);
			LED_ON(LED3_PORT , LED3_PIN);
			LED_ON(LED4_PORT , LED4_PIN);
		}
		
		else if (press == 6)
		{
			LED_OFF(LED1_PORT , LED1_PIN);
			LED_OFF(LED2_PORT , LED2_PIN);
			LED_ON(LED3_PORT , LED3_PIN);
			LED_ON(LED4_PORT , LED4_PIN);
		}
		
		else if (press == 7)
		{
			LED_OFF(LED1_PORT , LED1_PIN);
			LED_OFF(LED2_PORT , LED2_PIN);
			LED_OFF(LED3_PORT , LED3_PIN);
			LED_ON(LED4_PORT , LED4_PIN);
		}
		
		else if (press == 8)
		{
			LED_OFF(LED1_PORT , LED1_PIN);
			LED_OFF(LED2_PORT , LED2_PIN);
			LED_OFF(LED3_PORT , LED3_PIN);
			LED_OFF(LED4_PORT , LED4_PIN);
			
			press = 0 ;  /** REINITIALIZE PRESS TO 0 AGAIN **/
		}
    }
}

ISR(INT0_vect)
{
	press++;  /** EACH INTERRUPT TRIGGER INCREASE PRESS BY 1 **/
}