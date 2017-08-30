#define COMPONENT console

#include "\x\fsh_radio\addons\main\script_mod.hpp"

#define DEBUG_MODE_FULL
#define RECOMPILE recompile = 1

#include "\x\fsh_radio\addons\main\script_macros.hpp"

#define ICON_JACK	    QPATHTOF(data\icon_jack.paa)

#define UI_CSL -1

#define UI_CSL_SETTINGS         8230
#define UI_CSL_RADIO            8231
#define UI_CSL_AUX              8232
#define UI_CSL_RADIO_LIST       8233
#define UI_CSL_RADIO_INFO       8234
#define UI_CSL_AUX_INFO         8235
#define UI_CSL_AUX_ICON         8236
#define UI_CSL_HIGHLIGHTER      8237
#define UI_CSL_TIME             8238

#define UI_CYCLE_TIME           0.25

#define GET_UI_DATA \
    disableSerialization; \
    private _ui = uiNamespace getVariable "dashboardConsole"; \
    private _uiSettings = _ui DisplayCtrl UI_CSL_SETTINGS;\
    private _uiRadio = _ui DisplayCtrl UI_CSL_RADIO;\
    private _uiAux = _ui DisplayCtrl UI_CSL_AUX;\
    private _uiAuxInfo = _ui DisplayCtrl UI_CSL_AUX_INFO;\
    private _uiAuxIcon = _ui DisplayCtrl UI_CSL_AUX_ICON;\
    private _uiTime = _ui DisplayCtrl UI_CSL_TIME;\
    private _uiRadioList = _ui DisplayCtrl UI_CSL_RADIO_LIST;\
    private _uiRadioInfo = _ui DisplayCtrl UI_CSL_RADIO_INFO; \
    private _uiHighlighter = _ui DisplayCtrl UI_CSL_HIGHLIGHTER
