/*
 * HLCD_program.c
 *
 * Created: 18-Feb-23 19:46:04
 *  Author: Ahmed Abdelmonem
 */
/*#include "HLCD_config.h"
#include "HLCD_interface.h"
#include "../../Libraries_/LIB_STDTypes.h"
#include "../../Libraries_/LIB_BMNP.h"
#include "../../MCAL/MDIO/MDIO_interface.h"



void HLCD_voidInit(void)
{
	u8 u8Local_Iter = 0;

	for(u8Local_Iter = 0 ; u8Local_Iter < NUM_OF_LCDs ; u8Local_Iter++)
	{
		if(HLCDArrayOfLCD[u8Local_Iter].enumType == FOUR_BIT)
		{
			_delay_ms(40);
			HLCD_voidWriteData(Command, FUNCTION_SET, HLCD_NUM0);

			_delay_ms(1);
			HLCD_voidWriteData(Command, DISPLAY_ON_ONLY, HLCD_NUM0);

			_delay_ms(1);
			HLCD_voidWriteData(Command, CLEAR_DISPLAY, HLCD_NUM0);

			_delay_ms(5);
			HLCD_voidWriteData(Command, ENTRY_MODE_INC, HLCD_NUM0);
		}
		else
		{

			MDIO_enumPinDirection(&HLCDArrayOfLCD[u8Local_Iter].DIO_tPin_D0);
			MDIO_enumPinDirection(&HLCDArrayOfLCD[u8Local_Iter].DIO_tPin_D1);
			MDIO_enumPinDirection(&HLCDArrayOfLCD[u8Local_Iter].DIO_tPin_D2);
			MDIO_enumPinDirection(&HLCDArrayOfLCD[u8Local_Iter].DIO_tPin_D3);
		}

		MDIO_enumPinDirection(&HLCDArrayOfLCD[u8Local_Iter].DIO_tPin_D4);
		MDIO_enumPinDirection(&HLCDArrayOfLCD[u8Local_Iter].DIO_tPin_D5);
		MDIO_enumPinDirection(&HLCDArrayOfLCD[u8Local_Iter].DIO_tPin_D6);
		MDIO_enumPinDirection(&HLCDArrayOfLCD[u8Local_Iter].DIO_tPin_D7);

		MDIO_enumPinDirection(&HLCDArrayOfLCD[u8Local_Iter].DIO_tPin_E);
		MDIO_enumPinDirection(&HLCDArrayOfLCD[u8Local_Iter].DIO_tPin_RS);
		MDIO_enumPinDirection(&HLCDArrayOfLCD[u8Local_Iter].DIO_tPin_RW);
	}

}


void HLCD_voidClearLCD(HLCD_t* HLCD_tCpy_Obj)
{
	HLCD_voidWriteData(Command, CLEAR_DISPLAY, HLCD_NUM0);
}


void HLCD_voidWriteData(HLCD_DataType DataType, u8 u8Data, u8 HLCD_Index)
{
	HLCDArrayOfLCD[HLCD_Index].DIO_tPin_RW.enumOutputLevel = MDIO_Low;
	MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_RW);
	if (DataType == Command)
	{
		HLCDArrayOfLCD[HLCD_Index].DIO_tPin_RS.enumOutputLevel = MDIO_Low;
		MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_RS);

		HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D4.enumOutputLevel = GET_BIT(u8Data, 4);
		HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D5.enumOutputLevel = GET_BIT(u8Data, 5);
		HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D6.enumOutputLevel = GET_BIT(u8Data, 6);
		HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D7.enumOutputLevel = GET_BIT(u8Data, 7);

		MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D4);
		MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D5);
		MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D6);
		MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D7);

		HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D4.enumOutputLevel = GET_BIT(u8Data, 0);
		HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D5.enumOutputLevel = GET_BIT(u8Data, 1);
		HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D6.enumOutputLevel = GET_BIT(u8Data, 2);
		HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D7.enumOutputLevel = GET_BIT(u8Data, 3);

		MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D4);
		MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D5);
		MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D6);
		MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D7);

		HLCDArrayOfLCD[HLCD_Index].DIO_tPin_E.enumOutputLevel = MDIO_High;
		MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_E);
		_delay_ms(1);
		HLCDArrayOfLCD[HLCD_Index].DIO_tPin_E.enumOutputLevel = MDIO_Low;
		MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_E);
	}
	else
	{
		HLCDArrayOfLCD[HLCD_Index].DIO_tPin_RS.enumOutputLevel = MDIO_High;
		MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_RS);

		HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D4.enumOutputLevel = GET_BIT(u8Data, 4);
		HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D5.enumOutputLevel = GET_BIT(u8Data, 5);
		HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D6.enumOutputLevel = GET_BIT(u8Data, 6);
		HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D7.enumOutputLevel = GET_BIT(u8Data, 7);

		MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D4);
		MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D5);
		MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D6);
		MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D7);

		HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D4.enumOutputLevel = GET_BIT(u8Data, 0);
		HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D5.enumOutputLevel = GET_BIT(u8Data, 1);
		HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D6.enumOutputLevel = GET_BIT(u8Data, 2);
		HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D7.enumOutputLevel = GET_BIT(u8Data, 3);

		MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D4);
		MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D5);
		MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D6);
		MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_D7);

		HLCDArrayOfLCD[HLCD_Index].DIO_tPin_E.enumOutputLevel = MDIO_High;
		MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_E);
		_delay_ms(1);
		HLCDArrayOfLCD[HLCD_Index].DIO_tPin_E.enumOutputLevel = MDIO_Low;
		MDIO_enumPinValue(&HLCDArrayOfLCD[HLCD_Index].DIO_tPin_E);
	}

}*/

