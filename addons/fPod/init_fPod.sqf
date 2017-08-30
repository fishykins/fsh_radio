#include "script_component.hpp"
//------------------------------Variables----------------------------------//

GVAR(isOpen) = false;  //True if looking at fPod
GVAR(isOn) = false;  //True if fpod is on
GVAR(cycling) = false;
GVAR(paused) = false;
GVAR(pauseData) = [];
GVAR(pauseTime) = -1;
GVAR(sliderClicked) = false;
GVAR(sliderPos) = -1;
GVAR(volume) = 0.5;
GVAR(modes) = [
    ["Radio",[UI_FPOD_RADIOLIST]],
    ["Songs",[UI_FPOD_SONGLIST]],
    ["Artists",[UI_FPOD_ARTISTLIST]],
    ["Playlists",[UI_FPOD_PLAYLISTS]],
    ["Settings",[UI_FPOD_S_TEXT_SHUFFLE,UI_FPOD_S_LIST_SHUFFLE,UI_FPOD_S_SLIDER_VOLUME,UI_FPOD_S_TEXT_VOLUME,UI_FPOD_S_TEXT_BLUETOOTH,UI_FPOD_S_LIST_BLUETOOTH]]
];
GVAR(modesCopy) = +GVAR(modes);

//------------------------------All Songs---------------------------------//

GVAR(bisSongs) = ["","BIS"] call cba_fnc_findMusic;
GVAR(allSongs) = ["song",""] call cba_fnc_findMusic; _songs = _allSongs - _bisMusic;
GVAR(songs) = +GVAR(allSongs) - GVAR(bisSongs);

//-------------------------Predefined Playlists---------------------------//
GVAR(playlists) = [];
GVAR(playlists) pushBack ["Stealth", ["","stealth"] call cba_fnc_findMusic];
GVAR(playlists) pushBack ["Action", ["","action"] call cba_fnc_findMusic];

//------------------------------ARTISTS-----------------------------------//
GVAR(artists) = [];
GVAR(artists) pushBack ["Bohemia Interactive", +GVAR(bisSongs)];

private _artistsTemp = [];
private _artistSongsTemp = [];
{
    private _artist = [_x, "artist","Unknown"] call cba_fnc_getMusicData;
    private _artistIndex = _artistsTemp find _artist;
    if (_artistIndex isEqualto -1) then {
        _artistIndex = _artistsTemp pushBack _artist;
        _artistSongsTemp pushBack [];
    };
    private _array = _artistSongsTemp select _artistIndex;
    _array pushBack _x;
    _artistSongsTemp set [_artistIndex, _array];
} forEach GVAR(songs);

//Combine arrays
{
    GVAR(artists) pushBack [_artistsTemp select _forEachIndex, _artistSongsTemp select _forEachIndex];
} forEach _artistsTemp;
//------------------------------Functions---------------------------------//
//fsh_radio_fPod_fnc_

FUNCMAIN(hasFpod) = {
    private _unit = player;
    ("fsh_fPod" in (vestItems _unit + uniformItems _unit + backpackItems _unit + assignedItems _unit))
};
FUNC(open) = {createdialog QGVAR(RscFPod);};
FUNC(init) = COMPILE_FILE(fnc_init);
FUNC(exit) = {GVAR(isOpen) = false;};

FUNC(button_play) = {
    if (!GVAR(paused)) exitWith {ERROR("Cannot play- not paused!")};
    //Translate paused data
    GVAR(pauseData) params [["_audioType", "local"], ["_songClass", ""], ["_startTime", 0], ["_endTime", 0]];
    private _timeSincePaused = CBA_missionTime - GVAR(pauseTime);
    private _startTimeNew = _startTime + _timeSincePaused;
    private _endTimeNew = _endTime + _timeSincePaused;
    [_audioType, _songClass, _startTimeNew, _endTimeNew] call FSH_fnc_setPlayerAudio;
    GVAR(paused) = false;
};

