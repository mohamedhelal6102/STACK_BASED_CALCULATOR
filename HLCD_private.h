
#ifndef HLCD_PRIVATE_H_
#define HLCD_PRIVATE_H_


#define HLCD_u8FirstRowStart            ((u8)0b10000000)
#define HLCD_u8SecondRowStart           ((u8)0b11000000)

#define HLCD_u8FirstRow      	 	((u8)0)
#define HLCD_u8SecRow         		((u8)1)
#define HLCD_u8ThirdRow       		((u8)3)
#define HLCD_u8FourthRow         	((u8)4)

#define HLCD_u8FirstCol       ((u8)0)
#define HLCD_u8LastCol        ((u8)15)

#define HLCD_u8FirstCGRAMPos  ((u8)0)
#define HLCD_u8LastCGRAMPos   ((u8)8)

#define LCD_R0_COMMAND                0x80
#define LCD_R1_COMMAND                0xC0
#define LCD_R2_COMMAND                0x94
#define LCD_R3_COMMAND                0xD4



#endif /* HLCD_PRIVATE_H_ */
