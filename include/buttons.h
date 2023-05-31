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

    //*arrows
    // vertical movement
    if(up_btn   < T_THRESHOLD)
      y=-1;
    else if(down_btn < T_THRESHOLD)
      y= 1; 
    else 
      y=0;

    // orizontal movement
    if(right_btn< T_THRESHOLD)
      x= 1; 
    else if(left_btn < T_THRESHOLD)
      x=-1; 
    else 
      x=0;

    //*function buttons
    //enter
    if(enter_btn< T_THRESHOLD)
      enter++; 
    else 
      enter=0;
    
    //cancel
    if(cancel_btn < T_THRESHOLD)
      cancel++; 
    else 
      cancel=0;

    //select
    if(select_btn < T_THRESHOLD)
      selectb++; 
    else 
      selectb=0;

    delay(T_DELAY);
  }
}
