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

TaskHandle_t mouseTaskHandle 	 = NULL;
TaskHandle_t batteryTaskHandle 	 = NULL;
TaskHandle_t bluetoothTaskHandle = NULL;
TaskHandle_t buttonsTaskHandle = NULL;

#define MYFONT &Roboto_Thin_24

TFT_eSPI tft = TFT_eSPI(TFT_WIDTH, TFT_HEIGHT); // Invoke custom library

BleMouse bleMouse("K-Ability", "Espressif", 77);

enum deviceFunctions deviceFuncState;
int x, y, cancel, selectb, enter = 0;

#include "display.h"
#include "battery.h"
#include "bluetooth.h"
#include "buttons.h"
#include "mouse.h"

void setup(){
	Serial.begin(115200);
	log_i("Start");

	startDisplay();
	bleMouse.begin();
	
	deviceFuncState = MOUSE;

	xTaskCreatePinnedToCore(bluetoothTask, "bluetoothTask", 2000, NULL, 2, &bluetoothTaskHandle,1);
	xTaskCreatePinnedToCore(mouseTask, 	 	"mouseTask", 	4000, NULL, 3, &mouseTaskHandle,   	1);
	xTaskCreatePinnedToCore(batteryTask, 	"batteryTask", 	2000, NULL, 1, &batteryTaskHandle, 	0);
	xTaskCreatePinnedToCore(buttonsTask, 	"buttonsTask", 	2000, NULL, 1, &buttonsTaskHandle, 	0);
	vTaskSuspend(mouseTaskHandle);
}

void loop() {
  vTaskDelete(NULL); 
}