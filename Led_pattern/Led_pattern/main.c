/**************************************************/
/* Author  : Mustafa Mohammed Abdou               */
/* Date    : 4 April , 2023                       */
/* Version : V01                                  */
/* Hint    : Application layer of led pattern     */
/**************************************************/

#include <util/delay.h>  /** TO CALL _delay_ms()  **/

/** INCLUDE LIBRARIES **/
#include "common_macros.h"
#include "standard_types.h"

/** INTERFACE FILES OF LOWER LAYERS **/
#include "DIO_interface.h"
#include "button_interface.h"
#include "button_config.h"

#include "LED_interface.h"
#include "LED_config.h"


int main(void)
{
	/** VARIABLE TO HOLD BUTTON STATUS , COUNTER FOR PRESSING TIMES **/
	static uint8_t button1_status = 0 , button1_counter = 0 ;
	
	Button_init(BUTTON1_PORT , BUTTON1_PIN); /** INITIALIZE BUTTON 1 **/
	
	LED_INIT(LED1_PORT , LED1_PIN); /** INIT LED 1 **/
	LED_INIT(LED2_PORT , LED2_PIN); /** INIT LED 2 **/
	LED_INIT(LED3_PORT , LED3_PIN); /** INIT LED 3 **/
	LED_INIT(LED4_PORT , LED4_PIN); /** INIT LED 4 **/
	
	/** ALL lEDS ARE OFF IN THE BEGINNING **/
	LED_OFF(LED1_PORT , LED1_PIN); 
	LED_OFF(LED2_PORT , LED2_PIN);
	LED_OFF(LED3_PORT , LED3_PIN); 
	LED_OFF(LED4_PORT , LED4_PIN);
   
    while (1) 
    {
		Is_pressed(BUTTON1_PORT , BUTTON1_PIN , &button1_status);  /* GET THE STATUS OF THE BUTTON */

		if (button1_status) /* IF BUTTON IS PRESSED */
		{
			_delay_ms(30);  /* DELAY FOR 30 ms TO AVOID BOUNCING */
			 
			Is_pressed(BUTTON1_PORT , BUTTON1_PIN , &button1_status); /* GET THE STATUS OF THE BUTTON AGAIN */
			
			if (button1_status) /* IF STATE IS STILL 1 */
			{
				button1_counter++ ; /* UPDATE BUTTON 1 COUNTER */
				
				/** DISPLAY THE PATTERN ACCORDING TO THE NUMBER OF PRESS TIMES (COUNTER) */
				if (button1_counter == 1)
				{
					LED_pattern1();
				}
				
				else if(button1_counter == 2)
				{
					LED_pattern2();
				}
				
				else if(button1_counter == 3)
				{
					LED_pattern3();
				}
				
				else if(button1_counter == 4)
				{
					LED_pattern4();
				}
				
				else if(button1_counter == 5)
				{
					LED_pattern5();
				}
				
				else if(button1_counter == 6)
				{
					LED_pattern6();
					
				} 
				
				else if(button1_counter == 7)
				{
					LED_pattern7();
					
				}
				
				else if(button1_counter == 8)
				{
					LED_pattern8();
					button1_counter = 0 ; /** REINITIALIZE THE COUNTER TO START FROM PATTERN 1 AGAIN */
				}
			
				while(button1_status)
				{
					Is_pressed(BUTTON1_PORT , BUTTON1_PIN , &button1_status);
				}
				
			}
			
		}
			
    }
}

