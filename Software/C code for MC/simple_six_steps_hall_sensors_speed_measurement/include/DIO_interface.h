/*******************************************************************************************/
/*			Author 		: Ezzeldin Magdy                                                   */
/*			Version 	: v02                                                              */
/*			Date		: 8/1/2021														   */
/*******************************************************************************************/
#ifndef		DIO_INTERFACE_H
#define 	DIO_INTERFACE_H

		/* interface macros */
#define		PORTA 		0
#define		PORTB 		1
#define		PORTC		2

#define		PIN0        0
#define		PIN1        1
#define		PIN2        2
#define		PIN3        3
#define		PIN4        4
#define		PIN5        5
#define		PIN6        6
#define		PIN7        7
#define		PIN8        8
#define		PIN9        9
#define		PIN10       10
#define		PIN11       11
#define		PIN12       12
#define		PIN13       13
#define		PIN14       14
#define		PIN15       15

/*pin mode and configuration options*/
#define		INPUT_ANALOG 						0b0000
#define		INPUT_FLOATING 						0b0100
#define		INPUT_PULL_UP_DOWM    				0b1000
						
#define		OUTPUT_10MHZ_PP    					0b0001
#define		OUTPUT_10MHZ_OD			 			0b0101
#define		OUTPUT_10MHZ_AF_PP		 			0b1001
#define		OUTPUT_10MHZ_AF_OD					0b1101

#define 	OUTPUT_2MHZ_PP		 				0b0010
#define		OUTPUT_2MHZ_OD			 			0b0110
#define		OUTPUT_2MHZ_AF_PP		 			0b1010
#define		OUTPUT_2MHZ_AF_OD					0b1110

#define		OUTPUT_50MHZ_PP		 				0b0011
#define		OUTPUT_50MHZ_OD			 			0b0111
#define		OUTPUT_50MHZ_AF_PP		 			0b1011
#define 	OUTPUT_50MHZ_AF_OD 					0b1111

			/* pin values */
#define HIGH 		1 
#define LOW  		0 
	
		/* interface functions */
void DIO_voidSetPinDirection(u8 copy_u8Port ,u8 copy_u8Pin , u8 copy_u8Mode  );
void DIO_voidSetPinValue    (u8 copy_u8Port ,u8 copy_u8Pin , u8 copy_u8value );
u8   DIO_u8GetPinValue      (u8 copy_u8Port ,u8 copy_u8Pin  );
void DIO_voidTogPinValue    (u8 copy_u8Port ,u8 copy_u8Pin  );

#endif
