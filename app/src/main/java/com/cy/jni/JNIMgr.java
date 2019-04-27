package com.cy.jni;

import com.cy.io.Log;

public class JNIMgr {
    static
    {
        System.loadLibrary("native-lib");
    }

    public native String stringFromJNI();
    public native String stringFromJNI2();
    public native byte[] byteArrFromJNI(byte[] in);
    public native void nativeJniDealInt();

    public int jniDealInt(int fromJni){
        Log.w("called from jni:"+fromJni);
        return fromJni++;
    }


}
