void bluetoothTask(void * parameter){  
  for(;;){
    bool bleConnected = bleMouse.isConnected();

		if(bleConnected && !isConnected){
			isConnected = true;
      showOnDisplay("Connected","c[#]]^?=-_", TFT_WHITE, TFT_BLACK);
      vTaskResume(mouseTaskHandle);
    }
		else if(!bleConnected && isConnected) {
			isConnected = false;
      showOnDisplay("Device","disconnected", TFT_WHITE, TFT_BLUE);
      vTaskSuspend(mouseTaskHandle);
      delay(2000);
			esp_restart();
    }
    delay(BT_DELAY);
  }
}