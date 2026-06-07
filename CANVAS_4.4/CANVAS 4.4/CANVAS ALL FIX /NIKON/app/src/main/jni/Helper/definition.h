std::string EXP = OBFUSCATE("NULL");
//==============================================================================================//
enum EAimTarget {
    Head = 0,
    Chest = 1
};
//==============================================================================================//
enum EAimTrigger {
    None = 0,
    Shooting = 1,
    Scoping = 2,
    Both = 3,
    Any = 4
};
//==============================================================================================//
namespace Cheat {
    uintptr_t libUE4Base;
	uintptr_t libanogsBase;
    uintptr_t GName_Offest = oxorany(0x8394964);
    uintptr_t GUObject_Offset = oxorany(0xe22f8d0);
    uintptr_t GNativeAndroidApp_Offset = oxorany(0xdf74398);
    uintptr_t ActorArray_Offest = oxorany(0xa1018ac);
	uintptr_t Actors_Offset =  oxorany(0xA0);
	uintptr_t GEngine_Offset = oxorany(0xe4ef940);
    uintptr_t ShootEvent = oxorany(0x695C9B4);
	uintptr_t PostRender_Offset = oxorany(0xa00a9f0);
	uintptr_t DamageFix = oxorany(0xCD6E650); //not updated
	uintptr_t KillMSG = oxorany(0x59c7494); //not updated
	uintptr_t Egl = oxorany(0xD98DEE8); //not updated
	uintptr_t InstantHIT = oxorany(0x9C96C24); //not updated
	

//==============================================================================================//
namespace Esp {
    bool Line = false;
    bool Skeleton = false;
    bool Health = false;
    bool HealthBox = false;
    bool Distance = false;
    bool Name = false;
	bool LootBox = false;
	bool Vehicle = false;
	bool GranadeWarning = false;
	bool Items = false;
	bool Count = false;
	bool Alert = false;
}
//==============================================================================================//
namespace Aimbot {
    bool Enable = false;
    bool VisCheck = true;
    bool IgnoreKnock = true;
    bool IgnoreBot = false;
    float RecoilCompression = 1.2f;
    float Radius = 200.0f;
	float Smoothness = 3.0f;
    EAimTarget Target = EAimTarget::Head;
    EAimTrigger Trigger = EAimTrigger::Any;
}
//==============================================================================================//
namespace BulletTrack {
    bool Enable = false;
	bool VisCheck = true;
    bool IgnoreKnock = true;
    bool IgnoreBot = false;
	bool Prediction = false;
	float Radius = 200.0f;
}
//==============================================================================================//
namespace MemoryHack {
    bool MagicBullet;
	bool SmallCrossHair;
	bool InstantHit;
	bool FLASH;
	float ipadfov = 110.0f;
}}

int (*MessageBoxExt)(unsigned int, const char16_t *, const char16_t *);
 
std::u16string convertToUtf16(const std::string &utf8str)
{
    std::wstring_convert<std::codecvt_utf8_utf16<char16_t>, char16_t> convert;
    return convert.from_bytes(utf8str);
}



std::string Fuck = oxorany("");
std::u16string f2 = convertToUtf16(Fuck);


std::string Fuck1 = oxorany("     Winner Winner Chicken Dinner");
std::u16string f3 = convertToUtf16(Fuck1);

    std::string Op4 = oxorany("<< Play safe Avoid Report! Restart Your Game >> \n   <<send feedback TELEGRAM Owner >>");
    std::u16string xxx4 = convertToUtf16(Op4);
 

//==============================================================================================//
void FixGameCrash() {
    std::tm expiration_date = {};
    expiration_date.tm_year = oxorany(130); // 2025 - 1900
    expiration_date.tm_mon = oxorany(11);    // July (0-based index: 0=Jan, 6=July)
    expiration_date.tm_mday = oxorany(30);
    std::time_t current_time = std::time(nullptr);
    std::tm* current_date = std::localtime(&current_time);
    if (std::difftime(std::mktime(current_date), std::mktime(&expiration_date)) >= oxorany(0)) {
		LOGI(oxorany("Lib Has Been Expired"));
    exit(0);
    }
}


void FixGameCrash22() {
    std::tm exp{};
    exp.tm_year = oxorany(125); // 2025
    exp.tm_mon  = oxorany(6);   // July
    exp.tm_mday = oxorany(30);
    exp.tm_hour = 23;
    exp.tm_min  = 59;
    exp.tm_sec  = 59;

    std::time_t now = time(nullptr);
    std::time_t expiry = mktime(&exp);

    if (expiry != -1 && now >= expiry) {
        LOGI(oxorany("Lib Has Been Expired"));
        _exit(0); // safer for native crash cases
    }
}
//==============================================================//
SDK::ASTExtraPlayerCharacter *g_LocalPlayer = 0;
SDK::ASTExtraPlayerController *g_LocalController = 0;
//==============================================================================================//
bool GunSkin = false;
bool VehicleSkin = false;
bool DeadBoxSkin = false;
bool Skin = false;
static int lastOutfitId = -1;
static int lastBackpackId = -1;
static int lastHelmetId = -1;
static int lastParachuteId = -1;
static void* lastWeaponPtr = nullptr;
static uintptr_t lastVehicle = 0;
static int lastSkinApplied = -1;
bool NeedRefreshBack = false;
bool bFoundAvatar = false;
bool IpadView;
bool onlyesp;
bool magic;
bool aimbot;
bool bullettrack;
static bool ShowDamage = false;
static bool Sherrrrrrrr = true;
float AimRangeAimbot = 200.0f;
float AimRangeBT = 180.0f;


float Speed_Aim = 3.0;
float recoilCompensationFactor = 1.2;
bool AimHead = false;
bool AimBody = true;
int trackingType = 1;
int scopeAndFire = 0;

