#include "script_component.hpp"
//------------------------------Variables----------------------------------//

if (isNil GVARMAIN(allRadioStations)) then {GVARMAIN(allRadioStations) = [];};
GVAR(receiving) = false; //Whether or not there is a script controlling music at current time
GVAR(audioUpdate) = false; //Force update audio by setting to true
GVARMAIN(audioData) = []; //Local audio data.  ["#type", "#className", start time, finsh time]
GVARMAIN(q) = [];
GVARMAIN(qi) = -1;
GVARMAIN(shuffle) = false;
GVARMAIN(bluetooth) = false;
GVARMAIN(volume) = 0.5;
//------------------------------Functions---------------------------------//

FSM(receive) = QUOTE(PATHTOF(receive.fsm));
FUNC(getAudioData) = COMPILE_FILE(fnc_getAudioData);
FUNCMAIN(update) = {
    GVAR(audioUpdate) = true;
    if (!GVAR(receiving)) then {
        execFSM FSM(receive);
    };
};


FUNCMAIN(hasAudioDevice) = {
    call FUNCMAIN(hasFpod)
};
