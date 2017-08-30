#include "script_component.hpp"

params [
    ["_class", "", [""]]
];

private _radioVar = RADIOVAR(_class);
private _categories = GET_RADIO_CATS(_class);
private _program = GET_RADIO_PROGRAM(_class);
//--------- Manage the program running order ----------
private _item = _program select 0;
private _newTrack = "";
private _trackDuration = 1;
ARRAY_CYCLE(_program);
//-----------------------------------------------------
//look up items category and pick a track
for [{private _i = 0}, {_i < (count _categories) && _i < 10}, {INC(_i)}] do {
    private _currentCat = _categories select _i;
    private _catName = _currentCat select 0;
    if (_catName isEqualTo _item) then {
        private _tracks = _currentCat select 1;
        if (!(_tracks isEqualTo [])) then {
            //Pick the first one from the list
            _newTrack = _tracks select 0;
            _trackDuration = [_newTrack,"duration"] call cba_fnc_getMusicData;
            //Update the list for next time
            ARRAY_CYCLE(_tracks);
            _currentCat set [1, _tracks];
            _categories set [_i, _currentCat];
        };
        _i = count _categories;
    };
};

if (_trackDuration < 1) then {_trackDuration = 4;};

private _currentTime = CBA_missionTime;
private _endTime = _currentTime + _trackDuration;

private _formattedTime = [_currentTime,"M:SS"] call cba_fnc_formatElapsedTime;

LOG_4("%1 is running item %2: %3 at %4", _class, _item, _newTrack, _formattedTime);
//systemChat format ["%1 is running item %2: %3 at %4", _class, _item, _newTrack, _formattedTime];

private _data = [_newTrack, _currentTime, _endTime];

SET_RADIO_DATA(_class,_data);
SET_RADIO_PROGRAM(_class,_program);
SET_RADIO_CATS(_class,_categories);

_endTime