FUNC(button_pause) = {
    if (GVAR(paused)) exitWith {ERROR("Cannot pause- already paused!")};
    GVAR(paused) = true;
    GVAR(pauseData) = GVARMAIN(audioData);
    GVAR(pauseTime) = CBA_missionTime;
    ["local", "", -1, -1] call FSH_fnc_setPlayerAudio;
};

FUNC(button_stop) = {hint "stop"};
FUNC(button_next) = {hint "next"};
FUNC(button_aux) = {hint "aux"};
FUNC(button_radio) = {hint "radio"};
FUNC(button_previous) = {hint "back"};
FUNC(button_close) = {hint "exit"};

FUNC(button_cycleLeft) = {
    if (GVAR(cycling)) exitWith {};
    ARRAY_CYCLE(GVAR(modes));
    GET_UI_DATA;
    _uiIconRadio ctrlSetPosition _posSettings;
    _uiIconSongs ctrlSetPosition _posRadio;
    _uiIconArtist ctrlSetPosition _posSongs;
    _uiIconPlaylist ctrlSetPosition _posArtist;
    _uiIconSettings ctrlSetPosition _posPlaylist;
    call FUNC(updateUI);
};
FUNC(button_cycleRight) = {
    if (GVAR(cycling)) exitWith {};
    private _newArray = [GVAR(modes) select ((count GVAR(modes))-1)];
    GVAR(modes) deleteAt ((count GVAR(modes))-1);
    GVAR(modes) = _newArray + GVAR(modes);
    GET_UI_DATA;
    _uiIconRadio ctrlSetPosition _posSongs;
    _uiIconSongs ctrlSetPosition _posArtist;
    _uiIconArtist ctrlSetPosition _posPlaylist;
    _uiIconPlaylist ctrlSetPosition _posSettings;
    _uiIconSettings ctrlSetPosition _posRadio;
    call FUNC(updateUI);
};

FUNC(button_playPause) = {
    FPOD_MODE;
    if (GVARMAIN(audioData) select 0 isEqualTo "local") then {
        if (GVARMAIN(audioData) select 1 isEqualTo "") then {
            call FUNC(button_play);
        } else {
            call FUNC(button_pause);
        };
        call FUNCMAIN(update);
    };
};

FUNC(updateUI) = {
    GVAR(cycling) = true;
    GET_UI_DATA;
    private _allModes = +GVAR(modes);
    private _newWindow = _allModes deleteAt 0;
    private _dispName = _newWindow select 0;
    private _ctrlsShow = _newWindow select 1;
    private _ctrlsHide = []; {_ctrlsHide = _ctrlsHide + (_x select 1);} forEach _allModes;

    {
        private _id = _ui DisplayCtrl _x;
        _id ctrlShow true;
    } forEach _ctrlsShow;

    {
        private _id = _ui DisplayCtrl _x;
        _id ctrlShow false;
    } forEach _ctrlsHide;

    //Set icon bar
    _uiMode ctrlSetText _dispName;
    //_uiMode ctrlSetStructuredText parseText _dispName;

    _uiIconRadio ctrlCommit UI_CYCLE_TIME;
    _uiIconSongs ctrlCommit UI_CYCLE_TIME;
    _uiIconArtist ctrlCommit UI_CYCLE_TIME;
    _uiIconPlaylist ctrlCommit UI_CYCLE_TIME;
    _uiIconSettings ctrlCommit UI_CYCLE_TIME;
    _null = [] spawn {
        sleep UI_CYCLE_TIME;
        GVAR(cycling) = false;
    };
};

FUNC(radiolist_changed) = {
    disableSerialization;
    private _ui = uiNamespace getVariable "fPod";
    private _uiListRadio = _ui DisplayCtrl UI_FPOD_RADIOLIST;
    private _index = _this select 1;
    ["radio", _uiListRadio lbData _index] call FSH_fnc_setPlayerAudio;
    call FUNCMAIN(update);
};

