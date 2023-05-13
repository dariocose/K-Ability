void move(int xDist, int yDist){
  if(xDist != 0 || yDist != 0)
    bleMouse.move(xDist*MOVE_RANGE, yDist*MOVE_RANGE);
}

void click(int ent){
  //int nowEnt = ent;
  //int preEnt
  

  if(ent == 1)
    bleMouse.click(MOUSE_LEFT);
}

void doubleClick(int ent){
  if(ent == 1){
    bleMouse.click(MOUSE_LEFT);
    delay(DOUBLE_CLICK_DELAY);
    bleMouse.click(MOUSE_LEFT);
  }
}

void mouseTask(void * parameter){
  Serial.print("++");
  Serial.print(isConnected);

	for(;;){
    if(isConnected){
      Serial.print("m");

      if(deviceFuncState == MOVE_CLICK){
        move(x, y);
        click(enter);
      } 
      else if(deviceFuncState == DOUBLE_CLICK){
              Serial.print("n");

        move(x, y);
        doubleClick(enter);
      }
          Serial.print("o");

      delay(T_DELAY);
    }
    else
      Serial.print("p");

  }
}
