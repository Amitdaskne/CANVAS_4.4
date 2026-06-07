package com.pubgm;

import android.app.Application;
import android.content.Context;

public class Killer extends Application {

    @Override
    protected void attachBaseContext(Context base) {
        APKKiller.Start(base);
        super.attachBaseContext(base);
    }
}
