/*
 * mux.c
 *
 *  Created on: 5 Aug 2017
 *      Author: E1193262
 */


#include "mux.h"
#include "button.h"


// Raw Ranges:
// initialize to mid-range and allow calibration to
// find the minimum and maximum for each axis
/*u16 xRawMin = 0;
u16 xRawMax = 1151;

u16 yRawMin = 0;
u16 yRawMax = 1162;

u16 zRawMin = 0;
u16 zRawMax = 1416;*/

u16 xRawMin = 512;
u16 xRawMax = 1443;

u16 yRawMin = 464;
u16 yRawMax = 1436;

u16 zRawMin = 335;
u16 zRawMax = 1568;

// Take multiple samples to reduce noise
const u16 sampleSize = 3;

const u16 axis_X = 2;
const u16 axis_Y = 1;
const u16 axis_Z = 0;

int cero[] = {0,0,0,0}; //channel 0
int uno[] = {1,0,0,0}; //channel 1
int dos[] = {0,1,0,0}; //channel 2
int tres[] = {1,1,0,0}; //channel 3
int cuatro[] = {0,0,1,0}; //channel 4
int cinco[] = {1,0,1,0}; //channel 5
int seis[] = {0,1,1,0}; //channel 6
int siete[] = {1,1,1,0}; //channel 7
int ocho[] = {0,0,0,1}; //channel 8
int nueve[] = {1,0,0,1}; //channel 9
int diez[] = {0,1,0,1}; //channel 10
int once[] = {1,1,0,1}; //channel 11
int doce[] = {0,0,1,1}; //channel 12
int trece[] = {1,0,1,1}; //channel 13
int catorce[] = {0,1,1,1}; //channel 14
int quince[] = {1,1,1,1};  //channel 15


u16 mux(){
	PrintString("\n###########################\n");
	PrintString("\nPlease enter option 0-9.\n");
	PrintString("\n###########################\n");
	PrintString("\n###########################\n");
	PrintString("\nChannel ??");
	PrintString("\n###########################\n");

	u8 channel = (u8) RxDByte_PC();

	return ReadMUX(channel);
}
int muxChannel(int channel,int i){

    int temp = 0;
	switch(channel){
	case 0: temp = cero[i];break;
	case 1: temp = uno[i]; break;
	case 2: temp = dos[i]; break;
	case 3: temp = tres[i]; break;
	case 4: temp = cuatro[i]; break;
	case 5: temp = cinco[i]; break;
	case 6: temp = seis[i]; break;
	case 7: temp = siete[i]; break;
	case 8: temp = ocho[i]; break;
	case 9: temp = nueve[i]; break;
	case 10: temp = diez[i];break;
	case 11: temp = once[i]; break;
	case 12: temp = doce[i]; break;
	case 13: temp = trece[i]; break;
	case 14: temp = catorce[i]; break;
	case 15: temp = quince[i]; break;
	default: PrintString("mux.c muxChannel 'incorrect channel'");break;
	}
	return temp;
}
//##############################################################################
u16 ReadMUX(int channel) {


	  int controlPin[] = {0, 1, 2, 3};

/*	  int muxChannel[16][4]={
	    {0,0,0,0}, //channel 0
	    {1,0,0,0}, //channel 1
	    {0,1,0,0}, //channel 2
	    {1,1,0,0}, //channel 3
	    {0,0,1,0}, //channel 4
	    {1,0,1,0}, //channel 5
	    {0,1,1,0}, //channel 6
	    {1,1,1,0}, //channel 7
	    {0,0,0,1}, //channel 8
	    {1,0,0,1}, //channel 9
	    {0,1,0,1}, //channel 10
	    {1,1,0,1}, //channel 11
	    {0,0,1,1}, //channel 12
	    {1,0,1,1}, //channel 13
	    {0,1,1,1}, //channel 14
	    {1,1,1,1}  //channel 15
	  };*/

	  //int muxChannel[16][4]={0,0,0,0,1,0,0,0,0,1,0,0,1,1,0,0,0,0,1,0,1,0,1,0,0,1,1,0,1,1,1,0,0,0,0,1,1,0,0,1,0,1,0,1,1,1,0,1,0,0,1,1,1,0,1,1,0,1,1,1,1,1,1,1};


	  //loop through the 4 sig
	  int i;
	  for( i = 0 ; i < 4; i ++){
	    //digitalWrite(controlPin[i], muxChannel[channel][i]);
		SetEPort(controlPin[i], muxChannel(channel,i));
		//mDelay(5);
	  }

	    //mDelay(10);

	  // Select EPORT1A and EPORT4A via multiplexer
		GPIO_ResetBits(PORT_ADC_SELECT0, PIN_ADC_SELECT0);
		GPIO_ResetBits(PORT_ADC_SELECT1, PIN_ADC_SELECT1);

		mDelay(10);

		ADC_SoftwareStartConvCmd(ADC1, ENABLE);
		mDelay(5);
		u16 temp = (u16) (ADC_GetConversionValue(ADC1));

	   //read the value at the SIG pin
	  //int val = analogRead(SIG_pin);

	  //return the value

	  return temp;
}

