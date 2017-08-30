#include "script_component.hpp"
//#include "\x\fsh_radio\addons\main\script_resources.hpp"

class CfgPatches {
    class ADDON {
        author = "Fishy";
        name = CSTRING(component);
        url = "";
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"CBA_common","CBA_music"};
        version = VERSION;
        authors[] = {"Fishy"};
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "CfgWeapons.hpp"


//Mod side
#include "\x\fsh_radio\addons\ui\script_RscClasses.hpp"
#include "\x\fsh_radio\addons\ui\script_RscDialog.hpp"
#include "script_ui.hpp"

//Uni
#include "ui_fPod.hpp"
