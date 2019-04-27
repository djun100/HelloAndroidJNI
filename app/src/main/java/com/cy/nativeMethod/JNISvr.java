package com.cy.nativeMethod;


public class JNISvr {
    
    // ---------------------------------------------------------
    // accessed by native methods
    // --------------------
    int data1 = 0; 
    static int data2 = 0;
    
        
    static {
        System.loadLibrary("native-lib");
    }
    

    private static onJNIListener mListener = null;
    
    public JNISvr() {
        Debug.printI("Construct");        
    }
    
    public void setOnJNIListener(onJNIListener listener) {
        
        mListener = listener;
    }
    
    
    public int getData1() {
        Debug.printI("getData1 function is called..");
                
        return data1;
    }
    
    public int getData2() {
        Debug.printI("getData2 function is called..");
                
        return data2;
    }


    public interface onJNIListener {
        
        void onNativeFunc1();
        
        void onNativeStaticFunc1();
        
    }
    
    
    // ---------------------------------------------------------
    // Java methods called from the native side
    // --------------------    
    public void nativeFunc1() {
        Debug.printI("nativeFunc1 function is called..");
        mListener.onNativeFunc1();
    }
    
    public static void nativeStaticFunc1() {
       Debug.printI("nativeStaticFunc1 function is called..");
       mListener.onNativeStaticFunc1();
    
    }    
    
    
    // ---------------------------------------------------------
    // Native methods called from the Java side
    // --------------------    
    public native final String getJNIString();
    public native final void testCallBack();
    public native static final void testStaticCallBack();
    public native final void setJavaData(int i);
    public native static final void setJavaStaticData(int i);

}
