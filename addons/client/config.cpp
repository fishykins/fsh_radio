#include "script_component.hpp"

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