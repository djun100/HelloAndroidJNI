package com.cy.jni;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import com.cy.data.UtilByte;
import com.cy.host.BaseHostActivity;
import com.cy.io.Log;
import com.cy.nativeMethod.NativeMethodActivity;
import com.cy.ndkbuild.AndroidClass;
import com.cy.view.UtilToast;

import fr.myrddin.hellojni.HelloJNI;
import fr.myrddin.hellojni.R;

public class LaunchActivity extends BaseHostActivity {

    private Button mBtnNDKBuild;
    private Button mBtnCmake1;
    private Button mBtnCmake2;
    private Button mBtnNativeMethodMap;

    private View.OnClickListener mOnClickListener = new View.OnClickListener() {
        @Override
        public void onClick(View v) {
            switch (v.getId()) {
                case R.id.btnCmake1:
                    HelloJNI test = new HelloJNI();
                    String number1 = test.giveMeANumber() + "";
                    Log.w(number1);
                    UtilToast.showShort(number1);

                    break;
                case R.id.btnCmake2:
                    String jni2 = new JNIMgr().stringFromJNI2();
                    Log.w(jni2);
                    UtilToast.showShort(jni2);

                    byte[] byteArrFromJNI = new JNIMgr().byteArrFromJNI(new byte[]{2, 5, 8});
                    Log.w("byteArrFromJNI:"
                            + UtilByte.byteArray2HexStringWithSpace(byteArrFromJNI));

                    break;
                case R.id.btnNDKBuild:
                    int number = 10;
                    int[] data = new int[number];
                    for (int i = 0; i < number; i++) {
                        data[i] = i;
                    }

                    for (int i = 0; i < 2; i++) {
                        AndroidClass test1 = new AndroidClass(data, number);

                        String result = "test sum-----" + i + "   " + test1.calcSum()
                                + "\ntest mean-----" + i + "   " + test1.calcMean();

                        UtilToast.showShort(result);
                        Log.w(result);

                        test1.AndroidClassFree();
                    }

                    break;
                case R.id.btnNativeMethodMap:
                    baseStartActivity(NativeMethodActivity.class);

                    break;
                default:
                    break;
            }
        }
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_launch);
        initView();
    }

    @Override
    protected void baseInit1Data() {

    }

    @Override
    protected void baseInit2View() {

    }

    private void initView() {
        mBtnCmake1 = (Button) findViewById(R.id.btnCmake1);
        mBtnCmake2 = (Button) findViewById(R.id.btnCmake2);
        mBtnNDKBuild = (Button) findViewById(R.id.btnNDKBuild);
        mBtnNativeMethodMap = findViewById(R.id.btnNativeMethodMap);
        mBtnCmake1.setOnClickListener(mOnClickListener);
        mBtnCmake2.setOnClickListener(mOnClickListener);
        mBtnNDKBuild.setOnClickListener(mOnClickListener);
        mBtnNativeMethodMap.setOnClickListener(mOnClickListener);
    }


}