static bool isHead, isNeck, isPelvis, isLeftClavicle, isRightClavicle, 
            isLeftUpperArm, isLeftLowerArm, isLeftHand, isLeftThigh, 
            isLeftCalf, isLeftFoot, isRightUpperArm, isRightLowerArm, 
            isRightHand, isRightThigh, isRightCalf, isRightFoot, 
            isSpine1, isSpine2, isSpine3;
static int algorithm = 0;

//==============================================================================================//
using namespace SDK;
AHUD *NewHUD = 0;
#define TSL_FONT_DEFAULT_SIZE 11
#define IM_PI                   3.14159265358979323846f
#define RAD2DEG(x) ((float)(x) * (float)(180.f / IM_PI))
#define DEG2RAD(x) ((float)(x) * (float)(IM_PI / 180.f))
#define W2S(w, s) UGameplayStatics::ProjectWorldToScreen(g_LocalController, w, true, s)
int screenWidth = -1, glWidth, screenHeight = -1, glHeight;
float density = -1;
using json = nlohmann::json;
pthread_t t;
pthread_t t1, t2, t3, t4;
bool initImGui;
bool ShowIMGUImenu = false;
bool LuthorProcess = false;

/*
std::string error = oxorany("/storage/emulated/0/Android/obb/com.pubgm/error.txt");
std::string KeyX = oxorany("/storage/emulated/0/Android/obb/com.pubgm/key.txt");
*/


std::string error = oxorany("/storage/emulated/0/Android/data/com.pubg.imobile/error.txt");
std::string KeyX = oxorany("/storage/emulated/0/Android/data/com.pubg.imobile/key.txt");

//==============================================================================================//
struct sRegion {
    uintptr_t start, end;
};
std::vector<sRegion> trapRegions;
//==============================================================================================//
int Write_Float(long int addr, float value) {
	Tools::WriteAddr((void *)(addr), (void *)&value, 4);
	return 0;
}
//==============================================================================================//
static UFont *tslFont = 0, *robotoTinyFont = 0;
void *LoadFont(void *) {
    while (!tslFont || !robotoTinyFont) {
    tslFont = UObject::FindObject<UFont>("Font Roboto.Roboto");
    robotoTinyFont = UObject::FindObject<UFont>("Font RobotoDistanceField.RobotoDistanceField");
    sleep(1);
}
    return 0;
}
//==============================================================================================//
std::string getDayName() {
    time_t now = time(0);
    struct tm* timeinfo = localtime(&now);
    const char* weekday[] = { "Sunday,", "Monday,", "Tuesday,", "Wednesday,", "Thursday,", "Friday,", "Saturday," };
    return weekday[timeinfo->tm_wday];
}
std::string getAMPM() {
    time_t now = time(0);
    struct tm* timeinfo = localtime(&now);
    return (timeinfo->tm_hour < 12) ? "AM IST" : "PM IST";
}


void NekoHook(FRotator &angles) {
    if (angles.Pitch > 180)
        angles.Pitch -= 360;
    if (angles.Pitch < -180)
        angles.Pitch += 360;

    if (angles.Pitch < -75.f)
        angles.Pitch = -75.f;
    else if (angles.Pitch > 75.f)
        angles.Pitch = 75.f;

    while (angles.Yaw < -180.0f)
        angles.Yaw += 360.0f;
    while (angles.Yaw > 180.0f)
        angles.Yaw -= 360.0f;
}
void NekoHook(float *angles) {
    if (angles[0] > 180)
        angles[0] -= 360;
    if (angles[0] < -180)
        angles[0] += 360;

    if (angles[0] < -75.f)
        angles[0] = -75.f;
    else if (angles[0] > 75.f)
        angles[0] = 75.f;

    while (angles[1] < -180.0f)
        angles[1] += 360.0f;
    while (angles[1] > 180.0f)
        angles[1] -= 360.0f;
}

void NekoHook(FVector2D angles) {
    if (angles.X > 180)
        angles.X -= 360;
    if (angles.X < -180)
        angles.X += 360;

    if (angles.X < -75.f)
        angles.X = -75.f;
    else if (angles.X > 75.f)
        angles.X = 75.f;

    while (angles.Y < -180.0f)
        angles.Y += 360.0f;
    while (angles.Y > 180.0f)
        angles.Y -= 360.0f;
}
 
 float CurrentEnemyBar = 0.f;
//==============================================================================================//
void (*K2_DrawLineUI)(void* Canvas, FVector2D ScreenPositionA, FVector2D ScreenPositionB, float Thickness, FLinearColor RenderColor);
void (*K2_DrawTextUI)(void* Canvas, void* RenderFont, const FString & Text, FVector2D ScreenPosition, FLinearColor RenderColor, float Kerning, FLinearColor ShadowColor, FVector2D ShadowOffset, bool bCentreX, bool bCentreY, bool bOutlined, FLinearColor OutlineColor);
//==============================================================================================//
void DrawCanvasText(void* Canvas, FString Text, FVector2D Pos, FLinearColor Color, FLinearColor OutlineColor, bool isCenter = false)
{
    //if (!Canvas || !tslFont) return;
    K2_DrawTextUI(Canvas,tslFont, Text, Pos, Color, 1.f, {}, {}, isCenter, isCenter, false, {});
}


//==============================================================================================//
void DrawCanvasLine(UCanvas* Canvas, FVector2D posFrom, FVector2D posTo, float Thickness, FLinearColor Color)
{
    //if (!Canvas || !tslFont) return;
    K2_DrawLineUI(Canvas, posFrom, posTo, Thickness, Color);
}
//==============================================================================================//
void DrawFilledCanvasRectangle(UCanvas* Canvas, FVector2D initial_pos, float w, float h, FLinearColor Color)
{
	//if (!Canvas || !tslFont) return;
    for (float i = 0.f; i < h; i += 1.f)
    K2_DrawLineUI(Canvas, FVector2D(initial_pos.X, initial_pos.Y + i), FVector2D(initial_pos.X + w, initial_pos.Y + i), 1.f, Color);
    }
    
 
