/*
 * check.h
 *
 *  Created on: 12 Jul 2017
 *      Author: E1193262
 */

#ifndef CM530_APP_INC_CHECK_H_
#define CM530_APP_INC_CHECK_H_

#include "stm32f10x_type.h"
#include "serial.h"
#include "mic.h"
#include "system_func.h"
#include "led.h"
#include "BioloidEx.h"
#include "wiring.h"
#include "Hex_cfg.h"
#include "adc.h"
#include "system_init.h"


void MenuOptions(void);
void SensorOptions(void);
void BuzzedImperialMarch(void);
void servoScanningTest(void);
void checkLeds(void);
void Move(unsigned int pose[]);
void SetRegOnAllServos(u8 bReg, u8 bVal);
void led(u8 state);
u16 readPort(void);
void adcPinSetup(void);
u16 irSensorRight(void);
u16 irSensorLeft(void);
u16 DmsSensor(void);
void GyroSensor(void);
u16 GyroSensorX(void);
u16 GyroSensorY(void);
unsigned int * ChoosePose(void);
u16 readIRsensor(void);



#endif /* CM530_APP_INC_CHECK_H_ */
