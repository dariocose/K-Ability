void controlButtons(int canc, int sel){
  if(canc == 1){
    deviceFuncState = MOVE_CLICK;
    refreshScreenState(deviceFuncState);
  }
  else if(sel == 1){
    deviceFuncState++;
    if(deviceFuncState > 6)
      deviceFuncState = 0;
    
    refreshScreenState(deviceFuncState);
  }
}

void move(int xDist, int yDist){
  if(xDist != 0 || yDist != 0)
    bleMouse.move(xDist*MOVE_RANGE, yDist*MOVE_RANGE);
}

void click(int ent){
  if(ent == 1){
    bleMouse.click(MOUSE_LEFT);
    log_e("click");
  }
}

//! controllare
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

void mouseTask(void * parameter){

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

      default:
        break;
      }
    }
    delay(T_DELAY);
  }
}
