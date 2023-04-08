void bluetoothTask(void * parameter){
	for(;;){
		if(bleMouse.isConnected() && !isConnected) {
			isConnected = true;
			vTaskResume(mouseTaskHandle);
			// changeScreen = true;
    } 
		else if(!bleMouse.isConnected() && isConnected) {
			isConnected = false;
			vTaskSuspend(mouseTaskHandle);
			showOnDisplay("Waiting for","connection...", TFT_WHITE, TFT_BLACK);
    }
		delay(1000);
	}
}