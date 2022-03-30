/*
 * main.c
 *
 *  Created on: Oct 30, 2021
 *      Author: azzma
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"

void main (void)
{
	/*		Initialize clocks		    */
	RCC_voidInitSysClock(); 				/* HSE , NO BYPASS , 8MHz */
	RCC_voidEnableClock(RCC_APB2 , 2 ); 	/*	GPIOA 	*/

	/*		Initialize pins direction	*/
	DIO_voidSetPinDirection(PORTA , PIN1  , OUTPUT_10MHZ_PP);		/*	MOSFET 1	*/
	DIO_voidSetPinDirection(PORTA , PIN2  , OUTPUT_10MHZ_PP);		/*	MOSFET 2	*/
	DIO_voidSetPinDirection(PORTA , PIN3  , OUTPUT_10MHZ_PP);		/*	MOSFET 3	*/
	DIO_voidSetPinDirection(PORTA , PIN4  , OUTPUT_10MHZ_PP);		/*	MOSFET 4	*/
	DIO_voidSetPinDirection(PORTA , PIN5  , OUTPUT_10MHZ_PP);		/*	MOSFET 5	*/
	DIO_voidSetPinDirection(PORTA , PIN6  , OUTPUT_10MHZ_PP);		/*	MOSFET 6	*/

	/*	initialize other peripherals */
	MSTK_voidInit();
	u8 Turning_on_sequence[6]  = {1 , 2 , 3, 4 , 5, 6}; /*	element value refers to MOSFET number */
	u8 Turning_off_sequence[6] = {5 , 6 , 1, 2 , 3, 4};
	u8 i = 0 ;

while (1)
{
	DIO_voidSetPinValue(PORTA ,  Turning_on_sequence[i]  , HIGH );
	DIO_voidSetPinValue(PORTA ,  Turning_off_sequence[i] , LOW  );
	MSTK_voidSetBusyWait(3333);
	i++ ;
	if (i == 6)
	{
		i = 0 ;
	}

}
}


