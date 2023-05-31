#include "Pin.h"
#include "Definitions.h"

#include <Arduino.h>

#include <TFT_eSPI.h> 
#include <SPI.h>
#include <Wire.h>
#include <BleMouse.h>
#include <BleKeyboard.h>

int vref =  1100;
bool isConnected = false;

TaskHandle_t mouseKeyboardTaskHandle 	 = NULL;
TaskHandle_t batteryTaskHandle 	 = NULL;
TaskHandle_t bluetoothTaskHandle = NULL;
TaskHandle_t buttonsTaskHandle = NULL;

#define MYFONT &Roboto_Thin_24

TFT_eSPI tft = TFT_eSPI(TFT_WIDTH, TFT_HEIGHT);

BleMouse bleMouse("K-Ability", "Espressif", 77);

int deviceFuncState;
int x, y, cancel, selectb, enter = 0;
bool isPressed = false;

#include "display.h"
#include "battery.h"
#include "bluetooth.h"
#include "buttons.h"
#include "mouseKeyboard.h"

void setup(){
	Serial.begin(115200);
	Serial.println("Start");

	startDisplay();
	bleMouse.begin();
	
	deviceFuncState = MOVE_CLICK;

	xTaskCreatePinnedToCore(bluetoothTask, 			"bluetoothTask",			2000, NULL, 2, &bluetoothTaskHandle,			1);
	xTaskCreatePinnedToCore(mouseKeyboardTask,	"mouseKeyboardTask",	4000, NULL, 3, &mouseKeyboardTaskHandle,	1);
	xTaskCreatePinnedToCore(batteryTask, 	 			"batteryTask",				2000, NULL, 1, &batteryTaskHandle,				0);
	xTaskCreatePinnedToCore(buttonsTask, 	 			"buttonsTask",				2000, NULL, 1, &buttonsTaskHandle,				0);
	vTaskSuspend(mouseKeyboardTaskHandle);

	log_e("log_e");
	log_i("log_i");
	log_n("log_n");
	log_w("log_w");
}

void loop() {
  vTaskDelete(NULL); 
}