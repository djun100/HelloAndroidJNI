package com.example.testclass;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;


public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        int number = 10;
    	int[] data = new int[number];
    	for (int i = 0; i < number; i++) {
    		data[i] = i;
    	}

    	for(int i=0;i<2;i++) {
	        AndroidClass test=new AndroidClass(data,number);
	        System.out.println("test sum-----"+i+"   "+test.calcSum());
	        System.out.println("test mean-----"+i+"   "+test.calcMean());
            ((TextView)findViewById(R.id.mtv)).setText(
                    "test sum-----"+i+"   "+test.calcSum()+"\n"+
                    "test mean-----"+i+"   "+test.calcMean());
	        test.AndroidClassFree();
    	}
    }
}
