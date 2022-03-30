/******************************************************************************************/
/* Author    : Ezzeldin magdy                                                             */
/* Version   : V01                                                                        */
/* Date      : 3 / 9 / 2021                                                              */
/******************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER1_interface.h"
#include "TIMER1_private.h"
#include "TIMER1_config.h"

void (* CallBack  )(void) ;
void (* CallBack2 )(void) ;
void (* CallBack3 )(u16 ) ;
void (* CallBack4 )(u16 ) ;
void (* CallBack6 )(void ) ;
void MTIMER1_voidCountUp (u16 copy_u16ReloadValue , void (* ptr )(void))
{
							/*		Set TIMER1 Configurations						*/

	/*	set counter direction as up counter 	*/
	CLR_BIT (MTIMER1 -> CR1 , 4 );
	/*	set timer prescaler 8MHZ / (7999 + 1 ) = 1000HZ --> Tick = 1ms */
	MTIMER1 -> PSC = 7999 ;
	/*	set timer preload value 	*/
	MTIMER1 -> ARR =  copy_u16ReloadValue ;
	/*	make ARR Register preloaded */
	SET_BIT (MTIMER1 -> CR1 , 7);
	/*  repetitions   4 + 1 = 5 times  */
//		MTIMER1 -> RCR = 8 ;
						/*		Set TIMER1 update interrupt Configurations			*/

		/*	ensble up date interrupt 	*/
	SET_BIT ( MTIMER1 -> DIER , 0 ) ;
		/*	call back 	*/
	CallBack = ptr ;


						/*			enable timer counter 							*/
	SET_BIT ( MTIMER1 -> CR1 , 0 ) ;
}
void MTIMER1_voidCountDown (u16 copy_u16ReloadValue , void (* ptr )(void))
{
							/*		Set TIMER1 Configurations						*/

	/*	set counter direction as Down counter 	*/
	SET_BIT (MTIMER1 -> CR1 , 4 );
	/*	set timer prescaler 8MHZ / (7999 + 1 ) = 1000HZ --> Tick = 1ms */
	MTIMER1 -> PSC = 7999 ;
	/*	set timer preload value 	*/
	MTIMER1 -> ARR =  copy_u16ReloadValue ;
	/*	make ARR Register preloaded */
	SET_BIT (MTIMER1 -> CR1 , 7);
	/*  repetitions   4 + 1 = 5 times  */
//		MTIMER1 -> RCR = 8 ;
						/*		Set TIMER1 update interrupt Configurations			*/

		/*	ensble up date interrupt 	*/
	SET_BIT ( MTIMER1 -> DIER , 0 ) ;
		/*	call back 	*/
	CallBack = ptr ;


						/*			enable timer counter 							*/
	SET_BIT ( MTIMER1 -> CR1 , 0 ) ;
}
void MTIMER1_voidCountUpDown (u16 copy_u16ReloadValue , void (* ptr )(void))
{
							/*		Set TIMER1 Configurations						*/

/*	set counter direction as Up Down counter 	*/
SET_BIT (MTIMER1 -> CR1 , 5 );
/*	set timer prescaler 8MHZ / (7999 + 1 ) = 1000HZ --> Tick = 1ms */
MTIMER1 -> PSC = 7999 ;
/*	set timer preload value 	*/
MTIMER1 -> ARR =  copy_u16ReloadValue ;
/*	make ARR Register preloaded */
SET_BIT (MTIMER1 -> CR1 , 7);
/*  repetitions   4 + 1 = 5 times  */
//		MTIMER1 -> RCR = 8 ;
						/*		Set TIMER1 update interrupt Configurations			*/

/*	ensble up date interrupt 	*/
SET_BIT ( MTIMER1 -> DIER , 0 ) ;
/*	call back 	*/
CallBack = ptr ;

						/*			enable timer counter 							*/
SET_BIT ( MTIMER1 -> CR1 , 0 ) ;

}
void MTIMER1_externalcounter (u16 copy_u16ReloadValue , void (*ptr1) (void) , void (*ptr2) (void)  )
{
	/*	timer1 base configuration	*/
		/*	configure timer1 direction as up counter	*/
		CLR_BIT (MTIMER1 -> CR1 , 4 );
		/*	no need to prescaler configuration*/
		/*	set timer reload value	*/
		MTIMER1 -> ARR = copy_u16ReloadValue ;
		/*	CallBack	*/
		CallBack = ptr1 ;
		/*	enable up date interrupt 	*/
		SET_BIT ( MTIMER1 -> DIER , 0 ) ;
		/*	external trigger configurations */
		/*	 external clock mode 1	*/
		SET_BIT (MTIMER1 -> SMCR , 0 );
		SET_BIT (MTIMER1 -> SMCR , 1 );
		SET_BIT (MTIMER1 -> SMCR , 2 );
		/*	Select TI2 as the trigger input source 	*/
		CLR_BIT (MTIMER1 -> SMCR , 4 );
		SET_BIT (MTIMER1 -> SMCR , 5 );
		SET_BIT (MTIMER1 -> SMCR , 6 );
		/*	falling edge trigger 	*/
		SET_BIT (MTIMER1 -> SMCR , 15 );
		/*	filter	*/
		SET_BIT (MTIMER1 -> SMCR , 0 );
		SET_BIT (MTIMER1 -> SMCR , 1 );
		SET_BIT (MTIMER1 -> SMCR , 2 );
		SET_BIT (MTIMER1 -> SMCR , 3 );
		/*	trigger interrupt enable	*/
		SET_BIT ( MTIMER1 -> DIER , 6 ) ;
		/*	CallBack	*/
		CallBack2 = ptr2 ;
		/*	enable timer counter 		*/
		SET_BIT ( MTIMER1 -> CR1 , 0 ) ;

}
void MTIMER1_voidGeneratePWM1 (  u8 copy_u8DutyPercentage )
{

		/*	set Capture compare register value = set duty cycle    		  				    */
		MTIMER1 -> CCR1 =  (1- (copy_u8DutyPercentage  /100.0 )) * (MTIMER1 -> ARR)  ;


}
void MTIMER1_voidGeneratePWM3 (  u8 copy_u8DutyPercentage )
{

		/*	set Capture compare register value = set duty cycle    		  				    */
		MTIMER1 -> CCR2 =  (1- (copy_u8DutyPercentage  /100.0 )) * (MTIMER1 -> ARR)  ;


}
void MTIMER1_voidGeneratePWM5 (  u8 copy_u8DutyPercentage )
{

		/*	set Capture compare register value = set duty cycle    		  				    */

		MTIMER1 -> CCR3 =  (1- (copy_u8DutyPercentage  /100.0 )) * (MTIMER1 -> ARR)  ;


}
void MTIMER1_voidConfigurePWM ( u16 copy_u32PeriodInMicro  )
{
	MTIMER1 -> PSC  = 7 ;
	/*	configure timer1 direction as up counter	*/
	//CLR_BIT (MTIMER1 -> CR1 , 4 );

	SET_BIT (MTIMER1 -> CR1 , 5 );
	SET_BIT (MTIMER1 -> CR1 , 6 );

//	/*	set timer preload value 					*/
//	MTIMER1 -> ARR =  copy_u32PeriodInMicro -1  ;
	/*	set duty cycle    		  				    */
//	MTIMER1 -> CCR1 =   (copy_u8DutyPercentage   / 100.0   )*copy_u32PeriodInMicro ;
//	MTIMER1 -> CCR2 =   (copy_u8DutyPercentage   / 100.0   )*copy_u32PeriodInMicro ;
//	MTIMER1 -> CCR3 =   (copy_u8DutyPercentage   / 100.0   )*copy_u32PeriodInMicro ;

	/*	set Auto Reload Register value 	= set period									*/
		MTIMER1 -> ARR = (u16 ) (copy_u32PeriodInMicro /2.0 )  ;
		/*	set Capture compare register value = set duty cycle    		  				    */
		MTIMER1 -> CCR1 =   (MTIMER1 -> ARR)  ;
		MTIMER1 -> CCR2 =   (MTIMER1 -> ARR)  ;
		MTIMER1 -> CCR3 =   (MTIMER1 -> ARR)  ;

	/* CCR1 preload enable */
	SET_BIT (MTIMER1 -> CCMR1 , 3 );
	SET_BIT (MTIMER1 -> CCMR1 , 11);
	SET_BIT (MTIMER1 -> CCMR2 , 3 );
	/* ARR preload enable */
	SET_BIT (MTIMER1 -> CR1   , 7 );

	/*	output compare mode		*/
	/*  Write OCxM = 110 to CCRxPWM mode 1 - In upcounting , channel 1 is active as long as TIMx_CNT<TIMx_CCR1 else inactive. */
	SET_BIT (MTIMER1 -> CCMR1 , 4 );
	SET_BIT (MTIMER1 -> CCMR1 , 5 );
	SET_BIT (MTIMER1 -> CCMR1 , 6 );
	SET_BIT (MTIMER1 -> CCMR1 , 12 );
	SET_BIT (MTIMER1 -> CCMR1 , 13 );
	SET_BIT (MTIMER1 -> CCMR1 , 14 );
	SET_BIT (MTIMER1 -> CCMR2 , 4 );
	SET_BIT (MTIMER1 -> CCMR2 , 5 );
	SET_BIT (MTIMER1 -> CCMR2 , 6 );
	/*  Write CCxP = 0 to select active high polarity */
	//CLR_BIT (MTIMER1 -> CCER , 1 );

	/*	output compare channels		*/
	/* CC1 channel is configured as output */ /*	CC1S	*/
	//CLR_BIT (MTIMER1 -> CCMR1 , 0 );
	//CLR_BIT (MTIMER1 -> CCMR1 , 1 );
	/*  OC1 signal is output on the corresponding output pin depending on MOE, OSSI, OSSR, OIS1, OIS1N and CC1NE bits.*/
	SET_BIT (MTIMER1 -> CCER , 0 ); /*	CC1E	*/
	SET_BIT (MTIMER1 -> CCER , 4 ); /*	CC2E	*/
	SET_BIT (MTIMER1 -> CCER , 8 ); /*	CC3E	*/
	/*	OC and OCN outputs are enabled if their respective enable bits are set (CCxE, CCxNE in TIMx_CCER register)	*/
		SET_BIT (MTIMER1 -> BDTR , 15);	/*	MOE		*/

		/*	enable timer counter 		*/
		SET_BIT ( MTIMER1 -> CR1 , 0 ) ;
}
void MTIMER1_voidGeneratePWMCenterAligned ( u32 copy_u32EvenPeriodInus , u8 copy_u8DutyPercentage , u8 copy_u8DeadTimeInus )
{
	/*	Select the counter clock  as as clocked directly by the internal clock 	*/
	// CLR_BIT (MTIMER1 -> SMCR , 0);
	// CLR_BIT (MTIMER1 -> SMCR , 1);
	// CLR_BIT (MTIMER1 -> SMCR , 2);
	/*		set timer prescaler 8MHZ / (7 + 1 ) = 1MHZ	 --> Tick = CK_CTR = 1 us	*/
	MTIMER1 -> PSC  = 7  ;
	/*	configure timer1 direction as up down counter	*/
	SET_BIT (MTIMER1 -> CR1 , 5 );
	SET_BIT (MTIMER1 -> CR1 , 6 );
	/*	set Auto Reload Register value 	= set period									*/
	MTIMER1 -> ARR = (u16 ) (copy_u32EvenPeriodInus /2 )  ;
	/*	make ARR Register preloaded */
	SET_BIT (MTIMER1 -> CR1 , 7);
	/*	set Capture compare register value = set duty cycle    		  				    */
	MTIMER1 -> CCR1 =  (copy_u8DutyPercentage * (MTIMER1 -> ARR) ) /100  ;
	/*	make CCR Register preloaded */
	SET_BIT (MTIMER1 -> CCMR1 , 3 );

	/*	Initialize (up date ) all registers */
	SET_BIT ( MTIMER1 -> CR1 , 2 ) ;
	SET_BIT ( MTIMER1 -> EGR , 0 ) ;

	/*	Select the output mode				*/
	/* Select output polarity	as high */
		CLR_BIT (MTIMER1 -> CCER , 1 );
		CLR_BIT (MTIMER1 -> CCER , 3 );
	/* Select PWM mode 1 (LOW_TRUE)		 */
	    CLR_BIT (MTIMER1 -> CCMR1 , 4 );
		SET_BIT (MTIMER1 -> CCMR1 , 5 );
		SET_BIT (MTIMER1 -> CCMR1 , 6 );
	/* CC1 channel is configured as output */
	//CLR_BIT (MTIMER1 -> CCMR1 , 0 );
	//CLR_BIT (MTIMER1 -> CCMR1 , 1 );
	/*  enable the output OC1 signal */
		SET_BIT (MTIMER1 -> CCER , 0 );
	/*  enable the output OC1N signal */
		SET_BIT (MTIMER1 -> CCER , 2 );
	/*	MOE = Main Output Enable 	  */
		SET_BIT (MTIMER1 -> BDTR , 15);
		//SET_BIT (MTIMER1 -> BDTR , 11);
		//SET_BIT (MTIMER1 -> BDTR , 10);

	/*	Dead time configuration */
	CLR_BIT ( MTIMER1 -> CR1 , 8 ) ;
	SET_BIT ( MTIMER1 -> CR1 , 9	 ) ;
	MTIMER1 -> BDTR &= ~ (0xFF << 0 ) ;
	MTIMER1 -> BDTR |=   (copy_u8DeadTimeInus << 0 ) ;

	/*	enable timer counter 		*/
	SET_BIT ( MTIMER1 -> CR1 , 0 ) ;

}
void MTIMER1_voidConfigPWM ( u32 copy_u32EvenPeriodInus , u8 copy_u8DutyPercentage  )
{
							/*	Time Base Unit  */
	/*	Select the counter clock  as as clocked directly by the internal clock 	*/
	// CLR_BIT (MTIMER1 -> SMCR , 0);
	// CLR_BIT (MTIMER1 -> SMCR , 1);
	// CLR_BIT (MTIMER1 -> SMCR , 2);
	/*		set timer prescaler 8MHZ / (7 + 1 ) = 1MHZ	 --> Tick = CK_CTR = 1 us	*/
	MTIMER1 -> PSC  = 7  ;
	/*	configure timer1 direction as up down counter	*/
	SET_BIT (MTIMER1 -> CR1 , 5 );
	SET_BIT (MTIMER1 -> CR1 , 6 );
	/*	set Auto Reload Register value 	= set period									*/
	MTIMER1 -> ARR = (u16 ) (copy_u32EvenPeriodInus /2.0 )  ;
	/*	set Capture compare register value = set duty cycle    		  				    */
	MTIMER1 -> CCR1 =  (1- (copy_u8DutyPercentage  /100.0 )) * (MTIMER1 -> ARR)  ;
	MTIMER1 -> CCR2 =  (1- (copy_u8DutyPercentage  /100.0 )) * (MTIMER1 -> ARR)  ;
	MTIMER1 -> CCR3 =  (1- (copy_u8DutyPercentage  /100.0 )) * (MTIMER1 -> ARR)  ;
	/*	make ARR Register preloaded */
	SET_BIT (MTIMER1 -> CR1 , 7);
	/*	make CCR Register preloaded */
	SET_BIT (MTIMER1 -> CCMR1 , 3 );
	SET_BIT (MTIMER1 -> CCMR1 , 11);
	SET_BIT (MTIMER1 -> CCMR2 , 3 );

	/*	Initialize (up date ) all registers */
	SET_BIT ( MTIMER1 -> CR1 , 2 ) ;
	SET_BIT ( MTIMER1 -> EGR , 0 ) ;

	/*	enable timer counter 		*/
	SET_BIT ( MTIMER1 -> CR1 , 0 ) ;

}
void MTIMER1_voidGenerateOutputControlSignals (u8 * OCM  ,  u8 * CCE  , u8 * CCNE )
{
											/*	Select the output mode				*/
		/* Select output polarity	as high */
			CLR_BIT (MTIMER1 -> CCER , 1 );
			CLR_BIT (MTIMER1 -> CCER , 3 );
		/* Select PWM mode 1 (forced active , forced inactive or PWM2 )		 */
			/*	OC1 */
			MTIMER1 -> CCMR1 &= ~(0X7<<4);
			MTIMER1 -> CCMR1 |= OCM[0] << 4;

			/*	OC2	*/
			MTIMER1 -> CCMR1 &= ~(0X7<<12);
			MTIMER1 -> CCMR1 |= OCM[1] << 12;
			/*	OC3	*/
			MTIMER1 -> CCMR2 &= ~(0X7<<4);
			MTIMER1 -> CCMR2 |= OCM[2] << 4;
										/*	Select the output mode				*/

		/* CC1 channel is configured as output */
		//CLR_BIT (MTIMER1 -> CCMR1 , 0 );
		//CLR_BIT (MTIMER1 -> CCMR1 , 1 );
		/*  enable the output OC1,2,3 signal */

			(CCE [0] == 1 )? (SET_BIT (MTIMER1 -> CCER , 0 ) ): (CLR_BIT (MTIMER1 -> CCER , 0 )) ;
			(CCE [1] == 1 )?( SET_BIT (MTIMER1 -> CCER , 4 ) ) :(CLR_BIT (MTIMER1 -> CCER , 4 )) ;
			(CCE [2] == 1 )?( SET_BIT (MTIMER1 -> CCER , 8 ) ): (CLR_BIT (MTIMER1 -> CCER , 8 ) );

		/*  enable the output OC1,2,3N signal */
			(CCNE [0] == 1 )?( SET_BIT (MTIMER1 -> CCER , 2 )) :( CLR_BIT (MTIMER1 -> CCER , 2 )) ;
			(CCNE [1] == 1 )? (SET_BIT (MTIMER1 -> CCER , 6 )) : (CLR_BIT (MTIMER1 -> CCER , 6 )) ;
			(CCNE [2] == 1 )? (SET_BIT (MTIMER1 -> CCER , 10 )) :( CLR_BIT (MTIMER1 -> CCER ,10 )) ;


			SET_BIT (MTIMER1 -> BDTR , 15);

}

