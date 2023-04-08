void showOnDisplay(const char *riga1,const char *riga2, uint16_t txtColor, uint16_t bgrColor){
    tft.fillScreen(bgrColor);

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