#define F_CPU 16000000UL

//used libraries
#include "../../Libraries_/LIB_STDTypes.h"
#include "../../Libraries_/LIB_BMNP.h"

//DIO
#include "../../MCAL/MDIO/MDIO_interface.h"
#include "../../MCAL/MDIO/MDIO_Registers.h"

//LCD
#include "HLCD_config.h"
#include "HLCD_interface.h"
#include "HLCD_private.h"

#include <util/delay.h>

tenumFncErrorState HLCD_enumInit(void)
{
	tenumFncErrorState ReturnFunState = LSTY_EXECUTED_SUCCESSFULLY ;
	u8 u8Local_Iter;

	for(u8Local_Iter = 0 ; u8Local_Iter < NUM_OF_LCDs ; u8Local_Iter++ )
	{
		MDIO_enumPinDirection(&HLCDArrayOfLCD[u8Local_Iter].DIO_tEnablePin);
		MDIO_enumPinDirection(&HLCDArrayOfLCD[u8Local_Iter].DIO_tReadWritePin);
		MDIO_enumPinDirection(&HLCDArrayOfLCD[u8Local_Iter].DIO_tRegSelectPin);

		if(HLCDArrayOfLCD[u8Local_Iter].HLCD_enumMODE == HLCD_8Bit_Mode)
		{
			MDIO_enumPinDirection(&HLCDArrayOfLCD[u8Local_Iter].DIO_tDataPin_0);
			MDIO_enumPinDirection(&HLCDArrayOfLCD[u8Local_Iter].DIO_tDataPin_1);
			MDIO_enumPinDirection(&HLCDArrayOfLCD[u8Local_Iter].DIO_tDataPin_2);
			MDIO_enumPinDirection(&HLCDArrayOfLCD[u8Local_Iter].DIO_tDataPin_3);

		}

		MDIO_enumPinDirection(&HLCDArrayOfLCD[u8Local_Iter].DIO_tDataPin_4);
		MDIO_enumPinDirection(&HLCDArrayOfLCD[u8Local_Iter].DIO_tDataPin_5);
		MDIO_enumPinDirection(&HLCDArrayOfLCD[u8Local_Iter].DIO_tDataPin_6);
		MDIO_enumPinDirection(&HLCDArrayOfLCD[u8Local_Iter].DIO_tDataPin_7);
		_delay_ms(30);

		if(HLCDArrayOfLCD[u8Local_Iter].HLCD_enumMODE == HLCD_8Bit_Mode)
		{
			HLCD_enumWriteData(Command, FUNCTION_SET, u8Local_Iter);
		}
		else if (HLCDArrayOfLCD[u8Local_Iter].HLCD_enumMODE == HLCD_4Bit_Mode)
		{
			HLCD_enumWriteData(Command, LCD_4BitMode1, HLCD_NUM0);
			HLCD_enumWriteData(Command, LCD_4BitMode2, HLCD_NUM0);
			HLCD_enumWriteData(Command, LCD_2Lines5X8_4BitMode, HLCD_NUM0);
		}
		else
		{
			ReturnFunState = LSTY_READ_ERROR;
			return ReturnFunState;
		}

		_delay_ms(1);
		HLCD_enumWriteData(Command, DISPLAY_ON_WITH_CURSOR, u8Local_Iter);
		_delay_ms(1);
		HLCD_enumWriteData(Command, CLEAR_DISPLAY, u8Local_Iter);
		_delay_ms(2);
	}

	return ReturnFunState;
}

