/******************************************************************************************/
/* Author    : Ezzeldin magdy                                                             */
/* Version   : V01                                                                        */
/* Date      : 5 / 9 / 2021                                                              */
/******************************************************************************************/
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

void MADC1_voidInit (void);
void MADC1_voidEnableInterrupt ( void (*ptr)(u16 Data ));
void MADC1_voidStartConversion ( u8 copy_u8ChannelIndex );

#define 		PA0			0 /* channel 0 */
#define 		PA1			1 /* channel 1 */
#define 		PA2			2 /* channel 2 */
#define 		PA3			3 /* channel 3 */
#define 		PA4			4 /* channel 4 */
#define 		PA5			5 /* channel 5 */
#define 		PA6			6 /* channel 6 */
#define 		PA7			7 /* channel 7 */
#define 		PB1			8 /* channel 8 */
#define 		PB2			9 /* channel 9 */


#endif
