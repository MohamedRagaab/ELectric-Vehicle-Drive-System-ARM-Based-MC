/******************************************************************************************/
/* Author    : Ezzeldin magdy                                                             */
/* Version   : V01                                                                        */
/* Date      : 5 / 9 / 2021                                                              */
/******************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_config.h"
void (*CallBack)(u16 Data );
void MADC1_voidInit (void)
{

	/*	Configure ADC1 Mode 		       	*/
	/*	single conversion mode 		    	*/
	CLR_BIT (MADC1 -> CR2 ,1  );
	/*	Single channels  					*/
	CLR_BIT (MADC1 -> SQR1 ,20  );
	CLR_BIT (MADC1 -> SQR1 ,21  );
	CLR_BIT (MADC1 -> SQR1 ,22  );
	CLR_BIT (MADC1 -> SQR1 ,23  );
	/*	SQ1 = CH0  =   PAx			 				*/
	SET_BIT (MADC1 -> SQR3 ,0   );
	SET_BIT (MADC1 -> SQR3 ,1   );
	CLR_BIT (MADC1 -> SQR3 ,2   );
	CLR_BIT (MADC1 -> SQR3 ,3   );
	CLR_BIT (MADC1 -> SQR3 ,4   );

	/*	Enable trigger	         				*/
	SET_BIT(MADC1 -> CR2 , 17  );
	SET_BIT(MADC1 -> CR2 , 18  );
	SET_BIT(MADC1 -> CR2 , 19  );
	SET_BIT(MADC1 -> CR2 , 20  );

	/*	Right Alignment         				*/
	CLR_BIT (MADC1 -> CR2,11   );
	SET_BIT (MADC1 -> CR1,11   );
//	SET_BIT (MADC1 -> CR1,14   );

	/*	enable ADC1						*/
	SET_BIT (MADC1 -> CR2 ,0   );



}
void MADC1_voidEnableInterrupt ( void (*ptr)(u16 Data ))
{
	CallBack = ptr ;
	SET_BIT (MADC1 -> CR1 ,5   );
}
void MADC1_voidStartConversion ( u8 copy_u8ChannelIndex )
{
/*	select the channel			*/
	MADC1 -> SQR3 &= ~(0b1111<<0);
	MADC1 -> SQR3 |= copy_u8ChannelIndex ;
/*	SW Start trigger to start conversion */
	SET_BIT (MADC1 -> CR2 ,22    );

}


void ADC1_2_IRQHandler (void)
{
	CallBack ((u16)(MADC1 -> DR));

}


