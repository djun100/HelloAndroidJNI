#include "myGreatLib/Hello.cpp"
#include <jni.h>

#ifdef ANDROID

#endif
extern "C" {
JNIEXPORT jint JNICALL Java_fr_myrddin_hellojni_HelloJNI_jniGiveMeANumber(JNIEnv *, jobject) {
    Hello hello;
    return hello.giveMeANumber();
}

}