FUNC(songlist_changed) = {
    disableSerialization;
    private _ui = uiNamespace getVariable "fPod";
    private _uiListSongs = _ui DisplayCtrl UI_FPOD_SONGLIST;
    private _ctrlIndex = _this select 1;

    private _value = _uiListSongs lbValue _ctrlIndex;
    private _song = GVAR(songs) select _value;

    GVARMAIN(q) = GVAR(songs);
    GVARMAIN(qi) = _value;

    private _data = ["local", _song, cba_missionTime, ([_song,"duration", 4] call cba_fnc_getMusicData)];
    _data call FSH_fnc_setPlayerAudio;
    GVAR(paused) = false;
    call FUNCMAIN(update);
};

FUNC(tree_changed) = {
    disableSerialization;
    private _ui = uiNamespace getVariable "fPod";
    params ["_ctrl", "_ctrlData", "_searchArray"];
    private _uiList = _ui DisplayCtrl _ctrl;
    private _index = _ctrlData select 1;

    private _song = "";

    private _data = _uiList tvData _index;
    private _value = _uiList tvValue _index;
    for [{private _i = 0}, {_i < count _searchArray}, {INC(_i)}] do {
        private _entry = _searchArray select _i;
        private _dispName = _entry select 0;
        if (_dispName isEqualto _data) then {
            private _allSongs = _entry select 1;
            _song = _allSongs select _value;
            GVARMAIN(q) = _allSongs;
            GVARMAIN(qi) = _value;
            _i = count _searchArray;
        };
    };

    if (_song isEqualTo "") exitWith {}; //No need to do anything
    private _data = ["local", _song, cba_missionTime, ([_song,"duration", 4] call cba_fnc_getMusicData)];
    _data call FSH_fnc_setPlayerAudio;
    GVAR(paused) = false;
    call FUNCMAIN(update);
};

FUNC(artistList_changed) = {[UI_FPOD_ARTISTLIST, _this, +GVAR(artists)] call FUNC(tree_changed);};
FUNC(playlist_changed) = {[UI_FPOD_PLAYLISTS, _this, +GVAR(playlists)] call FUNC(tree_changed);};

FUNC(doubleClick_songList) = {};

FUNC(slider_changed) = {GVAR(sliderPos) = _this select 1;};
FUNC(slider_down) = {GVAR(sliderClicked) = true;};
FUNC(slider_up) = {
    GVAR(sliderClicked) = false;
    FPOD_MODE;
    if (GVAR(sliderPos) >= 0) then {
        if (GVAR(paused)) then {
            //Music is paused so update pause data instead of main feed
            GVAR(pauseData) params [["_audioType", "local"], ["_songClass", ""], ["_startTime", 0]];
            private _songDuration = [_songClass, "duration", 0] call cba_fnc_getMusicData;
            private _newStartTime = GVAR(pauseTime) - (_songDuration * GVAR(sliderPos));
            GVAR(pauseData) = [_audioType, _songClass, _newStartTime, _songDuration];
        } else {
            //Update the main audio feed.
            GVARMAIN(audioData) params [["_audioType", "local"], ["_songClass", ""], ["_startTime", 0]];
            private _songDuration = [_songClass, "duration", 0] call cba_fnc_getMusicData;
            private _newStartTime = cba_missionTime - (_songDuration * GVAR(sliderPos));
            [_audioType, _songClass, _newStartTime, _songDuration] call FSH_fnc_setPlayerAudio;
        };
        call FUNCMAIN(update);

    };
    GVAR(sliderPos) = -1;
};

FUNC(volume_changed) = {
    GVARMAIN(volume) = _this select 1;
    if (fsh_radio_ace) then {
        hintSilent "Sadly, ace is a selfish mod and wont let us do this. WIP...";
    };
};


//DEF_AUDIO_TYPE("fPod",FUNC(getAudioData));
