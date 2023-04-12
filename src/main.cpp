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

#define MYFONT &Roboto_Thin_24

TFT_eSPI tft = TFT_eSPI(TFT_WIDTH, TFT_HEIGHT); // Invoke custom library

BleMouse bleMouse;

#include "display.h"
#include "battery.h"
#include "bluetooth.h"
#include "mouse.h"

void setup(){
	Serial.begin(115200);
	log_i("Start");

	startDisplay();

	xTaskCreatePinnedToCore(bluetoothTask,	"bluetoothTask",2000, NULL, 3, &bluetoothTaskHandle,1);
	xTaskCreatePinnedToCore(mouseTask, 	 	"mouseTask", 	2000, NULL, 2, &mouseTaskHandle,   	0);
	xTaskCreatePinnedToCore(batteryTask, 	"batteryTask", 	2000, NULL, 1, &batteryTaskHandle, 	0);
}

void loop() {
  vTaskDelete(NULL); 
}