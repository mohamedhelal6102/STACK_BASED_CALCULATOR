
/*#include "HLCD_config.h"
#include "../../Libraries_/LIB_STDTypes.h"
#include "../../Libraries_/LIB_BMNP.h"
#include "../../MCAL/MDIO/MDIO_interface.h"

#ifndef HLCD_INTERFACE_H_
#define HLCD_INTERFACE_H_

#define EIGHT_BIT_MODE						((u8)0b00111000)
#define FOUR_BIT_MODE						((u8)0b00101000)

#define CLEAR_DISPLAY						((u8)0b00000001)
#define RETURN_HOME							((u8)0b00000010)
#define ENTRY_MODE_INC						((u8)0b00000111)
#define ENTRY_MODE_DEC						((u8)0b00000101)
#define DISPLAY_ON_ONLY						((u8)0b00001100)
#define DISPLAY_ON_WITH_CURRSOR				((u8)0b00001110)
#define DISPLAY_ON_WITH_CURRSOR_BLINKING	((u8)0b00001111)
#define CURRSOR_SHIFT_RIGHT					((u8)0b00010100)
#define CURRSOR_SHIFT_LEFT					((u8)0b00010000)
#define DISPLAY_SHIFT_RIGHT					((u8)0b00011100)
#define DISPLAY_SHIFT_LEFT					((u8)0b00011000)
#define FUNCTION_SET						((u8)0b00111100)

typedef enum{
	FOUR_BIT, EIGHT_BIT
}HLCD_Mode;

typedef enum{
	Command, Data
}HLCD_DataType;

typedef struct {
	
	HLCD_Mode enumType;

	DIO_Pin DIO_tPin_D0;
	DIO_Pin DIO_tPin_D1;
	DIO_Pin DIO_tPin_D2;
	DIO_Pin DIO_tPin_D3;
	DIO_Pin DIO_tPin_D4;
	DIO_Pin DIO_tPin_D5;
	DIO_Pin DIO_tPin_D6;
	DIO_Pin DIO_tPin_D7;

	DIO_Pin DIO_tPin_E;
	DIO_Pin DIO_tPin_RW;
	DIO_Pin DIO_tPin_RS;
	
}HLCD_t;

extern HLCD_t HLCDArrayOfLCD [NUM_OF_LCDs];

void HLCD_voidInit(void);
void HLCD_voidClearLCD(HLCD_t* HLCD_tCpy_Obj);
void HLCD_voidWriteData(HLCD_DataType DataType, u8 u8Data, u8 HLCD_Index);
//void HLCD_
//void HLCD_
//void HLCD_
//void HLCD_

#endif */

#ifndef HLCD_INTERFACE_H_
#define HLCD_INTERFACE_H_


#include "../../Libraries_/LIB_STDTypes.h"
#include "../../MCAL/MDIO/MDIO_interface.h"
#include "HLCD_config.h"

//list of all commands in LCD module
#define LCD_4BitMode1					((u8)0x33)
#define LCD_4BitMode2					((u8)0x32)
#define LCD_2Lines5X8_4BitMode			((u8)0x28)
#define CLEAR_DISPLAY         			((u8)0b00000001)
#define RETURN_HOME    		 			((u8)0b00000010)
#define ENTRY_MODE_INC 		 			((u8)0b00000111)
#define ENTRY_MODE_DEC  		 		((u8)0b00000101)
#define DISPLAY_ON_ONLY		 			((u8)0b00001100)
#define DISPLAY_ON_WITH_CURSOR  		((u8)0b00001110)
#define DISPLAY_ON_WITH_CURSOR_BLINKING ((u8)0b00001111)
#define CURSOR_SHIFT_RIGHT  			((u8)0b00010100)
#define CURSOR_SHIFT_LEFT  		 		((u8)0b00010000)
#define DISPLAY_SHIFT_RIGHT  			((u8)0b00011100)
#define DISPLAY_SHIFT_LEFT  			((u8)0b00011000)
#define FUNCTION_SET  		 			((u8)0b00111100)

typedef enum{
	Command, Data
}HLCD_DataType;

//LCD 2 MODES of operations
typedef enum{
	HLCD_4Bit_Mode, HLCD_8Bit_Mode
}HLCD_Mode;

typedef struct Hlcd{
	HLCD_Mode HLCD_enumMODE;

	MDIO_Pin DIO_tDataPin_0;
	MDIO_Pin DIO_tDataPin_1;
	MDIO_Pin DIO_tDataPin_2;
	MDIO_Pin DIO_tDataPin_3;
	MDIO_Pin DIO_tDataPin_4;
	MDIO_Pin DIO_tDataPin_5;
	MDIO_Pin DIO_tDataPin_6;
	MDIO_Pin DIO_tDataPin_7;

	MDIO_Pin DIO_tRegSelectPin;
	MDIO_Pin DIO_tReadWritePin;
	MDIO_Pin DIO_tEnablePin;
}HLCD;

extern HLCD HLCDArrayOfLCD [NUM_OF_LCDs];

tenumFncErrorState HLCD_enumInit(void);
tenumFncErrorState HLCD_enumWriteData(HLCD_DataType enumCpy_LCDDatatype, u8 u8Cpy_LCDData, u8 u8Cpy_LCDNumber);
tenumFncErrorState HLCD_enumIntegerToString(s32 s32Cpy_Number, u8 u8Cpy_LCDNumber);
tenumFncErrorState HLCD_enumFloatToString(f32 f32Cpy_Number, u8 u8Cpy_LCDNumber);
tenumFncErrorState HLCD_enumDisplayString(u8* u8String, u8 u8Cpy_LCDNumber);
tenumFncErrorState HLCD_enumClearScreen(u8 u8Cpy_LCDNumber);
tenumFncErrorState HLCD_enumGoToXY(u8 u8Cpy_Row, u8 u8Cpy_Col, u8 u8Cpy_LCDNumber);
tenumFncErrorState HLCD_enumDisplayCustom(u8 u8Cpy_Location, u8* u8Cpy_String, u8 u8Cpy_LCDNumber);

#endif