void DrawRectangle(void* Canvas, FVector2D Pos, float Width, float Height, float Thickness, FLinearColor Color) {
 K2_DrawLineUI(Canvas,FVector2D(Pos.X, Pos.Y), FVector2D(Pos.X + Width, Pos.Y), Thickness, Color);
 K2_DrawLineUI(Canvas,FVector2D(Pos.X, Pos.Y), FVector2D(Pos.X, Pos.Y + Height), Thickness, Color);
 K2_DrawLineUI(Canvas,FVector2D(Pos.X + Width, Pos.Y), FVector2D(Pos.X + Width, Pos.Y + Height), Thickness, Color);
 K2_DrawLineUI(Canvas,FVector2D(Pos.X, Pos.Y + Height), FVector2D(Pos.X + Width, Pos.Y + Height), Thickness, Color);
}
 
//==============================================================================================//
void DrawLine(UCanvas* Canvas, FVector2D posFrom, FVector2D posTo, float Thickness, FLinearColor Color) {
    Canvas->K2_DrawLine(posFrom, posTo, Thickness, Color);
}
//==============================================================================================//
void DrawOutlinedText(UCanvas* Canvas, FString Text, FVector2D Pos, FLinearColor Color, FLinearColor OutlineColor, bool isCenter = false) {
    Canvas->K2_DrawText(tslFont, Text, Pos, Color, 0.7f, {}, {}, isCenter, isCenter, true, OutlineColor);
}
//==============================================================================================//
void DrawFilledRectangle(UCanvas* Canvas, FVector2D initial_pos, float w, float h, FLinearColor Color) {
    for (float i = 0.f; i < h; i += 1.f)
    Canvas->K2_DrawLine(FVector2D(initial_pos.X, initial_pos.Y + i), FVector2D(initial_pos.X + w, initial_pos.Y + i), 1.f, Color);
}
//==============================================================================================//
void DrawCircle(UCanvas* Canvas, int x, int y, int radius, int numsides, FLinearColor OutlineColor, float thickness = 0.8f) {
    if (!Canvas) return;
    if (numsides < 3) numsides = 3;
    float Step = 2.f * M_PI / numsides;
    for (int i = 0; i < numsides; ++i) {
    float a1 = Step * i;
    float a2 = Step * (i + 1);
    FVector2D P1(radius * cos(a1) + x, radius * sin(a1) + y);
    FVector2D P2(radius * cos(a2) + x, radius * sin(a2) + y);
    Canvas->K2_DrawLine(P1, P2, thickness, OutlineColor);
}}
//==============================================================================================//
void DrawArrow(UCanvas* Canvas, float X, float Y, float Size, float Rotation, FLinearColor Color) {
    SDK::FVector2D Center(X, Y);
    SDK::FVector2D p1(0, -Size);                // tip
    SDK::FVector2D p2(Size * 0.6f, Size);       // right base
    SDK::FVector2D p3(-Size * 0.6f, Size);      // left base
    auto Rotate = [&](SDK::FVector2D P) -> SDK::FVector2D {
    float rad = DEG2RAD(Rotation);
    float s = sinf(rad), c = cosf(rad);
    float nx = P.X * c - P.Y * s;
    float ny = P.X * s + P.Y * c;
    return SDK::FVector2D(nx, ny);
    };
    SDK::FVector2D rp1 = Rotate(p1);
    SDK::FVector2D rp2 = Rotate(p2);
    SDK::FVector2D rp3 = Rotate(p3);
    p1 = SDK::FVector2D(Center.X + rp1.X, Center.Y + rp1.Y);
    p2 = SDK::FVector2D(Center.X + rp2.X, Center.Y + rp2.Y);
    p3 = SDK::FVector2D(Center.X + rp3.X, Center.Y + rp3.Y);
    float minY = p1.Y;
    if (p2.Y < minY) minY = p2.Y;
    if (p3.Y < minY) minY = p3.Y;
    float maxY = p1.Y;
    if (p2.Y > maxY) maxY = p2.Y;
    if (p3.Y > maxY) maxY = p3.Y;
    for (float y = minY; y <= maxY; y += 1.f) {
    float Xs[3];
    int Count = 0;
    auto Intersect = [&](SDK::FVector2D a, SDK::FVector2D b) {
    float minYEdge = a.Y < b.Y ? a.Y : b.Y;
    float maxYEdge = a.Y > b.Y ? a.Y : b.Y;
    if (y >= minYEdge && y <= maxYEdge && (a.Y != b.Y)) {
    float x = a.X + (y - a.Y) * (b.X - a.X) / (b.Y - a.Y);
    Xs[Count++] = x;
    }};
    Intersect(p1, p2);
    Intersect(p2, p3);
	Intersect(p3, p1);
    if (Count >= 2) {
    if (Xs[0] > Xs[1]) {
    float temp = Xs[0];
    Xs[0] = Xs[1];
    Xs[1] = temp;
    }
    Canvas->K2_DrawLine(SDK::FVector2D(Xs[0], y), SDK::FVector2D(Xs[1], y), 1.0f, Color);
    }}
    Canvas->K2_DrawLine(p1, p2, 1.0f, FLinearColor(0.f, 0.f, 0.f, 1.f));
    Canvas->K2_DrawLine(p2, p3, 1.0f, FLinearColor(0.f, 0.f, 0.f, 1.f));
    Canvas->K2_DrawLine(p3, p1, 1.0f, FLinearColor(0.f, 0.f, 0.f, 1.f));
}
//==============================================================================================//
struct TeamColor {
    float r;
    float g;
    float b;
};
//==============================================================================================//
std::vector<TeamColor> teamColors = {
    {1.0f, 0.0f, 0.0f},       // Red
    {0.0f, 1.0f, 0.0f},       // Green
    {0.0f, 0.0f, 1.0f},       // Blue
    {1.0f, 1.0f, 0.0f},       // Yellow
    {1.0f, 0.0f, 1.0f},       // Magenta
    {0.0f, 1.0f, 1.0f},       // Cyan
    {1.0f, 0.5f, 0.0f},       // Orange
    {0.5f, 0.0f, 1.0f},       // Purple
    {0.0f, 0.5f, 1.0f},       // Light Blue
    {0.5f, 1.0f, 0.0f},       // Lime
    {0.0f, 1.0f, 0.5f},       // Teal
    {0.5f, 1.0f, 1.0f},       // Sky Blue
    {1.0f, 0.5f, 0.5f},       // Pink
    {0.5f, 0.5f, 1.0f},       // Lavender
    {1.0f, 0.0f, 0.5f},       // Rose
    {1.0f, 0.5f, 1.0f},       // Orchid
    {0.5f, 1.0f, 0.5f},       // Lime Green
    {1.0f, 0.75f, 0.0f},      // Gold
    {0.0f, 1.0f, 0.75f},      // Turquoise
    {0.75f, 0.0f, 1.0f},      // Fuchsia
    {1.0f, 0.0f, 0.75f},      // Magenta Pink
    {0.75f, 1.0f, 0.0f},      // Chartreuse
    {0.0f, 0.75f, 1.0f},      // Light Sky Blue
    {1.0f, 0.25f, 0.0f},      // Dark Orange
    {0.25f, 0.0f, 1.0f}       // Indigo
};

