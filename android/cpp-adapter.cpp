#include <jni.h>
#include <jsi/jsi.h>

#include "react-native-env-js.h"

extern "C"
JNIEXPORT void JNICALL
Java_com_reactnativeenvjs_EnvJsModule_nativeInstall(JNIEnv *env, jobject thiz, jlong jsi) {
    auto runtime = reinterpret_cast<facebook::jsi::Runtime *>(jsi);

    if (runtime) {
        installSequel(*runtime);
    }
}
