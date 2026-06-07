
#define COLOR_WHITE FLinearColor(1.f, 1.f, 1.f, 1.f)
#define COLOR_BLACK FLinearColor(0.f, 0.f, 0.f, 1.f)


void LocalPlayer(UCanvas* Canvas) {
    ASTExtraPlayerCharacter* localPlayer = nullptr;
    ASTExtraPlayerController* localPlayerController = nullptr;
    if (!Canvas) return;
    auto GWorld = GetWorld();
    if (GWorld && GWorld->NetDriver && GWorld->NetDriver->ServerConnection) {
		localPlayerController = reinterpret_cast<ASTExtraPlayerController*>(GWorld->NetDriver->ServerConnection->PlayerController);
    if (localPlayerController && GWorld->PersistentLevel) {
        auto PlayerActors = GetActors(GWorld->PersistentLevel);
        for (int i = 0; i < PlayerActors.Num(); ++i) {
        AActor* Actor = PlayerActors[i];
    if (!Actor) continue;
    if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
        auto Player = reinterpret_cast<ASTExtraPlayerCharacter*>(Actor);
    if (Player && Player->PlayerKey == localPlayerController->PlayerKey) {
        localPlayer = Player;
        break;
    }}}}}
    g_LocalPlayer = localPlayer;
    g_LocalController = localPlayerController;
    
    
    	if (Cheat::Aimbot::Enable) {
        ASTExtraPlayerCharacter *Target = GetTargetForAim();
				if (Target)
				{
   bool triggerOk = false;
if (scopeAndFire == 0) {
   triggerOk = g_LocalPlayer->bIsWeaponFiring;
 } else if (scopeAndFire == 1) {
triggerOk = g_LocalPlayer->bIsWeaponFiring || g_LocalPlayer->bIsGunADS;
  } else triggerOk = true;
		  	if (triggerOk){
   FVector targetAimPos;
 if (AimHead) {
   if(algorithm == 0) {
targetAimPos=Target->GetBonePos("Head", {});
   } else if(algorithm == 1) {
targetAimPos = Target->GetBonePos("Head", {});
   }else if(algorithm == 2){
targetAimPos = Target->GetBonePos("pelvis", {});//锁骨
   }else if(algorithm == 3){
targetAimPos = Target->GetBonePos("calf_l", {});//左小腿
   }else if(algorithm == 4){
targetAimPos = Target->GetBonePos("calf_r", {});//右小腿
   }else if(algorithm == 5){
targetAimPos = Target->GetBonePos("lowerarm_l", {});//左小臂
   }else if(algorithm == 6){
targetAimPos = Target->GetBonePos("lowerarm_r", {});//右小臂
   }else if(algorithm == 7){
targetAimPos = Target->GetBonePos("upperarm_l", {});//左上臂
   }else if(algorithm == 8){
targetAimPos = Target->GetBonePos("upperarm_r", {});//右上臂
   }else if(algorithm == 9) {
targetAimPos = Target->GetBonePos("thigh_l", {});//左大腿
   }else if(algorithm == 10) {
targetAimPos = Target->GetBonePos("thigh_r", {});//右大腿
   }else if(algorithm == 11) {
targetAimPos = Target->GetBonePos("foot_l", {});//左脚
   }else if(algorithm == 12){
targetAimPos = Target->GetBonePos("foot_r", {});//右脚
   }
 }
 if(AimBody){
   if(algorithm == 0) {
targetAimPos = Target->GetBonePos("Head", {});//头
   }else if(algorithm == 1) {
targetAimPos = Target->GetBonePos("spine_03", {});//Neck
   }else if(algorithm == 2){
targetAimPos = Target->GetBonePos("pelvis", {});//屁股
   }else if(algorithm == 3){
targetAimPos = Target->GetBonePos("calf_l", {});//左小腿
   }else if(algorithm == 4){
targetAimPos = Target->GetBonePos("calf_r", {});//右小腿
   }else if(algorithm == 5){
targetAimPos = Target->GetBonePos("lowerarm_l", {});//左小臂
   }else if(algorithm == 6){
targetAimPos = Target->GetBonePos("lowerarm_r", {});//右小臂
   }else if(algorithm == 7){
targetAimPos = Target->GetBonePos("upperarm_l", {});//左上臂
   }else if(algorithm == 8){
targetAimPos = Target->GetBonePos("upperarm_r", {});//右上臂
   }else if(algorithm == 9) {
targetAimPos = Target->GetBonePos("thigh_l", {});//左大腿
   }else if(algorithm == 10) {
targetAimPos = Target->GetBonePos("thigh_r", {});//右大腿
   }else if(algorithm == 11) {
targetAimPos = Target->GetBonePos("foot_l", {});//左脚
   }else if(algorithm == 12){
targetAimPos = Target->GetBonePos("foot_r", {});//右脚
}
 }
        auto WeaponManagerComponent = g_LocalPlayer->WeaponManagerComponent;
 if (WeaponManagerComponent)
 {
auto propSlot = WeaponManagerComponent->GetCurrentUsingPropSlot();
if ((int)propSlot.GetValue() >= 1 && (int)propSlot.GetValue() <= 3)
{
  auto CurrentWeaponReplicated = (ASTExtraShootWeapon *)WeaponManagerComponent->CurrentWeaponReplicated;
  if (CurrentWeaponReplicated)
  {
auto ShootWeaponComponent = CurrentWeaponReplicated->ShootWeaponComponent;
  if (ShootWeaponComponent)
  {
UShootWeaponEntity *ShootWeaponEntityComponent = ShootWeaponComponent->ShootWeaponEntityComponent;
  if (ShootWeaponEntityComponent)
  {
 ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
 float dist = g_LocalPlayer->GetDistanceTo(Target);
 auto timeToTravel = dist / ShootWeaponEntityComponent->BulletRange;
  if (CurrentVehicle)
  {
 FVector LinearVelocity = CurrentVehicle->ReplicatedMovement.LinearVelocity;
 targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(LinearVelocity, timeToTravel));
   }else{
 FVector Velocity = Target->GetVelocity();
 targetAimPos = UKismetMathLibrary::Add_VectorVector(targetAimPos, UKismetMathLibrary::Multiply_VectorFloat(Velocity, timeToTravel));
   }

   if (g_LocalPlayer->bIsWeaponFiring)
   {
 float dist = g_LocalPlayer->GetDistanceTo(Target) / 100.f;
 targetAimPos.Z -= dist * recoilCompensationFactor;
}

 FVector fDir = UKismetMathLibrary::Subtract_VectorVector(targetAimPos, g_LocalController->PlayerCameraManager->CameraCache.POV.Location);
 FRotator Yaptr = UKismetMathLibrary::Conv_VectorToRotator(fDir);

 FRotator CpYaT = g_LocalController->PlayerCameraManager->CameraCache.POV.Rotation;

 Yaptr.Pitch -= CpYaT.Pitch;
 Yaptr.Yaw -= CpYaT.Yaw;
 Yaptr.Roll = 0.f;
 NekoHook(Yaptr);

 CpYaT.Pitch += Yaptr.Pitch / Speed_Aim; // Aim X Speed Make Float : Xs
 CpYaT.Yaw += Yaptr.Yaw / Speed_Aim; // Aim Y Speed Make Float : Ys
 CpYaT.Roll = 0.f;

g_LocalPlayer->AddControllerYawInput(Yaptr.Yaw);
g_LocalPlayer->AddControllerPitchInput(Yaptr.Pitch);
}}}}}}}}                   
}
//==============================================================================================//
void DrawPlayerESP(UCanvas* Canvas) {
    int totalEnemies = 0, totalBots = 0;
if (g_LocalPlayer && g_LocalController && g_LocalPlayer->PartHitComponent && Canvas) { //1st open
    if (g_LocalPlayer->PartHitComponent) {
auto ConfigCollisionDistSqAngles = g_LocalPlayer->PartHitComponent->ConfigCollisionDistSqAngles;
for (int j = 0; j < ConfigCollisionDistSqAngles.Num(); j++) {
ConfigCollisionDistSqAngles[j].Angle = 90.0f;
}
g_LocalPlayer->PartHitComponent->ConfigCollisionDistSqAngles = ConfigCollisionDistSqAngles;
}
        static FName HeadBone = FName("Head");
        static FName RootBone = FName("Root");
        auto GWorld = GetWorld();
    if (GWorld && GWorld->PersistentLevel) { //2nd Open
        auto Actors = GetActors(GWorld->PersistentLevel);
        for (int i = 0; i < Actors.Num(); ++i) { //3rd open
        auto Actor = Actors[i];
    if (!Actor) continue;
    if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) { //4th open
        auto* Player = static_cast<ASTExtraPlayerCharacter*>(Actor);
    if (!Player || Player->PlayerKey == g_LocalController->PlayerKey || Player->TeamID == g_LocalController->TeamID || Player->bDead || Player->bHidden)
        continue;
        float Distance = g_LocalPlayer->GetDistanceTo(Player) / 100.f;
    if (Distance > 500.f) continue;
    if (Player->bEnsure) ++totalBots;
        else ++totalEnemies;

	    FVector HeadPos = Player->GetBonePos(HeadBone, {0, 0, 0});
        FVector RootPos = Player->GetBonePos(RootBone, {0, 0, 0});
        FVector2D Head2D, Root2D;
    if (!W2S(HeadPos, &Head2D) || !W2S(RootPos, &Root2D)) continue;
        bool IsVisible = g_LocalController->LineOfSightTo(Player, {0, 0, 0}, true); 
		FLinearColor color = Player->bEnsure  ? (IsVisible ? FLinearColor(0.f, 1.f, 1.f, 1.f) : FLinearColor(1.f, 0.f, 0.f, 1.f)) : (IsVisible ? FLinearColor(0.f, 1.f, 1.f, 1.f) : FLinearColor(1.f, 0.f, 0.f, 1.f));
    if (Head2D.X < 0 || Head2D.Y < 0 || Head2D.X > glWidth || Head2D.Y > glHeight)
        continue;
	// 🚀 Aimbot
	
	

    // 🚀 Draw Player Line
    if (Cheat::Esp::Line) {
        FVector2D Start(glWidth / 2.f, 0.f);
        FVector2D End(Head2D.X, Head2D.Y - 16.f);
        DrawLine(Canvas, Start, End, 0.8f, color);
    }
    // 🚀 Draw Player Health
    if (Cheat::Esp::Health) {
        float CurHP = (float)std::max(0, std::min((int)Player->Health, (int)Player->HealthMax));
        float MaxHP = Player->HealthMax;
    if (Player->Health == 0.0f && !Player->bDead) {
        CurHP = Player->NearDeathBreath;
    if (Player->NearDeatchComponent)
        MaxHP = Player->NearDeatchComponent->BreathMax;
    }
        float red   = (float)std::min(((510 * (MaxHP - CurHP)) / MaxHP), 255.0f);
        float green = (float)std::min(((510 * CurHP) / MaxHP), 255.0f);
        float blue  = green;
        float alpha = 255.0f;
        FLinearColor HPColor(red / 255.0f, green / 255.0f, blue / 255.0f, alpha / 255.0f);
    if (Player->Health == 0.0f && !Player->bDead)
        HPColor = FLinearColor(1.f, 0.f, 0.f, 155.f / 255.f);
        float BarWidth  = 30.0f;   // Width
        float BarHeight = 3.0f;    // Height
        FVector2D BarStart(Head2D.X - (BarWidth / 2), Head2D.Y - 16.0f);
        FVector2D BarEnd(BarStart.X + BarWidth, BarStart.Y + BarHeight);
        float FillWidth = (CurHP / MaxHP) * BarWidth;
        DrawFilledRectangle(Canvas, BarStart, BarWidth, BarHeight, FLinearColor(0.f, 0.f, 0.f, 1.0f));
        DrawFilledRectangle(Canvas, BarStart, FillWidth, BarHeight, HPColor);
    }
    // 🚀 Draw Player Skeleton
	if (Cheat::Esp::Skeleton) {
	    std::unordered_map < const char *, FVector2D > boneScreen;
        for (const auto & group:skeleton) {
	    for (const char *bone:group) {
    if (boneScreen.find(bone) != boneScreen.end())
	    continue;
		FVector bonePos = Player->GetBonePos(bone, { });
		FVector2D screenPos;
	if (W2S(bonePos, &screenPos))
	    boneScreen[bone] = screenPos;
	}}
        for (const auto & group:skeleton) {
	    for (size_t j = 0; j < group.size() - 1; ++j) {
	if (boneScreen.count(group[j]) && boneScreen.count(group[j + 1])) {
		DrawLine(Canvas, boneScreen[group[j]], boneScreen[group[j + 1]], 0.8f, color);
	}}}}
	// 🚀 Draw Player Name
    if (Cheat::Esp::Name) {
        tslFont->LegacyFontSize = 9;
        FString playerName = Player->bEnsure ? FString("BOT") : Player->PlayerName;
		DrawOutlinedText(Canvas, playerName, FVector2D(Root2D.X, Root2D.Y + 15.0f), FLinearColor(0.f, 1.f, 1.f, 1.f), FLinearColor(0.f, 0.f, 0.f, 0.0f), true);
    }
    // 🚀 Draw Player Distance
    if (Cheat::Esp::Distance) {
        tslFont->LegacyFontSize = 9;
        std::wstring distX = std::to_wstring((int)Distance) + L"M";
        FLinearColor distColor = (Distance >= AimRangeAimbot) ? FLinearColor(1.f, 0.f, 0.f, 1.f) : FLinearColor(1.f, 1.f, 0.f, 1.f);
        DrawOutlinedText(Canvas, FString(distX), FVector2D(Root2D.X, Root2D.Y + 28.0f), distColor, FLinearColor(0.f, 0.f, 0.f, 0.0f), true);
    }
	} //1st closed
    // 🚀 Draw Vehicle Esp
	if (Cheat::Esp::Vehicle && Actor->IsA(ASTExtraVehicleBase::StaticClass())) {
        auto *Vehicle = static_cast < ASTExtraVehicleBase * >(Actor);
    if (!Vehicle->Mesh || Vehicle->bHidden)
	    continue;
        float Distance = Vehicle->GetDistanceTo(g_LocalPlayer) / 100.f;
    if (Distance > 600.f)
	    continue;
        FVector2D ScreenPos;
    if (!W2S(Vehicle->K2_GetActorLocation(), &ScreenPos))
	    continue;
        const char *nameStr = GetVehicleName(Vehicle);
        std::wstring VehicleNameW(nameStr, nameStr + std::strlen(nameStr));
        std::wstring DistanceW = std::to_wstring(static_cast < int >(Distance)) + L"m";
        tslFont->LegacyFontSize = 10;
        bool isMoving = GetVectorSize(Vehicle->ReplicatedMovement.LinearVelocity) > 10.f;
        FLinearColor color = isMoving ? FLinearColor(1.f, 0.f, 0.f, 1.f) : FLinearColor(1.f, 1.f, 0.f, 0.f);
        auto CenterX =[&](const std::wstring & text) {
	    float approxWidth = text.length() * (tslFont->LegacyFontSize * 0.5f);
	    return ScreenPos.X - approxWidth / 2.f;
    };
        DrawOutlinedText(Canvas, FString(VehicleNameW), {CenterX(VehicleNameW), ScreenPos.Y} , color, FLinearColor(0.f, 0.f, 0.f, 0.0f));
        DrawOutlinedText(Canvas, FString(DistanceW), {CenterX(DistanceW), ScreenPos.Y + tslFont->LegacyFontSize + 3.5f} , color, FLinearColor(0.f, 0.f, 0.f, 0.0f));
    }
    // 🚀 Draw Granade Warning
	if (Cheat::Esp::GranadeWarning && Actor && Actor->IsA(ASTExtraGrenadeBase::StaticClass())) {
        auto* Grenade = static_cast<ASTExtraGrenadeBase*>(Actor);
    if (!Grenade || !Grenade->RootComponent || !g_LocalPlayer || !tslFont || !Canvas || Grenade->bHidden) 
	    continue;
        float Distance = Grenade->GetDistanceTo(g_LocalPlayer) / 100.f;
    if (Distance > 150.f) continue;
        FVector2D ScreenPos;
    if (!W2S(Grenade->K2_GetActorLocation(), &ScreenPos)) continue;
        std::string className = (Grenade->ClassPrivate != nullptr) ? Grenade->ClassPrivate->GetName() : "Unknown";
        std::wstring grenadeName = L"Unknown";
        FLinearColor textColor = FLinearColor(0.f, 1.f, 0.f, 1.f); // Green
    if (className.find("Frag") != std::string::npos) {
        grenadeName = L"Grenade";
        textColor = FLinearColor(1.f, 0.f, 0.f, 1.f); // Red
    } else if (className.find("Burn") != std::string::npos) {
        grenadeName = L"Molotov";
        textColor = FLinearColor(1.f, 0.f, 0.f, 1.f); // Red
    } else if (className.find("Stun") != std::string::npos) {
        grenadeName = L"Stun";
    } else if (className.find("Smoke") != std::string::npos) {
        grenadeName = L"Smoke";
    } else if (className.find("Apple") != std::string::npos) {
        grenadeName = L"Apple";
    }
        std::wstring distanceText = std::to_wstring(static_cast<int>(Distance)) + L"m";
        tslFont->LegacyFontSize = 11;
        FVector2D nameSize = GetTextSize2(grenadeName, tslFont->LegacyFontSize);
        FVector2D distSize = GetTextSize2(distanceText, tslFont->LegacyFontSize);
        float maxWidth = std::max(nameSize.X, distSize.X);
        float centerX = ScreenPos.X - maxWidth / 2.f;
        DrawOutlinedText(Canvas, FString(grenadeName), { centerX, ScreenPos.Y }, textColor, FLinearColor(0.f, 0.f, 0.f, 0.0f), true);
        DrawOutlinedText(Canvas, FString(distanceText), { centerX, ScreenPos.Y + nameSize.Y + 2.f }, textColor, FLinearColor(0.f, 0.f, 0.f, 0.0f), true);
    }
    // 🚀 Draw LootBox Esp
    if (Cheat::Esp::LootBox && Actor->IsA(APickUpListWrapperActor::StaticClass())) {
        auto* Pick = static_cast<APickUpListWrapperActor*>(Actor);
    if (!Pick || !Pick->RootComponent) continue;
        float Distance = Pick->GetDistanceTo(g_LocalPlayer) / 100.f;
    if (Distance > 150.f) continue;
        FVector2D ScreenPos;
    if (!W2S(Pick->K2_GetActorLocation(), &ScreenPos)) continue;
        tslFont->LegacyFontSize = 9;
        std::wstring nameStr = L"LootBox";
        std::wstring distStr = std::to_wstring((int)Distance) + L"M";
        FVector2D NameSize = GetTextSize2(nameStr, 9);
        FVector2D DistSize = GetTextSize2(distStr, 9);
        float nameX = ScreenPos.X - NameSize.X / 2.f;
        float distY = ScreenPos.Y + NameSize.Y + 2.f;
        DrawOutlinedText(Canvas, FString(nameStr), {nameX, ScreenPos.Y}, FLinearColor(0.f, 1.f, 0.f, 1.f), FLinearColor(0,0,0,0), false);
        DrawOutlinedText(Canvas, FString(distStr), {ScreenPos.X - DistSize.X / 2.f, distY}, FLinearColor(0.f, 1.f, 0.f, 1.f), FLinearColor(0,0,0,0), false);
    }
    // 🚀 Draw Loot Esp
	if (Actor->IsA(APickUpWrapperActor::StaticClass())) {
        auto* PickUp = static_cast<APickUpWrapperActor*>(Actor);
    if (!PickUp || !PickUp->RootComponent) continue;
        int itemId = PickUp->DefineID.TypeSpecificID;
        auto it = AutoDrawItems.find(itemId);
    if (it == AutoDrawItems.end() || !it->second.enabled) continue;
        float Distance = PickUp->GetDistanceTo(g_LocalPlayer) / 100.f;
    if (Distance > 50.f) continue;
        FVector2D ScreenPos;
    if (!W2S(PickUp->K2_GetActorLocation(), &ScreenPos)) continue;
        tslFont->LegacyFontSize = 9;
        std::wstring distStr = std::to_wstring((int)Distance) + L"M";
        auto& itemCfg = it->second;
        FVector2D nameSize = GetTextSize2(itemCfg.name, 9);
        FVector2D distSize = GetTextSize2(distStr, 9);
        DrawOutlinedText(Canvas, FString(itemCfg.name), {ScreenPos.X - nameSize.X / 2.f, ScreenPos.Y}, itemCfg.color, FLinearColor(0, 0, 0, 0), false);
        DrawOutlinedText(Canvas, FString(distStr), {ScreenPos.X - distSize.X / 2.f, ScreenPos.Y + nameSize.Y + 2.f}, itemCfg.color, FLinearColor(0, 0, 0, 0), false);
    }
    } //2nd closed
	} //3rd closed
	} //4th closed
    // 🚀 Draw Player Alert
    if (Cheat::Esp::Alert) {
        auto GWorld = GetWorld();
    if (GWorld && GWorld->PersistentLevel && g_LocalPlayer && g_LocalController) {
        auto Actors = GetActors(GWorld->PersistentLevel);
        for (int i = 0; i < Actors.Num(); ++i) {
        auto Actor = Actors[i];
    if (!Actor) continue;
    if (!Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) continue;
        auto* Player = static_cast<ASTExtraPlayerCharacter*>(Actor);
    if (!Player) continue;
    if (Player->PlayerKey == g_LocalController->PlayerKey) continue;
    if (Player->TeamID == g_LocalController->TeamID) continue;
    if (Player->bDead || Player->bHidden) continue;
        FVector TargetPos; 
        ASTExtraVehicleBase* TargetVeh = Player->CurrentVehicle;
    if (TargetVeh) TargetPos = TargetVeh->RootComponent->RelativeLocation;
        else TargetPos = Player->RootComponent->RelativeLocation;
        FVector LocalPos;
        ASTExtraVehicleBase* LocalVeh = g_LocalPlayer->CurrentVehicle;
    if (LocalVeh) LocalPos = LocalVeh->RootComponent->RelativeLocation;
        else LocalPos = g_LocalPlayer->RootComponent->RelativeLocation;
        bool edgeFlag = false;
        FVector EntityPos = WorldToRadar(g_LocalController->PlayerCameraManager->CameraCache.POV.Rotation.Yaw, TargetPos, LocalPos, 0.0f, 0.0f, Vector3((float)glWidth, (float)glHeight, 0.0f), edgeFlag
    );
        Vector3 forward = Vector3((float)(glWidth / 2) - EntityPos.X, (float)(glHeight / 2) - EntityPos.Y, 0.0f);
        FVector angle = FVector();
        VectorAnglesRadar(forward, angle);
        const auto angle_yaw_rad = DEG2RAD(angle.Y + 180.f);
        const auto new_point_x = (glWidth / 2) + (43.f / 2.f) * 8.f * cosf(angle_yaw_rad);
        const auto new_point_y = (glHeight / 2) + (43.f / 2.f) * 8.f * sinf(angle_yaw_rad);
		FLinearColor teamColor = GetColorForTeam(Player->TeamID);
		DrawArrow(Canvas, new_point_x, new_point_y, 10.0f, angle.Y - 90.0f, teamColor);
    }}}
	




