//==============================================================================================//
EGLBoolean (*orig_eglSwapBuffers)(EGLDisplay dpy, EGLSurface surface);
EGLBoolean _eglSwapBuffers(EGLDisplay dpy, EGLSurface surface) {
    eglQuerySurface(dpy, surface, EGL_WIDTH, &glWidth);
    eglQuerySurface(dpy, surface, EGL_HEIGHT, &glHeight);
    if (glWidth <= 0 || glHeight <= 0)
        return orig_eglSwapBuffers(dpy, surface);
    if (!g_App)
        return orig_eglSwapBuffers(dpy, surface);
        screenWidth = ANativeWindow_getWidth(g_App->window);
        screenHeight = ANativeWindow_getHeight(g_App->window);
        density = AConfiguration_getDensity(g_App->config);
    if (!initImGui) {
        ImGui::CreateContext();
        ImGuiStyle& style = ImGui::GetStyle();
        ImGui::StyleColorsDark();
        style.WindowPadding = ImVec2(7, 7);
        style.WindowRounding = 0.0f;
        style.FramePadding = ImVec2(4, 4);
        style.FrameRounding = 5.5f;
        style.FrameBorderSize = 1.0f;
        style.WindowBorderSize = 0.0f;
		style.ScrollbarSize = 30.0f;
        ImGui_ImplAndroid_Init();
        ImGui_ImplOpenGL3_Init("#version 300 es");
        ImGuiIO &io = ImGui::GetIO();
        io.ConfigWindowsMoveFromTitleBarOnly = true;
        io.IniFilename = NULL;
		ImFontConfig cfg;
        cfg.SizePixels = 18.0f;
        io.Fonts->AddFontDefault(&cfg);
        initImGui = true;
    }
        ImGuiIO &io = ImGui::GetIO();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplAndroid_NewFrame(glWidth, glHeight);
        ImGui::NewFrame();
		
	if (ShowIMGUImenu) {
        ImGui::SetNextWindowSize(ImVec2((float)glWidth * 0.33f, (float)glHeight * 0.47f), ImGuiCond_Once);
    if (ImGui::Begin("Hack Menu", &ShowIMGUImenu, ImGuiWindowFlags_NoCollapse)) {
        // Left menu (tabs)
        ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 0.6f);
        ImGui::PushStyleColor(ImGuiCol_Border, ImColor(100, 100, 100, 200).Value);
        ImGui::PushStyleColor(ImGuiCol_ChildBg, ImColor(9, 36, 89, 0).Value);
        ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 0.0f);
        ImGui::BeginChild("menu_left", ImVec2(170, 0), true);
        ImGui::PopStyleVar(2);
        ImGui::PopStyleColor(2);
    if (ImGui::Button("Esp Menu", ImVec2(150, 30))) {
        Settings::Tab = 1;
        ImGui::Spacing();
    }
    if (ImGui::Button("Aim Menu", ImVec2(150, 30))) {
        Settings::Tab = 2;
        ImGui::Spacing();
    }
    if (ImGui::Button("Mod Skins", ImVec2(150, 30))) {
        Settings::Tab = 3;
    }
	if (ImGui::Button("Memory Hack", ImVec2(150, 30))) {
        Settings::Tab = 4;
    }
        ImGui::EndChild();
        ImGui::SameLine();
        // Right menu (content)
        ImGui::PushStyleVar(ImGuiStyleVar_ChildBorderSize, 0.6f);
        ImGui::PushStyleColor(ImGuiCol_Border, ImColor(100, 100, 100, 200).Value);
        ImGui::PushStyleColor(ImGuiCol_ChildBg, ImColor(9, 36, 89, 0).Value);
        ImGui::PushStyleVar(ImGuiStyleVar_ChildRounding, 0.0f);
        ImGui::BeginChild("menu_right", ImVec2(0, 0), true);
        ImGui::PopStyleVar(2);
        ImGui::PopStyleColor(2);
    if (Settings::Tab == 1) {
        static int subTab = 1;
    if (ImGui::Button("Player ESP", ImVec2(130, 30)))
        subTab = 1;
        ImGui::SameLine();
    if (ImGui::Button("Other ESP", ImVec2(130, 30)))
        subTab = 2;
       ImGui::Separator();
    if (subTab == 1) {
		ImGui::Text("Player Esp Setting:");
        ImGui::Checkbox(" Esp Line", &Cheat::Esp::Line);
        ImGui::Checkbox(" Esp Skeleton", &Cheat::Esp::Skeleton);
        ImGui::Checkbox(" Esp Distance", &Cheat::Esp::Distance);
        ImGui::Checkbox(" Esp Health", &Cheat::Esp::Health);
        ImGui::Checkbox(" Esp Name", &Cheat::Esp::Name);
        ImGui::Checkbox(" Esp Count", &Cheat::Esp::Count);
    }
    if (subTab == 2) {
		ImGui::Text("Other Esp Setting:");
        ImGui::Checkbox(" Esp Vehicle", &Cheat::Esp::Vehicle);
        ImGui::Checkbox(" Esp LootBox", &Cheat::Esp::LootBox);
        ImGui::Checkbox(" Esp GranadeWarning", &Cheat::Esp::GranadeWarning);
        ImGui::Checkbox(" Esp Items", &Cheat::Esp::Items);
    }}
    if (Settings::Tab == 2) {
        static int subTab2 = 1;
    if (ImGui::Button("Aimbot", ImVec2(130, 30)))
        subTab2 = 1;
        ImGui::SameLine();
    if (ImGui::Button("B.Track", ImVec2(130, 30)))
        subTab2 = 2;
        ImGui::Separator();
		
    if (subTab2 == 1) {
		ImGui::Text("Aimbot Setting:");
        ImGui::Checkbox(" Enable Aimbot", &Cheat::Aimbot::Enable);
	if (Cheat::Aimbot::Enable) {
		Cheat::BulletTrack::Enable = false;
        ImGui::Checkbox(" Visiblity Check", &Cheat::Aimbot::VisCheck);
        ImGui::Checkbox(" Ignore Knock", &Cheat::Aimbot::IgnoreKnock);
        ImGui::Checkbox(" Ignore Bot", &Cheat::Aimbot::IgnoreBot);
		ImGui::Text("Fov Radius:");
        ImGui::SliderFloat("##Fov", &Cheat::Aimbot::Radius, 30.0f, 1000.0f, "%.1f");
        ImGui::Text("Aimbot Smoothness:");
        ImGui::SliderFloat("##Smooth", &Cheat::Aimbot::Smoothness, 1.0f, 15.0f, "%.1f");
    }}
	
    if (subTab2 == 2) {
        ImGui::Text("Bullet Track Setting:");
    if (!btserver) {
        Cheat::BulletTrack::Enable = false;
        ImGui::BeginDisabled();  // disable checkbox interaction
        ImGui::Checkbox("Enable B.Track (Server OFF)", &Cheat::BulletTrack::Enable);
        ImGui::EndDisabled();
    } else {
    if (ImGui::Checkbox("Enable B.Track", &Cheat::BulletTrack::Enable)) {
    if (Cheat::BulletTrack::Enable) {
        Cheat::Aimbot::Enable = false;
    }}}
	
    if (btserver && Cheat::BulletTrack::Enable) {
        ImGui::Checkbox(" Visiblity Check", &Cheat::BulletTrack::VisCheck);
        ImGui::Checkbox(" Ignore Knock", &Cheat::BulletTrack::IgnoreKnock);
        ImGui::Checkbox(" Ignore Bot", &Cheat::BulletTrack::IgnoreBot);
        ImGui::Checkbox(" Prediction", &Cheat::BulletTrack::Prediction);
		ImGui::Checkbox(" Instant Hit", &Cheat::MemoryHack::InstantHit);
        ImGui::Text("Fov Radius:");
        ImGui::SliderFloat("##fovbt", &Cheat::BulletTrack::Radius, 30.0f, 1000.0f, "%.1f");
    }}}
	
	if (Settings::Tab == 3) {
        static int subTab3 = 1;
    if (ImGui::Button("Outfit", ImVec2(100, 30)))
        subTab3 = 1;
        ImGui::SameLine();
    if (ImGui::Button("Guns", ImVec2(100, 30)))
        subTab3 = 2;
        ImGui::SameLine();
    if (ImGui::Button("Vehicle", ImVec2(100, 30)))
        subTab3 = 3;
        ImGui::Separator();	
    if (subTab3 == 1) {
        ImGui::Text("Select Any Cloth:");
        static int localOutfit = 0;
        ImGui::SetNextItemWidth(glWidth * 0.19f);
    if (ImGui::BeginCombo("##OutfitCombo", g_Outfits[localOutfit].name)) {
        for (int i = 0; i < IM_ARRAYSIZE(g_Outfits); i++) {
        bool is_selected = (localOutfit == i);
    if (ImGui::Selectable(g_Outfits[i].name, is_selected)) {
        localOutfit = i;
        g_PlayerOutfit.currentOutfit = i; // store index
    }
    if (is_selected)
        ImGui::SetItemDefaultFocus();
    }
        ImGui::EndCombo();
    }}

    if (subTab3 == 2) {
		ImGui::Text("Gun Skins Setting:");
	    ImGui::Checkbox(" Enable Gun Skins", &GunSkin);
    }
	
    if (subTab3 == 3) {
        ImGui::Text("Vehicle Skins Setting:");
	    ImGui::Checkbox(" Enable Vehicle Skins", &VehicleSkin);
    }}
	
	if (Settings::Tab == 4) {
        ImGui::Text("Memory Hacks:");
	    ImGui::Checkbox(" Wide View", &IpadView);
	if (IpadView) {
		ImGui::SliderFloat("##ipad", &Cheat::MemoryHack::ipadfov, 80.0f, 140.0f, "%.1f");
	}
	    //ImGui::Checkbox(" Small Crosshair", &Cheat::MemoryHack::SmallCrossHair);

	}
	
	
	
	}
        ImGui::EndChild();
        ImGui::End();
    }
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    return orig_eglSwapBuffers(dpy, surface);
}
//==============================================================================================//
int32_t (*orig_onInputEvent)(struct android_app *app, AInputEvent *inputEvent);
int32_t hooked_InputEvent(struct android_app *app, AInputEvent *inputEvent) {
    if (AInputEvent_getType(inputEvent) == AINPUT_EVENT_TYPE_KEY && AKeyEvent_getAction(inputEvent) == AKEY_EVENT_ACTION_DOWN) {
        int32_t key_val = AKeyEvent_getKeyCode(inputEvent);
        if (key_val == AKEYCODE_VOLUME_UP) {}
        if (key_val == AKEYCODE_VOLUME_DOWN) {}
    }
    if (initImGui) {
        ImGui_ImplAndroid_HandleInputEvent(inputEvent, {(float) screenWidth / glWidth, (float) screenHeight / glHeight});
    }
    return orig_onInputEvent ? orig_onInputEvent(app, inputEvent) : 0;
}
//=======================================================================================
#include <android/sensor.h>
#include <android/looper.h>

