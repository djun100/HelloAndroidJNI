package com.cy.jni;

public class JNIMgr {
    static
    {
        System.loadLibrary("native-lib");
    }

    public native String stringFromJNI();
    public native String stringFromJNI2();

}
