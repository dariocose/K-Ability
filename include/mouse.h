void move(int xDist, int yDist, int ent){
  if(isConnected && (xDist != 0 || yDist != 0 || ent != 0)){
    bleMouse.move(xDist*MOVE_RANGE, yDist*MOVE_RANGE);
    if(ent == 1) //!
      bleMouse.click(MOUSE_LEFT);
  }
}

void mouseTask(void * parameter){

	for(;;){
    
    if(deviceFuncState == MOUSE && (x!=0 || y!=0 || enter!=0))
      move(x, y, enter);
    
    delay(T_DELAY);
  }
}
