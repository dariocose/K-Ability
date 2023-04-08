#include "Pin.h"
#include "Definitions.h"

#include <Arduino.h>

#include <TFT_eSPI.h> 
#include <SPI.h>
#include <Wire.h>
#include <BleMouse.h>
#include <BleKeyboard.h>

int vref =  1100;

TaskHandle_t displayTaskHandle 	 = NULL;
TaskHandle_t batteryTaskHandle 	 = NULL;
TaskHandle_t bluetoothTaskHandle = NULL;

#define MYFONT &Roboto_Thin_24

TFT_eSPI tft = TFT_eSPI(TFT_WIDTH, TFT_HEIGHT); // Invoke custom library

#include "display.h"
#include "bluetooth.h"
#include "battery.h"

void setup(){
	Serial.begin(115200);
	Serial.println("Start");


	tft.begin();
	tft.invertDisplay(1);
	tft.setRotation(1);
	showOnDisplay("Waiting for","connection...", TFT_WHITE, TFT_BLACK);
  	xTaskCreatePinnedToCore(batteryTask, "batteryTask", 2000, NULL, 1, &batteryTaskHandle, 0);

	// xTaskCreatePinnedToCore(bluetoothTask, "bluetoothTask", 2000, NULL, 1, &bluetoothTaskHandle, 1);
}

void loop() {
  vTaskDelete(NULL); 
}