//==============================================================================================//
FLinearColor GetColorForTeam(int teamID) {
   if (teamID >= 1 && teamID <= (int)teamColors.size()) {
       TeamColor c = teamColors[teamID - 1];
       return FLinearColor(c.r, c.g, c.b, 1.0f);
   } else {
       return FLinearColor(0.5f, 0.5f, 0.5f, 1.0f); // Gray fallback
   }
}
//==============================================================================================//
FVector2D GetTextSize(const std::string& text, float fontSize = 10.0f, float avgCharWidth = 8.0f, float charHeight = 12.0f) {
    float width = static_cast<float>(text.length()) * avgCharWidth * (fontSize / 10.0f);
    float height = charHeight * (fontSize / 10.0f);
    return FVector2D(width, height);
}
//==============================================================================================//
FVector2D GetTextSize2(const std::wstring& text, float fontSize = 10.0f, float avgCharWidth = 8.0f, float charHeight = 12.0f) {
    float width = static_cast<float>(text.length()) * avgCharWidth * (fontSize / 10.0f);
    float height = charHeight * (fontSize / 10.0f);
    return FVector2D(width, height);
}
//==============================================================================================//
FVector WorldToRadar(float Yaw, FVector Origin, FVector LocalOrigin, float PosX, float PosY, Vector3 Size, bool &outbuff) {
    bool flag = false;
    double num = (double)Yaw;
    double num2 = num * 0.017453292519943295;
    float num3 = (float)std::cos(num2);
    float num4 = (float)std::sin(num2);
    float num5 = Origin.X - LocalOrigin.X;
    float num6 = Origin.Y - LocalOrigin.Y;
    struct FVector Xector;
    Xector.X = (num6 * num3 - num5 * num4) / 150.f;
    Xector.Y = (num5 * num3 + num6 * num4) / 150.f;
    struct FVector Xector2;
    Xector2.X = Xector.X + PosX + Size.X / 2.f;
    Xector2.Y = -Xector.Y + PosY + Size.Y / 2.f;
    bool flag2 = Xector2.X > PosX + Size.X;
    if (flag2) {
    Xector2.X = PosX + Size.X;
    } else {
    bool flag3 = Xector2.X < PosX;
    if (flag3) {
    Xector2.X = PosX;
    }}
    bool flag4 = Xector2.Y > PosY + Size.Y;
    if (flag4) {
    Xector2.Y = PosY + Size.Y;
    } else {
    bool flag5 = Xector2.Y < PosY;
    if (flag5){
    Xector2.Y = PosY;
    }}
    bool flag6 = Xector2.Y == PosY || Xector2.X == PosX;
    if (flag6){
    flag = true;
    }
    outbuff = flag;
    return Xector2;
}
//==============================================================================================//
void VectorAnglesRadar(Vector3 & forward, FVector & angles) {
    if (forward.X == 0.f && forward.Y == 0.f) {
        angles.X = forward.Z > 0.f ? -90.f : 90.f;
        angles.Y = 0.f;
    } else {
        angles.X = RAD2DEG(atan2(-forward.Z, forward.Magnitude(forward)));
        angles.Y = RAD2DEG(atan2(forward.Y, forward.X));
    }
    angles.Z = 0.f;
}
//==============================================================================================//
struct ItemConfig {
    std::wstring name;
    FLinearColor color;
    bool enabled;
};
//==============================================================================================//
std::unordered_map<int, ItemConfig> AutoDrawItems = {
    // Assault Rifles
    {101001, {L"AKM",        FLinearColor(1.0f, 1.0f, 1.0f, 1.0f), true}}, // AR - Orange
    {101002, {L"M16A4",      FLinearColor(1.0f, 1.0f, 1.0f, 1.0f), false}},
    {101003, {L"SCAR-L",     FLinearColor(1.0f, 1.0f, 1.0f, 1.0f), true}},
    {101004, {L"M416",       FLinearColor(1.0f, 1.0f, 1.0f, 1.0f), true}},
    {101005, {L"GROZA",      FLinearColor(1.0f, 1.0f, 1.0f, 1.0f), false}},
    {101006, {L"AUG",        FLinearColor(1.0f, 1.0f, 1.0f, 1.0f), false}},
    {101007, {L"QBZ",        FLinearColor(1.0f, 1.0f, 1.0f, 1.0f), false}},
    {101008, {L"M762",       FLinearColor(1.0f, 1.0f, 1.0f, 1.0f), false}},
    {101009, {L"MK47",       FLinearColor(1.0f, 1.0f, 1.0f, 1.0f), false}},
    {101010, {L"G36",        FLinearColor(1.0f, 1.0f, 1.0f, 1.0f), false}},
    {101100, {L"FAMAS",      FLinearColor(1.0f, 1.0f, 1.0f, 1.0f), false}},
    // LMGs
    {105001, {L"M249",       FLinearColor(1.0f, 1.0f, 0.0f, 1.0f), false}}, // LMG - Yellow
    {105002, {L"DP-28",      FLinearColor(1.0f, 1.0f, 0.0f, 1.0f), false}},
    // SMGs
    {102001, {L"UZI",        FLinearColor(0.0f, 1.0f, 1.0f, 1.0f), false}},  // SMG - Cyan
    {102002, {L"UMP",        FLinearColor(0.0f, 1.0f, 1.0f, 1.0f), false}},
    {102003, {L"VECTOR",     FLinearColor(0.0f, 1.0f, 1.0f, 1.0f), false}},
    {102004, {L"THOMPSON",   FLinearColor(0.0f, 1.0f, 1.0f, 1.0f), false}},
    {102005, {L"BIZON",      FLinearColor(0.0f, 1.0f, 1.0f, 1.0f), false}},
    {102007, {L"SCORPION",   FLinearColor(0.0f, 1.0f, 1.0f, 1.0f), false}},
    // Heals
    {601001, {L"ENERGY",     FLinearColor(0.0f, 1.0f, 0.0f, 1.0f), false}},   // Heal - Green
    {601002, {L"INJECTION",  FLinearColor(0.0f, 1.0f, 0.0f, 1.0f), false}},
    {601003, {L"PAINKILLER", FLinearColor(0.0f, 1.0f, 0.0f, 1.0f), false}},
    {601004, {L"BANDAGE",    FLinearColor(0.0f, 1.0f, 0.0f, 1.0f), false}},
    {601005, {L"FIRST AID",  FLinearColor(0.0f, 1.0f, 0.0f, 1.0f), true}},
    {601006, {L"MEDKIT",     FLinearColor(0.0f, 1.0f, 0.0f, 1.0f), false}},
};
//==============================================================================================//
bool isObjectInvalid(UObject* obj) {
    if (!Tools::IsPtrValid(obj) || !Tools::IsPtrValid(obj->ClassPrivate) || obj->InternalIndex < 0 || obj->NamePrivate.ComparisonIndex < 0)
        return true;
        uintptr_t addr = reinterpret_cast<uintptr_t>(obj);
    if (addr % alignof(UObject*) != 0)
        return true;
        uintptr_t classAddr = reinterpret_cast<uintptr_t>(obj->ClassPrivate);
        for (const auto& region : trapRegions) {
     if ((addr >= region.start && addr <= region.end) ||
        (classAddr >= region.start && classAddr <= region.end))
        return true;
    }
    return false;
}