ASensorManager* sensorManager = nullptr;
const ASensor* accelerometer = nullptr;
ASensorEventQueue* sensorEventQueue = nullptr;

void initAccelerometer(android_app* app) {
    sensorManager = ASensorManager_getInstance();
    accelerometer = ASensorManager_getDefaultSensor(sensorManager, ASENSOR_TYPE_ACCELEROMETER);
    ALooper* looper = ALooper_forThread();
    if (!looper) looper = ALooper_prepare(ALOOPER_PREPARE_ALLOW_NON_CALLBACKS);
    sensorEventQueue = ASensorManager_createEventQueue(sensorManager, looper, LOOPER_ID_USER, nullptr, nullptr);
    ASensorEventQueue_enableSensor(sensorEventQueue, accelerometer);
    ASensorEventQueue_setEventRate(sensorEventQueue, accelerometer, (1000L/60)*1000); // 60Hz
}

// Process accelerometer events
void pollAccelerometer() {
    ASensorEvent event;
    while (ASensorEventQueue_getEvents(sensorEventQueue, &event, 1) > 0) {
    if (event.type == ASENSOR_TYPE_ACCELEROMETER) {
    float ax = event.acceleration.x;
    float ay = event.acceleration.y;
    float az = event.acceleration.z;
    float magnitude = sqrt(ax*ax + ay*ay + az*az);
    if (magnitude >= 35.0f) {
    //LOGI("Device shaken! Magnitude=%.2f", magnitude);
    ShowIMGUImenu = true;
}}}}

void* shake_thread(void*) {
    while (true) {
        pollAccelerometer();
        std::this_thread::sleep_for(std::chrono::milliseconds(16)); // ~60Hz
    }
    return nullptr;
}

void HookInputEvent(struct android_app* g_App) {
    size_t offset = offsetof(android_app, onInputEvent);
    void* target = *(void**)((uintptr_t)g_App + offset);
    A64HookFunction(target, (void*)&hooked_InputEvent, (void**)&orig_onInputEvent);
}
