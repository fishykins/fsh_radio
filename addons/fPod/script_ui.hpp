//====================================================================================//
//====================================================================================//
#define UI_SIZE 0.7

#define DEFAULT	        QPATHTOF(UI\console\default.paa)
#define ICON_RADIO	    QPATHTOF(UI\console\icon_radio.paa)
#define ICON_MUSIC	    QPATHTOF(UI\console\icon_music.paa)
#define ICON_SETTINGS	QPATHTOF(UI\console\icon_settings.paa)
#define ICON_PAUSE	    QPATHTOF(UI\console\icon_pause.paa)
#define ICON_PLAY	    QPATHTOF(UI\console\icon_play.paa)
#define ICON_BOX	    QPATHTOF(UI\console\icon_box.paa)

#define WALLPAPER	    QPATHTOF(UI\console\wallpaper.paa)
#define DASHBOARD	    QPATHTOF(UI\console\dshboard.paa)


//====================================================================================//
//====================================================================================//
#define SCREEN_X1      (0.35 * UI_SIZE)
#define SCREEN_X2      (1 - SCREEN_X1)
#define SCREEN_Y1      (0.2 * UI_SIZE)
#define SCREEN_Y2      (1 - SCREEN_Y1)

#define SCREEN_H       HEIGHT(SCREEN_Y2,SCREEN_Y1)
#define SCREEN_W       WIDTH(SCREEN_X2,SCREEN_X1)

#define Y_DIV          8
#define DIV_H          (SCREEN_H/Y_DIV)

#define TOPTAB_X1      SCREEN_X1
#define TOPTAB_X2      (TOPTAB_X1 + (SCREEN_W/2))
#define TOPTAB_X3      SCREEN_X2
#define TOPTAB_Y1      SCREEN_Y1
#define TOPTAB_Y2      (SCREEN_Y1 + DIV_H)
#define TOPTAB_YMID    TOPTAB_Y1 + (HEIGHT(TOPTAB_Y2,TOPTAB_Y1)/2)
#define TOPTAB_W       (SCREEN_W/2)


#define BOX_X1 SCREEN_X1
#define BOX_X2 SCREEN_X2
#define BOX_Y1 (TOPTAB_Y2 + DIV_H/4)
#define BOX_Y2 BOTTOMTAB_Y1

#define BOTTOMTAB_X1   SCREEN_X1
#define BOTTOMTAB_X2   SCREEN_X2
#define BOTTOMTAB_Y1   (SCREEN_Y2 - DIV_H)
#define BOTTOMTAB_YMID (SCREEN_Y2 - (DIV_H/2))
#define BOTTOMTAB_Y2   (SCREEN_Y2)

#define BOTTOMTAB_WIDTH (WIDTH(BOTTOMTAB_X2,BOTTOMTAB_X1))

#define BOTTOMTAB_SLIDER_Y (SCREEN_Y2 - (DIV_H/4))

#define BOTTOMTAB_HEIGHT_MIN ((HEIGHT(BOTTOMTAB_SLIDER_Y,BOTTOMTAB_Y1))/2)


#define BOTTOMTAB_PLAY_X1 (TOPTAB_X2 - BOTTOMTAB_HEIGHT_MIN)
#define BOTTOMTAB_PLAY_X2 (TOPTAB_X2 + BOTTOMTAB_HEIGHT_MIN)


#define BUTTON_PLAY_POS     UIPOS(BOTTOMTAB_PLAY_X1,BOTTOMTAB_Y1,BOTTOMTAB_PLAY_X2,BOTTOMTAB_SLIDER_Y)

//====================================================================================//
//====================================================================================//

#define IMAGE_SIZE             (0.5 * DIV_H)
#define IMAGE_SIZE_S           (IMAGE_SIZE * 0.3)
#define IMAGE_SIZE_M           (IMAGE_SIZE * 0.5)
#define IMAGE_SIZE_L           (IMAGE_SIZE * 1)

#define TT_OFSET                    (SCREEN_W/4)
#define TOPTAB_XL                   (TOPTAB_X1 + TT_OFSET)
#define TOPTAB_XR                   (TOPTAB_X3 - TT_OFSET)

#define TOPTAB_IMAGE_MID_X1         (TOPTAB_X2 - IMAGE_SIZE_L)
#define TOPTAB_IMAGE_MID_X2         (TOPTAB_X2 + IMAGE_SIZE_L)

#define TOPTAB_IMAGE_LEFT_X1        (TOPTAB_XL - IMAGE_SIZE_S)
#define TOPTAB_IMAGE_LEFT_X2        (TOPTAB_XL + IMAGE_SIZE_S)

#define TOPTAB_IMAGE_RIGHT_X1       (TOPTAB_XR - IMAGE_SIZE_S)
#define TOPTAB_IMAGE_RIGHT_X2       (TOPTAB_XR + IMAGE_SIZE_S)

#define TOPTAB_IMAGE_TALL_Y1        (TOPTAB_YMID - IMAGE_SIZE_L)
#define TOPTAB_IMAGE_TALL_Y2        (TOPTAB_YMID + IMAGE_SIZE_L)
#define TOPTAB_IMAGE_SHORT_Y1       (TOPTAB_YMID - IMAGE_SIZE_M)
#define TOPTAB_IMAGE_SHORT_Y2       (TOPTAB_YMID + IMAGE_SIZE_M)
#define TOPTAB_IMAGE_TINY_Y1        (TOPTAB_YMID - IMAGE_SIZE_S)
#define TOPTAB_IMAGE_TINY_Y2        (TOPTAB_YMID + IMAGE_SIZE_S)


#define IMAGE_H           HEIGHT(TOPTAB_Y2,TOPTAB_Y1);
#define IMAGE_Y           TOPTAB_Y1;
#define IMAGE_MIDDLE_X    SCREEN_X1 + (0.5 * SCREEN_W) - (0.5 * IMAGE_W)
#define IMAGE_MIDDLE_M    0.02
#define IMAGE_LEFT_X      SCREEN_X1 + (0.2 * SCREEN_W) - (0.5 * IMAGE_W)
#define IMAGE_RIGHT_X     SCREEN_X1 + (0.8 * SCREEN_W) - (0.5 * IMAGE_W)


#define SETTINGS_X(_var1)       (SCREEN_X1 + (SCREEN_W * _var1))
#define SETTINGS_Y(_var2)       (BOX_Y1 + ((BOX_Y2 - BOX_Y1) * _var2))
#define SETTINGS_2(_var1,_var2)  SETTINGS_4(_var1,_var2,(_var1 + 0.4),(_var2 + 0.4))
#define SETTINGS_4(_var1,_var2,_var3,_var4)  UIPOS(SETTINGS_X(_var1),SETTINGS_Y(_var2),SETTINGS_X(_var3),SETTINGS_Y(_var4))

//====================================================================================//
//====================================================================================//
