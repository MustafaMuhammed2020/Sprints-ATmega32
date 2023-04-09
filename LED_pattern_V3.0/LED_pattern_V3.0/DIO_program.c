/**************************************************/
/* Author  : Mustafa Mohammed Abdou               */
/* Date    : 3 April , 2023                       */
/* Version : V01                                  */
/* Hint    : Program file of DIO                  */
/**************************************************/

/** INCLUDE LIBRARIES **/
#include "common_macros.h"
#include "standard_types.h"

/** INCLUDE DRIVER FILES **/
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

/******************************************************************/
/* DESCRIBTION  : FUNCTION TO SET THE DIRECTION OF SPECIFIC PIN   */
/* INPUT   : PORT , PINID , DIRECTION                             */
/* RETURNS : PinDirection_t                                       */
/******************************************************************/
PinDirection_t DIO_SETPINDIR(uint8_t portID , uint8_t pinID , uint8_t dir)
{
	PinDirection_t Local_dirstate = VALID_DIRECTION ; /** VARIABLE TO RETURN THE STATUS OF DIRECTION **/
	
	switch(dir) /** SWITCH CASE ON THE DIRECTION VALUE **/
	{
		case DIO_PIN_INPUT:  /* INPUT CASE  */
		
		switch(portID) /** SWITCH CASE ON THE PORT ID */
		{
			case DIO_PORTA:
			clear_bit(DDRA , pinID);           /** CONFIGURE THIS PIN IN PORTA AS INPUT PIN **/
			Local_dirstate = VALID_DIRECTION ; /** RETURN AS DIR NO ERRORS **/
			break;
			
			case DIO_PORTB:
			clear_bit(DDRB , pinID);           /** CONFIGURE THIS PIN IN PORTB AS INPUT PIN **/
			Local_dirstate = VALID_DIRECTION ; /** RETURN AS DIR NO ERRORS **/
			break;
			
			case DIO_PORTC:
			clear_bit(DDRC , pinID);           /** CONFIGURE THIS PIN IN PORTC AS INPUT PIN **/
			Local_dirstate = VALID_DIRECTION ; /** RETURN AS DIR NO ERRORS **/
			break;
			
			case DIO_PORTD:
			clear_bit(DDRD , pinID);           /** CONFIGURE THIS PIN IN PORTD AS INPUT PIN **/
			Local_dirstate = VALID_DIRECTION ; /** RETURN AS DIR NO ERRORS **/
			break;
			
			default: /** DO NOTHING **/
			Local_dirstate = NOT_VALID_DIRECTION ; /** RETURN AS DIR NOT VALID ERRORS **/
			break;
		} 
		break;
		
		case DIO_PIN_OUTPUT:  /* OUTPUT CASE  */
		
		switch(portID) /** SWITCH CASE ON THE PORT ID */
		{
			case DIO_PORTA:
			set_bit(DDRA , pinID);             /** CONFIGURE THIS PIN IN PORTA AS OUTPUT PIN **/
			Local_dirstate = VALID_DIRECTION ; /** RETURN AS DIR NO ERRORS **/
			break;
			
			case DIO_PORTB:
			set_bit(DDRB , pinID);             /** CONFIGURE THIS PIN IN PORTA AS OUTPUT PIN **/
			Local_dirstate = VALID_DIRECTION ; /** RETURN AS DIR NO ERRORS **/
			break;
			
			case DIO_PORTC:
			set_bit(DDRC , pinID);             /** CONFIGURE THIS PIN IN PORTA AS OUTPUT PIN **/
			Local_dirstate = VALID_DIRECTION ; /** RETURN AS DIR NO ERRORS **/
			break;
			
			case DIO_PORTD:
			set_bit(DDRD , pinID);             /** CONFIGURE THIS PIN IN PORTA AS OUTPUT PIN **/
			Local_dirstate = VALID_DIRECTION ; /** RETURN AS DIR NO ERRORS **/
			break;
			
			default:  /** DO NOTHING **/
			Local_dirstate = NOT_VALID_DIRECTION ; /** RETURN AS DIR NOT VALID ERRORS **/
			break;
		} 
		break;
		 
		 
		default:  /** DIRECTION ISN'T INPUT OR OUTPUT */
		Local_dirstate = NOT_VALID_DIRECTION ; /** RETURN AS DIR NOT VALID ERRORS **/
		break ; 
	} 
	
	return Local_dirstate ; /** RETURN THE STATE OF FUNCTION **/
}


