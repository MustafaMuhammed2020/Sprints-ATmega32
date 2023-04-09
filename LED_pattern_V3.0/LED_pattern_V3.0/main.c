/******************************************************************/
/* Author  : Mustafa Mohammed Abdou                               */
/* Date    : 5 , April 2023                                       */
/* Version : V01                                                  */
/* Hint    : Application layer                                    */
/******************************************************************/

#include <avr/interrupt.h>  /** FOR INTERRUPTS **/

#include "common_macros.h"

#include "DIO_interface.h"
#include "LED_interface.h"
#include "TMR0_interface.h"
#include "INT_interface.h"


#include "LED_config.h"
#include "TMR0_config.h"
#include "LED_interface.h"
#include "INT_config.h"


uint8_t blinking_mode = 0 ;  /** VARIABLE TO DECIDE WHICH BLINKING MODE IS APPLIED **/

uint8_t LED_mode  =  0 ;     /** VARIABLE TO DECIDE THE MODE OF LEDs **/



int main(void)
{
	/** INITIALIZE THE LEDS **/
	LED_INIT(LED1_PORT , LED1_PIN);
	LED_INIT(LED2_PORT , LED2_PIN);
	LED_INIT(LED3_PORT , LED3_PIN);
	LED_INIT(LED4_PORT , LED4_PIN);
	
	/** LEDs ARE OFF AS INITIAL STATE **/
	LED_OFF(LED1_PORT , LED1_PIN);
	LED_OFF(LED2_PORT , LED2_PIN);
	LED_OFF(LED3_PORT , LED3_PIN);
	LED_OFF(LED4_PORT , LED4_PIN);
	
	
	TMR0_INIT(); /** INITIALIZE TMR0 **/
	
	INT0_INIT(); /** INITIALIZE INT0 **/
	
	INT1_INIT(); /** INITIALIZE INT  **/
	
    while (1) 
    {
		
	   if (LED_mode >= 8)  /** RETURN TO LED MODE 0 AGAIN **/
	   {
		   LED_mode =  0;
	   }
       
	   if (blinking_mode >= 5) /** RETURN TO BLINKING MODE 0 AGAIN **/
	   {
		   blinking_mode = 0 ;
	   }
	   
	   
       switch (blinking_mode)  /** SWICH CASE ON BLINKING MODE **/
       {
		   case 0 :
		    
			if (LED_mode == 0) /** ALL LEDs ARE OFF **/
			{
				LED_OFF(LED1_PORT , LED1_PIN);
				LED_OFF(LED2_PORT , LED2_PIN);
				LED_OFF(LED3_PORT , LED3_PIN);
				LED_OFF(LED4_PORT , LED4_PIN);
			}
			
			else if(LED_mode == 1) /** LED 1 IS BLINKING **/
			{
				LED_ON(LED1_PORT , LED1_PIN);
				TMR0_DELAY_MS(100);
			    LED_OFF(LED1_PORT , LED1_PIN);
				TMR0_DELAY_MS(900);
			}
			
			else if(LED_mode == 2) /** LED 1 , 2 ARE BLINKING **/
			{
				LED_ON(LED1_PORT , LED1_PIN);
				LED_ON(LED2_PORT , LED2_PIN);
				TMR0_DELAY_MS(100);
				LED_OFF(LED1_PORT , LED1_PIN);
				LED_OFF(LED2_PORT , LED2_PIN);
				TMR0_DELAY_MS(900);
			}
			
			else if(LED_mode == 3) /** LED 1 , 2 , 3  ARE BLINKING **/
			{
				LED_ON(LED1_PORT , LED1_PIN);
				LED_ON(LED2_PORT , LED2_PIN);
				LED_ON(LED3_PORT , LED3_PIN);
				TMR0_DELAY_MS(100);
				LED_OFF(LED1_PORT , LED1_PIN);
				LED_OFF(LED2_PORT , LED2_PIN);
				LED_OFF(LED3_PORT , LED3_PIN);
				TMR0_DELAY_MS(900);
			}
			
			else if(LED_mode == 4) /** LED 1 , 2 , 3 , 4  ARE BLINKING **/
			{
				LED_ON(LED1_PORT , LED1_PIN);
				LED_ON(LED2_PORT , LED2_PIN);
				LED_ON(LED3_PORT , LED3_PIN);
				LED_ON(LED4_PORT , LED4_PIN);
				TMR0_DELAY_MS(100);
				LED_OFF(LED1_PORT , LED1_PIN);
				LED_OFF(LED2_PORT , LED2_PIN);
				LED_OFF(LED3_PORT , LED3_PIN);
				LED_OFF(LED4_PORT , LED4_PIN);
				TMR0_DELAY_MS(900);
			}
			
			else if(LED_mode == 5) /** LED 1 IS OFF AND  2 , 3 , 4  ARE BLINKING **/
			{
				LED_OFF(LED1_PORT , LED1_PIN);
				
				LED_ON(LED2_PORT , LED2_PIN);
				LED_ON(LED3_PORT , LED3_PIN);
				LED_ON(LED4_PORT , LED4_PIN);
				TMR0_DELAY_MS(100);
				LED_OFF(LED2_PORT , LED2_PIN);
				LED_OFF(LED3_PORT , LED3_PIN);
				LED_OFF(LED4_PORT , LED4_PIN);
				TMR0_DELAY_MS(900);
			}
			
			else if(LED_mode == 6) /** LED 1 , 2 ARE OFF AND  3 , 4  ARE BLINKING **/
			{
				LED_OFF(LED1_PORT , LED1_PIN);
				LED_OFF(LED2_PORT , LED2_PIN);
				
				LED_ON(LED3_PORT , LED3_PIN);
				LED_ON(LED4_PORT , LED4_PIN);
				TMR0_DELAY_MS(100);
				LED_OFF(LED3_PORT , LED3_PIN);
				LED_OFF(LED4_PORT , LED4_PIN);
				TMR0_DELAY_MS(900);
			}
			
			else if(LED_mode == 7) /** LED 1 , 2 , 3 ARE OFF AND  4  IS BLINKING **/
			{
				LED_OFF(LED1_PORT , LED1_PIN);
				LED_OFF(LED2_PORT , LED2_PIN);
				LED_OFF(LED3_PORT , LED3_PIN);
				
				LED_ON(LED4_PORT , LED4_PIN);
				TMR0_DELAY_MS(100);
				LED_OFF(LED4_PORT , LED4_PIN);
				TMR0_DELAY_MS(900);
			}
			
		   break ;
		   
		   case 1 :
		   
		   if (LED_mode == 0) /** ALL LEDs ARE OFF **/
		   {
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   LED_OFF(LED4_PORT , LED4_PIN);
		   }
		   
		   else if(LED_mode == 1) /** LED 1 IS BLINKING **/
		   {
			   LED_ON(LED1_PORT , LED1_PIN);
			   TMR0_DELAY_MS(200);
			   LED_OFF(LED1_PORT , LED1_PIN);
			   TMR0_DELAY_MS(800);
		   }
		   
		   else if(LED_mode == 2) /** LED 1 , 2 ARE BLINKING **/
		   {
			   LED_ON(LED1_PORT , LED1_PIN);
			   LED_ON(LED2_PORT , LED2_PIN);
			   TMR0_DELAY_MS(200);
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   TMR0_DELAY_MS(800);
		   }
		   
		   else if(LED_mode == 3) /** LED 1 , 2 , 3  ARE BLINKING **/
		   {
			   LED_ON(LED1_PORT , LED1_PIN);
			   LED_ON(LED2_PORT , LED2_PIN);
			   LED_ON(LED3_PORT , LED3_PIN);
			   TMR0_DELAY_MS(200);
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   TMR0_DELAY_MS(800);
		   }
		   
		   else if(LED_mode == 4) /** LED 1 , 2 , 3 , 4  ARE BLINKING **/
		   {
			   LED_ON(LED1_PORT , LED1_PIN);
			   LED_ON(LED2_PORT , LED2_PIN);
			   LED_ON(LED3_PORT , LED3_PIN);
			   LED_ON(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(200);
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   LED_OFF(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(800);
		   }
		   
		   else if(LED_mode == 5) /** LED 1 IS OFF AND  2 , 3 , 4  ARE BLINKING **/
		   {
			   LED_OFF(LED1_PORT , LED1_PIN);
			   
			   LED_ON(LED2_PORT , LED2_PIN);
			   LED_ON(LED3_PORT , LED3_PIN);
			   LED_ON(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(200);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   LED_OFF(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(800);
		   }
		   
		   else if(LED_mode == 6) /** LED 1 , 2 ARE OFF AND  3 , 4  ARE BLINKING **/
		   {
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   
			   LED_ON(LED3_PORT , LED3_PIN);
			   LED_ON(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(200);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   LED_OFF(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(800);
		   }
		   
		   else if(LED_mode == 7) /** LED 1 , 2 , 3 ARE OFF AND  4  IS BLINKING **/
		   {
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   
			   LED_ON(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(200);
			   LED_OFF(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(800);
		   }
		   break ;
		   
		   case 2 :
		   
		   if (LED_mode == 0) /** ALL LEDs ARE OFF **/
		   {
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   LED_OFF(LED4_PORT , LED4_PIN);
		   }
		   
		   else if(LED_mode == 1) /** LED 1 IS BLINKING **/
		   {
			   LED_ON(LED1_PORT , LED1_PIN);
			   TMR0_DELAY_MS(300);
			   LED_OFF(LED1_PORT , LED1_PIN);
			   TMR0_DELAY_MS(700);
		   }
		   
		   else if(LED_mode == 2) /** LED 1 , 2 ARE BLINKING **/
		   {
			   LED_ON(LED1_PORT , LED1_PIN);
			   LED_ON(LED2_PORT , LED2_PIN);
			   TMR0_DELAY_MS(300);
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   TMR0_DELAY_MS(700);
		   }
		   
		   else if(LED_mode == 3) /** LED 1 , 2 , 3  ARE BLINKING **/
		   {
			   LED_ON(LED1_PORT , LED1_PIN);
			   LED_ON(LED2_PORT , LED2_PIN);
			   LED_ON(LED3_PORT , LED3_PIN);
			   TMR0_DELAY_MS(300);
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   TMR0_DELAY_MS(700);
		   }
		   
		   else if(LED_mode == 4) /** LED 1 , 2 , 3 , 4  ARE BLINKING **/
		   {
			   LED_ON(LED1_PORT , LED1_PIN);
			   LED_ON(LED2_PORT , LED2_PIN);
			   LED_ON(LED3_PORT , LED3_PIN);
			   LED_ON(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(300);
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   LED_OFF(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(700);
		   }
		   
		   else if(LED_mode == 5) /** LED 1 IS OFF AND  2 , 3 , 4  ARE BLINKING **/
		   {
			   LED_OFF(LED1_PORT , LED1_PIN);
			   
			   LED_ON(LED2_PORT , LED2_PIN);
			   LED_ON(LED3_PORT , LED3_PIN);
			   LED_ON(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(300);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   LED_OFF(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(700);
		   }
		   
		   else if(LED_mode == 6) /** LED 1 , 2 ARE OFF AND  3 , 4  ARE BLINKING **/
		   {
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   
			   LED_ON(LED3_PORT , LED3_PIN);
			   LED_ON(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(300);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   LED_OFF(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(700);
		   }
		   
		   else if(LED_mode == 7) /** LED 1 , 2 , 3 ARE OFF AND  4  IS BLINKING **/
		   {
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   
			   LED_ON(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(300);
			   LED_OFF(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(700);
		   }
		   break ;
		   
		   case 3 :
		   
		   if (LED_mode == 0) /** ALL LEDs ARE OFF **/
		   {
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   LED_OFF(LED4_PORT , LED4_PIN);
		   }
		   
		   else if(LED_mode == 1) /** LED 1 IS BLINKING **/
		   {
			   LED_ON(LED1_PORT , LED1_PIN);
			   TMR0_DELAY_MS(500);
			   LED_OFF(LED1_PORT , LED1_PIN);
			   TMR0_DELAY_MS(500);
		   }
		   
		   else if(LED_mode == 2) /** LED 1 , 2 ARE BLINKING **/
		   {
			   LED_ON(LED1_PORT , LED1_PIN);
			   LED_ON(LED2_PORT , LED2_PIN);
			   TMR0_DELAY_MS(500);
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   TMR0_DELAY_MS(500);
		   }
		   
		   else if(LED_mode == 3) /** LED 1 , 2 , 3  ARE BLINKING **/
		   {
			   LED_ON(LED1_PORT , LED1_PIN);
			   LED_ON(LED2_PORT , LED2_PIN);
			   LED_ON(LED3_PORT , LED3_PIN);
			   TMR0_DELAY_MS(500);
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   TMR0_DELAY_MS(500);
		   }
		   
		   else if(LED_mode == 4) /** LED 1 , 2 , 3 , 4  ARE BLINKING **/
		   {
			   LED_ON(LED1_PORT , LED1_PIN);
			   LED_ON(LED2_PORT , LED2_PIN);
			   LED_ON(LED3_PORT , LED3_PIN);
			   LED_ON(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(500);
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   LED_OFF(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(500);
		   }
		   
		   else if(LED_mode == 5) /** LED 1 IS OFF AND  2 , 3 , 4  ARE BLINKING **/
		   {
			   LED_OFF(LED1_PORT , LED1_PIN);
			   
			   LED_ON(LED2_PORT , LED2_PIN);
			   LED_ON(LED3_PORT , LED3_PIN);
			   LED_ON(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(500);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   LED_OFF(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(500);
		   }
		   
		   else if(LED_mode == 6) /** LED 1 , 2 ARE OFF AND  3 , 4  ARE BLINKING **/
		   {
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   
			   LED_ON(LED3_PORT , LED3_PIN);
			   LED_ON(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(500);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   LED_OFF(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(500);
		   }
		   
		   else if(LED_mode == 7) /** LED 1 , 2 , 3 ARE OFF AND  4  IS BLINKING **/
		   {
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   
			   LED_ON(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(500);
			   LED_OFF(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(500);
		   }
		   break;
		   
		   case 4 :
		   
		   if (LED_mode == 0) /** ALL LEDs ARE OFF **/
		   {
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   LED_OFF(LED4_PORT , LED4_PIN);
		   }
		   
		   else if(LED_mode == 1) /** LED 1 IS BLINKING **/
		   {
			   LED_ON(LED1_PORT , LED1_PIN);
			   TMR0_DELAY_MS(800);
			   LED_OFF(LED1_PORT , LED1_PIN);
			   TMR0_DELAY_MS(200);
		   }
		   
		   else if(LED_mode == 2) /** LED 1 , 2 ARE BLINKING **/
		   {
			   LED_ON(LED1_PORT , LED1_PIN);
			   LED_ON(LED2_PORT , LED2_PIN);
			   TMR0_DELAY_MS(800);
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   TMR0_DELAY_MS(200);
		   }
		   
		   else if(LED_mode == 3) /** LED 1 , 2 , 3  ARE BLINKING **/
		   {
			   LED_ON(LED1_PORT , LED1_PIN);
			   LED_ON(LED2_PORT , LED2_PIN);
			   LED_ON(LED3_PORT , LED3_PIN);
			   TMR0_DELAY_MS(800);
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   TMR0_DELAY_MS(200);
		   }
		   
		   else if(LED_mode == 4) /** LED 1 , 2 , 3 , 4  ARE BLINKING **/
		   {
			   LED_ON(LED1_PORT , LED1_PIN);
			   LED_ON(LED2_PORT , LED2_PIN);
			   LED_ON(LED3_PORT , LED3_PIN);
			   LED_ON(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(800);
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   LED_OFF(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(200);
		   }
		   
		   else if(LED_mode == 5) /** LED 1 IS OFF AND  2 , 3 , 4  ARE BLINKING **/
		   {
			   LED_OFF(LED1_PORT , LED1_PIN);
			   
			   LED_ON(LED2_PORT , LED2_PIN);
			   LED_ON(LED3_PORT , LED3_PIN);
			   LED_ON(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(800);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   LED_OFF(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(200);
		   }
		   
		   else if(LED_mode == 6) /** LED 1 , 2 ARE OFF AND  3 , 4  ARE BLINKING **/
		   {
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   
			   LED_ON(LED3_PORT , LED3_PIN);
			   LED_ON(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(800);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   LED_OFF(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(200);
		   }
		   
		   else if(LED_mode == 7) /** LED 1 , 2 , 3 ARE OFF AND  4  IS BLINKING **/
		   {
			   LED_OFF(LED1_PORT , LED1_PIN);
			   LED_OFF(LED2_PORT , LED2_PIN);
			   LED_OFF(LED3_PORT , LED3_PIN);
			   
			   LED_ON(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(800);
			   LED_OFF(LED4_PORT , LED4_PIN);
			   TMR0_DELAY_MS(200);
		   }
		   break;
		   
		   default:
		   /** DO NOTHING **/
		   break;
       }
       
	}
}


/** ISR OF INT0  **/
ISR(INT0_vect)
{
	blinking_mode++ ; /** CHANGE THE BLINKING MODE **/
}

/** ISR OF INT1 **/
ISR(INT1_vect)
{
	LED_mode++ ;  /** CHANGE THE LEDs **/
}