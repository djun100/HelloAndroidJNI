package com.cy.ndkbuild;


import com.cy.io.Log;

public class AndroidClass {
    private long ptr_;
    static {
        Log.i("AndroidClass", "before load library");
        System.loadLibrary("AndroidClass");
        Log.i("AndroidClass", "after load library");
    }

    public AndroidClass(int[] data, int num) {
        ptr_ = AndroidClassGen(data, num);
    }

    private native long AndroidClassGen(int[] data, int num);

    private native void AndroidClassFree(long ptr);

    private native double calcMean(long ptr);

    private native int calcSum(long ptr);



    public void AndroidClassFree() {
        AndroidClassFree(ptr_);
    }

    public double calcMean() {
        return calcMean(ptr_);
    }

    public double calcSum() {
        return calcSum(ptr_);
    }

    // AndroidClassGetPtr程序不使用，如果需要在外部的AndroidClass定义的对象A使用对象B，则使用这个函数传入 B的指针。
    public double AndroidClassGetPtr() {
        return ptr_;
    }
}



