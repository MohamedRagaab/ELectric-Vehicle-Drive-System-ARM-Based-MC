/*******************************************************************************************/
/*			Auther 		: Ezzeldin Magdy                                                   */
/*			Version 	: v02                                                              */
/*			Date		: 8/1/2021														   */
/*******************************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_voidSetPinDirection(u8 copy_u8Port ,u8 copy_u8Pin , u8 copy_u8Mode )
{
	if( copy_u8Pin <= 7)
	{
		switch (copy_u8Port)
		{
			case PORTA :	
							GPIOA_CRL &= ~((0b1111)<< (copy_u8Pin *4) ) ;
							GPIOA_CRL |=  ((copy_u8Mode) << (copy_u8Pin *4) );
							break;
			case PORTB :		
							GPIOB_CRL &= ~((0b1111)<< (copy_u8Pin *4) ) ;
							GPIOB_CRL |= ((copy_u8Mode) << (copy_u8Pin *4) );
							break;
			case PORTC :	
							GPIOC_CRL &= ~((0b1111)<< (copy_u8Pin *4) ) ;
							GPIOC_CRL |=  ((copy_u8Mode) << (copy_u8Pin *4) );
							break;
			/*  default    : return error                       break; */
		}
	}
	else if ( copy_u8Pin <= 15)
	{

		switch (copy_u8Port)
		{
			case PORTA :	 
							GPIOA_CRH &= ~((0b1111)<< ((copy_u8Pin - 8 ) *4) ) ;		/*reset the pin bits*/
							GPIOA_CRH |= ((copy_u8Mode) << ((copy_u8Pin - 8 ) *4) );   /*write the configuration to pin bits */
							break;
			case PORTB :		
							GPIOB_CRH &= ~((0b1111)<< ((copy_u8Pin - 8 ) *4) ) ;		/*reset the pin bits*/
							GPIOB_CRH |=  ((copy_u8Mode) << ((copy_u8Pin - 8 ) *4) );   /*write the configuration to pin bits */
							break;
			case PORTC :	
							GPIOC_CRH &= ~((0b1111)<< ((copy_u8Pin - 8 ) *4) ) ;		/*reset the pin bits*/
							GPIOC_CRH |=  ((copy_u8Mode) << ((copy_u8Pin - 8 ) *4) );   /*write the configuration to pin bits */
							break;
			/*  default    : return error                       break; */
		}
	}
	else
	{/* return error*/}
}
void DIO_voidSetPinValue    (u8 copy_u8Port ,u8 copy_u8Pin , u8 copy_u8value )
{
	if((copy_u8Pin >= 0) &&(copy_u8Pin <= 15) )
	{
		switch (copy_u8Port)
		{
			case PORTA :	
							if ( copy_u8value == HIGH )
							{
							 SET_BIT( GPIOA_ODR , copy_u8Pin );	
							}
							else if ( copy_u8value == LOW )
							{
							 CLR_BIT( GPIOA_ODR , copy_u8Pin );		
							}
							break;
			case PORTB :		
							if ( copy_u8value == HIGH )
							{
							 SET_BIT( GPIOB_ODR , copy_u8Pin );	
							}
							else if ( copy_u8value == LOW )
							{
							 CLR_BIT( GPIOB_ODR , copy_u8Pin );		
							}
							break;
			case PORTC :	
							if ( copy_u8value == HIGH )
							{
							 SET_BIT( GPIOC_ODR , copy_u8Pin );	
							}
							else if ( copy_u8value == LOW )
							{
							 CLR_BIT( GPIOC_ODR , copy_u8Pin );		
							}
							break;
			/*  default    : return error                       break; */
		}
	}
	else
	{/* return error */}
}
u8   DIO_u8GetPinValue      (u8 copy_u8Port ,u8 copy_u8Pin  )
{
	if((copy_u8Pin >= 0) &&(copy_u8Pin <= 15) )
	{
		u8 loc_u8Value ;
		switch (copy_u8Port)
		{
			case PORTA :	
							loc_u8Value = GET_BIT (GPIOA_IDR , copy_u8Pin );
							break;
			case PORTB :		
							loc_u8Value = GET_BIT (GPIOB_IDR , copy_u8Pin );
							break;
			case PORTC :	
							loc_u8Value = GET_BIT (GPIOC_IDR , copy_u8Pin );
							break;
			/*  default    : return error                       break; */
		}
		return loc_u8Value ;
	}
	else
	{/* return error */}

}
void DIO_voidTogPinValue(u8 copy_u8Port ,u8 copy_u8Pin )
{
	if((copy_u8Pin >= 0) &&(copy_u8Pin <= 15) )
	{
		switch (copy_u8Port)
		{
			case PORTA :	
							
							 TOG_BIT( GPIOA_ODR , copy_u8Pin );	
							break;
			case PORTB :		
							 TOG_BIT( GPIOB_ODR , copy_u8Pin );	
							break;
			case PORTC :	
							 TOG_BIT( GPIOC_ODR , copy_u8Pin );	
							break;
			/*  default    : return error                       break; */
		}
	}
	else
	{/* return error */}
}