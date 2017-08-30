#define COMPONENT fPod

#include "\x\fsh_radio\addons\main\script_mod.hpp"

#define DEBUG_MODE_FULL
#define RECOMPILE recompile = 1

#include "\x\fsh_radio\addons\main\script_macros.hpp"

#define FPOD_MODE   if (!(GVARMAIN(audioData) select 0 isEqualTo "local")) exitWith {}

#define UI_FPOD 580
#define UI_FPOD_SONGLIST 589
#define UI_FPOD_ARTISTLIST 590
#define UI_FPOD_PLAYLISTS 591
#define UI_FPOD_RADIOLIST 592
#define UI_FPOD_LIST_TITLE 593
#define UI_FPOD_INFO_TITLE 594
#define UI_FPOD_INFO_ARTIST 595
#define UI_FPOD_INFO_SONGTIME 596
#define UI_FPOD_INFO_SONGEND 597
#define UI_FPOD_SLIDER 598

#define UI_FPOD_IMAGE_MUSIC 600
#define UI_FPOD_IMAGE_RADIO 601
#define UI_FPOD_IMAGE_SETTINGS 602
#define UI_FPOD_IMAGE_PLAYLIST 603
#define UI_FPOD_IMAGE_ARTIST 604
#define UI_FPOD_IMAGE_PLAY 605
#define UI_FPOD_IMAGE_PAUSE 606

#define UI_FPOD_MODE 607

#define UI_FPOD_S_TEXT_SHUFFLE 608
#define UI_FPOD_S_LIST_SHUFFLE 609
#define UI_FPOD_S_TEXT_VOLUME 610
#define UI_FPOD_S_SLIDER_VOLUME 611
#define UI_FPOD_S_TEXT_BLUETOOTH 612
#define UI_FPOD_S_LIST_BLUETOOTH 613

#define UI_CYCLE_TIME 0.5

#define GET_UI_DATA \
    disableSerialization; \
    private _ui = uiNamespace getVariable "fPod"; \
    private _uiListRadio = _ui DisplayCtrl UI_FPOD_RADIOLIST; \
    private _uiListSongs = _ui DisplayCtrl UI_FPOD_SONGLIST; \
    private _uiListPlaylist = _ui DisplayCtrl UI_FPOD_PLAYLISTS; \
    private _uiListArtists = _ui DisplayCtrl UI_FPOD_ARTISTLIST; \
    private _uiIconSongs = _ui DisplayCtrl UI_FPOD_IMAGE_MUSIC; \
    private _uiIconRadio = _ui DisplayCtrl UI_FPOD_IMAGE_RADIO; \
    private _uiIconPlay = _ui DisplayCtrl UI_FPOD_IMAGE_PLAY; \
    private _uiIconPause = _ui DisplayCtrl UI_FPOD_IMAGE_PAUSE; \
    private _uiIconSettings = _ui DisplayCtrl UI_FPOD_IMAGE_SETTINGS; \
    private _uiIconPlaylist = _ui DisplayCtrl UI_FPOD_IMAGE_PLAYLIST; \
    private _uiIconArtist = _ui DisplayCtrl UI_FPOD_IMAGE_ARTIST; \
    private _uiInfoArtist = _ui DisplayCtrl UI_FPOD_INFO_ARTIST; \
    private _uiInfoSong = _ui DisplayCtrl UI_FPOD_INFO_TITLE; \
    private _uiInfoTime = _ui DisplayCtrl UI_FPOD_INFO_SONGTIME; \
    private _uiSettingsShuffle = _ui DisplayCtrl UI_FPOD_S_LIST_SHUFFLE; \
    private _uiSettingsVolume = _ui DisplayCtrl UI_FPOD_S_SLIDER_VOLUME; \
    private _uiSettingsBluetooth = _ui DisplayCtrl UI_FPOD_S_LIST_BLUETOOTH; \
    private _uiInfoEnd = _ui DisplayCtrl UI_FPOD_INFO_SONGEND; \
    private _uiSlider = _ui DisplayCtrl UI_FPOD_SLIDER; \
    private _uiMode = _ui DisplayCtrl UI_FPOD_MODE; \
    private _posSongs = ctrlPosition _uiIconSongs; \
    private _posPlaylist = ctrlPosition _uiIconPlaylist; \
    private _posRadio = ctrlPosition _uiIconRadio; \
    private _posArtist = ctrlPosition _uiIconArtist; \
    private _posSettings = ctrlPosition _uiIconSettings
