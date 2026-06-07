__int64 (*oLobbyWeaponSkin)(__int64 result, int WeaponSkinID, bool bUse, bool bSync);
__int64 hLobbyWeaponSkin(__int64 result, int WeaponSkinID, bool bUse, bool bSync) { 
    auto it = ModSkinsID.find(WeaponSkinID);
    if (it != ModSkinsID.end()) {
        WeaponSkinID = it->second;
    }
    return oLobbyWeaponSkin(result, WeaponSkinID, bUse, bSync);
}



