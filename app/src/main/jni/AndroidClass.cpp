#include <jni.h>
#include "myMeanSum.h"

#ifdef __cplusplus  //最好有这个，否则被编译器改了函数名字找不到不要怪我
extern "C" {
#endif

/*
 * Class:     com_example_testclass_AndroidClass
 * Method:    AndroidClassGen
 * Signature: ([II)J
 */
JNIEXPORT jlong JNICALL Java_com_cy_ndkbuild_AndroidClass_AndroidClassGen
  (JNIEnv *env, jobject obj, jintArray data, jint num)
{
	jint *iAdata = env->GetIntArrayElements(data, 0);

	jlong ptr= reinterpret_cast<jlong>(new myMeanSum(reinterpret_cast<int*>(iAdata), num));

	env->ReleaseIntArrayElements(data, iAdata, 0);

	return ptr;
}

/*
 * Class:     com_example_testclass_AndroidClass
 * Method:    AndroidClassFree
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_cy_ndkbuild_AndroidClass_AndroidClassFree
  (JNIEnv *, jobject, jlong ptr)
{
	if(reinterpret_cast<myMeanSum*>(ptr))
	{
		delete reinterpret_cast<myMeanSum*>(ptr);
		ptr = 0;
	}
}

/*
 * Class:     com_example_testclass_AndroidClass
 * Method:    calcMean
 * Signature: (J)D
 */
JNIEXPORT jdouble JNICALL Java_com_cy_ndkbuild_AndroidClass_calcMean
  (JNIEnv *, jobject, jlong ptr)
{
	jdouble ret = reinterpret_cast<myMeanSum*>(ptr)->calcMean();

	return ret;
}

/*
 * Class:     com_example_testclass_AndroidClass
 * Method:    calcSum
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_cy_ndkbuild_AndroidClass_calcSum
  (JNIEnv *, jobject, jlong ptr)
{
	jint ret = reinterpret_cast<myMeanSum*>(ptr)->calcSum();

	return ret;
}


#ifdef __cplusplus
}
#endif