/******************************************************************/
/* DESCRIBTION  : FUNCTION TO SET THE VALUE OF SPECIFIC PIN       */
/* INPUT   : PORT , PINID , DIRECTION                             */
/* RETURNS : PinValue_t                                           */
/******************************************************************/
PinValue_t DIO_SETPINVAL(uint8_t portID , uint8_t pinID , uint8_t val)
{
	
	PinValue_t Local_valstate = VALID_VALUE ; /** VARIABLE TO RETURN THE STATUS OF VALUE **/ 
	
	switch(val)
	{
		case DIO_PIN_LOW:  /** IN CASE PIN VALUE IS LOW */
		
		switch(portID)  /** SWITCH CASE ON THE PORT ID */ 
		{
			case DIO_PORTA:
			clear_bit(PORTA , pinID);       /** SET THIS PIN AS LOW **/
			Local_valstate = VALID_VALUE ;  /** RETURN VALUE AS VALID **/
			break;
			
			case DIO_PORTB:
			clear_bit(PORTB , pinID);       /** SET THIS PIN AS LOW **/
			Local_valstate = VALID_VALUE ;  /** RETURN VALUE AS VALID **/
			break;
			
			case DIO_PORTC:
			clear_bit(PORTC , pinID);       /** SET THIS PIN AS LOW **/
			Local_valstate = VALID_VALUE ;  /** RETURN VALUE AS VALID **/
			break;
			
			case DIO_PORTD:
			clear_bit(PORTD , pinID);       /** SET THIS PIN AS LOW **/
			Local_valstate = VALID_VALUE ;  /** RETURN VALUE AS VALID **/
			break;
			
			default:
			Local_valstate = NOT_VALID_VALUE ;  /** RETURN VALUE AS NOT VALID **/
			break;
		} 
		break;
		
		case DIO_PIN_HIGH:
		
		switch(portID)
		{
			case DIO_PORTA:
			set_bit(PORTA , pinID);         /** SET THIS PIN AS HIGH  **/
			Local_valstate = VALID_VALUE ;  /** RETURN VALUE AS VALID **/
			break;
			
			case DIO_PORTB:
			set_bit(PORTB , pinID);         /** SET THIS PIN AS HIGH  **/
			Local_valstate = VALID_VALUE ;  /** RETURN VALUE AS VALID **/
			break;
			
			case DIO_PORTC:
			set_bit(PORTC , pinID);         /** SET THIS PIN AS HIGH  **/
			Local_valstate = VALID_VALUE ;  /** RETURN VALUE AS VALID **/
			break;
			
			case DIO_PORTD:
			set_bit(PORTD , pinID);         /** SET THIS PIN AS HIGH  **/
			Local_valstate = VALID_VALUE ;  /** RETURN VALUE AS VALID **/
			break;
			
			default:
			Local_valstate = NOT_VALID_VALUE ;  /** RETURN VALUE AS NOT VALID **/
			break;
		} 
		break;
		
		default :
		Local_valstate = NOT_VALID_VALUE ;  /** RETURN VALUE AS NOT VALID **/
		break ;
	} 
	
	return Local_valstate ; /** RETURN THE FINAL STATE OF THE FUNCTION */
}


/******************************************************************/
/* DESCRIBTION  : FUNCTION TO GET THE VALUE OF SPECIFIC PIN       */
/* INPUT   : PORTID , PINID , POINTER TO SET THE VALUE IN IT      */
/* RETURNS : PinRead_t                                            */
/******************************************************************/
PinRead_t DIO_READPIN(uint8_t portID , uint8_t pinID , uint8_t* val)
{
	PinRead_t Local_Pinstate = NOT_VALID_READ ;  /** VARIABLE TO HOLD THE FUNCTION ERROR STATE */
	
	switch(portID)  /** SWITCH CASE ON PORT ID **/
	{
		case DIO_PORTA:               /** PORTA  **/
		*val = get_bit(PINA , pinID); /** GET THE VALUE OF THE BIT **/
		Local_Pinstate = VALID_READ ;  /** READ IS VALID  **/
		break;
		
		case DIO_PORTB:               /** PORTB  **/
		*val = get_bit(PINB , pinID); /** GET THE VALUE OF THE BIT **/
		Local_Pinstate = VALID_READ ;  /** READ IS VALID  **/
		break;
		
		case DIO_PORTC:               /** PORTC  **/
		*val = get_bit(PINC , pinID); /** GET THE VALUE OF THE BIT **/
		Local_Pinstate = VALID_READ ;  /** READ IS VALID  **/
		break;
		
		case DIO_PORTD:               /** PORTD  **/
		*val = get_bit(PIND , pinID); /** GET THE VALUE OF THE BIT **/
		Local_Pinstate = VALID_READ ;  /** READ IS VALID  **/
		break;
		
		default:
		Local_Pinstate = NOT_VALID_READ ;  /** READ IS NOT VALID  **/
		break;
	} 
	
	return Local_Pinstate ; /** RETURN THE FINAL STATE OF THE FUNCTION **/	
}

/******************************************************************/
/* DESCRIBTION  : FUNCTION TO TOGGLE SPECIFIC PIN                 */
/* INPUT   : PORTID , PINID                                       */
/* RETURNS : VOID                                                 */
/******************************************************************/
PinRead_t DIO_TOGGLEPIN(uint8_t portID , uint8_t pinID )
{
	switch(portID) /** SWITCH ON THE PORT ID **/
	{
		case DIO_PORTA:
		toggle_bit(PORTA , pinID);
		break;
		
		case DIO_PORTB:
		toggle_bit(PORTB , pinID);
		break;
		
		case DIO_PORTC:
		toggle_bit(PORTC , pinID);
		break;
		
		case DIO_PORTD:
		toggle_bit(PORTD , pinID);
		break;
		
		default:
		/** DO NOTHING **/
		break;
	} 
}