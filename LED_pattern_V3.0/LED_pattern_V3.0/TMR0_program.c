/******************************************************************/
/* Author  : Mustafa Mohammed Abdou                               */
/* Date    : 5 , April 2023                                       */
/* Version : V01                                                  */
/* Hint    : Implementation of Timer 0 APIs                       */
/******************************************************************/ 

#include "common_macros.h"
#include "standard_types.h"


#include "TMR0_interface.h"
#include "TMR0_private.h"
#include "TMR0_config.h"

uint32_t NO_OF_OVS = 0 ;   /** VARIABLE TO HOLD THE NUMBER OF OVER FLOWS **/


/****************************************************************/
/** FUNCTION TO INITIALIZE TMR0 WITH SOME CONFIGURATIONS        */
/** ARGUMENTS  : VOID                                           */
/** RETURNS    : TMR0_init                                      */
/****************************************************************/
TMR0_init TMR0_INIT(void)
{
	TMR0_init init_status = VALID_INIT ; /** VARIABLE TO RETURN THE STATUS OF INITIALIZATION **/
	
    /* COUNTER MODE OF TMR0 */
	#if TIMER0_CLK_SRC == EXTERNAL_CLK_SRC
	
	  /* EXTERNAL PIN AS CLOCK SOURCE */
	  //DIO_SETPINDIR(DIO_PORTB , DIO_PIN0 , DIO_PIN_INPUT);

	  //DIO_SETPULLUPS(DIO_PORTB , DIO_PIN0 );
	  
	 #if CNT0_EXTERNAL_EDGE_MODE == FALLING_EDGE_CNT
	  
	  clear_bit(TCCR0 , 0);
	  set_bit(TCCR0 , 1);
	  set_bit(TCCR0 , 2);
	  
	  init_status = VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	  
	 #elif CNT0_EXTERNAL_EDGE_MODE == RISING_EDGE_CNT
	  
	  set_bit(TCCR0 , 0);
	  set_bit(TCCR0 , 1);
	  set_bit(TCCR0 , 2);
	  init_status = VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	 
	 #endif
	 
	 /* TIMER MODE OF TMR0 */
	#elif TIMER0_CLK_SRC == INTERNAL_CLK_SRC
	
	 #if TIMER0_MODE == TMR0_NORMAL_MODE
	 
	 clear_bit(TCCR0 , 7);
	 clear_bit(TCCR0 , 6);
	 clear_bit(TCCR0 , 3);
	 clear_bit(TCCR0 , 4);
	 clear_bit(TCCR0 , 5);
	 
	 init_status = VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	 
	 #elif TIMER0_MODE == TMR0_FASTPWM_NON_INVERTED_MODE
	 
	 set_bit(TCCR0 , 7);
	 set_bit(TCCR0 , 6);
	 set_bit(TCCR0 , 3);
	 clear_bit(TCCR0 , 4);
	 set_bit(TCCR0 , 5);
	 
	 init_status = VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	 
	 #elif TIMER0_MODE == TMR0_FASTPWM_INVERTED_MODE
	 
	 set_bit(TCCR0 , 7);
	 set_bit(TCCR0 , 6);
	 set_bit(TCCR0 , 3);
	 set_bit(TCCR0 , 4);
	 set_bit(TCCR0 , 5);
	 
	 init_status = VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	 
	 #elif TIMER0_MODE == TMR_PHASE_CORRECT_NON_INVERTED_MODE
	 
	 set_bit(TCCR0 , 7);
	 set_bit(TCCR0 , 6);
	 clear_bit(TCCR0 , 3);
	 clear_bit(TCCR0 , 4);
	 set_bit(TCCR0 , 5);
	 
	 init_status = VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	 
	 #elif TIMER0_MODE == TMR_PHASE_CORRECT_INVERTED_MODE
	 
	 set_bit(TCCR0 , 7);
	 set_bit(TCCR0 , 6);
	 clear_bit(TCCR0 , 3);
	 set_bit(TCCR0 , 4);
	 set_bit(TCCR0 , 5);
	 
	 init_status = VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	 
	 #elif TIMER0_MODE == TMR0_CTC_MODE
	 
	 DIO_SETPINDIR(DIO_PORTB , DIO_PIN3 , DIO_PIN_OUTPUT); /** SET CTC BIT AS OUTPUT PIN **/
	 
	 clear_bit(TCCR0 , 7);
	 clear_bit(TCCR0 , 6);
	 set_bit(TCCR0 , 3);
	 
	 /* ENABLE INTERRUPT */
	 set_bit(SREG , 7);
	 set_bit(TIMSK , 1);
	 
	 init_status = VALID_INIT ; /** INITIALIZATION STATUS IS TRUE **/
	 
	  #if COMPARE_ACTION == SET_ON_COMPARE
	   
	   set_bit(TCCR0 , 4);
	   set_bit(TCCR0 , 5);
	   
	  #elif COMPARE_ACTION == CLEAR_ON_COMPARE
	   
	   clear_bit(TCCR0 , 4);
	   set_bit(TCCR0 , 5);
	   
	  #elif COMPARE_ACTION == TOOGLE_ON_COMPARE
	   
	   set_bit(TCCR0 , 4);
	   clear_bit(TCCR0 , 5);
	  #endif
	 #endif
	#endif
	
	return init_status ; /** RETURN THE STATUS OF INITIALIZATION **/
}