if (Cheat::Esp::Count) {
 int total = totalEnemies + totalBots;

 if (total > 0) {
 std::string s;
 s += " ";
 s += std::to_string(total);
 
 // Optional: show breakdown in smaller way (still one visual "box"/line)
 if (totalEnemies > 0 && totalBots > 0) {
 s += " (";
 s += std::to_string(totalEnemies);
 s += "+";
 s += std::to_string(totalBots);
 s += ")";
 }
 
 s += " ";

 tslFont->LegacyFontSize = 22;
 
 DrawOutlinedText(Canvas, FString(s.c_str()), 
 {(float)glWidth / 2, 100}, 
 FLinearColor(1.f, 0.f, 0.f, 1.f),
 COLOR_BLACK,
 true);

 tslFont->LegacyFontSize = TSL_FONT_DEFAULT_SIZE;
 }
}

}//Main Close


void *(*oProcessEvent)(UObject *pObj, UFunction *pFunc, void *pArgs);
void* hkProcessEvent(UObject *a1, UFunction *a, void *b) {
    if (!a1 || !a) return oProcessEvent(a1, a, b);

    auto fnc = a->GetFullName();
 
   if (g_LocalController && g_LocalPlayer &&
        fnc.find("ClientOnDamageToOther") != std::string::npos) {
        auto localController = reinterpret_cast<ASTExtraPlayerController *>(a1);
        auto Params = reinterpret_cast<ASTExtraPlayerController_ClientOnDamageToOther_Params *>(b);
        if (Params) {
            auto damage = Params->_DamageToOther;
            auto HUD = reinterpret_cast<ASurviveHUD *>(localController->MyHUD);
            if (HUD) HUD->AddHitDamageNumberWithConfig(damage, g_LocalPlayer, g_LocalController, 0, 1, 1, 1);
        }
    }
 return oProcessEvent(a1, a, b);
}

