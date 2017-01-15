package fr.myrddin.hellojni;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;

public class HelloJNIActivity extends Activity {
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        TextView mtv= (TextView) findViewById(R.id.mtv);

        HelloJNI test = new HelloJNI();
        mtv.setText(test.giveMeANumber()+"");;
    }
}