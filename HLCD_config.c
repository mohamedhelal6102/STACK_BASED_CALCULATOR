/*
 * HLCD_config.c
 *
 * Created: 18-Feb-23 19:45:51
 *  Author: Ahmed Abdelmonem
  
#include "HLCD_config.h"
#include "HLCD_interface.h"
#include "../../Libraries_/LIB_STDTypes.h"
#include "../../Libraries_/LIB_BMNP.h"
#include "../../MCAL/MDIO/MDIO_interface.h"


HLCD_t HLCDArrayOfLCD [ NUM_OF_LCDs ] = {

	[HLCD_NUM0] =	{
		.enumType = FOUR_BIT,
		
		 0,0,0,0,
		.DIO_tPin_D4 = {MDIO_PIN4, MDIO_PORTA, MDIO_Output, MDIO_High},
		.DIO_tPin_D5 = {MDIO_PIN5, MDIO_PORTA, MDIO_Output, MDIO_High},
		.DIO_tPin_D6 = {MDIO_PIN6, MDIO_PORTA, MDIO_Output, MDIO_High},
		.DIO_tPin_D7 = {MDIO_PIN7, MDIO_PORTA, MDIO_Output, MDIO_High},
		
		.DIO_tPin_E =  {MDIO_PIN3, MDIO_PORTB, MDIO_Output, MDIO_High},
		.DIO_tPin_RW = {MDIO_PIN2, MDIO_PORTB, MDIO_Output, MDIO_High},
		.DIO_tPin_RS = {MDIO_PIN1, MDIO_PORTB, MDIO_Output, MDIO_High}
	}
};*/

#include "../../MCAL/MDIO/MDIO_interface.h"
#include "HLCD_config.h"
#include "HLCD_interface.h"
#include "HLCD_private.h"

HLCD HLCDArrayOfLCD [NUM_OF_LCDs] =
{
	{ HLCD_4Bit_Mode ,
		
		.DIO_tDataPin_0    = {MDIO_PIN0, MDIO_PORTA, MDIO_Output, MDIO_High},
		.DIO_tDataPin_1    = {MDIO_PIN1, MDIO_PORTA, MDIO_Output, MDIO_High},
		.DIO_tDataPin_2    = {MDIO_PIN2, MDIO_PORTA, MDIO_Output, MDIO_High},
		.DIO_tDataPin_3    = {MDIO_PIN3, MDIO_PORTA, MDIO_Output, MDIO_High},
		.DIO_tDataPin_4    = {MDIO_PIN0, MDIO_PORTB, MDIO_Output, MDIO_High},
		.DIO_tDataPin_5    = {MDIO_PIN1, MDIO_PORTB, MDIO_Output, MDIO_High},
		.DIO_tDataPin_6    = {MDIO_PIN2, MDIO_PORTB, MDIO_Output, MDIO_High},
		.DIO_tDataPin_7    = {MDIO_PIN4, MDIO_PORTB, MDIO_Output, MDIO_High},

		.DIO_tRegSelectPin = {MDIO_PIN3, MDIO_PORTA, MDIO_Output, MDIO_High},
		.DIO_tReadWritePin = {MDIO_PIN0, MDIO_PORTC, MDIO_Output, MDIO_High},
		.DIO_tEnablePin    = {MDIO_PIN2, MDIO_PORTA, MDIO_Output, MDIO_High}
	}
};