/*********************************************************************************/
/** FUNCTION TO LET TIMER 0 START WORK BY ASSIGNING PRESCALLER OR CLOCK SOURCE   */
/** ARGUMENTS  : VOID                                                            */
/** RETURNS    : TMR0_start                                                      */
/*********************************************************************************/
TMR0_start TMR0_START(void)
{
	TMR0_start start_status = VALID_START ; /** VARIABLE TO RETURN THE STATUS OF START **/
	
	#if TIMER0_PRESCALER_VAL == PRESCALER_1024
	
	set_bit(TCCR0 , 0);
	clear_bit(TCCR0 , 1);
	set_bit(TCCR0 , 2);
	
	start_status = VALID_START ; /** START DONE PROBERLY **/
	
	#elif TIMER0_PRESCALER_VAL == NO_PRESCALER
	
	set_bit(TCCR0 , 0);
	clear_bit(TCCR0 , 1);
	clear_bit(TCCR0 , 2);
	
	start_status = VALID_START ; /** START DONE PROBERLY **/
	
	#elif TIMER0_PRESCALER_VAL == PRESCALER_8
	
	clear_bit(TCCR0 , 0);
	set_bit(TCCR0 , 1);
	clear_bit(TCCR0 , 2);
	
	start_status = VALID_START ; /** START DONE PROBERLY **/
	
	#elif TIMER0_PRESCALER_VAL == PRESCALER_64
	
	set_bit(TCCR0 , 0);
	set_bit(TCCR0 , 1);
	clear_bit(TCCR0 , 2);
	
	start_status = VALID_START ; /** START DONE PROBERLY **/
	
	#elif TIMER0_PRESCALER_VAL == PRESCALER_256
	
	clear_bit(TCCR0 , 0);
	clear_bit(TCCR0 , 1);
	set_bit(TCCR0 , 2);
	
	start_status = VALID_START ; /** START DONE PROBERLY **/
	
	#endif
	
	return start_status ; /** RETURN THE STATUS **/
}

/*******************************************************************************/
/** FUNCTION TO STOP TIMER 0                                                   */
/** ARGUMENTS  : VOID                                                          */
/** RETURNS    : TMR0_stop                                                     */
/*******************************************************************************/
TMR0_stop TMR0_STOP(void)
{
	TMR0_stop stop_Status = VALID_STOP ; /** VARIABLE TO RETURN THE STATUS **/
	
	/** SET CONFIGURATIONS AS NO CLOCK SOURCE **/
	clear_bit(TCCR0 , 0);
	clear_bit(TCCR0 , 1);
	clear_bit(TCCR0 , 2);
	
	stop_Status = VALID_STOP ; /** STOP DONE PROPERLY **/
	
	return stop_Status ; /** RETURN THE STATUS **/
	
}

/*******************************************************************************/
/** FUNCTION TO SET DELAY USING TIMER 0                                        */
/** ARGUMENTS  : TAKES DELAY IN ms                                             */
/** RETURNS    : TMR0_delay                                                    */
/*******************************************************************************/
TMR0_delay TMR0_DELAY_MS(uint32_t DELAY_MS)
{
	
	uint32_t Localoverflowcounter = 0 ;
	
	TMR0_delay delay_status = NOT_VALID_DELAY ; /** VARIABLE TO RETURN THE STATUS **/
	
	#if TIMER0_PRESCALER_VAL == PRESCALER_1024  /** CHECK THE PRESCALLER FROM CONFIG FILE **/
	 
        NO_OF_OVS = (DELAY_MS / 16.384);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/ 
	
        TCNT0 = 0 ;   /** SET THE INITIAL VALUE IN TCNT0 REGISTER **/
	
	    delay_status = VALID_DELAY ; /** VALID DELAY CONFIGURATIN **/
	
	#elif TIMER0_PRESCALER_VAL == PRESCALER_256

	NO_OF_OVS = (DELAY_MS / 262.144);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/
	
	TCNT0 = 0 ;   /** SET THE INITIAL VALUE IN TCNT0 REGISTER **/
	
	delay_status = VALID_DELAY ; /** VALID DELAY CONFIGURATIN **/
	
	#elif TIMER0_PRESCALER_VAL == PRESCALER_64
		
	NO_OF_OVS = (DELAY_MS / 1.024);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/
	
	TCNT0 = 0 ;   /** SET THE INITIAL VALUE IN TCNT0 REGISTER **/
	
	delay_status = VALID_DELAY ; /** VALID DELAY CONFIGURATIN **/
	
	#elif TIMER0_PRESCALER_VAL == NO_PRESCALER
	
	NO_OF_OVS = (DELAY_MS / 0.256);   /** CALCULATING NUMBER OF OVERFLOWS ( DESIRED DELAY / TIME OF OVER FLOW ) **/
	
	TCNT0 = 0 ;   /** SET THE INITIAL VALUE IN TCNT0 REGISTER **/
	
	delay_status = VALID_DELAY ; /** VALID DELAY CONFIGURATIN **/
	
	#endif
	
	TMR0_START(); /** START TMR0 PRESCALLER **/
	
	while ( Localoverflowcounter < NO_OF_OVS ) /** STUCK IN THIS LOOP UNTILL THIS CONDITION IS FALSE **/
	{
		while((TIFR & (1 << 0)) == 0); /** DO NOTHING UNTILL THIS FLAG RAISED (OVERFLOW HAPPENED) **/
		
		set_bit(TIFR , 0);        /** CLEAR THE FLAG BY SOFTWARE **/
		
		Localoverflowcounter++ ; /** INCREASE THE OVERFLOWS BY ONE **/
	}
	
	Localoverflowcounter = 0 ; /** REINTIALIZE THE OVERFLOWS COUNTER TO 0 AGAIN **/

	TMR0_STOP(); /** STOP TMR0 TOSTART FROM 0 WHEN IT CALLED AGAIN **/
	
	return delay_status ; /** RETURN THE STATUS **/
}

