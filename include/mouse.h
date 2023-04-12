void mouseTask(void * parameter){
	byte up, down, left, right, cancel, select, enter;

	for(;;){
    if(isConnected){
      up    = touchRead(UP_BTN);
      down  = touchRead(DOWN_BTN);
      left  = touchRead(LEFT_BTN);
      right = touchRead(RIGHT_BTN);

      cancel = touchRead(CANCEL_BTN);
      select = touchRead(SELECT_BTN);
      enter  = touchRead(ENTER_BTN);

      if(up < T_TRASHOLD)
        log_d("up %i", up);

      if(down < T_TRASHOLD)
        log_e("down %i", down);

      if(left < T_TRASHOLD)
        log_i("left %i", left);

      if(right < T_TRASHOLD)
        log_n("right %i", right);

      if(cancel < T_TRASHOLD)
        log_v("cancel %i", cancel);

      if(select < T_TRASHOLD)
        log_d("select %i", select);

      if(enter < T_TRASHOLD)
        log_w("enter %i", enter);

      delay(T_DELAY);
    }
  }
}