void MTIMER1_voidConfigSlaveMode (void ( *Ptr_To_COM_Task ) ( 	void  ))
{
	/*	Configure Timer1 as slave for Timer2 	*/
	/*	Trigger selection	ITR1	*/
	SET_BIT (MTIMER1 -> SMCR , 4 );
	CLR_BIT (MTIMER1 -> SMCR , 5 );
	CLR_BIT (MTIMER1 -> SMCR , 6 );
	/*	 Slave mode selection		*/
//	SET_BIT (MTIMER1 -> SMCR , 2 );
//	CLR_BIT (MTIMER1 -> SMCR , 1 );
//	CLR_BIT (MTIMER1 -> SMCR , 0 );
	/*	CCxE, CCxNE and OCxM bits are preloaded,
	 *  after having been written, they are updated only when a commutation event (COM) occurs -->
	 *  rising edge detected on TRGI */
	SET_BIT (MTIMER1 -> CR2 , 0);
	/*When capture/compare control bits are preloaded (CCPC=1),
	 * they are updated by setting the COMG bit or when an rising edge occurs on TRGI*/
	SET_BIT (MTIMER1 -> CR2 , 2);

	/*	MOE = Main Output Enable 	  */
			SET_BIT (MTIMER1 -> BDTR , 15);
		//	SET_BIT (MTIMER1 -> BDTR , 11);



	/*	enable COM interrupt */
SET_BIT (MTIMER1 -> DIER , 5);
	CallBack6 = Ptr_To_COM_Task;



}
void MTIMER1_voidMeasurePWMSignalAsynch ( void ( *Ptr_To_CC1_Task ) ( u16  ) ,  void ( *Ptr_To_CC2_Task) ( u16  ) )
{
		/*		Set TIMER1 Configurations						*/

	/*	set counter direction as up counter 	*/
	CLR_BIT (MTIMER1 -> CR1 , 4 );
	/*	set timer prescaler 8MHZ / (7999 + 1 ) = 1000HZ --> Tick = 1ms */
	MTIMER1 -> PSC = 7 ;
	/*	set timer preload value 	*/
	//MTIMER1 -> ARR =  copy_u16ReloadValue ;
	/*	make ARR Register preloaded */
	//SET_BIT (MTIMER1 -> CR1 , 7);


	/* 	CC1 channel is configured as input  , IC1 is mapped on TI1 */
	SET_BIT (MTIMER1 -> CCMR1 , 0);
	CLR_BIT (MTIMER1 -> CCMR1 , 1);
	/*	CC2 channel is configured as input  , IC2 is mapped on TI1	*/
//	CLR_BIT (MTIMER1 -> CCMR1 , 8);
//	SET_BIT (MTIMER1 -> CCMR1 , 9);
	/*	CC1 channel polarity is configured as rising edge			*/
	CLR_BIT (MTIMER1 -> CCER  , 1);
	/*	CC2 channel polarity is configured as falling edge			*/
//	SET_BIT (MTIMER1 -> CCER  , 5);
	/*	Select the valid trigger input								*/
//	SET_BIT (MTIMER1 -> SMCR , 4);
//	CLR_BIT (MTIMER1 -> SMCR , 5);
//	SET_BIT (MTIMER1 -> SMCR , 6);
	/*	Configure the slave mode controller in reset mode			*/
	SET_BIT (MTIMER1 -> SMCR , 2 );
	CLR_BIT (MTIMER1 -> SMCR , 1 );
	CLR_BIT (MTIMER1 -> SMCR , 0 );
	/*	Enable capture from the counter into the capture register	*/
	SET_BIT (MTIMER1 -> CCER , 0 );	/*	CC1 */
//	SET_BIT (MTIMER1 -> CCER , 4 ); /*	CC2	*/
	/*	enable  Capture/Compare 1 interrupt  						*/
	SET_BIT ( MTIMER1 -> DIER , 1 ) ;
	/*	call back 	*/
	CallBack3 = Ptr_To_CC1_Task ;
	/*	enable  Capture/Compare 2 interrupt  						*/
//	SET_BIT ( MTIMER1 -> DIER , 2 ) ;
	/*	call back 	*/
//	CallBack4 = Ptr_To_CC2_Task ;
	/*			enable timer counter 								*/
	SET_BIT ( MTIMER1 -> CR1 , 0 ) ;

}


