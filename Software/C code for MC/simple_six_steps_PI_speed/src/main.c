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
#include "TIMER2_interface.h"
#include "LCD_interface.h"
#include "PID_interface.h"
#define MOSFET4 PIN15
#define MOSFET6 PIN14
#define MOSFET2 PIN13

volatile  u8 H1 = 0 , H2 = 0 , H3 = 0 ;
volatile u8 duty  = 0 ;
volatile f32 speed = 0 ;
volatile f32 Setpoint = 100 ;
volatile PIDController PID ;

void Task1 ( u16 Data )
	{
		/*if (Data > 4000)
		{
			Data =  4000 ;
		} */
		//duty = 0.5 * 0.025 * Data ;
		duty = PID.Output;
									H1 = DIO_u8GetPinValue(PORTA , PIN0);	/*	Hall1 	*/
								    H2 = DIO_u8GetPinValue(PORTA , PIN1);	/*	Hall2 	*/
								    H3 = DIO_u8GetPinValue(PORTA , PIN2);	/*	Hall3 	*/
								          if (H1 == 1 && H2 == 0 && H3 == 1)
								   {
								    	  DIO_voidSetPinValue(PORTB ,  MOSFET4 ,  LOW  );
								    	  DIO_voidSetPinValue(PORTB ,  MOSFET2  , LOW  );
								    	  MTIMER1_voidGeneratePWM3 (  0    );
								    	  MTIMER1_voidGeneratePWM1 (  0    );
								    	  MTIMER1_voidGeneratePWM5 (  duty );
								    	  DIO_voidSetPinValue(PORTB ,  MOSFET6 ,  HIGH  );
								   }
								    else  if (H1 == 1 && H2 == 0 && H3 == 0)
								   {
								    	  DIO_voidSetPinValue(PORTB ,  MOSFET4 ,  LOW  );
								    	  DIO_voidSetPinValue(PORTB ,  MOSFET6  , LOW  );
								    	  MTIMER1_voidGeneratePWM3 (  0    );
								    	  MTIMER1_voidGeneratePWM1 (  0    );
								    	  MTIMER1_voidGeneratePWM5 (  duty );
								    	  DIO_voidSetPinValue(PORTB ,  MOSFET2 ,  HIGH  );
								   }
								  	else  if (H1 == 1 && H2 == 1 && H3 == 0)
								   {
								    	  DIO_voidSetPinValue(PORTB ,  MOSFET4 ,  LOW  );
									      DIO_voidSetPinValue(PORTB ,  MOSFET6  , LOW  );
										  MTIMER1_voidGeneratePWM5 (  0    );
									      MTIMER1_voidGeneratePWM1 (  0    );
										  MTIMER1_voidGeneratePWM3 (  duty );
										  DIO_voidSetPinValue(PORTB ,  MOSFET2 ,  HIGH  );

								   }
								  	 else  if (H1 == 0 && H2 == 1 && H3 == 0)
								  	{
								  	   	  DIO_voidSetPinValue(PORTB ,  MOSFET2 ,  LOW  );
								          DIO_voidSetPinValue(PORTB ,  MOSFET6  , LOW  );
								          MTIMER1_voidGeneratePWM5 (  0    );
								  		  MTIMER1_voidGeneratePWM1 (  0    );
								          MTIMER1_voidGeneratePWM3 (  duty );
								  		  DIO_voidSetPinValue(PORTB ,  MOSFET4 ,  HIGH  );

								  	}
								  	else  if (H1 == 0 && H2 == 1 && H3 == 1)
								   {

								  	   	  DIO_voidSetPinValue(PORTB ,  MOSFET2 ,  LOW  );
									      DIO_voidSetPinValue(PORTB ,  MOSFET6  , LOW  );
										  MTIMER1_voidGeneratePWM5 (  0    );
									      MTIMER1_voidGeneratePWM3 (  0    );
										  MTIMER1_voidGeneratePWM1 (  duty );
										  DIO_voidSetPinValue(PORTB ,  MOSFET4 ,  HIGH  );

								    }
								  	else if (H1 == 0 && H2 == 0 && H3 == 1)
								  {
								  	   	  DIO_voidSetPinValue(PORTB ,  MOSFET4 ,  LOW  );
										  DIO_voidSetPinValue(PORTB ,  MOSFET2  , LOW  );
										  MTIMER1_voidGeneratePWM5 (  0    );
									      MTIMER1_voidGeneratePWM3 (  0    );
										  MTIMER1_voidGeneratePWM1 (  duty );
										  DIO_voidSetPinValue(PORTB ,  MOSFET6 ,  HIGH  );
								  }

	}
