#define CURRENT_FIRMWARE_TITLE    "k_ability_frmwr"
#define CURRENT_FIRMWARE_VERSION  "0.0.1"

//*bluetooth.h
#define BT_DELAY 1000

//*buttons.h
#define T_THRESHOLD 40  //Touch buttons threshold
#define T_DELAY 10 //Touch buttons delay >1 ; affects buttons reactivity

//*battery.h
#define BATTERY_DELAY 30000U

//*mouseKeyboard.h
#define MKT_LOOP_DELAY  10
#define MOVE_RANGE 6  //output range of X or Y movement; affects movement speed
#define DOUBLE_CLICK_DELAY 100

//gestures
#define CONFIG        0
#define MOVE_CLICK    1
#define DOUBLE_CLICK  2
#define DRAG_DROP     3
#define SWIPE         4
#define SCROLL_ZOOM   5
#define KEYBOARD      6

#define NUM_TOT 7