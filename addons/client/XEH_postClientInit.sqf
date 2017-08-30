#include "script_component.hpp"

[] spawn {
	waitUntil {!isNull player};

	// Add eventHandlers
	player addEventHandler ["GetInMan", FUNCMAIN(update)];
    player addEventHandler ["GetOutMan", FUNCMAIN(update)];
};