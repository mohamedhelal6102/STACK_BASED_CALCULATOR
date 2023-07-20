
#ifndef MDIO_REGISTERS_H_
#define MDIO_REGISTERS_H_

typedef struct{
	u8 PIN_R;
	u8 DDR_R;
	u8 PORT_R;	
}DIO_R;

#define MDIOA	((volatile DIO_R*) 0x39)
#define MDIOB	((volatile DIO_R*) 0x36)
#define MDIOC	((volatile DIO_R*) 0x33)
#define MDIOD	((volatile DIO_R*) 0x30)

#endif /* MDIO_REGISTERS_H_ */
