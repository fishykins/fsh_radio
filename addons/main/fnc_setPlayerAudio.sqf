/* ----------------------------------------------------------------------------
Function: FSH_fnc_setPlayerAudio

Description:
    Sets a player's audio data. Local

Parameters:
    0: Vehicle <OBJECT>
    1: audio data <ARRAY>

Returns:
    true <BOOLEAN>

Author:
    fishy
---------------------------------------------------------------------------- */
#include "script_component.hpp"


params [
    ["_type","",[""]],
    ["_class","",[""]],
    ["_time1",-1,[1]],
    ["_time2",-1,[1]]
];

private _audioData = [_type, _class, _time1, _time2];
//hint format ["Audio data being set: %1", _audioData];
GVARMAIN(audioData) = _audioData;

if (PVEH isEqualTo player) exitWIth {true};

if (PVEH_GV(QGVARMAIN(auxMode), false)) then {
    private _connection = PVEH_GV(QGVARMAIN(auxConnect), objNull);
    if (_connection isEqualTo player) then {
        PVEH_SV(QGVARMAIN(auxAudio), _audioData);
        //hint format ["Vehicle aux being set: %1", _audioData];
    };
};

true
