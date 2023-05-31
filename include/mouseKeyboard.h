void controlButtons(int canc, int sel){
  if(canc == 1){
    deviceFuncState = MOVE_CLICK;
    refreshScreenState(deviceFuncState);
  }
  else if(sel == 1){
    deviceFuncState++;
    if(deviceFuncState > NUM_TOT)
      deviceFuncState = 1;
    
    log_e("deviceFuncState %i", deviceFuncState); 
    refreshScreenState(deviceFuncState);
  }
}

void move(int xDist, int yDist){
  if(xDist != 0 || yDist != 0){
    bleMouse.move(xDist*MOVE_RANGE, yDist*MOVE_RANGE);
  }
}

void click(int ent){
  if(ent == 1){
    bleMouse.click(MOUSE_LEFT);
    log_e("click");
  }
}

void doubleClick(int ent){
  if(ent == 1){
    bleMouse.click(MOUSE_LEFT);
    delay(DOUBLE_CLICK_DELAY);
    bleMouse.click(MOUSE_LEFT);
  }
}

void dragDrop(int ent){
  if(ent == 1 && !isPressed){
    bleMouse.press(MOUSE_LEFT);
    isPressed = true;
    showOnDisplay("DRAG_DROP","pressed", TFT_WHITE, TFT_BLACK);
  }
  else if(ent == 1 && isPressed){
    bleMouse.release(MOUSE_LEFT);
    isPressed = false;
    showOnDisplay("DRAG_DROP","not pressed", TFT_WHITE, TFT_BLACK);
  }
}

void scroll(int yDist){
  if(yDist != 0)
    bleMouse.move(0, 0, -yDist, 0);
}

void swipe(int xDist, int yDist){
  if(xDist != 0 || yDist != 0){
    bleMouse.press();
		delay(200);
		for(int i = 0; i < 10; i++) {
      bleMouse.move(xDist*4, yDist*4);
            //delay(5);
		}

    bleMouse.release();

		for (int i = 0; i < 10; i++) {
      bleMouse.move(-xDist*4, -yDist*4);
		}
    delay(500);  
  }
}

void mouseKeyboardTask(void * parameter){
	for(;;){
    if(isConnected){
      controlButtons(cancel, selectb);

      switch (deviceFuncState){
        case MOVE_CLICK:
          move(x, y);
          click(enter);
          break;

        case DOUBLE_CLICK:
          move(x, y);
          doubleClick(enter);
          break;      
        
        case DRAG_DROP:
          move(x, y);
          dragDrop(enter);
          break;     

        case SWIPE:
          swipe(x, y);
          break;      
        
        case SCROLL_ZOOM:
          scroll(y); //!moltiplicatore
          break;     

        default:
          break;
      }
    }
    delay(MKT_LOOP_DELAY);
  }
}