tenumFncErrorState HLCD_enumWriteData(HLCD_DataType enumCpy_LCDDatatype, u8 u8Cpy_LCDData, u8 u8Cpy_LCDNumber)
{
	tenumFncErrorState enumLocal_errState = LSTY_EXECUTED_SUCCESSFULLY;
	Register RegLocal_data;
	RegLocal_data.Byte = u8Cpy_LCDData;
	if((u8Cpy_LCDNumber >= 0)  && (u8Cpy_LCDNumber < NUM_OF_LCDs))
	{
		if(enumCpy_LCDDatatype == Data)
		{
			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tRegSelectPin.enumOutputLevel = MDIO_High;
		}
		else if(enumCpy_LCDDatatype == Command)
		{
			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tRegSelectPin.enumOutputLevel = MDIO_Low;
		}

		HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tReadWritePin.enumOutputLevel = MDIO_Low;
		MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tRegSelectPin);
		MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tReadWritePin);

		if(HLCDArrayOfLCD[u8Cpy_LCDNumber].HLCD_enumMODE == HLCD_4Bit_Mode)
		{

			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_4.enumOutputLevel = RegLocal_data.Bit.B4;
			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_5.enumOutputLevel = RegLocal_data.Bit.B5;
			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_6.enumOutputLevel = RegLocal_data.Bit.B6;
			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_7.enumOutputLevel = RegLocal_data.Bit.B7;

			MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_4);
			MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_5);
			MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_6);
			MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_7);

			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tEnablePin.enumOutputLevel = MDIO_High;
			MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tEnablePin);
			_delay_ms(10);
			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tEnablePin.enumOutputLevel = MDIO_Low;
			MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tEnablePin);

			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_4.enumOutputLevel = RegLocal_data.Bit.B0;
			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_5.enumOutputLevel = RegLocal_data.Bit.B1;
			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_6.enumOutputLevel = RegLocal_data.Bit.B2;
			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_7.enumOutputLevel = RegLocal_data.Bit.B3;

			MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_4);
			MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_5);
			MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_6);
			MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_7);

			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tEnablePin.enumOutputLevel = MDIO_High;
			MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tEnablePin);
			_delay_ms(10);
			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tEnablePin.enumOutputLevel = MDIO_Low;
			MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tEnablePin);
		}
		else if(HLCDArrayOfLCD[u8Cpy_LCDNumber].HLCD_enumMODE == HLCD_8Bit_Mode)
		{
			RegLocal_data.Byte = u8Cpy_LCDData;

			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_0.enumOutputLevel = RegLocal_data.Bit.B0;
			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_1.enumOutputLevel = RegLocal_data.Bit.B1;
			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_2.enumOutputLevel = RegLocal_data.Bit.B2;
			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_3.enumOutputLevel = RegLocal_data.Bit.B3;
			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_4.enumOutputLevel = RegLocal_data.Bit.B4;
			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_5.enumOutputLevel = RegLocal_data.Bit.B5;
			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_6.enumOutputLevel = RegLocal_data.Bit.B6;
			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_7.enumOutputLevel = RegLocal_data.Bit.B7;

			MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_0);
			MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_1);
			MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_2);
			MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_3);
			MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_4);
			MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_5);
			MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_6);
			MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tDataPin_7);

			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tEnablePin.enumOutputLevel = MDIO_High;
			MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tEnablePin);
			_delay_ms(10);
			HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tEnablePin.enumOutputLevel = MDIO_Low;
			MDIO_enumPinValue(&HLCDArrayOfLCD[u8Cpy_LCDNumber].DIO_tEnablePin);
		}
		else
		{
			enumLocal_errState = LSTY_READ_ERROR;
		}
	}
	else
	{
		enumLocal_errState = LSTY_OUT_OF_RANGE;
	}

	return enumLocal_errState;
}

