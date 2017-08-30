#include "script_component.hpp"

//Define a few functions
FUNC(radioInit) = COMPILE_FILE(init_radioStation);
FUNC(newTrack) = COMPILE_FILE(fnc_newTrack);
FSM(broadcast) = QUOTE(PATHTOF(broadcast.fsm));

//Start Broadcasting!
GVAR(music) = call cba_fnc_compileMusic;

GVARMAIN(allRadioStations) = [] call COMPILE_FILE(fnc_compileStations);
publicVariable QGVARMAIN(allRadioStations);
