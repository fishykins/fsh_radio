#include "script_component.hpp"

//------------------------------Variables----------------------------------//
GVAR(modes) = [
    ["Settings",[],UI_CSL_SETTINGS],
    ["Radio",[UI_CSL_RADIO_LIST],UI_CSL_RADIO],
    ["AUX",[UI_CSL_AUX_INFO],UI_CSL_AUX],
    ["HIDDEN",[UI_CSL_RADIO_INFO]]
];

//------------------------------FUNCTIONS----------------------------------//
FUNC(hasConsole) = {true}; 
FUNC(checkPower) = {
    (_this select 0) isEqualto !(PVEH_GV(QGVARMAIN(power), false))
}; 
FUNC(canConnect) = {
    (
        (PVEH_GV(QGVARMAIN(auxConnect), objNull) isEqualTo objNull) && 
        (call FUNCMAIN(hasFpod)) && 
        PVEH_GV(QGVARMAIN(power), false)
    )
}; 

FUNC(canDisonnect) = {
    (
        !(PVEH_GV(QGVARMAIN(auxConnect), objNull) isEqualTo objNull) &&
        PVEH_GV(QGVARMAIN(power), false)
    )
}; 

FUNC(openConsole) = {
    if (PVEH_GV(QGVARMAIN(power), false)) then {
        createdialog QGVAR(RscConsole);
    };
}; 
FUNC(turnOn) = {PVEH_SV(QGVARMAIN(power), true); hint "on"};
FUNC(turnOff) = {PVEH_SV(QGVARMAIN(power), false); hint "off"};
FUNC(connect) = {
    if (PVEH_GV(QGVARMAIN(auxConnect), objNull) isEqualTo objnull) then {
        PVEH_SV(QGVARMAIN(auxConnect), player); 
        PVEH_SV(QGVARMAIN(auxAudio), GVARMAIN(audioData)); 
        hint "connected";
    } else {
        PVEH_SV(QGVARMAIN(auxConnect), objNull); 
        PVEH_SV(QGVARMAIN(auxAudio), []); 
        hint "disconnected";
    };
};

FUNC(init) = {
    disableSerialization;
    private _ui = _this select 0;
    uiNamespace setVariable ["dashboardConsole", _ui];
    GET_UI_DATA;
    private _audioData = PVEH_AUDIODATA; 

    //Radio
    
    _uiRadioList lbAdd "none";
    _uiRadioList lbSetData [(lbSize _uiRadioList)-1, ""];
    
    private _index = 0;
    private _set = false;
    {
        INC(_index);
        _name = format ['%1', _x];
        _uiRadioList lbAdd _name;
        _uiRadioList lbSetData [(lbSize _uiRadioList)-1, _x];
        if (!_set && !(_audioData isEqualTo [])) then {
            if (_audioData select 0 isEqualTo "radio") then {
                if (_audioData select 1 isEqualTo _x) then {
                    _uiRadioList lbSetCurSel _index;
                    _set = true;
                };
            };
        };
    } forEach GVARMAIN(allRadioStations);
    
    if (!_set && GVARMAIN(audioData) select 0 isEqualTo "radio") then {
        _uiRadioList lbSetCurSel 0;
    };
    call FUNC(moveHighlighter); 
    call FUNC(updateUi);
};

FUNC(exit) = {
    disableSerialization;
    uiNamespace setVariable ["dashboardConsole", nil];
};

FUNC(button_settings) = { 
    PVEH_SV(QGVAR(mode), 0); 
    call FUNC(moveHighlighter); 
};

FUNC(button_radio) = { 
    PVEH_SV(QGVAR(mode), 1); 
    PVEH_SV(QGVARMAIN(auxMode), false); 
    call FUNC(moveHighlighter); 
};

FUNC(button_aux) = { 
    PVEH_SV(QGVAR(mode), 2); 
    PVEH_SV(QGVARMAIN(auxMode), true); 
    call FUNC(moveHighlighter); 
};

FUNC(moveHighlighter) = {
    GET_UI_DATA;
    _uiId = (GVAR(modes) select (PVEH_GV(QGVAR(mode), 1))) select 2;
    private _pos = ctrlPosition(_ui DisplayCtrl _uiId); 
    _uiHighlighter ctrlSetPosition _pos;
    _uiHighlighter ctrlCommit UI_CYCLE_TIME; 
    call FUNC(updateUi);
};

FUNC(updateUi) = {
    GET_UI_DATA;
    private _modesHidden = +GVAR(modes);
    private _mode = PVEH_GV(QGVAR(mode), 1);
    private _modeCurrent = _modesHidden deleteAt _mode;
    private _ctrlsShow = _modeCurrent select 1;
    private _ctrlsHide = []; {_ctrlsHide = _ctrlsHide + (_x select 1);} forEach _modesHidden;
    {   
        private _id = _ui DisplayCtrl _x;
        _id ctrlShow true;
    } forEach _ctrlsShow;
    
    {   
        private _id = _ui DisplayCtrl _x;
        _id ctrlShow false;
    } forEach _ctrlsHide;
    
    private _connectedUnit = PVEH_GV(QGVARMAIN(auxConnect), objNull);
    if (!(_connectedUnit isEqualTo objNull)) then {
        _uiAuxIcon ctrlShow true;
        _uiAuxInfo ctrlSetStructuredText composeText [
            "Connected to", lineBreak, 
            parseText format["<t color='#ffff00'>%1</t>", name _connectedUnit],
            "'s fPod"
        ];
    } else {
        _uiAuxIcon ctrlShow false;
        _uiAuxInfo ctrlSetStructuredText parseText 
            "<t size='1.5' align='center' valign='middle'>waiting for input...</t>";
    };
    
    //Highlight either Radio or AUX
    #define COLA_YELLOW [1,1,0,1];
    #define COLA_WHITE [1,1,1,1];
    
    if (PVEH_GV(QGVARMAIN(auxMode), false)) then {
        _uiAux ctrlSetTextColor COLA_YELLOW;
        _uiRadio ctrlSetTextColor COLA_WHITE;
    } else {
        _uiAux ctrlSetTextColor COLA_WHITE;
        _uiRadio ctrlSetTextColor COLA_YELLOW;
    };
    
    //Clock
    _uiTime ctrlSetText format ["%1:%2",date select 3,date select 4];
};

FUNC(radio_list_changed) = {
    GET_UI_DATA;
    private _index = _this select 1;
    ["radio", _uiRadioList lbData _index] call fsh_fnc_setVehicleAudio;

    call FUNCMAIN(update);
};