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

//! controllare
void doubleClick(int ent){
  if(ent == 1){
    bleMouse.click(MOUSE_LEFT);
    delay(DOUBLE_CLICK_DELAY);
    bleMouse.click(MOUSE_LEFT);
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
      
      default:
        break;
      }
    }
    delay(T_DELAY);
  }
}
