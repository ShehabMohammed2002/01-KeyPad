/*
 *  File : KeyPad_prg.h
 *  DATE: þ9/9/2022
 *  Author: Shehab aldeen
 *  Version : V1
 *  Describtion : --------------
 */
#include<util/delay.h>
#include"../LIB/STD_TYPES.h"
#include"../LIB/Bit_math.h"
#include"KeyPad_interface.h"
#include"KeyPad_cfg.h"
#include"KeyPad_Private.h"

void KeyPad_VidInit(void){

if ( 4 == KEYPAD_NUM_COL ){
	/*to define first 4 pins as inputs for rows
	and second 4 pins as output for columns*/
	DIO_VidSetPortDirection( KEYPAD_PORT , 0xf0 ) ;

	/*to active Pull_up_resistor for 4 pins input for rows
	and output high on columns*/
	DIO_VidSetPortValue( KEYPAD_PORT , 0xff );
     }//end if

else if (  3 == KEYPAD_NUM_COL ){

/*to define first 3 pins as inputs for rows
and second 3 pins as output for columns*/
DIO_VidSetPortDirection( KEYPAD_PORT , 0x28 );

/*to active Pull_up_resistor for 3 pins input for rows
and output high on columns*/
DIO_VidSetPortValue( KEYPAD_PORT , 0x3f );
      }//end else if
}


u8 KeyPad_U8GetNUM (void){
	u8 local_key = 50 ;
	for (u8 C=0 ; C<KEYPAD_NUM_COL ; C++){
		DIO_VidSetPinValue( KEYPAD_PORT , C+KEYPAD_NUM_COL , LOW ) ;
		for (u8 R=0 ; R<KEYPAD_NUM_ROW ; R++){
			u8 pressed = DIO_U8GetPinValue(KEYPAD_PORT,R);
			if (LOW == pressed )
			{
				local_key = (KEYPAD_NUM_ROW*R)+C ;
				while(LOW == pressed)
				{
				    pressed = DIO_U8GetPinValue(KEYPAD_PORT,R) ;
				}//end while loop
				_delay_ms(5);
			}//end if loop
		}//end 1st for loop
	DIO_VidSetPinValue( KEYPAD_PORT , C+KEYPAD_NUM_COL , HIGH );
	}//end 2nd for loop
	return local_key ;
}//end FUNC KeyPad_U8GetNUM
