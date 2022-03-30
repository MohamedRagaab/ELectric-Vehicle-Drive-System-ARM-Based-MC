/******************************************************************************************/
/* Author    : Ezzeldin magdy                                                             */
/* Version   : V01                                                                        */
/* Date      : 3 / 9 / 2021                                                              */
/******************************************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "TIMER2_config.h"
#include "TIMER2_interface.h"
#include "TIMER2_private.h"

void (* CallBack  )(void) ;
void (* CallBack2 )(void) ;
void (* CallBack3 )(u16 ) ;
void (* CallBack4 )(u16 ) ;
void (* CallBack5 )(u16 ) ;
void MTIMER2_voidCountUp (u16 copy_u16ReloadValue , void (* ptr )(void))
{
							/*		Set TIMER1 Configurations						*/

	/*	set counter direction as up counter 	*/
	CLR_BIT (MTIMER2 -> CR1 , 4 );
	/*	set timer prescaler 8MHZ / (7999 + 1 ) = 1000HZ --> Tick = 1ms */
	MTIMER2 -> PSC = 7999 ;
	/*	set timer preload value 	*/
	MTIMER2 -> ARR =  copy_u16ReloadValue ;
	/*	make ARR Register preloaded */
	SET_BIT (MTIMER2 -> CR1 , 7);
						/*		Set TIMER1 update interrupt Configurations			*/

		/*	ensble up date interrupt 	*/
	SET_BIT ( MTIMER2 -> DIER , 0 ) ;
		/*	call back 	*/
	CallBack = ptr ;


						/*			enable timer counter 							*/
	SET_BIT ( MTIMER2 -> CR1 , 0 ) ;
}
void MTIMER2_voidCountDown (u16 copy_u16ReloadValue , void (* ptr )(void))
{
							/*		Set TIMER1 Configurations						*/

	/*	set counter direction as Down counter 	*/
	SET_BIT (MTIMER2 -> CR1 , 4 );
	/*	set timer prescaler 8MHZ / (7999 + 1 ) = 1000HZ --> Tick = 1ms */
	MTIMER2 -> PSC = 7999 ;
	/*	set timer preload value 	*/
	MTIMER2 -> ARR =  copy_u16ReloadValue ;
	/*	make ARR Register preloaded */
	SET_BIT (MTIMER2 -> CR1 , 7);
						/*		Set TIMER1 update interrupt Configurations			*/

		/*	ensble up date interrupt 	*/
	SET_BIT ( MTIMER2 -> DIER , 0 ) ;
		/*	call back 	*/
	CallBack = ptr ;


						/*			enable timer counter 							*/
	SET_BIT ( MTIMER2 -> CR1 , 0 ) ;
}
void MTIMER8_voidCountUpDown (u16 copy_u16ReloadValue , void (* ptr )(void))
{
							/*		Set TIMER1 Configurations						*/

/*	set counter direction as Up Down counter 	*/
SET_BIT (MTIMER2 -> CR1 , 5 );
/*	set timer prescaler 8MHZ / (7999 + 1 ) = 1000HZ --> Tick = 1ms */
MTIMER2 -> PSC = 7999 ;
/*	set timer preload value 	*/
MTIMER2 -> ARR =  copy_u16ReloadValue ;
/*	make ARR Register preloaded */
SET_BIT (MTIMER2 -> CR1 , 7);
						/*		Set TIMER1 update interrupt Configurations			*/

/*	ensble up date interrupt 	*/
SET_BIT ( MTIMER2 -> DIER , 0 ) ;
/*	call back 	*/
CallBack = ptr ;

						/*			enable timer counter 							*/
SET_BIT ( MTIMER2 -> CR1 , 0 ) ;

}
void MTIMER8_externalcounter (u16 copy_u16ReloadValue , void (*ptr1) (void) , void (*ptr2) (void)  )
{
	/*	timer1 base configuration	*/
		/*	configure timer1 direction as up counter	*/
		CLR_BIT (MTIMER2 -> CR1 , 4 );
		/*	no need to prescaler configuration*/
		/*	set timer reload value	*/
		MTIMER2 -> ARR = copy_u16ReloadValue ;
		/*	CallBack	*/
		CallBack = ptr1 ;
		/*	enable up date interrupt 	*/
		SET_BIT ( MTIMER2 -> DIER , 0 ) ;
		/*	external trigger configurations */
		/*	 external clock mode 1	*/
		SET_BIT (MTIMER2 -> SMCR , 0 );
		SET_BIT (MTIMER2 -> SMCR , 1 );
		SET_BIT (MTIMER2 -> SMCR , 2 );
		/*	Select TI2 as the trigger input source 	*/
		CLR_BIT (MTIMER2 -> SMCR , 4 );
		SET_BIT (MTIMER2 -> SMCR , 5 );
		SET_BIT (MTIMER2 -> SMCR , 6 );
		/*	falling edge trigger 	*/
		SET_BIT (MTIMER2 -> SMCR , 15 );
		/*	filter	*/
		SET_BIT (MTIMER2 -> SMCR , 0 );
		SET_BIT (MTIMER2 -> SMCR , 1 );
		SET_BIT (MTIMER2 -> SMCR , 2 );
		SET_BIT (MTIMER2 -> SMCR , 3 );
		/*	trigger interrupt enable	*/
		SET_BIT ( MTIMER2 -> DIER , 6 ) ;
		/*	CallBack	*/
		CallBack2 = ptr2 ;
		/*	enable timer counter 		*/
		SET_BIT ( MTIMER2 -> CR1 , 0 ) ;

}
void MTIMER2_voidGeneratePWM ( u16 copy_u32PeriodInMicro , u8 copy_u8DutyPercentage )
{
	MTIMER2 -> PSC  = 7 ;
	/*	configure timer1 direction as up counter	*/
	CLR_BIT (MTIMER2 -> CR1 , 4 );
	/*	set timer preload value 					*/
	MTIMER2 -> ARR =  copy_u32PeriodInMicro -1  ;
	/*	set duty cycle    		  				    */
	MTIMER2 -> CCR1 =  (1- (copy_u8DutyPercentage   / 100  ) )* (MTIMER2 -> ARR) ;
	/*  Set period									*/
	/* CC1 channel is configured as output */
	//CLR_BIT (MTIMER1 -> CCMR1 , 0 );
	//CLR_BIT (MTIMER1 -> CCMR1 , 1 );
	/* OC1PE: Output Compare 1 preload enable */
	SET_BIT (MTIMER2 -> CCMR1 , 3 );
	/* PWM mode 1 - In upcounting, channel 1 is active as long as TIMx_CNT<TIMx_CCR1 else inactive. */
	SET_BIT (MTIMER2 -> CCMR1 , 5 );
	SET_BIT (MTIMER2 -> CCMR1 , 6 );
	/* CC1P: Capture/Compare 1 output polarity	as high */
	//CLR_BIT (MTIMER1 -> CCER , 1 );
	/* On - OC1 signal is output on the corresponding output pin depending on MOE, OSSI, OSSR, OIS1, OIS1N and CC1NE bits.*/
		SET_BIT (MTIMER2 -> CCER , 0 );
	/*MOE can be set by software or automatically at the next update event (if the break input is not be active)*/
//	SET_BIT (MTIMER2 -> BDTR , 14);
	/*	enable timer counter 		*/
	SET_BIT ( MTIMER2 -> CR1 , 0 ) ;
}

