package com.vatedroid;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;


public class Vatedroid extends Activity
{
   
    private native void init();

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        init();

        Log.d("Fuck!","YEAH!");

    }
   
    static {
        System.loadLibrary("vatewrap");
    }

}
