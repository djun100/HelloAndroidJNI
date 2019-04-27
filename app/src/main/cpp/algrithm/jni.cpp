#include <jni.h>
#include <string>
#include "algrithm.cpp"

extern "C" {
jstring
Java_com_cy_jni_JNIMgr_stringFromJNI(JNIEnv *env, jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

JNIEXPORT jstring JNICALL
Java_com_cy_jni_JNIMgr_stringFromJNI2(JNIEnv *env, jobject instance) {
    main();
    std::string hello = "Hello from C++2";
    return env->NewStringUTF(hello.c_str());
}
}