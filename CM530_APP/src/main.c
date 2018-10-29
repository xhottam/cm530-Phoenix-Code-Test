#include "stm32f10x_type.h"
#include "system_init.h"
#include "system_func.h"
#include "check.h"
#include "serial.h"
#include "adc.h"
#include "button.h"
#include "mux.h"
#include "wiring.h"

#define DEBUG_PRINT_VOLTAGE

byte option;
const int SERVOCOUNT = 18;
int id;



int main(void) {


	SysInit();
	BioloidControllerEx();
	servoScanningTest();
	adcPinSetup();
	MenuOptions();
	while (1) {

		option = RxDByte_PC();

		if (option == '0') {
			PrintString("\n###########################\n");
			PrintString("Servo Scanning.");
			PrintString("\n###########################\n");
			servoScanningTest();
			MenuOptions();
		} else if (option == '1') {
			PrintString("\n###########################\n");
			PrintString("Move.");
			PrintString("\n###########################\n");
			Move(ChoosePose());
			MenuOptions();
		} else if (option == '2') {
			PrintString("\n###########################\n");
			PrintString("Read MUX");
			PrintString("\n###########################\n");
			//TxD_Dec_U16(readPort());
			//TxD_Dec_U16(readIRsensor());
			accel_read_XYZ();
			MenuOptions();
		}else if (option == '3') {
			PrintString("\n###########################\n");
			PrintString("Read Sensors.");
			PrintString("\n###########################\n");
			SensorOptions();
			MenuOptions();
		}else if (option == '4') {
			PrintString("\n############################################\n");
			PrintString("SetRegOnAllServos. Relax Servos AX_SYNC_WRITE");
			PrintString("\n############################################\n");
			SetRegOnAllServos(AXM_TORQUE_ENABLE, 0);
			MenuOptions();
		} else if (option == '5') {
			PrintString("\n################################################\n");
			PrintString("SetRegOnAllServos. Torque ON Servos AX_SYNC_WRITE");
			PrintString("\n################################################\n");
			SetRegOnAllServos(AXM_TORQUE_ENABLE, 1);
			MenuOptions();
		} else if (option == '6') {
			PrintString("\n################################################\n");
			PrintString("SetRegOnAllServos. LED ON");
			PrintString("\n################################################\n");
			SetRegOnAllServos(AXM_LED, 1);
			MenuOptions();
		} else if (option == '7') {
			PrintString("\n################################################\n");
			PrintString("SetRegOnAllServos. LED OFF");
			PrintString("\n################################################\n");
			led(0);
			MenuOptions();
		} else if (option == '8') {
			PrintString("\n###########################\n");
			PrintString("Led Check.");
			PrintString("\n###########################\n");
			checkLeds();
			MenuOptions();
		} else if (option == '9') {
			PrintString("\n###########################\n");
			PrintString("Buzzer Check.");
			PrintString("\n###########################\n");
			BuzzedImperialMarch();
			MenuOptions();
		} else if (option == 'v') {
			PrintString("\n###########################\n");
			PrintString("Battery Check.");
			PrintString("\n###########################\n");
			Battery_Monitor_Alarm();
			MenuOptions();
		} else if (option == 'b') {
			PrintString("\n###########################\n");
			PrintString("Buttons Check.");
			PrintString("\n###########################\n");
			PrintString("Press : START , UP ,DOWN, LEFT, RIGHT\n");
			while (!ReadButton(START))
				;
			PrintString("START\n");
			while (!ReadButton(UP))
				;
			PrintString("UP\n");
			while (!ReadButton(DOWN))
				;
			PrintString("DOWN\n");
			while (!ReadButton(LEFT))
				;
			PrintString("LEFT\n");
			while (!ReadButton(RIGHT))
				;
			PrintString("RIGHT\n");
			MenuOptions();
		} else {
			PrintString("Opcion invalida\n");
		}

	}

	return 0;
}
