#include "script_component.hpp"

GVAR(ace) = if (isClass(configFile >> "CfgPatches" >> "ace_main")) then {true} else {false};
GVARMAIN(ace) = GVAR(ace);
