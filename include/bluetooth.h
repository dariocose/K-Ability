void bluetoothTask(void * parameter){  
  for(;;){
    bool bleConnected = bleMouse.isConnected();

		if(bleConnected && !isConnected){
			isConnected = true;
      showOnDisplay("Connected","c[#]]^?=-_", TFT_WHITE, TFT_BLACK);
      delay(1000);
      vTaskResume(mouseKeyboardTaskHandle);
      showOnDisplay("Mouse","click", TFT_WHITE, TFT_BLACK);
    }
		else if(!bleConnected && isConnected) {
			isConnected = false;
      showOnDisplay("Device","disconnected", TFT_WHITE, TFT_BLUE);
      vTaskSuspend(mouseKeyboardTaskHandle);
      delay(2000);
			esp_restart();
    }
    delay(BT_DELAY);
  }
}