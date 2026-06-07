#include <list>
#include <vector>
#include <cstring>
#include <pthread.h>
#include <thread>
#include <jni.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/socket.h>
#include <malloc.h>
#include <math.h>
#include <sys/stat.h>
#include <errno.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <locale>
#include <string>
#include <codecvt>
#include "SDK.hpp"
#include "KittyMemory/MemoryPatch.h"
#include "Substrate/SubstrateHook.h"
#include "Includes/Logger.h"
#include "Includes/Utils.h"
#include "Includes/Macros.h"
#include "Includes/oxorany.h"
#include "Tools.h"
#include "Includes/json.hpp"
#include "Includes/StrEnc.h"
#include "Includes/android_include.h"
#include "imgui/imgui.h"
#include <EGL/egl.h>
#include "imgui/backends/imgui_impl_android.h"
#include "imgui/backends/imgui_impl_opengl3.h" 
#include <curl/curl.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <cassert>
#include <fcntl.h>
#include <unistd.h>
#include <random>
#include <unordered_map>
#include "Vector3.hpp"


size_t &_lxy_oxor_any_::X()
{
    static size_t x = 0;
    return x;
}

size_t &_lxy_oxor_any_::Y()
{
    static size_t y = 0;
    return y;
}


size_t getLibrarySize(const char *libraryName)
{
    FILE *mapsFile = fopen("/proc/self/maps", "r");
    if (mapsFile == nullptr)
    {
        return 0;
    }

    char line[256];
    size_t size = 0;
    uintptr_t startAddr = 0, endAddr = 0;
    while (fgets(line, sizeof(line), mapsFile))
    {
        if (strstr(line, libraryName))
        {
            sscanf(line, "%lx-%lx", &startAddr, &endAddr);
            size = endAddr - startAddr;
            break;
        }
    }

    fclose(mapsFile);
    return size;
}


namespace Settings {
    static int Tab = 1;
}


