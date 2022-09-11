/*
 *  File : KeyPad_Interface.h
 *  DATE: þ9/9/2022
 *  Author: Shehab aldeen
 *  Version : V1
 *  Describtion : --------------
 */
#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"
 
 #ifndef KEYPAD_INTERFACE_H_
 #define KEYPAD_INTERFACE_H_

void KeyPad_VidInit(void);
u8 KeyPad_U8GetNUM (void);
u8 KeyPad_U8Num(u8 num);
 
 #endif
