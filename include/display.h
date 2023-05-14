void showOnDisplay(const char *riga1,const char *riga2, uint16_t txtColor, uint16_t bgrColor){
  tft.fillScreen(bgrColor);
  Serial.println("tft: " + String(riga1) +" "+String(riga2));

  //tESTO
  tft.setTextSize(1);
  tft.setTextColor(txtColor);
  tft.setCursor(0, 0);
  tft.setTextDatum(TL_DATUM);
  tft.setFreeFont(MYFONT);     
  tft.drawString(riga1,   10, 10);
  tft.drawString(riga2,   10, 40);
  //Selettore
  // for (size_t i = 0; i < 6; i++){
  //     byte xd = MARGIN_X + 11 + (i*10) + (i*28);
  //     if(i != curGesture)
  //         tft.fillRect(xd, MARGIN_Y + 121, 28, 6, txtColor);
  // }
  //Batteria
  tft.drawRect(TFT_HEIGHT-30,      14, 18,   9, txtColor);
  tft.fillRect(TFT_HEIGHT-30,      15, 18/2, 7, txtColor); //%batteria
  tft.fillRect(TFT_HEIGHT-30+18,   16, 2,    5, txtColor);

  // changeScreen = false;
}

void refreshScreenState(int rs){

  switch (deviceFuncState){
    case MOVE_CLICK:
      showOnDisplay("Mouse","click", TFT_WHITE, TFT_BLACK);
      break;

    case DOUBLE_CLICK:
      showOnDisplay("Mouse","Double click", TFT_WHITE, TFT_BLACK);
      break;      
    
    case DRAG_DROP:
      showOnDisplay("DRAG_DROP","wip", TFT_WHITE, TFT_BLACK);
      break;   

    case SWIPE:
      showOnDisplay("SWIPE","wip", TFT_WHITE, TFT_BLACK);
      break;   

    case SCROLL:
      showOnDisplay("SCROLL","wip", TFT_WHITE, TFT_BLACK);
      break;   

    case KEYBOARD:
      showOnDisplay("KEYBOARD","wip", TFT_WHITE, TFT_BLACK);
      break;   

    default:
      break;
  }
}

void startDisplay(){
  Serial.println("Start display");

	tft.begin();
	tft.invertDisplay(1);
	tft.setRotation(1);

	if (TFT_BL > 0) { // TFT_BL has been set in the TFT_eSPI library in the User Setup file TTGO_T_Display.h
		pinMode(TFT_BL, OUTPUT); // Set backlight pin to output mode
		digitalWrite(TFT_BL, TFT_BACKLIGHT_ON); // Turn backlight on. TFT_BACKLIGHT_ON has been set in the TFT_eSPI library in the User Setup file TTGO_T_Display.h
	}
  showOnDisplay("Waiting for","connection...", TFT_WHITE, TFT_BLACK);
}