/*
 * mux.h
 *
 *  Created on: 5 Aug 2017
 *      Author: E1193262
 */

#ifndef CM530_HW_INC_MUX_H_
#define CM530_HW_INC_MUX_H_

#include "stm32f10x_type.h"
#include "led.h"
#include "wiring.h"
#include "stm32f10x_gpio.h"
#include "adc.h"
#include "system_init.h"
#include "system_func.h"
#include "serial.h"
#include "wiring.h"





u16 ReadMUX(int channel);
u16 mux();


u16 accel_read_X(void);
u16 accel_read_Y(void);
u16 accel_read_Z(void);
int accel_ReadAxis(const int axisChannel);
void accel_AutoCalibrate(u16 xRaw, u16 yRaw, u16 zRaw);
int muxChannel(int channel,int i);

u16 proximity_read(int channel);

#endif /* CM530_HW_INC_MUX_H_ */
