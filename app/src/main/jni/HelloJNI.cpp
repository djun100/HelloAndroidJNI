#include "myGreatLib/Hello.cpp"
#include <jni.h>
#ifdef ANDROID
#include <android/log.h>
#endif
extern "C" {
JNIEXPORT jint JNICALL Java_fr_myrddin_hellojni_HelloJNI_jniGiveMeANumber(JNIEnv *, jobject)
{
	Hello hello;
	return hello.giveMeANumber();
}

}