void MTIMER2_voidMeasurePWMSignalAsynch ( void ( *Ptr_To_CC1_Task ) ( u16  ) ,  void ( *Ptr_To_CC2_Task) ( u16  ) )
{
	//MTIMER1 -> ARR = 0XFFFF;
	//MTIMER1 -> RCR = 0XFFFF;
	//SET_BIT ( MTIMER1 -> CR1 , 2 ) ;
	//SET_BIT ( MTIMER1 -> EGR , 0 ) ;
	//CLR_BIT ( MTIMER1 -> CR1 , 2 ) ;
		/*		Set TIMER1 Configurations						*/

	/*	set counter direction as up counter 	*/
	CLR_BIT (MTIMER2 -> CR1 , 4 );
	/*	set timer prescaler 8MHZ / (7999 + 1 ) = 1000HZ --> Tick = 1ms */
	MTIMER2 -> PSC = 7999 ;
	/*	set timer preload value 	*/
	//MTIMER1 -> ARR =  copy_u16ReloadValue ;
	/*	make ARR Register preloaded */
	//SET_BIT (MTIMER1 -> CR1 , 7);


	/* 	CC1 channel is configured as input  , IC1 is mapped on TI1 */
	SET_BIT (MTIMER2 -> CCMR1 , 0);
	CLR_BIT (MTIMER2 -> CCMR1 , 1);
	/*	CC2 channel is configured as input  , IC2 is mapped on TI1	*/
//	CLR_BIT (MTIMER1 -> CCMR1 , 8);
//	SET_BIT (MTIMER1 -> CCMR1 , 9);
	/*	CC1 channel polarity is configured as rising edge			*/
	CLR_BIT (MTIMER2 -> CCER  , 1);
	/*	CC2 channel polarity is configured as falling edge			*/
//	SET_BIT (MTIMER1 -> CCER  , 5);
	/*	Select the valid trigger input								*/
	SET_BIT (MTIMER2 -> SMCR , 4);
	CLR_BIT (MTIMER2 -> SMCR , 5);
	SET_BIT (MTIMER2 -> SMCR , 6);
	/*	Configure the slave mode controller in reset mode			*/
	SET_BIT (MTIMER2 -> SMCR , 2 );
	CLR_BIT (MTIMER2 -> SMCR , 1 );
	CLR_BIT (MTIMER2 -> SMCR , 0 );
	/*	Enable capture from the counter into the capture register	*/
	SET_BIT (MTIMER2 -> CCER , 0 );	/*	CC1 */
//	SET_BIT (MTIMER1 -> CCER , 4 ); /*	CC2	*/
	/*	enable  Capture/Compare 1 interrupt  						*/
	SET_BIT ( MTIMER2 -> DIER , 1 ) ;
	/*	call back 	*/
	CallBack3 = Ptr_To_CC1_Task ;
	/*	enable  Capture/Compare 2 interrupt  						*/
//	SET_BIT ( MTIMER1 -> DIER , 2 ) ;
	/*	call back 	*/
//	CallBack4 = Ptr_To_CC2_Task ;
	/*			enable timer counter 								*/
	SET_BIT ( MTIMER2 -> CR1 , 0 ) ;

}
 void MTIMER2_voidMeasureHallSensorsAsynch( void ( *Ptr_TO_CC_Task ) ( u16  ))
 {
		/*		Set TIMER1 Configurations						*/

	/*	set counter direction as up counter 	*/
	//CLR_BIT (MTIMER2 -> CR1 , 4 );
	/*	set timer prescaler 8MHZ / (61 + 1 ) = 129 KHZ --> Tick = 8us */
	MTIMER2 -> PSC = 61 ;
	/*	set timer preload value 	*/
	MTIMER2 -> ARR =  0XFFFF ;

	/* 	CC1 channel is configured as input  , IC1 is mapped on TRC */
	SET_BIT (MTIMER2 -> CCMR1 , 0);
	SET_BIT (MTIMER2 -> CCMR1 , 1);

	/*	CC1 channel polarity is configured as rising edge			*/
	//CLR_BIT (MTIMER2 -> CCER  , 1);

	/*	The TIMx_CH1, CH2 and CH3 pins are connected to the TI1 input (XOR combination)	*/
	SET_BIT (MTIMER2 -> CR2 ,7);

	SET_BIT (MTIMER2 -> CCMR1 , 4 );
	SET_BIT (MTIMER2 -> CCMR1 , 5 );
	SET_BIT (MTIMER2 -> CCMR1 , 12 );
	SET_BIT (MTIMER2 -> CCMR1 , 13);
	SET_BIT (MTIMER2 -> CCMR2 , 4 );
	SET_BIT (MTIMER2 -> CCMR2 , 5 );


	/*	Select the valid trigger input	(	 TI1 Edge Detector		)				*/
	CLR_BIT (MTIMER2 -> SMCR , 4);
	CLR_BIT (MTIMER2 -> SMCR , 5);
	SET_BIT (MTIMER2 -> SMCR , 6);
	/*	Configure the slave mode controller in reset mode			*/
	SET_BIT (MTIMER2 -> SMCR , 2 );
	CLR_BIT (MTIMER2 -> SMCR , 1 );
	CLR_BIT (MTIMER2 -> SMCR , 0 );
	/*	Enable capture from the counter into the capture register	*/
	SET_BIT (MTIMER2 -> CCER , 0 );	/*	CC1 */

	/*	Delay for perfect synchronization between the two timers   */
	//MTIMER2 -> CCR2 = 100 ;
	/* CC2 channel is configured as output */
	//CLR_BIT (MTIMER2 -> CCMR1 , 8 );
	//CLR_BIT (MTIMER2 -> CCMR1 , 9 );
	/* Program channel 2 in PWM 2 mode with the desired delay */
	//SET_BIT (MTIMER2 -> CCMR1 , 12 );
	//SET_BIT (MTIMER2 -> CCMR1 , 13 );
	//SET_BIT (MTIMER2 -> CCMR1 , 14 );
	/*	 OC2REF signal is used as trigger output (TRGO)	*/
	//SET_BIT (MTIMER2 -> CR2 , 4 );
	//CLR_BIT (MTIMER2 -> CR2 , 5 );
	//SET_BIT (MTIMER2 -> CR2 , 6 );


	/*	enable  Capture/Compare 1 interrupt  						*/
	SET_BIT ( MTIMER2 -> DIER , 1 ) ;
	/*	call back 	*/
	CallBack5 = Ptr_TO_CC_Task ;
	/*			enable timer counter 								*/
	SET_BIT ( MTIMER2 -> CR1 , 0 ) ;


 }

