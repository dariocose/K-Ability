void move(int xDist, int yDist, int ent){
  if(isConnected && (xDist != 0 || yDist != 0 || ent != 0)){
    bleMouse.move(xDist*MOVE_RANGE, yDist*MOVE_RANGE);
    if(ent == 1) //!
      bleMouse.click(MOUSE_LEFT);
  }
}

void mouseTask(void * parameter){
	byte up_btn, down_btn, left_btn, right_btn, cancel_btn, select_btn, enter_btn = 100;
  int x, y, cancel, select, enter = 0;

	for(;;){
    up_btn    = touchRead(UP_BTN);
    down_btn  = touchRead(DOWN_BTN);
    left_btn  = touchRead(LEFT_BTN);
    right_btn = touchRead(RIGHT_BTN);

    cancel_btn = touchRead(CANCEL_BTN);
    select_btn = touchRead(SELECT_BTN);
    enter_btn  = touchRead(ENTER_BTN);

    if(up_btn   < T_TRASHOLD){y=-1; log_d("up_btn %i", up_btn); } 
    else if(down_btn < T_TRASHOLD){y= 1; log_e("down_btn %i", down_btn); } 
    else y=0;

    if(right_btn< T_TRASHOLD){x= 1; log_i("right_btn %i", right_btn); } 
    else if(left_btn < T_TRASHOLD){x=-1; log_n("left_btn %i", left_btn);   } 
    else x=0;

    if(enter_btn< T_TRASHOLD){enter=1; log_v("enter_btn %i", enter_btn); } else {enter=0;}

    if(cancel_btn < T_TRASHOLD)
      log_w("cancel_btn %i", cancel_btn);

    if(select_btn < T_TRASHOLD)
      log_w("select_btn %i", select_btn);

    move(x, y, enter);
    delay(T_DELAY);
  }
}