void TIM1_UP_IRQHandler (void)
{
	CLR_BIT (MTIMER1 -> SR , 0 );	/*	clear update interrupt flag	*/
	CallBack () ;					/*	Call Back					*/
	
} 
void TIM1_CC_IRQHandler (void)
{
//	CLR_BIT (MTIMER1 -> SR , 6 );
//	CallBack2 () ;
if (GET_BIT (MTIMER1 -> SR , 1 ) == 1 )  /*	check if  Capture/Compare 1 interrupt flag	is set */
	{
	CLR_BIT (MTIMER1 -> SR , 1 ); /*	Clear Capture/Compare 1 interrupt flag	*/
	CallBack3 ( MTIMER1 -> CCR1  );				  /*	Call Back + Clearing CCR1 Register							*/
	}
//else if (GET_BIT (MTIMER1 -> SR , 2 ) == 1  ) /*	check if  Capture/Compare 2 interrupt flag	is set */
//	{
//	CLR_BIT (MTIMER1 -> SR , 2 ); /*	Clear Capture/Compare 2 interrupt flag	*/
//	CallBack4 ( MTIMER1 -> CCR2  );				  /*	Call Back + Clearing CCR2 Register							*/

//	}
}
void TIM1_TRG_COM_IRQHandler (void)
{
	CLR_BIT (MTIMER1 -> SR , 5 ); /*	Clear  COM interrupt flag	*/
	CallBack6 ();				  /*	Call Back + Clearing CCR1 Register							*/



}


