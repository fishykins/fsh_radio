/* ----------------------------------------------------------------------------
Function: fsh_radio_client_fnc_audioData

Description:
    checks passed audio date and finds actual values for the track.

Parameters:
    AUDIO DATA- 
        0. type of audio source <STRING>
        1. name of item <STRING>
        2. time <NUMBER>
        3. time <NUMBER>

Returns:
    Array-
        0. Track name <STRING>
        1. Track time <NUMBER>
        2. Time left on track <NUMBER>
        
Possible Audio Types:
    "radio"
    "local"

Author:
    fishy 
---------------------------------------------------------------------------- */
#include "script_component.hpp"

params [
    ["_audioType","",[""]], 
    ["_audioName","",[""]],
    ["_start",-1,[0]],
    ["_end",-1,[0]]
];

private _time = CBA_missionTime;
private _retTrack = "";
private _retTime = -1;
private _retTimeLeft = 1; 

//If no device exit
if (!(call FUNCMAIN(hasAudioDevice))) exitWith {[_retTrack, _retTime, _retTimeLeft]};

if (_audioType isEqualTo "local") then {
    _retTrack = _audioName;
    _retTime = _time - _start;
    _retTimeLeft = _end - _time;
} else {
    if (_audioType isEqualTo "radio") then {
        private _ret = GET_RADIO_DATA(_audioName);
        _ret params [
            ["_currentTrack","",[""]], 
            ["_startedTime",-1,[0]],
            ["_finishTime",-1,[0]]
        ];
        _retTrack = _currentTrack;
        _retTime = _time - _startedTime;
        _retTimeLeft = _finishTime - _time;
    };
};

[_retTrack, _retTime, _retTimeLeft]