void TASK2 (u16 CCR1_Value)
{
	if (CCR1_Value > 64516)
	{
		speed = 0;
	}
	else
	{
	speed = 2000000.0/(CCR1_Value * 31.0 );
	}


	          	     		MADC1_voidStartConversion ( PA3 );

}
void TASK3 (void)
{
	  PIDController_Update  (&PID ,  (3.14/30.0)* Setpoint , (3.14/30.0) * speed );

}
void main (void)
{
	/*		Initialize clocks		    */
	RCC_voidInitSysClock(); 				/* HSE , NO BYPASS , 8MHz */
	RCC_voidEnableClock(RCC_APB2 , 2 ); 	/*	GPIOA 				  */
	RCC_voidEnableClock(RCC_APB2 , 3 ); 	/*	GPIOB 				  */
	RCC_voidEnableClock(RCC_APB2 , 9);	/*	ADC1	*/
	RCC_voidEnableClock(RCC_APB2 , 11);	/*	TIMER1	*/	/*	PWM generation 		*/
	RCC_voidEnableClock(RCC_APB1 , 0);	/*	TIMER2	*/	/*	speed measurement 	*/

	/*		Initialize pins direction	*/

	DIO_voidSetPinDirection(PORTA , PIN8   , OUTPUT_10MHZ_AF_PP);	/*	MOSFET 1 H	  */
	DIO_voidSetPinDirection(PORTA , PIN9   , OUTPUT_10MHZ_AF_PP);	/*	MOSFET 3 H	  */
	DIO_voidSetPinDirection(PORTA , PIN10  , OUTPUT_10MHZ_AF_PP);	/*	MOSFET 5 H	  */

	DIO_voidSetPinDirection(PORTB , PIN13  , OUTPUT_10MHZ_PP);		/*	MOSFET 4 L	  */
	DIO_voidSetPinDirection(PORTB , PIN14  , OUTPUT_10MHZ_PP);	 	/*	MOSFET 6 L	  */
	DIO_voidSetPinDirection(PORTB , PIN15  , OUTPUT_10MHZ_PP);		/*	MOSFET 2 L	  */


	DIO_voidSetPinDirection (PORTA , PIN0 , INPUT_FLOATING);		/* Hall sensor 1 */
	DIO_voidSetPinDirection (PORTA , PIN1 , INPUT_FLOATING);		/* Hall sensor 2 */
	DIO_voidSetPinDirection (PORTA , PIN2 , INPUT_FLOATING);		/* Hall sensor 3 */

	DIO_voidSetPinDirection (PORTA , PIN3 , INPUT_ANALOG);			/* Duty cycle 	 *//*	Analog input  */
	LCD_voidSetPinsDirection(); /* LCD pins 4bit mode */


	/*	initialize other peripherals */
	MSTK_voidInit();
	NVIC_voidEnableInterrupt(18);	/*	ADC1 and ADC2 global interrupt	*/
	NVIC_voidEnableInterrupt(28);	/*	TIM2 global interrupt */
	NVIC_voidSetPriority (28 , 1 , 1 , PERIORITY_FORMAT_0 );
	NVIC_voidSetPriority (18 , 2 , 1 , PERIORITY_FORMAT_0 );
	NVIC_voidSetPriority (6  , 3 , 1 , PERIORITY_FORMAT_0 );
	MADC1_voidInit();
	MADC1_voidEnableInterrupt(Task1);
	MTIMER2_voidMeasureHallSensorsAsynch(TASK2);

	  LCD_voidInitialize();
		LCD_voidSendString("Speed =");
	PIDController_Init    (& PID );
		PID.Kp 			=	10	 ;
		PID.Ki 			=	10	 ;
		PID.Kd 			=	0	 ;
		PID. Tau	    =	0	 ;
		PID. T 			=	0.001	 ;
		PID. LimMin		=	0	 ;
		PID. LimMax		=	50	 ;

	  DIO_voidSetPinValue(PORTB ,  13 , LOW  );
	  DIO_voidSetPinValue(PORTB ,  14 , LOW  );
	  DIO_voidSetPinValue(PORTB ,  15 , LOW  );
	  MTIMER1_voidConfigurePWM(1000);

	MSTK_voidSetIntervalPeriodic (1000 , TASK3 );

while (1)
{
	MADC1_voidStartConversion ( PA3 );
						//  LCD_voidClearScreen();
	          			//	LCD_voidSendString("Speed =");
	          			//	LCD_voidSendDNumber(speed );
	          	     	//	LCD_voidSendString(" rpm");
	          			//	MSTK_voidSetBusyWait(500000);


}}