tenumFncErrorState HLCD_enumIntegerToString(s32 s32Cpy_Number, u8 u8Cpy_LCDNumber)
{
	tenumFncErrorState enumLocal_errState = LSTY_EXECUTED_SUCCESSFULLY ;
	u8 u8Local_Rem = 0, u8Local_DigitNum = 0;
	u32 u32Local_ReverseNum = 1;
	if((u8Cpy_LCDNumber >= 0)  && (u8Cpy_LCDNumber < NUM_OF_LCDs))
	{
		/*while(u32Cpy_Number > 0)
		{
			u32Local_ReverseNum = u32Local_ReverseNum * 10 + u32Cpy_Number % 10;
			u32Cpy_Number /=10;
		}
		while(u32Local_ReverseNum != 1)
		{
			HLCD_enumWriteData(Data, (u32Local_ReverseNum % 10) + '0', u8Cpy_LCDNumber);
			u32Local_ReverseNum /= 10;
		}*/

		s8 Local_S8_Counter = 0;
		u8 Local_U8_Arr[10] = {0};
		if(s32Cpy_Number < 0)
		{
			s32Cpy_Number = s32Cpy_Number * -1;
			//H_Lcd_Void_LCDWriteCharacter('-');
			HLCD_enumWriteData(Data, '-', HLCD_NUM0);
		}

		do
		{
			Local_U8_Arr[Local_S8_Counter] = s32Cpy_Number % 10;
			s32Cpy_Number                = s32Cpy_Number / 10;
			Local_S8_Counter++;
		}while(s32Cpy_Number != 0);

		while(Local_S8_Counter > 0)
		{
			//H_Lcd_Void_LCDWriteCharacter(Local_U8_Arr[--Local_S8_Counter] + 48);
			HLCD_enumWriteData(Data, Local_U8_Arr[--Local_S8_Counter] + 48, HLCD_NUM0);
		}
	}
	else
	{
		enumLocal_errState = LSTY_OUT_OF_RANGE;
	}
	return enumLocal_errState;
}

tenumFncErrorState HLCD_enumFloatToString(f32 f32Cpy_Number, u8 u8Cpy_LCDNumber)
{
	tenumFncErrorState enumLocal_errState = LSTY_EXECUTED_SUCCESSFULLY;

	if((u8Cpy_LCDNumber >= 0)  && (u8Cpy_LCDNumber < NUM_OF_LCDs))
	{
		u32 u32Local_WholeNum = f32Cpy_Number;
		HLCD_enumIntegerToString(u32Local_WholeNum,u8Cpy_LCDNumber);
		HLCD_enumWriteData(Data,'.',u8Cpy_LCDNumber);
		u64 u64Local_FracNum = (f32Cpy_Number * 100000);
		u64Local_FracNum = u64Local_FracNum % 100000;
		HLCD_enumIntegerToString((u32)u64Local_FracNum,u8Cpy_LCDNumber);
	}
	else
	{
		enumLocal_errState = LSTY_OUT_OF_RANGE;
	}
	return enumLocal_errState;
}

