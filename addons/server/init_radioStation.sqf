#include "script_component.hpp"

params [
    ["_class", "", [""]]
];

//systemChat format ["%1 has spawned", _class];
LOG_1("%1 has spawned", _class);

private _radioVar = RADIOVAR(_class);
private _baseCfg = configFile >> 'CfgRadioStations' >> _class;
private _missionCfg = missionConfigFile >> 'CfgRadioStations' >> _class;
private _config = _baseCfg;
private _name = getText (_baseCfg >> 'name');

if (_name isEqualTo "") then {
	_name = getText (_missionCfg >> 'name');
	_config = _missionCfg;
};

if (_name isEqualTo "") exitWith {ERROR_1("Radio station %1 does not exsist", _class)};
//=====================================================================================//
//Get radio station format
private _program = getArray (_config >> "program");
private _timeSpeed = getNumber (_config >> "Speed");
private _debug = if (getNumber (_config >> "debug") isEqualTo 1) then {true} else {false};

LOG_2("%1 has program %2", _class, _program);

//Get all track categories
private _categories = [];

for [{private _ii = 0}, {_ii < (count _config) && _ii < 30}, {INC(_ii)}] do {
	private _cat = _config select _ii;
	if (count _cat > 0) then {
		private _catName = configName _cat;
		private _catTracks = getArray (_cat >> 'tracks');
		private _catTypes = getArray (_cat >> 'types');
		private _catThemes = getArray (_cat >> 'themes');
		private _findMusicResults = ([_catTypes, _catThemes, GVAR(music)] call cba_fnc_findMusic) - _catTracks;
		private _catAllTracks = _catTracks + _findMusicResults;
		private _catAllTracks = [_catAllTracks] call CBA_fnc_shuffle;
		if (count _catAllTracks isEqualTo 0) then {
			WARNING_3("%1 found no tracks. Looked for %2 with themes of %3", _class, _catTypes, _catTypes);
		};
		_categories pushBack [_catName, _catAllTracks];
	};
};

LOG_2("%1 has categories %2", _class, _categories);

SET_RADIO_PROGRAM(_class,_program);
SET_RADIO_CATS(_class,_categories);

//Now we have a program lined up, go ahead and launch
[_class] execFSM FSM(broadcast);