//#################################################################################
int accel_ReadAxis(const int axisChannel)
{
  long reading = 0;
  ReadMUX(axisChannel);
  mDelay(1);
  int i;
  for (i = 0; i < sampleSize; i++)
  {
    reading += ReadMUX(axisChannel);
  }
  return reading/sampleSize;
}
//
// Find the extreme raw readings from each axis
//
void accel_AutoCalibrate(u16 xRaw, u16 yRaw, u16 zRaw)
{
  PrintString("Calibrate");
  if (xRaw < xRawMin)
  {
    xRawMin = xRaw;
  }
  if (xRaw > xRawMax)
  {
    xRawMax = xRaw;
  }

  if (yRaw < yRawMin)
  {
    yRawMin = yRaw;
  }
  if (yRaw > yRawMax)
  {
    yRawMax = yRaw;
  }

  if (zRaw < zRawMin)
  {
    zRawMin = zRaw;
  }
  if (zRaw > zRawMax)
  {
    zRawMax = zRaw;
  }
  TxD_Dec_U16(xRawMin);
  TxD_Dec_U16(xRawMax);
  TxD_Dec_U16(yRawMin);
  TxD_Dec_U16(yRawMax);
  TxD_Dec_U16(zRawMin);
  TxD_Dec_U16(zRawMax);
}

u16 accel_read_X(){

	u16 temp  = accel_ReadAxis(axis_X);
	//Convert raw values to 'milli-Gs"
	//long xScaled = map(temp, xRawMin, xRawMax, -1000, 1000);
	temp =  map(temp, xRawMin, xRawMax, 0, 512);
	// re-scale to fractional Gs
	//float xAccel = xScaled / 1000.0;
/*	PrintString("Raw Ranges: X: \n");
	TxD_Dec_U16(xRawMin);
	PrintString("-");
	TxD_Dec_U16(xRawMax);
	TxD_Dec_U16(temp);*/
	//Printu32d(xAccel);
	return temp;
}
u16 accel_read_Y(){
	u16 temp  = accel_ReadAxis(axis_Y);

	// Convert raw values to 'milli-Gs"
	//long yScaled = map(temp, yRawMin, yRawMax, -1000, 1000);
	temp =  map(temp, yRawMin, yRawMax, 0, 512);
	// re-scale to fractional Gs
	//float yAccel = yScaled / 1000.0;
/*	PrintString("Raw Ranges: Y: \n");
	TxD_Dec_U16(yRawMin);
	PrintString("-");
	TxD_Dec_U16(yRawMax);
	TxD_Dec_U16(temp);*/
	return temp;
}
u16 accel_read_Z(){
	u16 temp  = accel_ReadAxis(axis_Z);

	// Convert raw values to 'milli-Gs"
	//long zScaled = map(temp, zRawMin, zRawMax, -1000, 1000);
	temp =  map(temp, zRawMin, zRawMax, 0, 512);
	// re-scale to fractional Gs
	//float zAccel = zScaled / 1000.0;
/*	PrintString("Raw Ranges: Z: \n");
	TxD_Dec_U16(zRawMin);
	PrintString("-");
	TxD_Dec_U16(zRawMax);
	TxD_Dec_U16(temp);*/
	return temp;
}

void accel_read_XYZ(){

	u16 xTemp;
	u16 yTemp;
	u16 zTemp;
	u16 proximity_4;
	u16 proximity_5;
	u16 proximity_6;
	u16 proximity_7;


	while (!ReadButton(START)){
		xTemp = accel_read_X();
		yTemp = accel_read_Y();
		zTemp = accel_read_Z();

		proximity_4= proximity_read(4);
		proximity_5= proximity_read(5);
		proximity_6= proximity_read(6);
		proximity_7= proximity_read(7);

		TxD_Dec_U16(xTemp);
		TxD_Dec_U16(yTemp);
		TxD_Dec_U16(zTemp);
		TxD_Dec_U16(proximity_4);
		TxD_Dec_U16(proximity_5);
		TxD_Dec_U16(proximity_6);
		TxD_Dec_U16(proximity_7);
		PrintString("\n");
		//accel_AutoCalibrate(xTemp,yTemp,zTemp);

	}


}

//#################################################################################

u16 proximity_read(int channel){

	return ReadMUX(channel);

}


//#################################################################################