//----------
uintptr_t AvatarComponent = 0xb98;   // 64-bit offset
uintptr_t AvatarSyncData  = 0x3E8;   // 64-bit offset

int SkinCarDefault = 0;
int SkinCarMod = 0;
bool SkinCarNew = false;

static std::unordered_set<uintptr_t> ChangedDeadBoxes;
//--------------------------------------------------------------
uintptr_t GetVirtualFunctionAddress(uintptr_t clazz, uintptr_t index) {
    if (!clazz) return 0;
    uintptr_t vtablePtr = *(uintptr_t*)clazz;
    if (!vtablePtr) return 0;
    return *((uintptr_t*)vtablePtr + index);
}
//--------------------------------------------------------------
void ChangeItemAVc(uintptr_t thiz, int InItemID) {
    if (!thiz) return;
    auto fn = GetVirtualFunctionAddress(thiz, 185);
    if (!fn) return;
    ((void(*)(uintptr_t, int, bool))fn)(thiz, InItemID, true);
}
//--------------------------------------------------------------
void LobbySkins(UCanvas* Canvas) {
    auto GWorld = GetWorld();
    if (!GWorld || !GWorld->PersistentLevel)
        return;
        auto Actors = GetActors(GWorld->PersistentLevel);
     /*   for (int i = 0; i < Actors.Num(); ++i) {
        auto Actor = Actors[i];
    if (!Actor)
        continue;
    //--------------------------------------------------------------

	if (Actor->IsA(ASTExtraLobbyCharacter::StaticClass())) {
        auto* LobbyCharacter = (ASTExtraLobbyCharacter*)Actor;
    if (!LobbyCharacter)
        continue;
        auto AvatarComponent2 = (UCharacterAvatarComponent2*)*(uintptr_t*)((uintptr_t)LobbyCharacter + AvatarComponent);
    if (!AvatarComponent2)
        continue;
        auto NetAvatarComp = (FNetAvatarSyncData*)((uintptr_t)AvatarComponent2 + AvatarSyncData);
    if (!NetAvatarComp || NetAvatarComp->SlotSyncData.Num() == 0)
        continue;
        auto& Slotsybc = NetAvatarComp->SlotSyncData;
        bool updated = false;
        int selectedSuitIndex = g_PlayerOutfit.currentOutfit.load();
    if (selectedSuitIndex >= 0 && selectedSuitIndex < IM_ARRAYSIZE(g_Outfits)) {
        int desiredItemId = g_Outfits[selectedSuitIndex].itemId;
    if (Slotsybc.Num() > 2 && Slotsybc[2].ItemId != desiredItemId) {
        Slotsybc[2].ItemId = desiredItemId; // Suit slot (index 2)
        updated = true;
    }}
    if (updated)
        AvatarComponent2->OnRep_BodySlotStateChanged();
    }
    //--------------------------------------------------------------
    // 🔹 Vehicle Lobby Skins
    //--------------------------------------------------------------
    if (Actor->IsA(ASTExtraLobbyVehicle::StaticClass())) {
        auto* LobbyVehicle = (ASTExtraLobbyVehicle*)Actor;
    if (!LobbyVehicle)
        continue;
        auto VehicleAvatar = LobbyVehicle->VehicleAvatar;
    if (!VehicleAvatar)
        continue;
        int defaultSkin = VehicleAvatar->GetDefaultAvatarID();
        auto it = VehicleSkinMap.find(defaultSkin);
    if (it == VehicleSkinMap.end())
        continue;
        int newSkin = it->second;
    if (defaultSkin != newSkin) {
        VehicleAvatar->ChangeItemAvatar(newSkin, true);
        SkinCarDefault = newSkin;
        SkinCarMod = newSkin;
        SkinCarNew = true;
    }}}*/
    //--------------------------------------------------------------
    // 🔹 Dead Box (Tombbox) Skins
    //--------------------------------------------------------------
    if (!g_LocalPlayer || !g_LocalController)
        return;
        auto WeaponMgr = g_LocalPlayer->WeaponManagerComponent;
    if (!WeaponMgr || !WeaponMgr->CurrentWeaponReplicated)
        return;
        int WeaponID = WeaponMgr->CurrentWeaponReplicated->GetWeaponID();
        auto itSkin = ModSkinsID.find(WeaponID);
    if (itSkin == ModSkinsID.end())
        return;
        int desiredSkin = itSkin->second;
        for (int i = 0; i < Actors.Num(); ++i) {
        auto Actor = Actors[i];
    if (!Actor || !Actor->IsA(APlayerTombBox::StaticClass()))
        continue;
        auto* TombBox = (APlayerTombBox*)Actor;
    if (!TombBox || !TombBox->DamageCauser || !TombBox->TargetPlayer)
        continue;
    if (TombBox->DamageCauser->PlayerKey != g_LocalController->PlayerKey)
        continue;
        auto DeadBoxAvatarCompPtr = (uintptr_t*)((uintptr_t)TombBox + 0x718);
    if (!DeadBoxAvatarCompPtr)
        continue;
        auto DeadBoxAvatarComp = *DeadBoxAvatarCompPtr;
    if (!DeadBoxAvatarComp)
        continue;
    if (ChangedDeadBoxes.find(DeadBoxAvatarComp) == ChangedDeadBoxes.end()) {
        ChangeItemAVc(DeadBoxAvatarComp, desiredSkin);
        ChangedDeadBoxes.insert(DeadBoxAvatarComp);
    }
	}

	
}


