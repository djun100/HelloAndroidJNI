package com.cy.nativeMethod;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

import fr.myrddin.hellojni.R;


public class NativeMethodActivity extends Activity implements JNISvr.onJNIListener{

    TextView tv =  null;
    JNISvr jniService = null;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_nativemethod);
        
        jniService =  new JNISvr();
        jniService.setOnJNIListener(this);
        
        tv = (TextView)this.findViewById(R.id.ShowTextView);
        tv.setText(jniService.getJNIString());
        
    }

    public void onTestCB(View v) {
        jniService.testCallBack();
    }
    
    public void onTestStaticCB(View v) {
       jniService.testStaticCallBack(); 
        
    }    

    public void onGetDataBtn(View v) {
        int value = jniService.getData2();
        Debug.printI("value = " +  value);
        
        String text = String.valueOf(value);
        
        tv.setText(text);
        
    }
    
    public void onSetDataBtn(View v) {
        jniService.setJavaData(2468);
        jniService.setJavaStaticData(1133557788);
    }

    @Override
    public void onNativeFunc1() {
        // TODO Auto-generated method stub
        Toast.makeText(this, getText(R.string.str_toast_cb), Toast.LENGTH_SHORT).show();
    }

    @Override
    public void onNativeStaticFunc1() {
        // TODO Auto-generated method stub
        Toast.makeText(this, getText(R.string.str_toast_static_cb), Toast.LENGTH_SHORT).show();
    }
   
    
    
}
