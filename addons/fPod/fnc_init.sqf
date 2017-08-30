#include "script_component.hpp"

disableSerialization;
private _ui = _this select 0;
uiNamespace setVariable ["fPod", _ui];
GET_UI_DATA;

GVAR(isOpen) = true;
GVAR(modes) = [] + GVAR(modesCopy);
call FUNCMAIN(update);

_uiIconPause ctrlShow false;
_uiSlider sliderSetRange [0, 1];

_uiListRadio lbAdd "none";
_uiListRadio lbSetData [(lbSize _uiListRadio)-1, ""];

//======================================================================//
//======================================================================//
//Playlists
{
    _x params ["_dispname", "_array"];
    private _index = _uiListPlaylist tvAdd [[], _dispname];
    _uiListPlaylist tvSetData [[_index], "header"];
    {
        private _dispnameX = [_x,"name"] call cba_fnc_getMusicData;
        if (IS_STRING(_dispnameX)) then {
            private _subIndex = _uiListPlaylist tvAdd [[_index], _dispnameX];
            _uiListPlaylist tvSetData [[_index,_subIndex], _dispname];
            _uiListPlaylist tvSetValue [[_index,_subIndex], _forEachIndex];
        };
    } forEach _array;
} forEach GVAR(playlists);

//======================================================================//
//======================================================================//
//Artists
{
    _x params ["_dispname", "_array"];
    private _index = _uiListArtists tvAdd [[], _dispname];
    _uiListArtists tvSetData [[_index], "header"];
    {
        private _dispnameX = [_x,"name"] call cba_fnc_getMusicData;
        if (IS_STRING(_dispnameX)) then {
            private _subIndex = _uiListArtists tvAdd [[_index], _dispnameX];
            _uiListArtists tvSetData [[_index,_subIndex], _dispname];
            _uiListArtists tvSetValue [[_index,_subIndex], _forEachIndex];
        };
    } forEach _array;
} forEach GVAR(artists);

//======================================================================//
//======================================================================//
//Songs

{
    private _dispname = [_x,"name"] call cba_fnc_getMusicData;
    if (IS_STRING(_dispname)) then {
        private _index = _uiListSongs lbAdd  _dispname;
        _uiListSongs lbSetData [_index, "song"];
        _uiListSongs lbSetValue [_index, _forEachIndex];
    };
} forEach GVAR(songs);

//======================================================================//
//======================================================================//
//Radio
private _index = 0;
private _set = false;
{
    INC(_index);
    _name = format ['%1', _x];
    _uiListRadio lbAdd _name;
    _uiListRadio lbSetData [(lbSize _uiListRadio)-1, _name];
    if (!_set && !(GVARMAIN(audioData) isEqualTo [])) then {
        if (GVARMAIN(audioData) select 0 isEqualTo "radio") then {
            if (GVARMAIN(audioData) select 1 isEqualTo _x) then {
                _uiListRadio lbSetCurSel _index;
                _set = true;
            };
        };
    };
} forEach GVARMAIN(allRadioStations);

if (!_set && GVARMAIN(audioData) select 0 isEqualTo "radio") then {
    _uiListRadio lbSetCurSel 0;
};
//======================================================================//
//======================================================================//
//Settings

//Shuffle
_uiSettingsShuffle lbAdd "On";
_uiSettingsShuffle lbAdd "Off";

FUNC(toggleShuffle) = {};
_uiSettingsShuffle lbSetCurSel (if (GVARMAIN(shuffle)) then {0} else {1});
FUNC(toggleShuffle) = {GVARMAIN(shuffle) = !(GVARMAIN(shuffle));};

//Bluetooth
_uiSettingsBluetooth lbAdd "On";
_uiSettingsBluetooth lbAdd "Off";

FUNC(toggleBluetooth) = {};
_uiSettingsBluetooth lbSetCurSel (if (GVARMAIN(bluetooth)) then {0} else {1});
FUNC(toggleBluetooth) = {GVARMAIN(bluetooth) = !(GVARMAIN(bluetooth));};

//volume
_uiSettingsVolume sliderSetRange [0, 1];
_uiSettingsVolume sliderSetPosition (GVARMAIN(volume));

//======================================================================//
//======================================================================//


call FUNC(updateUI);

_null = [] spawn {
    GET_UI_DATA;

    _display_null = {
        _uiIconPause ctrlShow false;
        _uiIconPlay ctrlShow false;

        _uiInfoSong ctrlSetStructuredText parseText "";
        _uiInfoArtist ctrlSetStructuredText  parseText "";
        _uiInfoTime ctrlSetText "";
        _uiInfoEnd ctrlSetText "";
        _uiSlider ctrlShow false;
    };

    while {GVAR(isOpen)} do {
        if (GVARMAIN(audioData) select 0 isEqualTo "local") then { //Local music, not radio or alternative device
            private _data = ["",0];

            if (GVAR(paused)) then {
                GVAR(pauseData) params [["_audioType", "local"], ["_songClass", ""], ["_startTime", 0], ["_endTime", 0]];
                _data = [_songClass, GVAR(pauseTime) - _startTime];
                _uiIconPlay ctrlShow true;
                _uiIconPause ctrlShow false;
            } else {
                GVARMAIN(audioData) params [["_audioType", "local"], ["_songClass", ""], ["_startTime", 0], ["_endTime", 0]];
                _data = [_songClass, CBA_missionTime - _startTime];
                _uiIconPlay ctrlShow false;
                _uiIconPause ctrlShow true;
            };


            if (_data select 0 isEqualTo "") exitWith {call _display_null;};
            //Music is playing so we can update our data


            _data params [["_songClass", ""], ["_songTime", 0]];
            if (_songClass isEqualTo "") exitWith {call _display_null;};

            private _currentPos = _songTime;
            private _duration = ([_songClass, "duration"] call cba_fnc_getMusicData) max 1;
            private _songTitle = ([_songClass, "name"] call cba_fnc_getMusicData);
            private _songArtist = ([_songClass, "artist","Unknown"] call cba_fnc_getMusicData);

            _sizeSong = (14/(count _songTitle)) min 0.8;
            _uiInfoSong ctrlSetStructuredText parseText
            format ["<t size='%2' align='right'>%1</t>", _songTitle, _sizeSong];

            if (_songArtist != "") then {
                _sizeArtist = (10/(count _songArtist)) min 0.8;
                _uiInfoArtist ctrlSetStructuredText parseText
                format ["<t size='%2' align='left'>%1</t>", _songArtist, _sizeArtist];
            };
            _uiInfoTime ctrlSetText ([_currentPos, "M:SS"] call CBA_fnc_formatElapsedTime);
            _uiInfoEnd ctrlSetText ([_duration, "M:SS"] call CBA_fnc_formatElapsedTime);
            _uiSlider ctrlShow true;
            if (!GVAR(sliderClicked)) then {
                _uiSlider sliderSetPosition (_currentPos/_duration);
            };
        } else {
            //Not using local music so dont display any data
            call _display_null;
        };
        sleep 0.5;
    };
};
