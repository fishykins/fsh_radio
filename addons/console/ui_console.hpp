class GVAR(RscConsole) {
	idd = UI_CSL;
	movingEnable = false;
	enableSimulation = true;
	objects[] = {};
	onLoad = QUOTE(_this call FUNC(init));
	onUnLoad = QUOTE(_this call FUNC(exit));

	class controlsBackground  {
        class background_dash : GVARMAIN(RscPicture) {
			idc = -1;
			text = DASHBOARD;
			UIPOS(CONSOLE_X1,CONSOLE_Y1,CONSOLE_X2,CONSOLE_Y2);
		};
        class background_screen : GVARMAIN(RscPicture) {
			colorBackground[] = COL_BLACK;
            idc = -1;
            text = WALLPAPER;
			UIPOS(SCREEN_X1,SCREEN_Y1,SCREEN_X2,SCREEN_Y2);
		};
	};
    //====================================================================================//
    //====================================================================================//
	class controls {
        class radio_list : GVARMAIN(RscListBox) {
			idc = UI_CSL_RADIO_LIST;
            style = ST_CENTER;
            //idcLeft= 1432;
            //idcRight= 1433;
			text = "";
			sizeEx = 0.042;
            rowHeight=0.07;
            font = FONT_LARGE;
			onLBSelChanged = QUOTE(_this call FUNC(radio_list_changed));
			UIPOS(STATION_LIST_X1,STATION_LIST_Y1,STATION_LIST_X2,STATION_LIST_Y2);
		};
        class aux_info : GVARMAIN(RscStructuredText) {
            idc = UI_CSL_AUX_INFO;
            text = "waiting for input...";
            UIPOS(STATION_LIST_X1,STATION_LIST_Y1,STATION_LIST_X2,STATION_LIST_Y2);
        };
        //====================================================================================//
        //Icons
        class aux_icon : GVARMAIN(RscPicture) {
            idc = UI_CSL_AUX_ICON;
            text = ICON_JACK;
            UIPOS(AUX_ICON_X1,ICON_Y1,AUX_ICON_X2,ICON_Y2);
        };
        class display_time : GVARMAIN(RscText) {
            idc = UI_CSL_TIME;
            text = "";
            colorBackground[] = COL_AWHITE(0);
            sizeEx = CONSOLE_H * 0.029;
            UIPOS(AUX_TIME_X1,ICON_Y1,AUX_TIME_X2,ICON_Y2);
        };
        //====================================================================================//
        //Top Tab
        class disp_settings : GVARMAIN(RscText) {
            idc = UI_CSL_SETTINGS;
            colorBackground[] = COL_AWHITE(0);
            sizeEx = CONSOLE_W * 0.041;
            style = ST_CENTER;
            text = "Settings";
            UIPOS(BUTTON_SETTINGS_X1,TOPTAB_Y1,BUTTON_SETTINGS_X2,TOPTAB_Y2);
        };
        class disp_radio : disp_settings {
            idc = UI_CSL_RADIO;
            text = "Radio";
            UIPOS(BUTTON_RADIO_X1,TOPTAB_Y1,BUTTON_RADIO_X2,TOPTAB_Y2);
        };
        class disp_aux : disp_settings {
            idc = UI_CSL_AUX;
            text = "AUX";
            UIPOS(BUTTON_AUX_X1,TOPTAB_Y1,BUTTON_AUX_X2,TOPTAB_Y2);
        };
        class disp_highligher : GVARMAIN(RscText) {
            idc = UI_CSL_HIGHLIGHTER;
            style = ST_FRAME;
            colorText[] = COL_PROFILE_BRIGHT;
            colorBackground[] = COL_AWHITE(0);
            text = "";
            UIPOS(BUTTON_RADIO_X1,TOPTAB_Y1,BUTTON_RADIO_X2,TOPTAB_Y2);
        };
        //====================================================================================//
        class button_settings : GVARMAIN(RscButtonMenu) {
            idc = -1;
            onButtonClick = QUOTE(_this call FUNC(button_settings));
            text = "";
            UIPOS(BUTTON_SETTINGS_X1,TOPTAB_Y1,BUTTON_SETTINGS_X2,TOPTAB_Y2);
        };
        class button_radio : button_settings {
            onButtonClick = QUOTE(_this call FUNC(button_radio));
            UIPOS(BUTTON_RADIO_X1,TOPTAB_Y1,BUTTON_RADIO_X2,TOPTAB_Y2);
        };
        class button_aux : button_settings {
            onButtonClick = QUOTE(_this call FUNC(button_aux));
            UIPOS(BUTTON_AUX_X1,TOPTAB_Y1,BUTTON_AUX_X2,TOPTAB_Y2);
        };

        //====================================================================================//
        //====================================================================================//
        //Bottom Tab
        class info : GVARMAIN(RscText) {
            idc = UI_CSL_RADIO_INFO;
            colorBackground[] = COL_WHITE;
            text = "Info";
            UIPOS(INFO_X1,BOTTOMTAB_Y1,INFO_X2,BOTTOMTAB_Y2);
        };
	};

};
