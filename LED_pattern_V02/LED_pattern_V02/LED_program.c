/**************************************************/
/* Author  : Mustafa Mohammed Abdou               */
/* Date    : 4 April , 2023                       */
/* Version : V01                                  */
/* Hint    : program file of led                  */
/**************************************************/

/** INCLUDE LIBRARIES **/
#include "common_macros.h"
#include "standard_types.h"

/** INCLUDE INTERFACE FILES OF LOWER LAYERS **/
#include "DIO_interface.h"

/** INCLUDE DRIVER FILES **/
#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"


/***************************************************/
/** FUNCTION TO INITIALIZE A PIN                  **/
/** INPUT : LED PORT , LED PIN                    **/
/** RETURNS : VOID                                **/
/***************************************************/
void LED_INIT(uint8_t led_port , uint8_t ledpin)
{
	
	DIO_SETPINDIR(led_port , ledpin , DIO_PIN_OUTPUT); /** SET THE LED PIN AS OUTPUT **/
}


/***************************************************/
/** FUNCTION TO SET A LED AS ON                   **/
/** INPUT : LED PORT , LED PIN                    **/
/** RETURNS : VOID                                **/
/***************************************************/
void LED_ON(uint8_t led_port , uint8_t ledpin)
{
	
	DIO_SETPINVAL(led_port , ledpin , DIO_PIN_HIGH); /** SET THE OUTPUT PIN AS HIGH **/
}

/***************************************************/
/** FUNCTION TO SET A LED AS OFF                  **/
/** INPUT : LED PORT , LED PIN                    **/
/** RETURNS : VOID                                **/
/***************************************************/
void LED_OFF(uint8_t led_port , uint8_t ledpin)
{
	
	DIO_SETPINVAL(led_port , ledpin , DIO_PIN_LOW); /** SET THE OUTPUT PIN AS LOW **/
}

/** PATTERNS TO BE DISPLAYED */
void LED_pattern1(void)
{
	/** LED1 ON **/
	LED_ON(LED1_PORT , LED1_PIN);
	LED_OFF(LED2_PORT , LED2_PIN);
	LED_OFF(LED3_PORT , LED3_PIN);
	LED_OFF(LED4_PORT , LED4_PIN);
}

void LED_pattern2(void)
{
	/** LED1 AND LED2 ARE ON **/
	LED_ON(LED1_PORT , LED1_PIN);
	LED_ON(LED2_PORT , LED2_PIN);
	LED_OFF(LED3_PORT , LED3_PIN);
	LED_OFF(LED4_PORT , LED4_PIN);
}

void LED_pattern3(void)
{
	/** LED1 , LED2 AND LED3 ARE ON **/
	LED_ON(LED1_PORT , LED1_PIN);
	LED_ON(LED2_PORT , LED2_PIN);
	LED_ON(LED3_PORT , LED3_PIN);
	LED_OFF(LED4_PORT , LED4_PIN);
}

void LED_pattern4(void)
{
	/** LED 1 , LED 2 , LED 3 AND LED 4 ARE ON **/
	LED_ON(LED1_PORT , LED1_PIN);
	LED_ON(LED2_PORT , LED2_PIN);
	LED_ON(LED3_PORT , LED3_PIN);
	LED_ON(LED4_PORT , LED4_PIN);
}

void LED_pattern5(void)
{
	/** LED 4 IS OFF **/
	LED_ON(LED1_PORT , LED1_PIN);
	LED_ON(LED2_PORT , LED2_PIN);
	LED_ON(LED3_PORT , LED3_PIN);
	LED_OFF(LED4_PORT , LED4_PIN);
}

void LED_pattern6(void)
{
	/** LED 4 AND LED 3 ARE OFF **/
	LED_ON(LED1_PORT , LED1_PIN);
	LED_ON(LED2_PORT , LED2_PIN);
	LED_OFF(LED3_PORT , LED3_PIN);
	LED_OFF(LED4_PORT , LED4_PIN);
}

void LED_pattern7(void)
{
	/** LED 4 AND LED 3 , LED 2 ARE OFF **/
	LED_ON(LED1_PORT , LED1_PIN);
	LED_OFF(LED2_PORT , LED2_PIN);
	LED_OFF(LED3_PORT , LED3_PIN);
	LED_OFF(LED4_PORT , LED4_PIN);
}

void LED_pattern8(void)
{
    /** ALL LEDS ARE OFF **/
	LED_OFF(LED1_PORT , LED1_PIN);
	LED_OFF(LED2_PORT , LED2_PIN);
	LED_OFF(LED3_PORT , LED3_PIN);
	LED_OFF(LED4_PORT , LED4_PIN);	
	
}

