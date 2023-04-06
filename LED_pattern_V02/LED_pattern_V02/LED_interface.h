/**************************************************/
/* Author  : Mustafa Mohammed Abdou               */
/* Date    : 4 April , 2023                       */
/* Version : V01                                  */
/* Hint    : interface file of led                */
/**************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

/***************************************************/
/** FUNCTION TO INITIALIZE A PIN                  **/
/** INPUT : LED PORT , LED PIN                    **/
/** RETURNS : VOID                                **/
/***************************************************/
void LED_INIT(uint8_t led_port , uint8_t ledpin);


/***************************************************/
/** FUNCTION TO SET A LED AS ON                   **/
/** INPUT : LED PORT , LED PIN                    **/
/** RETURNS : VOID                                **/
/***************************************************/
void LED_ON(uint8_t led_port , uint8_t ledpin);

/***************************************************/
/** FUNCTION TO SET A LED AS OFF                  **/
/** INPUT : LED PORT , LED PIN                    **/
/** RETURNS : VOID                                **/
/***************************************************/
void LED_OFF(uint8_t led_port , uint8_t ledpin);

/** PATTERNS TO BE DISPLAYED */
void LED_pattern1(void);
void LED_pattern2(void);
void LED_pattern3(void);
void LED_pattern4(void);
void LED_pattern5(void);
void LED_pattern6(void);
void LED_pattern7(void);
void LED_pattern8(void);


#endif