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
#include "NVIC_interface.h"
#include "ADC_interface.h"
#include "TIMER1_interface.h"
#define MOSFET4 PIN1
#define MOSFET6 PIN2
#define MOSFET2 PIN3

volatile  u8 H1 = 0 , H2 = 0 , H3 = 0 ;
volatile u8 duty =0 ;
void Task1 ( u16 Data )
	{
		if (Data > 4000)
		{
			Data =  4000 ;
		}
		duty = 0.025 * Data ;
		   H1 = DIO_u8GetPinValue(PORTA , PIN4);	/*	Hall1 	*/
				   H2 = DIO_u8GetPinValue(PORTA , PIN5);	/*	Hall2 	*/
				   H3 = DIO_u8GetPinValue(PORTA , PIN6);	/*	Hall3 	*/
				          if (H1 == 1 && H2 == 0 && H3 == 1)
				   {
				    	  DIO_voidSetPinValue(PORTA ,  MOSFET4 ,  LOW  );
				    	  DIO_voidSetPinValue(PORTA ,  MOSFET2  , LOW  );
				    	  MTIMER1_voidGeneratePWM3 (  0    );
				    	  MTIMER1_voidGeneratePWM5 (  0    );
				    	  MTIMER1_voidGeneratePWM1 (  duty );
				    	  DIO_voidSetPinValue(PORTA ,  MOSFET6 ,  HIGH  );
				   }
				    else  if (H1 == 1 && H2 == 0 && H3 == 0)
				   {
				    	  DIO_voidSetPinValue(PORTA ,  MOSFET4 ,  LOW  );
				    	  DIO_voidSetPinValue(PORTA ,  MOSFET6  , LOW  );
				    	  MTIMER1_voidGeneratePWM3 (  0    );
				    	  MTIMER1_voidGeneratePWM5 (  0    );
				    	  MTIMER1_voidGeneratePWM1 (  duty );
				    	  DIO_voidSetPinValue(PORTA ,  MOSFET2 ,  HIGH  );
				   }
				  	else  if (H1 == 1 && H2 == 1 && H3 == 0)
				   {
				    	  DIO_voidSetPinValue(PORTA ,  MOSFET4 ,  LOW  );
					      DIO_voidSetPinValue(PORTA ,  MOSFET6  , LOW  );
						  MTIMER1_voidGeneratePWM1 (  0    );
					      MTIMER1_voidGeneratePWM5 (  0    );
						  MTIMER1_voidGeneratePWM3 (  duty );
						  DIO_voidSetPinValue(PORTA ,  MOSFET2 ,  HIGH  );

				   }
				  	 else  if (H1 == 0 && H2 == 1 && H3 == 0)
				  	{
				  	   	  DIO_voidSetPinValue(PORTA ,  MOSFET2 ,  LOW  );
				          DIO_voidSetPinValue(PORTA ,  MOSFET6  , LOW  );
				          MTIMER1_voidGeneratePWM1 (  0    );
				  		  MTIMER1_voidGeneratePWM5 (  0    );
				          MTIMER1_voidGeneratePWM3 (  duty );
				  		  DIO_voidSetPinValue(PORTA ,  MOSFET4 ,  HIGH  );

				  	}
				  	else  if (H1 == 0 && H2 == 1 && H3 == 1)
				   {

				  	   	  DIO_voidSetPinValue(PORTA ,  MOSFET2 ,  LOW  );
					      DIO_voidSetPinValue(PORTA ,  MOSFET6  , LOW  );
						  MTIMER1_voidGeneratePWM1 (  0    );
					      MTIMER1_voidGeneratePWM3 (  0    );
						  MTIMER1_voidGeneratePWM5 (  duty );
						  DIO_voidSetPinValue(PORTA ,  MOSFET4 ,  HIGH  );

				    }
				  	else if (H1 == 0 && H2 == 0 && H3 == 1)
				  {
				  	   	  DIO_voidSetPinValue(PORTA ,  MOSFET4 ,  LOW  );
						  DIO_voidSetPinValue(PORTA ,  MOSFET2  , LOW  );
						  MTIMER1_voidGeneratePWM1 (  0    );
					      MTIMER1_voidGeneratePWM3 (  0    );
						  MTIMER1_voidGeneratePWM5 (  duty );
						  DIO_voidSetPinValue(PORTA ,  MOSFET6 ,  HIGH  );


				  }
	}

void main (void)
{
	/*		Initialize clocks		    */
	RCC_voidInitSysClock(); 				/* HSE , NO BYPASS , 8MHz */
	RCC_voidEnableClock(RCC_APB2 , 2 ); 	/*	GPIOA 				  */
	RCC_voidEnableClock(RCC_APB2 , 3 ); 	/*	GPIOB 				  */
	RCC_voidEnableClock(RCC_APB2 , 9);	/*	ADC1	*/
	RCC_voidEnableClock(RCC_APB2 , 11);	/*	TIMER1	*/
	/*		Initialize pins direction	*/
	DIO_voidSetPinDirection(PORTA , PIN0   , INPUT_ANALOG);			/*	Analog input  */

	DIO_voidSetPinDirection(PORTA , PIN8   , OUTPUT_10MHZ_AF_PP);	/*	MOSFET 1 H	  */
	DIO_voidSetPinDirection(PORTA , PIN9   , OUTPUT_10MHZ_AF_PP);	/*	MOSFET 3 H	  */
	DIO_voidSetPinDirection(PORTA , PIN10  , OUTPUT_10MHZ_AF_PP);	/*	MOSFET 5 H	  */

	DIO_voidSetPinDirection(PORTA , PIN1  , OUTPUT_10MHZ_PP);		/*	MOSFET 4 L	  */
	DIO_voidSetPinDirection(PORTA , PIN2  , OUTPUT_10MHZ_PP);	 	/*	MOSFET 6 L	  */
	DIO_voidSetPinDirection(PORTA , PIN3  , OUTPUT_10MHZ_PP);		/*	MOSFET 2 L	  */

	DIO_voidSetPinDirection(PORTA , PIN4  , INPUT_FLOATING);		/*  Hall sensor 1 */
	DIO_voidSetPinDirection(PORTA , PIN5  , INPUT_FLOATING);		/*  Hall sensor 2 */
	DIO_voidSetPinDirection(PORTA , PIN6  , INPUT_FLOATING);		/*  Hall sensor 3 */
	/*	initialize other peripherals */
	MSTK_voidInit();
	NVIC_voidEnableInterrupt(18);
	MADC1_voidInit();
	MADC1_voidEnableInterrupt(Task1);
	  DIO_voidSetPinValue(PORTA ,  1 , LOW  );
	  DIO_voidSetPinValue(PORTA ,  2 , LOW  );
	  DIO_voidSetPinValue(PORTA ,  3 , LOW  );
	  MTIMER1_voidConfigurePWM(1000);

while (1)
{
	MADC1_voidStartConversion ( PA0 );
	//	MSTK_voidSetBusyWait(50);
	/*	 do not use systick once more again 	*/



}}


