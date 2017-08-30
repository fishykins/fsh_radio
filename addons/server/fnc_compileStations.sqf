/* ----------------------------------------------------------------------------
Function: FSH_fnc_compileStations

Description:
    A function used to gather a list of all radiostation classes
    
Parameters:
    none

Returns:
    Array of compiled music (in CLASS format)
    
Example:
    (begin example)
        _allMusic = [] call CBA_fnc_compileMusic
    (end example)

Author:
    Fishy, Dorbedo, Dedmen
---------------------------------------------------------------------------- */
#include "script_component.hpp"

if (isNil QGVAR(compiledStations)) then {
    private _allStations = configProperties [MissionConfigFile >> "CfgRadioStations", "!((getText(_x >> 'name')) isEqualTo '')",true];
    _allStations append configProperties [configFile >> "CfgRadioStations", "!((getText(_x >> 'name')) isEqualTo '')",true];
    private _unsortedStations = [];
    {
        _unsortedStations pushBackUnique (configName _x);
    } forEach _allStations;
    GVAR(compiledStations) = +_unsortedStations;
};

GVAR(compiledStations)
