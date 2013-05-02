package com.vatedroid;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

public class VateDroidActivity extends Activity
{
    // static initializer loads native library
    static {
        System.loadLibrary("vatewrap");
    }
    
    // native instance method declaration
    private native String bottleThrower(String name, String code);

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        String result = bottleThrower("VateDroid Activity", "function concat(x,y){ return x+y; } concat('foo','bar');");
        Log.d("VATEDROID ACTIVITY BOTTLE THROWER RESULT", result);
    }
}
