#include "../cppWithHeadFile/Hello.cpp"
#include <jni.h>
#include "../cppMethod/TestMethod.cpp"

#ifdef ANDROID

#endif
extern "C" {
JNIEXPORT jint JNICALL Java_fr_myrddin_hellojni_HelloJNI_jniGiveMeANumber(JNIEnv *, jobject) {
    testCout();
    Hello hello;
    return hello.giveMeANumber();
//    return 100;
}

}