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

JNIEXPORT jbyteArray JNICALL
Java_com_cy_jni_JNIMgr_byteArrFromJNI(JNIEnv *env, jobject instance, jbyteArray j_array) {
    jint length = env->GetArrayLength(j_array);
    unsigned char array[length];
    env->GetByteArrayRegion(j_array, 0, length, (jbyte *) array);
    for (int i = 0; i < length; ++i) {
        array[i] = i;
    }
    jbyteArray jbyteArray1 = env->NewByteArray(length);
    env->SetByteArrayRegion(jbyteArray1, 0, length, (jbyte *) array);
    return jbyteArray1;
}

JNIEXPORT jint JNICALL
Java_com_cy_jni_JNIMgr_nativeJniDealInt(JNIEnv *env, jobject instance, jint jint1) {

}


}