//void TIM2_UP_IRQHandler (void)
//{
//	CLR_BIT (MTIMER2-> SR , 0 );	/*	clear update interrupt flag	*/
//	CallBack () ;					/*	Call Back					*/
	
//}
/*void TIM2_TRG_COM_IRQHandler (void)
{
	CLR_BIT (MTIMER2 -> SR , 6 );
	CallBack2 () ;

}*/
void TIM2_IRQHandler (void)
{
//	CLR_BIT (MTIMER1 -> SR , 6 );
//	CallBack2 () ;
if (GET_BIT (MTIMER2 -> SR , 1 ) == 1 )  /*	check if  Capture/Compare 1 interrupt flag	is set */
	{
	CLR_BIT (MTIMER2 -> SR , 1 ); /*	Clear Capture/Compare 1 interrupt flag	*/
//	CallBack3 ( MTIMER2 -> CCR1  );				  /*	Call Back + Clearing CCR1 Register							*/
	CallBack5 ( MTIMER2 -> CCR1  );				  /*	Call Back + Clearing CCR1 Register							*/
	}
//else if (GET_BIT (MTIMER1 -> SR , 2 ) == 1  ) /*	check if  Capture/Compare 2 interrupt flag	is set */
//	{
//	CLR_BIT (MTIMER1 -> SR , 2 ); /*	Clear Capture/Compare 2 interrupt flag	*/
//	CallBack4 ( MTIMER1 -> CCR2  );				  /*	Call Back + Clearing CCR2 Register							*/

//	}
}