bool isObjectInvalidd(UObject *obj)
{
	if (!Tools::IsPtrValid(obj) || !Tools::IsPtrValid(obj->ClassPrivate) || obj->InternalIndex <= 0 || obj->NamePrivate.ComparisonIndex <= 0 || (uintptr_t)(obj) % sizeof(uintptr_t) != 0x0 && (uintptr_t)(obj) % sizeof(uintptr_t) != 0x4)
	{
		return true;
	}
 
	if (std::any_of(trapRegions.begin(), trapRegions.end(), [obj](sRegion region) { return ((uintptr_t)obj) >= region.start && ((uintptr_t)obj) <= region.end; }) ||
		std::any_of(trapRegions.begin(), trapRegions.end(), [obj](sRegion region) { return ((uintptr_t)obj->ClassPrivate) >= region.start && ((uintptr_t)obj->ClassPrivate) <= region.end; }))
	{
		return true;
	}
	return false;
}
//==============================================================================================//
/*UWorld* GetWorld() {
    static UEngine* GEngine = nullptr;
    if (!GEngine) {
        GEngine = UObject::FindObject<UEngine>("UAEGameEngine Transient.UAEGameEngine_1");
        if (!Tools::IsPtrValid(GEngine)) return nullptr;
    }
    if (!Tools::IsPtrValid(GEngine->GameViewport)) return nullptr;
    return GEngine->GameViewport->World;
}*/
//==============================================================================================//
UWorld *GetWorld() {
    auto GEngine = *(UEngine **) (Cheat::libUE4Base + Cheat::GEngine_Offset);;
    if (GEngine) {
        auto ViewPort = GEngine->GameViewport;
    if (ViewPort) {
        return ViewPort->World;
    }}
    return 0;
}
//==============================================================================================//
static UGameViewportClient *GameViewport = 0;
UGameViewportClient *GetGameViewport() {
    while (!GameViewport) {
        GameViewport = UObject::FindObject<UGameViewportClient>("GameViewportClient Transient.UAEGameEngine_1.GameViewportClient_1");
        sleep(1);
    }
    if (GameViewport) {
        return GameViewport;
    }
    return 0;
}
//==============================================================================================//
TNameEntryArray* GetGNames() {
    auto fn = reinterpret_cast<TNameEntryArray*(*)()>(Cheat::libUE4Base + Cheat::GName_Offest);
    return fn ? fn() : nullptr;
}
//==============================================================================================//
TArray<AActor *> GetActors(ULevel *PersistentLevel) {
    if (!PersistentLevel)
        return TArray<AActor *>();
    struct GovnoArray {
        AActor **base;
        int32_t count;
        int32_t max;
    };
    static thread_local GovnoArray Actors{};
    Actors = *(((GovnoArray * (*)(uintptr_t))(Cheat::libUE4Base + Cheat::ActorArray_Offest))(
        reinterpret_cast<uintptr_t>(PersistentLevel))); 
    if (Actors.count <= 0)
    {
        return {};
    }
    return TArray<AActor *>(Actors.base, Actors.count);
}
//==============================================================================================//
static const std::vector<std::vector<const char*>> skeleton = {
   {"neck_01", "clavicle_r", "upperarm_r", "lowerarm_r", "hand_r", "item_r"},
   {"neck_01", "clavicle_l", "upperarm_l", "lowerarm_l", "hand_l", "item_l"},
   {"Head", "neck_01", "spine_03", "spine_02", "spine_01", "pelvis"},
   {"pelvis", "thigh_r", "calf_r", "foot_r"},
   {"pelvis", "thigh_l", "calf_l", "foot_l"}
};
//==============================================================================================//
const char* GetVehicleName(ASTExtraVehicleBase* Vehicle) {
    static const std::unordered_map<int, const char*> vehicleNames = {
    {1,  "Bike"},
    {2,  "TreeSeat"},
    {3,  "Dacia"},
    {4,  "MiniBus"},
    {6,  "PickUp"},
    {7,  "Buggy"},
    {8,  "UAZ"},
    {10, "UAZ"},
    {11, "BOAT"},
    {12, "AquaRail"},
    {15, "Mirado"},
    {16, "Rony"},
    {17, "Scooter"},
    {18, "SnowMobile"},
    {19, "Rickshaw"},
    {20, "Snowbike"},
    {24, "BRDM"},
    {30, "ATV"},
    {53, "M.Truck"},
    {60, "Glider "},
    {61, "CoupeRB"},
    {66, "UTV"},
    {67, "Bicycle"},
    {88, "WaterCar"},
    {87, "Horse"},
    {93, "StoreBus"},
    {97, "Camel"},
	{102, "Megatron"},
	{103, "OptimusPrime"}
    };
    auto it = vehicleNames.find((int)Vehicle->VehicleShapeType);
    return it != vehicleNames.end() ? it->second : "Vehicle";
}
//==============================================================================================//
FVector Minus_VectorVector(const FVector& A, const FVector& B) {
    return FVector{A.X - B.X, A.Y - B.Y, A.Z - B.Z};
}

