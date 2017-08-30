class CfgVehicles {
    class Man;
    class CAManBase: Man {
        class ACE_selfActions {
            class ACE_Equipment {
                class FSH_fPod {
                    displayName = "fPod";
                    condition = QUOTE([player] call FUNCMAIN(hasFpod));
                    exceptions[] = {"isNotInside", "isNotSitting"};
                    statement = QUOTE([player] call FUNC(open));
                    icon = QUOTE(PATHTOF(icon_aceMenu.paa));
                };
            };
        };
    };
	//////////////////////////////////////
	class Item_Base_F;
	class Item_fsh_fPod: Item_Base_F {
		scope = 2;
		scopeCurator = 2;
		displayName = "fPod";
		author = "Fishy";
		vehicleClass = "Items";
		class TransportItems {
			class fsh_fPod {
				name="fsh_fPod";
				count=1;
			};
		};
	};
};
