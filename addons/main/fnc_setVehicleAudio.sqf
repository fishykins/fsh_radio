/* ----------------------------------------------------------------------------
Function: fsh_fnc_setVehicleAudio

Description:
    Sets player's vehicle audio data

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
    ["_class",[],[""]],
    ["_time1",-1,[1]],
    ["_time2",-1,[1]]
];

if (PVEH isEqualTo player) exitWith {false};

_audioData = [_type, _class, _time1, _time2];
hint format ["Vehicle audio being set: %1", _audioData];
PVEH_SET_AUDIODATA(_audioData);

true
