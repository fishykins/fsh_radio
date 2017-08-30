#define UI_SIZE 0.7
//====================================================================================//
//====================================================================================//

#define WALLPAPER	    QPATHTOF(data\wallpaper2.paa)
#define DASHBOARD	    QPATHTOF(data\skin.paa)

//====================================================================================//
//====================================================================================//

#define CONSOLE_X1 0
#define CONSOLE_Y1 0
#define CONSOLE_X2 1
#define CONSOLE_Y2 1

#define CONSOLE_W WIDTH(CONSOLE_X2,CONSOLE_X1)
#define CONSOLE_H HEIGHT(CONSOLE_Y2,CONSOLE_Y1)

#define SCREEN_OFFSET_X (CONSOLE_W * 0.315)

#define SCREEN_X1 (CONSOLE_X1 + SCREEN_OFFSET_X)
#define SCREEN_X2 (CONSOLE_X2 - SCREEN_OFFSET_X)
#define SCREEN_Y1 (CONSOLE_Y1 + (CONSOLE_W * 0.105))
#define SCREEN_Y2 (CONSOLE_Y2 - (CONSOLE_W * 0.395))

#define SCREEN_W WIDTH(SCREEN_X2,SCREEN_X1)
#define SCREEN_H HEIGHT(SCREEN_Y2,SCREEN_Y1)

#define SCREEN_DIV_X    16
#define SCREEN_DIV_Y    16

#define SCN_D_X  (SCREEN_W/SCREEN_DIV_X)
#define SCN_D_Y  (SCREEN_H/SCREEN_DIV_Y)

#define OFX(var1)  (SCN_D_X * var1)
#define OFY(var1)  (SCN_D_Y * var1)

//====================================================================================//
//====================================================================================//

#define TOPTAB_Y1 (SCREEN_Y1 + OFY(1))
#define TOPTAB_Y2 (SCREEN_Y1 + OFY(3))

#define BOTTOMTAB_Y1 (SCREEN_Y2 - OFY(4))
#define BOTTOMTAB_Y2 (SCREEN_Y2 - OFY(1))

#define STATION_LIST_X1 (SCREEN_X1 + OFX(1))
#define STATION_LIST_X2 (SCREEN_X2 - OFX(1))
#define STATION_LIST_Y1 (TOPTAB_Y2 + OFY(1))
#define STATION_LIST_Y2 (BOTTOMTAB_Y1 - OFY(1))

//Top tab

#define OF_1 1
#define OF_2 5
#define OF_3 5.5

#define BUTTON_SETTINGS_X1 (SCREEN_X1 + OFX(OF_1))
#define BUTTON_SETTINGS_X2 (SCREEN_X1 + OFX(OF_2))

#define BUTTON_RADIO_X1 (SCREEN_X1 + OFX(OF_3))
#define BUTTON_RADIO_X2 (SCREEN_X2 - OFX(OF_3))

#define BUTTON_AUX_X1 (SCREEN_X2 - OFX(OF_2))
#define BUTTON_AUX_X2 (SCREEN_X2 - OFX(OF_1))

//Bottom Tab

#define INFO_X1 STATION_LIST_X1
#define INFO_X2 STATION_LIST_X2

//Icons

#define ICON_Y1 (SCREEN_Y1)
#define ICON_Y2 (SCREEN_Y1 + OFY(1))


#define AUX_ICON_X1 (SCREEN_X2 - OFX(OF_1))
#define AUX_ICON_X2 (SCREEN_X2)

#define AUX_TIME_X1 (SCREEN_X1)
#define AUX_TIME_X2 (SCREEN_X1 + OFX(OF_3))
