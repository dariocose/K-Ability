void bluetoothTask(void * parameter){  
  for(;;){
		if(bleMouse.isConnected() && !isConnected){
			isConnected = true;
      showOnDisplay("Connected","c[#]]^?=-_", TFT_WHITE, TFT_BLACK);
      vTaskResume(mouseTaskHandle);
    }
		else if(!bleMouse.isConnected() && isConnected) {
			isConnected = false;
      showOnDisplay("Device","disconnected", TFT_WHITE, TFT_BLUE);
      vTaskSuspend(mouseTaskHandle);
      delay(2000);
			esp_restart();
    }
    delay(BT_DELAY);
  }
}