/*
9 * check.c
 *
 *  Created on: 12 Jul 2017
 *      Author: E1193262
 */

#include "check.h"
#include "button.h"

unsigned int Center[] = {18, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512, 512};

u16 _xRawMin = 2000;
u16 _xRawMax = 1000;

u16 _yRawMin = 2000;
u16 _yRawMax = 1000;

u16 _zRawMin = 2000;
u16 _zRawMax = 1000;

u16 _xRaw,_yRaw,_zRaw;


//##############################################################################
void MenuOptions(void) {
	PrintString("\n###########################\n");
	PrintString("\nPlease enter option [0-9v-b] to run individual tests again.\n");
	PrintString("\n0) Servo Scanning Test\n");
	PrintString("\n1) Move Servos to Center\n");
	PrintString("\n2) MUX");
	PrintString("\n3) Read Sensors\n");
	PrintString("\n4) SetRegOnAllServos. Relax Servos AX_SYNC_WRITE\n");
	PrintString("\n5) SetRegOnAllServos. Torque ON Servos AX_SYNC_WRITE\n");
	PrintString("\n6) SetRegOnAllServos. LED ON\n");
	PrintString("\n7) SetRegOnAllServos. LED OFF\n");
	PrintString("\n8) Led Check.\n");
	PrintString("\n9) Buzzer Check\n");
	PrintString("\nv) Battery Check\n");
	PrintString("\nb) Perform BUTTON Test\n");
	PrintString("\n###########################\n");
}
//##############################################################################
void SensorOptions(void) {
	PrintString("\n###########################\n");
	PrintString("\nPlease enter option 0-5 to run individual tests again.\n");
	PrintString("\n0) Right IR Sensor\n");
	PrintString("\n1) Left IR Sensor\n");
	PrintString("\n2) DMS Sensor\n");
	PrintString("\n3) AutoCalibrate ADXL335\n");
	PrintString("\n4) Gyro Sensor: X\n");
	PrintString("\n5) Gyro Sensor: Y\n");
	PrintString("\n###########################\n");
	PrintString("\n###########################\n");
	PrintString("\nSensor ??");
	PrintString("\n###########################\n");

	u8 sensor = (u8) RxDByte_PC();

	if (sensor == '0'){
		Printu32d(ReadIR(EPORT1A));
	}else if (sensor == '1'){
		Printu32d(ReadIR(EPORT2A));
	}else if (sensor == '2'){
		Printu32d(ReadAnalog(EPORT5A));
	}else if (sensor == '3'){
		//GyroSensor();
		//AutoCalibrate_ADXL335();
		Accel_AXIS_Options();
	}else if (sensor == '4'){
		Printu32d(ReadAnalog(EPORT3A));
	}else if (sensor == '5'){
		Printu32d(ReadAnalog(EPORT4A));

	}else{
		PrintString("Opcion invalida\n");
	}



}
//##############################################################################
void Accel_AXIS_Options(void) {
	PrintString("\n###########################\n");
	PrintString("\nPlease enter option 0-2 to run individual autocalibration again.\n");
	PrintString("\n0) X axis\n");
	PrintString("\n1) Y axis\n");
	PrintString("\n2) Z axis\n");
	PrintString("\n3) Take samples\n");
	PrintString("\n###########################\n");
	PrintString("\n###########################\n");
	PrintString("\Axis ??");
	PrintString("\n###########################\n");

	u8 sensor = (u8) RxDByte_PC();

	if (sensor == '0'){
		AutoCalibrate_ADXL335(0);
	}else if (sensor == '1'){
		AutoCalibrate_ADXL335(1);
	}else if (sensor == '2'){
		AutoCalibrate_ADXL335(2);
	}else if (sensor == '3'){
			TakeSample_ADXL335();
	}else{
		PrintString("Opcion invalida\n");
	}
}
//##############################################################################
void BuzzedImperialMarch() {
	PrintString("\n###########################\n");
	PrintString("\n9) octave ??");
	PrintString("\n###########################\n");

	u8 octava = (u8) RxDByte_PC();
	PrintChar(octava);
	PrintString("\n");
	Printu8h(octava);
	PrintString("\n");
	if (octava > '0' && octava < '9') {
		PlayNote(500, NOTE_A, octava);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(500, NOTE_A, octava);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(500, NOTE_A, octava);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(350, NOTE_F, octava);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(150, NOTE_C, octava + 1);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(500, NOTE_A, octava);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(350, NOTE_F, octava);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(150, NOTE_C, octava + 1);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(1000, NOTE_A, octava);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		//end of first bit

		PlayNote(500, NOTE_E, octava + 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(500, NOTE_E, octava + 1);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(500, NOTE_E, octava + 1);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(350, NOTE_F, octava + 1);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(150, NOTE_C, octava + 1);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(500, NOTE_Gs, octava);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(350, NOTE_F, octava);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(150, NOTE_C, octava + 1);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(1000, NOTE_A, octava);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		//second bit...

		PlayNote(500, NOTE_A, octava + 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(350, NOTE_A, octava);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(150, NOTE_A, octava);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(500, NOTE_A, octava + 1);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(250, NOTE_Gs, octava + 1);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(250, NOTE_G, octava + 1);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(125, NOTE_Fs, octava + 1);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(125, NOTE_F, octava + 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(250, NOTE_Fs, octava + 1);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(270);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(250, NOTE_As, octava);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(500, NOTE_Ds, octava + 1);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(250, NOTE_D, octava + 1);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(250, NOTE_Cs, octava + 1);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		//start of the interesting bit

		PlayNote(125, NOTE_C, octava + 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(125, NOTE_B, octava);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(250, NOTE_C, octava + 1);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(270);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(125, NOTE_F, octava);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(500, NOTE_Gs, octava);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(375, NOTE_F, octava);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(125, NOTE_A, octava);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(500, NOTE_C, octava + 1);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(375, NOTE_A, octava);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(125, NOTE_C, octava + 1);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(1000, NOTE_E, octava + 1);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);

		//more interesting stuff (this doesn't quite get it right somehow)
		PlayNote(500, NOTE_A, octava + 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(350, NOTE_A, octava);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(150, NOTE_A, octava);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(500, NOTE_A, octava + 1);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(250, NOTE_Gs, octava + 1);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(250, NOTE_G, octava + 1);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);

		PlayNote(125, NOTE_Fs, octava + 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(125, NOTE_F, octava + 1);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(250, NOTE_Fs, octava + 1);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(270);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(250, NOTE_As, octava);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(500, NOTE_Ds, octava + 1);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(250, NOTE_D, octava + 1);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);
		PlayNote(250, NOTE_Cs, octava + 1);
		SetRegOnAllServos(AXM_LED, 0);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 1);

		//repeat.... repeat ..

		PlayNote(125, NOTE_C, octava + 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(125, NOTE_B, octava);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(250, NOTE_C, octava + 1);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(270);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(250, NOTE_F, octava);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(500, NOTE_Gs, octava);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(375, NOTE_F, octava);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(125, NOTE_C, octava + 1);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);


		PlayNote(500, NOTE_A, octava);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(375, NOTE_F, octava);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(125, NOTE_C, octava);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
		PlayNote(1000, NOTE_A, octava);
		SetRegOnAllServos(AXM_LED, 1);
		mDelay(20);
		SetRegOnAllServos(AXM_LED, 0);
	} else {
		BuzzedImperialMarch();
	}

}
//##############################################################################
void checkLeds(void) {
	// Reset the LEDs
	SetLED(TXD, 0);
	SetLED(RXD, 0);
	SetLED(AUX, 0);

	SetLED(MANAGE, 0);
	SetLED(PROGRAM, 0);
	SetLED(PLAY, 0);

	mDelay(1000);

	SetLED(TXD, 1);
	SetLED(RXD, 1);
	SetLED(AUX, 1);

	SetLED(MANAGE, 1);
	SetLED(PROGRAM, 1);
	SetLED(PLAY, 1);

	mDelay(1000);

	SetLED(TXD, 0);
	SetLED(RXD, 0);
	SetLED(AUX, 0);

	SetLED(MANAGE, 0);
	SetLED(PROGRAM, 0);
	SetLED(PLAY, 0);

}
//##############################################################################
void servoScanningTest(void) {
	u8 id, num = 0;
	u16 wdata;
	u16 error = 0;
	for (id = 1; id < (19); id++) {
		wdata = (dxl_read_byte(id, P_ID) & 0x00FF);
		if (wdata == id) {
			wdata = 0;
			num++;
			PrintString("{");
			Printu32d(id);
			PrintString(", ");

			wdata = dxl_read_word(id, P_MODEL_NUMBER_L);
			error = dxl_get_result();
			if (!(error & DXL_RXSUCCESS))
				PrintCommStatus(error);
			Printu32d(wdata);
			if (wdata == MODEL_AX12) {
				PrintString(" (AX-12)");
			} else if (wdata == MODEL_AX18) {
				PrintString(" (AX-18)");
			} else if (wdata == MODEL_AXS1) {
				PrintString(" (AX-S1)");
			} else if (wdata == MODEL_AXS20) {
				PrintString(" (AX-S20)");
			} else if (wdata == MODEL_JHFPS) {
				PrintString(" (JH-FPS)");
			} else if (wdata == MODEL_MX28) {
				PrintString(" (MX-28)");
			} else if (wdata == MODEL_HaViMo2) {
				PrintString(" (HaViMo2)");
			}

			PrintString(", ");
			Printu32d(dxl_read_byte(id, P_FIRMWARE_VERSION));
			PrintString("} \n");
		}
	}
	PrintString("\nDXL DEVICES:");
	Printu32d(num);
	PrintString("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

}
//##############################################################################
void Move(unsigned int pose[]) {

	BioloidControllerEx_loadPose(pose);
	BioloidControllerEx_readPose();
	BioloidControllerEx_interpolateSetup(1000);
	while(interpolating > 0){  // do& this while we have not reached our new pose
		BioloidControllerEx_interpolateStep(TRUE);     // move servos, if necessary.
	    mDelay(3);
	}
  }
//################################################################################
//--------------------------------------------------------------------
//[SetRegOnAllServos] Function that is called to set the state of one
//  register in all of the servos, like Torque on...
//--------------------------------------------------------------------
void SetRegOnAllServos(u8 bReg, u8 bVal) {

	// Need to first output the header for the Sync Write
	/*int length = 4 + (NUMSERVOS * 2);   // 2 = id + val
	 int checksum = 254 + length + AX_SYNC_WRITE + 1 + bReg;
	 setTXall();
	 ax12write(0xFF);
	 ax12write(0xFF);
	 ax12write(0xFE);
	 ax12write(length);
	 ax12write(AX_SYNC_WRITE);
	 ax12write(bReg);
	 ax12write(1);    // number of bytes per servo (plus the ID...)
	 for (int i = 0; i < NUMSERVOS; i++) {
	 byte id = pgm_read_byte(&cPinTable[i]);
	 checksum += id + bVal;
	 ax12write(id);
	 ax12write(bVal);

  }*/

	dxl_set_txpacket_id (BROADCAST_ID);
	dxl_set_txpacket_instruction(INST_SYNC_WRITE);
	dxl_set_txpacket_parameter(0,bReg);
	dxl_set_txpacket_parameter(1,1);
    int i;
	for (i = 0; i < poseSize; i++) {
		byte id = pgm_read_byte(&cPinTable[i]);
		dxl_set_txpacket_parameter(2 + 2 * i, id);
		dxl_set_txpacket_parameter(2 + 2 * i + 1, (bVal));
	}

	dxl_set_txpacket_length((1+1)*poseSize+4);
	dxl_txrx_packet();

	u16 CommStatus = dxl_get_result();

#ifdef USING_PC_UART
	if (CommStatus == DXL_RXSUCCESS)
		PrintErrorCode();
	else
		PrintCommStatus(CommStatus);
#endif
}
//#########################################################################
void led(u8 state) {

	int i;

	for (i = 0; i < poseSize; i++) {
		byte id = pgm_read_byte(&cPinTable[i]);
		dxl_write_byte(id,AXM_LED, state);

	}

}
//##########################################################################
u16 readPort(void){

       PrintString("\n###########################\n");
       PrintString("\nEPortA_e ??");
       PrintString("\n###########################\n");

       u8 port = (u8) RxDByte_PC();

       u16 temp = 0x8000;


       if ((port == '0') || (port == '3')) {


    	   	  //GPIO_SetBits(PORT_SIG_MOT1P, PIN_SIG_MOT1P);
    	   	  //GPIO_ResetBits(PORT_SIG_MOT1M, PIN_SIG_MOT1M);


              //uDelay(30);

              // Select EPORT1A and EPORT4A via multiplexer
              GPIO_ResetBits(PORT_ADC_SELECT0, PIN_ADC_SELECT0);
              GPIO_ResetBits(PORT_ADC_SELECT1, PIN_ADC_SELECT1);

              uDelay(10);

              if (port == '0') {
                     // Start ADC1 Software Conversion
                     ADC_SoftwareStartConvCmd(ADC1, ENABLE);
                     uDelay(5);// IRSENSOR
                     temp = (u16) (ADC_GetConversionValue(ADC1));

                     uDelay(10);// IRSENSOR

                     GPIO_ResetBits(PORT_SIG_MOT1P, PIN_SIG_MOT1P);
                     GPIO_ResetBits(PORT_SIG_MOT1M, PIN_SIG_MOT1M);

              } else {
                     // Start ADC2 Software Conversion
                     ADC_SoftwareStartConvCmd(ADC2, ENABLE);
                     uDelay(10);
                     temp = (u16) (ADC_GetConversionValue(ADC2));

                     GPIO_ResetBits(PORT_SIG_MOT4P, PIN_SIG_MOT4P);
                     GPIO_ResetBits(PORT_SIG_MOT4M, PIN_SIG_MOT4M);

              }
       } else if ((port == '1') || (port == '4')) {

    	   	  GPIO_SetBits(PORT_SIG_MOT2P, PIN_SIG_MOT2P);
    	   	  GPIO_ResetBits(PORT_SIG_MOT2M, PIN_SIG_MOT2M);


              uDelay(30);

              // Select EPORT2A and EPORT5A via multiplexer
              GPIO_SetBits(PORT_ADC_SELECT0, PIN_ADC_SELECT0);
              GPIO_ResetBits(PORT_ADC_SELECT1, PIN_ADC_SELECT1);

              uDelay(10);

              if (port == '1') {
                     // Start ADC1 Software Conversion
                     ADC_SoftwareStartConvCmd(ADC1, ENABLE);
                     uDelay(5);// IRSENSOR
                     temp = (u16) (ADC_GetConversionValue(ADC1));

                     uDelay(5);// IRSENSOR

                     GPIO_ResetBits(PORT_SIG_MOT2P, PIN_SIG_MOT2P);
                     GPIO_ResetBits(PORT_SIG_MOT2M, PIN_SIG_MOT2M);

              } else {
                     // Start ADC2 Software Conversion
                     ADC_SoftwareStartConvCmd(ADC2, ENABLE);
                     uDelay(10);
                     temp = (u16) (ADC_GetConversionValue(ADC2));

                     GPIO_ResetBits(PORT_SIG_MOT5P, PIN_SIG_MOT5P);
                     GPIO_ResetBits(PORT_SIG_MOT5M, PIN_SIG_MOT5M);

              }
       } else if ((port == '2') || (port == '5')) {


              uDelay(30);

              // Select EPORT3A and EPORT6A via multiplexer
              GPIO_ResetBits(PORT_ADC_SELECT0, PIN_ADC_SELECT0);
              GPIO_SetBits(PORT_ADC_SELECT1, PIN_ADC_SELECT1);

              uDelay(10);

              if (port == '2') {
                     // Start ADC1 Software Conversion
                     ADC_SoftwareStartConvCmd(ADC1, ENABLE);
                     uDelay(10);
                     temp = (u16) (ADC_GetConversionValue(ADC1));

                     GPIO_ResetBits(PORT_SIG_MOT3P, PIN_SIG_MOT3P);
                     GPIO_ResetBits(PORT_SIG_MOT3M, PIN_SIG_MOT3M);

              } else {
                     // Start ADC2 Software Conversion
                     ADC_SoftwareStartConvCmd(ADC2, ENABLE);
                     uDelay(10);
                     temp = (u16) (ADC_GetConversionValue(ADC2));

                     GPIO_ResetBits(PORT_SIG_MOT6P, PIN_SIG_MOT6P);
                     GPIO_ResetBits(PORT_SIG_MOT6M, PIN_SIG_MOT6M);

              }
       } else if (port == '6') {
              u16 temp;

              // Set ADC1 to read SIG_VDD/VBUS on Channel 13
              ADC_RegularChannelConfig(ADC1, ADC_Channel_13, 1,
              ADC_SampleTime_239Cycles5);
              uDelay(5);
              ADC_SoftwareStartConvCmd(ADC1, ENABLE);
              uDelay(5);
              temp = (ADC_GetConversionValue(ADC1));

              // Set ADC1 to read SIG_ADC0 (ADC1 multiplexer output) on Channel 10
              ADC_RegularChannelConfig(ADC1, ADC_Channel_10, 1,
              ADC_SampleTime_239Cycles5);
              uDelay(5);

		return temp;
	}else {
		PrintString("Opcion invalida\n");
	}
	return temp;
}
//##########################################################################
u16 readIRsensor(){
    // Select EPORT1A and EPORT4A via multiplexer
    GPIO_ResetBits(PORT_ADC_SELECT0, PIN_ADC_SELECT0);
    GPIO_ResetBits(PORT_ADC_SELECT1, PIN_ADC_SELECT1);
    uDelay(10);

    // Start ADC1 Software Conversion
   ADC_SoftwareStartConvCmd(ADC1, ENABLE);
   uDelay(5);// IRSENSOR
   return (u16) (ADC_GetConversionValue(ADC1));

}
//##########################################################################
void adcPinSetup(void){


/**	GPIO_ResetBits(PORT_SIG_MOT3P,PIN_SIG_MOT3P);
	GPIO_ResetBits(PORT_SIG_MOT3M,PIN_SIG_MOT3M);
	GPIO_ResetBits(PORT_SIG_MOT4P,PIN_SIG_MOT4P);
	GPIO_ResetBits(PORT_SIG_MOT4M,PIN_SIG_MOT4M);
	GPIO_ResetBits(PORT_SIG_MOT5P,PIN_SIG_MOT5P);
	GPIO_ResetBits(PORT_SIG_MOT5M,PIN_SIG_MOT5M);
	GPIO_ResetBits(PORT_SIG_MOT6P,PIN_SIG_MOT6P);
	GPIO_ResetBits(PORT_SIG_MOT6M,PIN_SIG_MOT6M);

	GPIO_ResetBits(PORT_SIG_MOT1P,PIN_SIG_MOT1P);
	GPIO_ResetBits(PORT_SIG_MOT1M,PIN_SIG_MOT1M);
	GPIO_ResetBits(PORT_SIG_MOT2P,PIN_SIG_MOT2P);
	GPIO_ResetBits(PORT_SIG_MOT2M,PIN_SIG_MOT2M);


	SetEPort(0, 0);
	SetEPort(1, 0);
	SetEPort(2, 0);
	SetEPort(3, 0);*/

	GPIO_SetBits(PORT_SIG_MOT2P,PIN_SIG_MOT2M);

}
//##########################################################################
u16 irSensorRight(){

	u16 temp;

	GPIO_SetBits(PORT_SIG_MOT1P, PIN_SIG_MOT1P);
	GPIO_ResetBits(PORT_SIG_MOT1M, PIN_SIG_MOT1M);

	// Select EPORT1A and EPORT4A via multiplexer
	GPIO_ResetBits(PORT_ADC_SELECT0, PIN_ADC_SELECT0);
	GPIO_ResetBits(PORT_ADC_SELECT1, PIN_ADC_SELECT1);

	//uDelay(30);
	mDelay(10);

	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	mDelay(5);// IRSENSOR
	temp = (u16) (ADC_GetConversionValue(ADC1));

	uDelay(5);// IRSENSOR

	GPIO_ResetBits(PORT_SIG_MOT1P, PIN_SIG_MOT1P);
	GPIO_ResetBits(PORT_SIG_MOT1M, PIN_SIG_MOT1M);

	return temp;
}
//##########################################################################
u16 irSensorLeft(){
	u16 temp;

	GPIO_SetBits(PORT_SIG_MOT2P, PIN_SIG_MOT2P);
	GPIO_ResetBits(PORT_SIG_MOT2M, PIN_SIG_MOT2M);

	// Select EPORT2A and EPORT5A via multiplexer
	GPIO_SetBits(PORT_ADC_SELECT0, PIN_ADC_SELECT0);
	GPIO_ResetBits(PORT_ADC_SELECT1, PIN_ADC_SELECT1);

	uDelay(30);

	// Start ADC1 Software Conversion
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	uDelay(5);// IRSENSOR
	temp = (u16) (ADC_GetConversionValue(ADC1));

	uDelay(5);// IRSENSOR

	GPIO_ResetBits(PORT_SIG_MOT2P, PIN_SIG_MOT2P);
	GPIO_ResetBits(PORT_SIG_MOT2M, PIN_SIG_MOT2M);

	return temp;

}
//##########################################################################
u16 DmsSensor(){

	// Select EPORT2A and EPORT5A via multiplexer
	GPIO_SetBits(PORT_ADC_SELECT0, PIN_ADC_SELECT0);
	GPIO_ResetBits(PORT_ADC_SELECT1, PIN_ADC_SELECT1);
    mDelay(10);
	// Start ADC1 Software Conversion
	ADC_SoftwareStartConvCmd(ADC2, ENABLE);
	mDelay(40);
	return (u16) ((ADC_GetConversionValue(ADC2))>>2);

}
//##########################################################################
void GyroSensor(void){

	TxD_Dec_U16(GyroSensorX());
	TxD_Dec_U16(GyroSensorY());
}
//##########################################################################
u16 GyroSensorX(void){
	u16 temp= 0;
    int i;
	// Select EPORT3A and EPORT6A via multiplexer
	GPIO_ResetBits(PORT_ADC_SELECT0, PIN_ADC_SELECT0);
	GPIO_SetBits(PORT_ADC_SELECT1, PIN_ADC_SELECT1);
	mDelay(10);

	for (i=0 ; i< 10; i++){
		// Start ADC1 Software Conversion
		ADC_SoftwareStartConvCmd(ADC1, ENABLE);
		mDelay(40);
		temp = temp + ((u16) (ADC_GetConversionValue(ADC1))>>2);

	}

	return temp/10;

}
//###########################################################################
void AutoCalibrate_ADXL335(int axi){

	PrintString(" AutoCalibrate_ADXL335 \n");


	while (!ReadButton(START)){
		if (axi ==  0 ){
			_xRaw  =  ReadAnalog(EPORT3A);
			if (_xRaw < _xRawMin)
			{
			   _xRawMin = _xRaw;
			}
			if (_xRaw > _xRawMax)
			{
			    _xRawMax = _xRaw;
			 }
		}
		if ( axi ==   1){
			_yRaw   = ReadAnalog(EPORT4A);
			 if (_yRaw < _yRawMin)
			 {
			    _yRawMin = _yRaw;
			 }
			 if (_yRaw > _yRawMax)
			  {
				 _yRawMax = _yRaw;
			  }
		}
		if ( axi ==  2 ){
			_zRaw  = ReadAnalog(EPORT2A);
			 if (_zRaw < _zRawMin)
			 {
			    _zRawMin = _zRaw;
			 }
			 if (_zRaw > _zRawMax)
			 {
			   _zRawMax = _zRaw;
			 }
		}
	}
	if (axi == 0 ){
		PrintString("Raw Ranges: X: \n");
			TxD_Dec_U16(_xRawMin);
			PrintString(" - ");
			TxD_Dec_U16(_xRawMax);
			PrintString("\n");
	}
	if (axi == 1){
		PrintString("Raw Ranges: Y: \n");
		TxD_Dec_U16(_yRawMin);
		PrintString(" - ");
		TxD_Dec_U16(_yRawMax);
		PrintString("\n");
	}
	if ( axi == 2){
		PrintString("Raw Ranges: Z: \n");
		TxD_Dec_U16(_zRawMin);
		PrintString(" - ");
		TxD_Dec_U16(_zRawMax);
		PrintString("\n");
	}
}
//###########################################################################
void TakeSample_ADXL335(){

	while (!ReadButton(START)){
		TxD_Dec_S16(ReadAnalog(EPORT3A));
		PrintString(" - ");
		TxD_Dec_S16(ReadAnalog(EPORT4A));
		PrintString(" - ");
		TxD_Dec_S16(ReadAnalog(EPORT2A));
		PrintString("\n");

		mDelay(50);
	}

}
//###########################################################################
u16 GyroSensorY(void){

	u16 temp= 0;
	int i;
	// Select EPORT1A and EPORT4A via multiplexer
	GPIO_ResetBits(PORT_ADC_SELECT0, PIN_ADC_SELECT0);
	GPIO_ResetBits(PORT_ADC_SELECT1, PIN_ADC_SELECT1);
	mDelay(10);

	for (i = 0; i < 10; i++) {
		// Start ADC1 Software Conversion
		ADC_SoftwareStartConvCmd(ADC2, ENABLE);
		mDelay(40);
		temp = temp + ((u16) (ADC_GetConversionValue(ADC2))>>2);
	}
	return temp / 10;

}
//#############################################################################
unsigned int * ChoosePose(void){

	PrintString("\n###########################\n");
	PrintString("\nPlease enter option 0-5 to run individual tests again.\n");
	PrintString("\n0) Center\n");
	PrintString("\n###########################\n");
	PrintString("\n###########################\n");
	PrintString("\nPose ??");
	PrintString("\n###########################\n");

	u8 pose = (u8) RxDByte_PC();

	if ( pose == '0') {

		return Center;

	}else {
		PrintString("Opcion invalida\n");
	}

	return 0;
}



