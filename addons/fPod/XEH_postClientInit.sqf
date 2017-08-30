#include "script_component.hpp"


[] spawn {
	waitUntil {!isNull player};
    player addItem "fsh_fPod";
};