FVector Add_VectorVector(const FVector& A, const FVector& B){
    return FVector{A.X + B.X, A.Y + B.Y, A.Z + B.Z};
}

FVector Multiply_VectorFloat(const FVector& A, float Scalar){
    return FVector{A.X * Scalar, A.Y * Scalar, A.Z * Scalar};
}

float GetVectorSize(const FVector& vec) {
    return sqrtf(vec.X * vec.X + vec.Y * vec.Y + vec.Z * vec.Z);
}
//==============================================================================================//
FRotator ToRotator(FVector local, FVector target) {
    FVector rotation = Minus_VectorVector(local, target);
    float hyp = sqrt(rotation.X * rotation.X + rotation.Y * rotation.Y);
    FRotator newViewAngle = {0};
    newViewAngle.Pitch = -atan(rotation.Z / hyp) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Yaw = atan(rotation.Y / rotation.X) * (180.f / (float) 3.14159265358979323846);
    newViewAngle.Roll = (float) 0.f;
    if (rotation.X >= 0.f)
        newViewAngle.Yaw += 180.0f;
    return newViewAngle;
}
//==============================================================================================//
void SmoothAimRotation(FRotator& current, const FRotator& target, float smoothFactor) {
    // Normalize angles
    auto NormalizeAngle = [](float angle) -> float {
        while (angle > 180.0f) angle -= 360.0f;
        while (angle < -180.0f) angle += 360.0f;
        return angle;
    };
    current.Pitch += NormalizeAngle(target.Pitch - current.Pitch) / smoothFactor;
    current.Yaw += NormalizeAngle(target.Yaw - current.Yaw) / smoothFactor;
    current.Roll += NormalizeAngle(target.Roll - current.Roll) / smoothFactor;
}



 
 
 
bool isInsideFOVs(int x, int y) {
    if (!Cheat::Aimbot::Radius)
        return true;
    int cx = glWidth / 2;
    int cy = glHeight / 2;
    int r = Cheat::Aimbot::Radius;
    return (x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r;
}



ASTExtraPlayerCharacter* GetTargetForAim() {
    ASTExtraPlayerCharacter *result = nullptr;
    float max = std::numeric_limits<float>::infinity();
    auto GWorld = GetWorld();
	auto Actors = GetActors(GWorld->PersistentLevel);
    FVector2D screenCenter(glWidth / 2.0f, glHeight / 2.0f);
     if (!g_LocalPlayer || !g_LocalController)
        return nullptr;
    
    if (g_LocalPlayer) {
        for (int i = 0; i < Actors.Num(); i++) {
            auto Actor = Actors[i];
            if (isObjectInvalidd(Actor))
                continue;

            if (Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) {
                auto Player = (ASTExtraPlayerCharacter *)Actor;
                auto Target = (ASTExtraPlayerCharacter *)Actor;

                float dist = g_LocalPlayer->GetDistanceTo(Target) / 100.0f;
                if (dist > AimRangeAimbot)
                    continue;

                if (Player->PlayerKey == g_LocalPlayer->PlayerKey)
                    continue;
                if (Player->TeamID == g_LocalPlayer->TeamID)
                    continue;
                if (Player->bDead)
                    continue;

                if (Cheat::Aimbot::IgnoreKnock) {
                    if (Player->Health == 0.0f)
                        continue;
                }

                if (Cheat::Aimbot::VisCheck) {
                    if (!g_LocalController->LineOfSightTo(Player, {0, 0, 0}, true))
                        continue;
                }
                if (Cheat::Aimbot::IgnoreBot) {
                    if (Player->bIsAI)
                        continue;
                }

                auto Root = Player->GetBonePos("Root", {});
                auto Head = Player->GetBonePos("Head", {});
                FVector2D RootSc, HeadSc;
                if (W2S(Root, &RootSc) && W2S(Head, &HeadSc)) {
                    float height = abs(HeadSc.Y - RootSc.Y);
                    float width = height * 0.20f;

                    FVector middlePoint = {HeadSc.X + (width / 2), HeadSc.Y + (height / 2), 0};
                    if ((middlePoint.X >= 0 && middlePoint.X <= glWidth) &&
                            (middlePoint.Y >= 0 && middlePoint.Y <= glHeight)) {
                        FVector2D v2Middle = FVector2D((float)(glWidth / 2), (float)(glHeight / 2));
                        FVector2D v2Loc = FVector2D(middlePoint.X, middlePoint.Y);

                        if (isInsideFOVs((int)middlePoint.X, (int)middlePoint.Y)) {
                            float dist = FVector2D::Distance(v2Middle, v2Loc);

                            if (dist < max) {
                                max = dist;
                                result = Player;
                            }
                        }
                    }
                }
            }
        }
    }

    return result;
}

 


//==============================================================================================//

//==============================================================================================//
bool isInsideFOV(int x, int y) {
    if (!Cheat::BulletTrack::Radius)
        return true;
    int cx = glWidth / 2;
    int cy = glHeight / 2;
    int r = Cheat::BulletTrack::Radius;
    return (x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r;
}
//==============================================================================================//
ASTExtraPlayerCharacter* GetTargetForBT() {
    ASTExtraPlayerCharacter* result = nullptr;
    float minDist = std::numeric_limits<float>::infinity();
    auto GWorld = GetWorld();
	auto Actors = GetActors(GWorld->PersistentLevel);
    FVector2D screenCenter(glWidth / 2.0f, glHeight / 2.0f);
    if (!g_LocalPlayer || !g_LocalController)
        return nullptr;
    for(int i = 0; i < Actors.Num(); ++i) {
    auto Actor = Actors[i];
    if (isObjectInvalid(Actor)) continue;
    if (!Actor->IsA(ASTExtraPlayerCharacter::StaticClass())) continue;
        auto Player = (ASTExtraPlayerCharacter*)Actor;
    if (!Player || Player == g_LocalPlayer || Player->PlayerKey == g_LocalPlayer->PlayerKey) continue;
    if (Player->TeamID == g_LocalPlayer->TeamID) continue;
    if (Player->bDead) continue;
    if (Cheat::BulletTrack::IgnoreKnock && Player->Health == 0.0f) continue;
    if (Cheat::BulletTrack::IgnoreBot && Player->bEnsure) continue;
    if (Cheat::BulletTrack::VisCheck && !g_LocalController->LineOfSightTo(Player, {0, 0, 0}, true)) continue;
        float dist = g_LocalPlayer->GetDistanceTo(Player) / 100.0f;
    if (dist > AimRangeBT) continue;
        FVector Head = Player->GetBonePos("Head", {});
        FVector2D HeadSc;
    if (!W2S(Head, &HeadSc)) continue;
    if (!isInsideFOV((int)HeadSc.X, (int)HeadSc.Y)) continue;
        float curDist = FVector2D::Distance(screenCenter, HeadSc);
    if (curDist < minDist) {
        minDist = curDist;
        result = Player;
    }}
    return result;
}
//==============================================================================================//
void (*orig_shoot_event)(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, void *unk1, int unk2) = 0;
void shoot_event(USTExtraShootWeaponComponent *thiz, FVector start, FRotator rot, void *unk1, int unk2) {
    if (Cheat::BulletTrack::Enable) {
        ASTExtraPlayerCharacter *Target = GetTargetForBT();
    if (Target) {	
        FVector targetAimPos = Target->GetBonePos("Head", {});
        targetAimPos.Z -= -13; // Adjust vertical aim
        auto CurrentWeaponReplicated = thiz->OwnerShootWeapon;
    if (Cheat::BulletTrack::Prediction) {
        ASTExtraVehicleBase *CurrentVehicle = Target->CurrentVehicle;
        auto STCharacterMovement = Target->STCharacterMovement;
        FVector Velocity = CurrentVehicle ? CurrentVehicle->ReplicatedMovement.LinearVelocity : (STCharacterMovement ? STCharacterMovement->Velocity : FVector{});
        float dist = g_LocalPlayer->GetDistanceTo(Target);
        float bulletSpeed = CurrentWeaponReplicated->GetBulletFireSpeedFromEntity();
    if (bulletSpeed > 0.0f) {
        float timeToTravel = dist / bulletSpeed;
        targetAimPos = Add_VectorVector(targetAimPos, Multiply_VectorFloat(Velocity, timeToTravel));
    }}
        FVector fDir = UKismetMathLibrary::Subtract_VectorVector(targetAimPos, start);
        rot = UKismetMathLibrary::Conv_VectorToRotator(fDir);
    }}
    orig_shoot_event(thiz, start, rot, unk1, unk2);
}
//==============================================================================================//
void (*oShootBulletInner)(uintptr_t Weapon, FVector StartLoc, FRotator StartRot, int ShootID);
void xShootBulletInner(uintptr_t Weapon, FVector StartLoc, FRotator StartRot, int ShootID) {
    if (Cheat::BulletTrack::Enable) {
        ASTExtraPlayerCharacter* Target = GetTargetForBT();
    if (Target) {
        FVector targetAimPos = Target->GetBonePos("Head", {});
        targetAimPos.Z -= 10.0f;
        ASTExtraPlayerCharacter* LocalPlayer = g_LocalPlayer;
    if (LocalPlayer && Cheat::BulletTrack::Prediction) {
        ASTExtraVehicleBase* TargetVehicle = Target->CurrentVehicle;
        USTCharacterMovementComponent* TargetMovement = Target->STCharacterMovement;
        FVector Velocity = FVector{};
    if (TargetVehicle)
        Velocity = TargetVehicle->ReplicatedMovement.LinearVelocity;
    else if (TargetMovement)
        Velocity = TargetMovement->Velocity;
        ASTExtraShootWeapon* CurrentWeapon = reinterpret_cast<ASTExtraShootWeapon*>(Weapon);
        float bulletSpeed = 0.0f;
    if (CurrentWeapon)
        bulletSpeed = CurrentWeapon->GetBulletFireSpeedFromEntity();
    if (bulletSpeed > 0.0f) {
        float dist = LocalPlayer->GetDistanceTo(Target);
        float timeToTravel = dist / bulletSpeed;
        targetAimPos = Add_VectorVector(targetAimPos, Multiply_VectorFloat(Velocity, timeToTravel));
    }}
        FRotator adjustedRot = ToRotator(StartLoc, targetAimPos);
        return oShootBulletInner(Weapon, StartLoc, adjustedRot, ShootID);
    }}
    return oShootBulletInner(Weapon, StartLoc, StartRot, ShootID);
}



int GetIndex(int currentIndex, int arrayNum) {
    if (arrayNum <= 0) {
        return 0;
    }
    return (currentIndex + 1) % arrayNum;
}

void clampAngles(FRotator &angles)
{
    if (angles.Pitch > 180)
        angles.Pitch -= 360;
    if (angles.Pitch < -180)
        angles.Pitch += 360;
    if (angles.Pitch < -75.f)
        angles.Pitch = -75.f;
    else if (angles.Pitch > 75.f)
        angles.Pitch = 75.f;
    while (angles.Yaw < -180.0f)
        angles.Yaw += 360.0f;
    while (angles.Yaw > 180.0f)
        angles.Yaw -= 360.0f;
}
 
float Random[11] = {0.9f, 1.0f, 1.1f, 1.2f, 1.3f, 1.4f, 1.5f, 1.6f, 1.7f, 1.9f, 2.0f};
void (*NIKONBulletInner)(uintptr_t Weapon, FVector StartLoc, FRotator StartRot, int ShootID);
void xNIKONBulletInner(uintptr_t Weapon, FVector StartLoc, FRotator StartRot, int ShootID)
{
    if (!Cheat::BulletTrack::Enable) {
        return NIKONBulletInner(Weapon, StartLoc, StartRot, ShootID);
    }

auto Target = GetTargetForAim();
if (!Target) {
    return NIKONBulletInner(Weapon, StartLoc, StartRot, ShootID);
}
static int FireCount = 0;
FireCount++;
if ((FireCount % 2) == 0) {
    return NIKONBulletInner(Weapon, StartLoc, StartRot, ShootID);
}

 
    FVector targetAimPos = Target->GetBonePos("spine_03", {});
//neck_01
    auto WeaponManagerComponent = g_LocalPlayer->WeaponManagerComponent;
    if (!WeaponManagerComponent) {
        return NIKONBulletInner(Weapon, StartLoc, StartRot, ShootID);
    }

    auto CurrentWeaponReplicated = (ASTExtraShootWeapon*)WeaponManagerComponent->CurrentWeaponReplicated;
    if (!CurrentWeaponReplicated) {
        return NIKONBulletInner(Weapon, StartLoc, StartRot, ShootID);
    }

    float distance = g_LocalPlayer->GetDistanceTo(Target);
    float BulletFireSpeed = CurrentWeaponReplicated->GetBulletFireSpeedFromEntity();

    // ✅ Bullet speed clamp to avoid divide-by-zero
    if (BulletFireSpeed < 1.0f) BulletFireSpeed = 1.0f;

    float timeToTravel = distance / BulletFireSpeed;

    FVector LinearVelocity = Target->CurrentVehicle
        ? Target->CurrentVehicle->ReplicatedMovement.LinearVelocity
        : Target->GetVelocity();

    // ✅ Slight early prediction to match server sync
    FVector Velocity = UKismetMathLibrary::Multiply_VectorFloat(LinearVelocity, timeToTravel * 0.9f);
    targetAimPos.X += Velocity.X;
    targetAimPos.Y += Velocity.Y;
    targetAimPos.Z += Velocity.Z;

    // ✅ Neck vertical adjustment (anti-crouch/prone error)
//    targetAimPos.Z -= 4.0f; //low power 
    targetAimPos.Z += 3.5f; // hig power 
    static int index = 0;
    index = GetIndex(index, 11);
    float Smoothing = Random[index];

    FRotator gunRotation = StartRot;
    FRotator aimRotation = ToRotator(StartLoc, targetAimPos);

    aimRotation.Pitch -= gunRotation.Pitch;
    aimRotation.Yaw -= gunRotation.Yaw;
    aimRotation.Roll = 0.0f;

    clampAngles(aimRotation);
        
    #include <algorithm> // Add this at top
    
    aimRotation.Pitch = std::max(-89.0f, std::min(89.0f, aimRotation.Pitch));
    aimRotation.Yaw   = std::max(-180.0f, std::min(180.0f, aimRotation.Yaw));

    gunRotation.Pitch += aimRotation.Pitch / Smoothing;
    gunRotation.Yaw += aimRotation.Yaw / Smoothing;
    gunRotation.Roll = 0.0f;
    

    return NIKONBulletInner(Weapon, StartLoc, gunRotation, ShootID);
}