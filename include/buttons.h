void buttonsTask(void * parameter){
	byte up_btn, down_btn, left_btn, right_btn, cancel_btn, select_btn, enter_btn = 100;

	for(;;){
    up_btn    = touchRead(UP_BTN);
    down_btn  = touchRead(DOWN_BTN);
    left_btn  = touchRead(LEFT_BTN);
    right_btn = touchRead(RIGHT_BTN);

    cancel_btn = touchRead(CANCEL_BTN);
    select_btn = touchRead(SELECT_BTN);
    enter_btn  = touchRead(ENTER_BTN);

    // vertical movement
    if(up_btn   < T_THRESHOLD){
      y=-1; 
      log_v("up_btn %i", up_btn); //!
    } 
    else if(down_btn < T_THRESHOLD){
      y= 1; 
      log_e("down_btn %i", down_btn); 
    } 
    else 
      y=0;

    // orizontal movement
    if(right_btn< T_THRESHOLD){
      x= 1; 
      log_w("right_btn %i", right_btn); //!
    } 
    else if(left_btn < T_THRESHOLD){
      x=-1; 
      log_n("left_btn %i", left_btn);   
    } 
    else 
      x=0;

    //function buttons
    //enter
    if(enter_btn< T_THRESHOLD){
      enter++; 
      log_v("enter_btn %i", enter_btn); 
    } 
    else 
      enter=0;
    
    //cancel
    if(cancel_btn < T_THRESHOLD){
      cancel++; 
      log_v("cancel_btn %i", cancel_btn); 
    } 
    else 
      cancel=0;

    //select
    if(select_btn < T_THRESHOLD){
      selectb++; 
      log_v("select_btn %i", select_btn); 
    } 
    else 
      selectb=0;
    
    delay(T_DELAY);
  }
}
