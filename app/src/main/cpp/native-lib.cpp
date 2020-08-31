// copy&pasted from : https://medium.com/androiddevelopers/getting-started-with-c-and-android-native-activities-2213b402ffff
//
// Created by Patrick Martin on 1/30/19.
//

#define APPNAME "runpixie"

#include <android_native_app_glue.h>
#include <jni.h>
#include <stdlib.h>
#include <string.h>
#include <android/log.h>
#include <iostream>
#include <string>

extern "C" {
void handle_cmd(android_app *pApp, int32_t cmd) {
}

void android_main(struct android_app *pApp) {
    pApp->onAppCmd = handle_cmd;

    int events;
    android_poll_source *pSource;

    int counter = 0;

    do {
        if (ALooper_pollAll(0, nullptr, &events, (void **) &pSource) >= 0) {
            if (pSource) {
                pSource->process(pApp, pSource);
            }
        }

        counter++;

        __android_log_print(ANDROID_LOG_VERBOSE, APPNAME, "My Log is:  %d", counter );

    } while (!pApp->destroyRequested);
}
}