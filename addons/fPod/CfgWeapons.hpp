class CfgWeapons {

    class ItemCore;
    class InventoryItem_Base_F;

    class fsh_fPod: ItemCore {
        type = 4096;//4;
        detectRange = -1;
        simulation = "ItemMineDetector";
        displayName = "fPod";
        descriptionShort = "fPod Personal audio device";
        //model = QPATHTOF(data\ace_earplugs.p3d);
        picture = QPATHTOF(UI\fPod_x_co.paa);
        scope = 2;
        class ItemInfo: InventoryItem_Base_F {
            mass = 2;
        };
    };
};
