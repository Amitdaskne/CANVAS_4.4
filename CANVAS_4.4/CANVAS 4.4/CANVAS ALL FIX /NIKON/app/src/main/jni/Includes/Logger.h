//
//  Logger.h
//
//  Created by MJ (Ruit) on 1/1/19.
//

#ifndef Logger_h
#define Logger_h

#include <jni.h>
#include <android/log.h>
#include <unordered_map>

enum LogType {
    oDEBUG = 3,
    oERROR = 6,
    oINFO  = 4,
    oWARN  = 5
};

#define TAG ("AVIWA")

std::mutex logMutex;
std::unordered_map<std::string, bool> loggedEntries;
void logUnique(int priority, const char* tag, const char* format, ...) {
    std::lock_guard<std::mutex> lock(logMutex); // Lock the mutex before accessing loggedEntries

    va_list args;
    va_start(args, format);

    char buffer[1024]; // Adjust size as needed
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    std::string logMessage = buffer;

    //Check if log message is already present in the map
    auto it = loggedEntries.find(logMessage);

    if (it == loggedEntries.end()) {
        loggedEntries[logMessage] = true;
        __android_log_print(priority, TAG, "%s", logMessage.c_str());
    }
}

#define LOGD(...) ((void)__android_log_print(oDEBUG, TAG, __VA_ARGS__))
#define LOGE(...) ((void)__android_log_print(oERROR, TAG, __VA_ARGS__))
#define LOGI(...) ((void)__android_log_print(oINFO,  TAG, __VA_ARGS__))
#define LOGW(...) ((void)__android_log_print(oWARN,  TAG, __VA_ARGS__))
#define LOGU(...) logUnique(ANDROID_LOG_INFO, TAG, __VA_ARGS__)

#endif /* Logger_h */
