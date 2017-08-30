#define MACRO_RADIO_ACTIONS \
	class ACE_SelfActions { \
		class FSH_vehicleRadio { \
			displayName = "Radio"; \
			condition = QUOTE(call FUNC(hasConsole)); \
			statement = ""; \
			priority = 0.3; \
			icon = QUOTE(PATHTOF(icon_radio.paa)); \
			class ACE_vehicleRadio_on { \
				displayName = "Power on"; \
				condition = QUOTE([true] call FUNC(checkPower)); \
				statement = QUOTE(call FUNC(turnOn)); \
				priority = 0.2; \
			}; \
			class FSH_vehicleRadio_off { \
				displayName = "Power off"; \
				condition = QUOTE([false] call FUNC(checkPower)); \
				statement = QUOTE(call FUNC(turnOff)); \
				priority = 0.2; \
			}; \
            class FSH_vehicleRadio_connect { \
				displayName = "Connect device"; \
				condition = QUOTE(call FUNC(canConnect)); \
                icon = ICON_JACK; \
				statement = QUOTE(call FUNC(connect)); \
				priority = 0.5; \
			}; \
            class FSH_vehicleRadio_disconnect { \
				displayName = "Disconnect device"; \
				condition = QUOTE(call FUNC(canDisonnect)); \
                icon = ICON_JACK; \
				statement = QUOTE(call FUNC(connect)); \
				priority = 0.5; \
			}; \
            class FSH_vehicleRadio_console { \
				displayName = "Open console"; \
                condition = QUOTE([false] call FUNC(checkPower)); \
                statement = QUOTE(call FUNC(openConsole)); \
                priority = 1; \
                icon = QUOTE(PATHTOF(icon_radio.paa)); \
			}; \
		}; \
	};


class CfgVehicles {
	class LandVehicle;
	class Car: LandVehicle {
		MACRO_RADIO_ACTIONS
	};
	class Tank: LandVehicle {
		MACRO_RADIO_ACTIONS
	};
	class Air;
	class Helicopter: Air {
		MACRO_RADIO_ACTIONS
	};
};
