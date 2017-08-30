class GVAR(RscFPod) {
	idd = UI_FPOD;
	movingEnable = true;
	enableSimulation = true;
	objects[] = {};
	onLoad = QUOTE(_this call FUNC(init));
	onUnLoad = QUOTE(_this call FUNC(exit));

	class controlsBackground  {
		class mainBackground : GVARMAIN(RscPicture) {
			colorBackground[] = COL_ABLACK(1);
			idc = -1;
            text = WALLPAPER;
            UIPOS(SCREEN_X1,SCREEN_Y1,SCREEN_X2,SCREEN_Y2);
		};
	};
	class controls {
		//////////////////////////////////////  ID CLASSES   /////////////////////////////////////////////////
        //=========================== Bottom Tab ====================================//
        class icon_play : GVARMAIN(RscPicture) {
            idc = UI_FPOD_IMAGE_PLAY;
            text = ICON_PLAY;
            BUTTON_PLAY_POS;
        };
        class icon_pause : GVARMAIN(RscPicture) {
            idc = UI_FPOD_IMAGE_PAUSE;
            text = ICON_PAUSE;
            BUTTON_PLAY_POS;
        };

        class data_title : GVARMAIN(RscStructuredText) {
            idc = UI_FPOD_INFO_TITLE;
            style = ST_RIGHT;
            font = "EtelkaNarrowMediumPro";
            sizeEx = 0.03;
            colorBackground[] = COL_NONE;
            colorText[] = COL_WHITE;
            text = "";
            UIPOS(BOTTOMTAB_X1,BOTTOMTAB_Y1,BOTTOMTAB_PLAY_X1,BOTTOMTAB_SLIDER_Y);
        };
        class data_artist : data_title {
            idc = UI_FPOD_INFO_ARTIST;
            style = ST_LEFT;
            text = "";
            UIPOS(BOTTOMTAB_PLAY_X2,BOTTOMTAB_Y1,BOTTOMTAB_X2,BOTTOMTAB_SLIDER_Y);
        };
        class data_currentTime : GVARMAIN(RscText) {
            idc = UI_FPOD_INFO_SONGTIME;
            font = "EtelkaNarrowMediumPro";
            sizeEx = 0.03;
            colorBackground[] = COL_NONE;
            colorText[] = COL_WHITE;
            style = ST_LEFT;
            text = "";
            UIPOS(BOTTOMTAB_X1,BOTTOMTAB_Y1,BOTTOMTAB_PLAY_X1,BOTTOMTAB_SLIDER_Y);
        };
        class data_endTime : data_currentTime {
            idc = UI_FPOD_INFO_SONGEND;
            style = ST_RIGHT;
            text = "";
            UIPOS(BOTTOMTAB_PLAY_X2,BOTTOMTAB_Y1,BOTTOMTAB_X2,BOTTOMTAB_SLIDER_Y);
        };

        class slider : GVARMAIN(RscSlider) {
			idc = UI_FPOD_SLIDER;
			text = "";
            tooltip = "";
            color[] = COL_WHITE;
            colorActive[] = COL_WHITE;
            colorDisabled[] = COL_WHITE;
			onSliderPosChanged = QUOTE(_this call FUNC(slider_changed));
            onMouseButtonDown = QUOTE(_this call FUNC(slider_down));
            onMouseButtonUp = QUOTE(_this call FUNC(slider_up));
			UIPOS(BOTTOMTAB_X1,BOTTOMTAB_SLIDER_Y,BOTTOMTAB_X2,BOTTOMTAB_Y2);
		};
        //============================= LISTS =======================================//
        class list_radio : GVARMAIN(RscListBox) {
			idc = UI_FPOD_RADIOLIST;
            style = ST_CENTER;
            //idcLeft= 1432;
            //idcRight= 1433;
			text = "";
			sizeEx = 0.042;
            rowHeight=0.07;
            font = FONT_LARGE;
			onLBSelChanged = QUOTE(_this call FUNC(radiolist_changed));
			UIPOS((BOX_X1+DIV_H),(BOX_Y1+DIV_H),(BOX_X2-DIV_H),(BOX_Y2-DIV_H));
		};

        class list_songs : GVARMAIN(RscListBox) {
            idc = UI_FPOD_SONGLIST;
            style = ST_LEFT;
            sizeEx = 0.032;
            rowHeight=0.035;
            onLBSelChanged = QUOTE(_this call FUNC(songlist_changed));
            UIPOS((BOX_X1+(DIV_H/8)),(BOX_Y1),(BOX_X2-(DIV_H/8)),(BOX_Y2));
        };

        class list_artists : GVARMAIN(RscTree) {
            idc = UI_FPOD_ARTISTLIST;
            UIPOS((BOX_X1+(DIV_H/8)),(BOX_Y1),(BOX_X2-(DIV_H/8)),(BOX_Y2));
            onTreeSelChanged = QUOTE(_this call FUNC(artistList_changed));
        };

        class list_playlists : list_artists {
            idc = UI_FPOD_PLAYLISTS;
            UIPOS((BOX_X1+(DIV_H/8)),(BOX_Y1),(BOX_X2-(DIV_H/8)),(BOX_Y2));
            onTreeSelChanged = QUOTE(_this call FUNC(playlist_changed));
        };

        //============================= TOP BAR =======================================//
        class icon_radio : GVARMAIN(RscPicture) {
            colorBackground[] = {0, 0, 0, 0.7};
			idc = UI_FPOD_IMAGE_RADIO;
            text = ICON_RADIO;
            UIPOS(TOPTAB_IMAGE_MID_X1,TOPTAB_IMAGE_TALL_Y1,TOPTAB_IMAGE_MID_X2,TOPTAB_IMAGE_TALL_Y2);
        };

        class icon_songs : icon_radio {
			idc = UI_FPOD_IMAGE_MUSIC;
			text = ICON_MUSIC;
            UIPOS(TOPTAB_IMAGE_LEFT_X1,TOPTAB_IMAGE_SHORT_Y1,TOPTAB_IMAGE_LEFT_X2,TOPTAB_IMAGE_SHORT_Y2);
        };

        class icon_artist : icon_radio {
			idc = UI_FPOD_IMAGE_ARTIST;
			text = ICON_MUSIC;
            UIPOS(TOPTAB_X2,TOPTAB_IMAGE_TINY_Y1,TOPTAB_X2,TOPTAB_IMAGE_TINY_Y2);
        };

        class icon_playlist : icon_artist {
			idc = UI_FPOD_IMAGE_PLAYLIST;
			text = ICON_MUSIC;
        };

        class icon_settings : icon_radio {
			idc = UI_FPOD_IMAGE_SETTINGS;
            text = ICON_SETTINGS;
            UIPOS(TOPTAB_IMAGE_RIGHT_X1,TOPTAB_IMAGE_SHORT_Y1,TOPTAB_IMAGE_RIGHT_X2,TOPTAB_IMAGE_SHORT_Y2);
        };

        class mode_type : GVARMAIN(RscText) {
            idc = UI_FPOD_MODE;
            type = 0;
            style = ST_CENTER;
            font = "EtelkaNarrowMediumPro";
            sizeEx = 0.06;
            colorBackground[] = COL_NONE; // {1,1,1,0.5};
            colorText[] = {1,1,1,1};
            text = "";
            UIPOS(TOPTAB_XL,(TOPTAB_IMAGE_TALL_Y2 - (DIV_H)),TOPTAB_XR,BOX_Y1);
        };
		/////////////////////////////////////////////   NON ID CLASSES    //////////////////////////////////////////////////

        class button_cycleLeft : GVARMAIN(RscButtonMenu) {
			idc = -1;
			text = "";
			onButtonClick = QUOTE(_this call FUNC(button_cycleLeft));
			UIPOS(TOPTAB_X1, TOPTAB_Y1, TOPTAB_X2, TOPTAB_Y2);
		};
        class button_cycleRight : button_cycleLeft {
			onButtonClick = QUOTE(_this call FUNC(button_cycleRight));
			UIPOS(TOPTAB_X2, TOPTAB_Y1, TOPTAB_X3, TOPTAB_Y2);
		};
        class button_playPause : button_cycleLeft {
			onButtonClick = QUOTE(_this call FUNC(button_playPause));
			BUTTON_PLAY_POS;
		};

        //SETTINGS
        class settings_text_shuffle : GVARMAIN(RscStructuredText) {
            idc = UI_FPOD_S_TEXT_SHUFFLE;
            font = "EtelkaNarrowMediumPro";
            sizeEx = 0.06;
            colorBackground[] = {1,1,1,0.5}; // COL_NONE;
            colorText[] = COL_WHITE;
            style = ST_LEFT;
            text = "Shuffle";
            SETTINGS_4(0.1,0.05,0.4,0.15);
        };
        class settings_list_shuffle : GVARMAIN(RscXListBox) {
            idc = UI_FPOD_S_LIST_SHUFFLE;
            colorBackground[] = COL_NONE;
            colorText[] = COL_WHITE;
            onLBSelChanged = QUOTE(_this call FUNC(toggleShuffle));
            SETTINGS_4(0.4,0.05,0.9,0.15);
        };

        class settings_text_volume : settings_text_shuffle {
            idc = UI_FPOD_S_TEXT_VOLUME;
            text = "Volume";
            SETTINGS_4(0.1,0.25,0.4,0.35);
        };
        class settings_slider_volume : GVARMAIN(RscSlider) {
			idc = UI_FPOD_S_SLIDER_VOLUME;
			text = "";
            tooltip = "";
            color[] = COL_WHITE;
            colorActive[] = COL_WHITE;
            colorDisabled[] = COL_WHITE;
			onSliderPosChanged = QUOTE(_this call FUNC(volume_changed));
            //onMouseButtonDown = QUOTE(_this call FUNC(slider_down));
            //onMouseButtonUp = QUOTE(_this call FUNC(slider_up));
			SETTINGS_4(0.4,0.25,0.9,0.35);
		};

        class settings_text_bluetooth : settings_text_shuffle {
            idc = UI_FPOD_S_TEXT_BLUETOOTH;
            text = "Bluetooth";
            SETTINGS_4(0.1,0.55,0.4,0.65);
        };
        class settings_list_bluetooth : settings_list_shuffle {
            idc = UI_FPOD_S_LIST_BLUETOOTH;
            onLBSelChanged = QUOTE(_this call FUNC(toggleBluetooth));
            SETTINGS_4(0.4,0.55,0.9,0.65);
        };
	};
};
