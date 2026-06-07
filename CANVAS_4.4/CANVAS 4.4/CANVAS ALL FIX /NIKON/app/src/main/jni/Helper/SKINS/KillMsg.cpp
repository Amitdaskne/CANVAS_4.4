void (*orig_kill_message_event)(ASTExtraPlayerController* thiz, struct FFatalDamageParameter* FatalDamageParameter);
void kill_message_event(ASTExtraPlayerController* thiz, struct FFatalDamageParameter* FatalDamageParameter) {
	if (GunSkin) {
    if (thiz->PlayerKey == FatalDamageParameter->CauserKey && !thiz->STExtraBaseCharacter->CurrentVehicle) {
    if (g_LocalPlayer && g_LocalPlayer->WeaponManagerComponent && g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated) {
        int WeaponID = g_LocalPlayer->WeaponManagerComponent->CurrentWeaponReplicated->GetWeaponID();
        auto it = ModSkinsID.find(WeaponID);
    if (it != ModSkinsID.end()) {
        FatalDamageParameter->CauserWeaponAvatarID = it->second;
    }}}}
    orig_kill_message_event(thiz, FatalDamageParameter);
}
//==============================================================================================//