tenumFncErrorState HLCD_enumDisplayString(u8* u8String, u8 u8Cpy_LCDNumber)
{
	tenumFncErrorState enumLocal_errState = LSTY_EXECUTED_SUCCESSFULLY ;
	u8 u8Local_Iter = 0;
	if((u8Cpy_LCDNumber >= 0)  && (u8Cpy_LCDNumber < NUM_OF_LCDs))
	{
		if(u8String != NULL)
		{
			while(u8String[u8Local_Iter] != '\0')
			{
				HLCD_enumWriteData(Data, u8String[u8Local_Iter], u8Cpy_LCDNumber);
				u8Local_Iter++;
			}
		}
		else
		{
			enumLocal_errState = LSTY_NULL_POINTER;
		}
	}
	else
	{
		enumLocal_errState = LSTY_OUT_OF_RANGE;
	}
	return enumLocal_errState;
}

tenumFncErrorState HLCD_enumClearScreen(u8 u8Cpy_LCDNumber)
{
	tenumFncErrorState enumLocal_errState = LSTY_EXECUTED_SUCCESSFULLY ;


	if((u8Cpy_LCDNumber >= 0)  && (u8Cpy_LCDNumber < NUM_OF_LCDs))
	{
		HLCD_enumWriteData(Command, CLEAR_DISPLAY, u8Cpy_LCDNumber);
	}
	else
	{
		enumLocal_errState = LSTY_OUT_OF_RANGE;
	}
	return enumLocal_errState;
}


tenumFncErrorState HLCD_enumGoToXY(u8 u8Cpy_Row, u8 u8Cpy_Col, u8 u8Cpy_LCDNumber)
{
	tenumFncErrorState enumLocal_errState = LSTY_EXECUTED_SUCCESSFULLY ;


	if((u8Cpy_LCDNumber >= 0)  && (u8Cpy_LCDNumber < NUM_OF_LCDs) && (u8Cpy_Row < HLCD_NUM_OF_ROWs) && (u8Cpy_Col < HLCD_NUM_OF_COLUMNs))
	{
		u8 Local_U8_Arr [4] = {LCD_R0_COMMAND , LCD_R1_COMMAND , LCD_R2_COMMAND , LCD_R3_COMMAND};
		HLCD_enumWriteData(Command, (Local_U8_Arr[u8Cpy_Row] + u8Cpy_Col), u8Cpy_LCDNumber);

	}
	else
	{
		enumLocal_errState = LSTY_OUT_OF_RANGE;
	}
	return enumLocal_errState;
}


tenumFncErrorState HLCD_enumDisplayCustom(u8 u8Cpy_Location, u8* u8Cpy_String, u8 u8Cpy_LCDNumber)
{
	tenumFncErrorState enumLocal_errState = LSTY_EXECUTED_SUCCESSFULLY;
	u8 u8Local_Iter;
	if((u8Cpy_LCDNumber >= 0)  && (u8Cpy_LCDNumber < NUM_OF_LCDs) && (u8Cpy_Location < 8))
	{	
		HLCD_enumWriteData(Command, (0x40 + (u8Cpy_Location*8)), HLCD_NUM0);

		for(u8Local_Iter = 0 ; u8Local_Iter < 8 ; u8Local_Iter++ )
		{
			HLCD_enumWriteData(Data, u8Cpy_String[u8Local_Iter], HLCD_NUM0);
		}
	}
	else
	{
		enumLocal_errState = LSTY_OUT_OF_RANGE;
	}
	return enumLocal_errState;
}


