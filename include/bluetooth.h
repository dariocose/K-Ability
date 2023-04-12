void bluetoothTask(void * parameter){  
  bleMouse.begin();

  for(;;){
		if(bleMouse.isConnected() && !isConnected){
			isConnected = true;
      showOnDisplay("Connected","c[#]]^?=-_", TFT_WHITE, TFT_BLACK);
    }
		else if(!bleMouse.isConnected() && isConnected) {
			isConnected = false;
			showOnDisplay("Waiting for","connection...", TFT_WHITE, TFT_BLACK);
    }
  }
}