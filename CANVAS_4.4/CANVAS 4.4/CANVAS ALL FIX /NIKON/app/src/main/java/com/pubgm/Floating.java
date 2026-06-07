package com.pubgm;
import android.annotation.SuppressLint;
import android.app.AlertDialog;
import android.app.Service;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.res.ColorStateList;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.PixelFormat;
import android.graphics.Point;
import android.graphics.Typeface;
import android.graphics.drawable.GradientDrawable;
import android.os.Build;
import android.os.Handler;
import android.os.IBinder;
import android.os.Message;
import android.util.Base64;
import android.view.Display;
import android.view.Gravity;
import android.view.MotionEvent;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.HorizontalScrollView;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RadioButton;
import android.widget.RadioGroup;
import android.widget.RelativeLayout;
import android.widget.ScrollView;
import android.widget.SeekBar;
import android.widget.Spinner;
import android.widget.Switch;
import android.widget.TextView;
import android.widget.Toast;
import java.io.File;
import android.app.*;
import android.widget.*;
import android.content.*;
import android.view.*;
import android.graphics.*;
import android.graphics.drawable.*;
import android.content.res.*;
import android.util.*;
import android.os.*;
import java.io.*;
import java.security.spec.*;
import android.text.*;
import android.net.*;
import java.nio.charset.*;
import org.json.*;
import android.annotation.TargetApi;
import android.view.WindowManager.LayoutParams;
import android.graphics.Canvas;
import android.annotation.SuppressLint;
import java.util.Random;
import java.text.SimpleDateFormat;
import java.util.Date;

import java.util.Locale;
import android.animation.ArgbEvaluator;
import android.animation.ValueAnimator;
import android.animation.TimeAnimator;
import android.app.Service;

import android.os.Bundle;


public class Floating extends Service {
    
    
    static Floating _activity;

        

   
    
    WindowManager windowManager;

    int screenWidth, screenHeight, type, screenDpi, CheckAttY = 0;
    float density;
    
    WindowManager.LayoutParams iconLayoutParams, mainLayoutParams, canvasLayoutParams;
    RelativeLayout iconLayout;
    LinearLayout mainLayout;
    CanvasView canvasLayout;
    TextView textTitle;
    RelativeLayout closeLayout, maximizeLayout, minimizeLayout;
    RelativeLayout.LayoutParams closeLayoutParams, maximizeLayoutParams, minimizeLayoutParams;
    

    ImageView iconImg;
    

    boolean CheckAtt;
    SharedPreferences configPrefs;
    long sleepTime = 1000 / 60;
 
    boolean isMaximized = false;

    
    
    private native boolean IsHideEsp(); 
    
    boolean isScreenRecorderEnabled = IsHideEsp();   

    
    

    
    
    
    
    
    int lastMaximizedX = 0, lastMaximizedY = 0;
    int lastMaximizedW = 0, lastMaximizedH = 0;

    int layoutWidth;
    int layoutHeight;
   

    private native void onSendConfig(String s, String v);
    static native  void Switch(int i,boolean jboolean1);
    private native void onCanvasDraw(Canvas canvas, int w, int h, float d);

    void CreateCanvas() {


        final int FLAGS = WindowManager.LayoutParams.FLAG_NOT_TOUCH_MODAL |
            WindowManager.LayoutParams.FLAG_LAYOUT_IN_SCREEN |
            WindowManager.LayoutParams.FLAG_FULLSCREEN |
            WindowManager.LayoutParams.FLAG_LAYOUT_INSET_DECOR |
            WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE |
            WindowManager.LayoutParams.FLAG_LAYOUT_NO_LIMITS |
            WindowManager.LayoutParams.FLAG_TRANSLUCENT_STATUS |
            WindowManager.LayoutParams.FLAG_NOT_TOUCHABLE;

        canvasLayoutParams = new WindowManager.LayoutParams(screenWidth, screenHeight, type, FLAGS, PixelFormat.RGBA_8888);

        canvasLayoutParams.x = 0;
        canvasLayoutParams.y = 0;
        canvasLayoutParams.gravity = Gravity.LEFT | Gravity.TOP;

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P) {
            canvasLayoutParams.layoutInDisplayCutoutMode = WindowManager.LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES;
        }

        canvasLayout = new CanvasView(this);


    
        RecorderFakeUtils.setFakeRecorderWindowLayoutParams(iconLayoutParams);
        RecorderFakeUtils.setFakeRecorderWindowLayoutParams(mainLayoutParams);
        RecorderFakeUtils.setFakeRecorderWindowLayoutParams(canvasLayoutParams);
        
        windowManager.addView(canvasLayout, canvasLayoutParams);
    }





    private class CanvasView extends View {
        public CanvasView(Context context) {
            super(context);
        }

        @Override
        protected void onDraw(Canvas canvas) {
            try {
                onCanvasDraw(canvas, screenWidth, screenHeight, density);
            } catch (Exception ex) {
                ex.printStackTrace();
            }
        }
    }

    private void UpdateConfiguration(String s, Object v) {
        try {
            onSendConfig(s, v.toString());

            SharedPreferences.Editor configEditor = configPrefs.edit();
            configEditor.putString(s, v.toString());
            configEditor.apply();
        } catch (Exception ex) {
            ex.printStackTrace();
        }
    }

    @Override
    public void onDestroy() {
        super.onDestroy();

        if (mUpdateCanvas.isAlive()) {
            mUpdateCanvas.interrupt();
        }
        if (mUpdateThread.isAlive()) {
            mUpdateThread.interrupt();
        }

        if (iconLayout != null) {
            windowManager.removeView(iconLayout);
        }
        if (mainLayout != null) {
            windowManager.removeView(mainLayout);
        }
        if (canvasLayout != null) {
            windowManager.removeView(canvasLayout);
        }
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        super.onStartCommand(intent, flags, startId);
        return START_NOT_STICKY;
    }

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }




    @Override
    public void onCreate() {
        System.loadLibrary("pubgm");
        super.onCreate();
        configPrefs = getSharedPreferences("config", MODE_PRIVATE);
        windowManager = (WindowManager) getSystemService(WINDOW_SERVICE);


        
        Point screenSize = new Point();
        Display display = windowManager.getDefaultDisplay();
        display.getRealSize(screenSize);

        screenWidth = screenSize.x;
        screenHeight = screenSize.y;
        screenDpi = getResources().getDisplayMetrics().densityDpi;

        density = getResources().getDisplayMetrics().density;

        
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            type = 2038;
        } else {
            type = 2002;
        }

        RecorderFakeUtils.setFakeRecorderWindowLayoutParams(iconLayoutParams);
        RecorderFakeUtils.setFakeRecorderWindowLayoutParams(mainLayoutParams);
        RecorderFakeUtils.setFakeRecorderWindowLayoutParams(canvasLayoutParams);
        
        CreateCanvas();

        mUpdateThread.start();
        mUpdateCanvas.start();
    }
    




    
    
    
    
    @SuppressLint("HandlerLeak")
    Handler handler = new Handler() {
        @Override
        public void handleMessage(Message msg) {
            super.handleMessage(msg);
            if (msg.what == 0) {
                try {
                    Point screenSize = new Point();
                    Display display = windowManager.getDefaultDisplay();
                    display.getRealSize(screenSize);

                    screenWidth = screenSize.x;
                    screenHeight = screenSize.y;

                    mainLayoutParams.width = layoutWidth;
                    mainLayoutParams.height = layoutHeight;

                    windowManager.updateViewLayout(mainLayout, mainLayoutParams);

                    canvasLayoutParams.width = screenWidth;
                    canvasLayoutParams.height = screenHeight;


                    windowManager.updateViewLayout(canvasLayout, canvasLayoutParams);

                } catch (Exception ex) {
                    ex.printStackTrace();
                }
            }
        }
    };

    Thread mUpdateCanvas = new Thread() {
        @Override
        public void run() {
            android.os.Process.setThreadPriority(android.os.Process.THREAD_PRIORITY_DISPLAY);
            while (isAlive() && !isInterrupted()) {
                try {
                    long t1 = System.currentTimeMillis();
                    canvasLayout.postInvalidate();
                    long td = System.currentTimeMillis() - t1;
                    Thread.sleep(Math.max(Math.min(0, sleepTime - td), sleepTime));
                } catch (Exception ex) {
                    ex.printStackTrace();
                }
            }
        }
    };

    Thread mUpdateThread = new Thread() {
        @Override
        public void run() {
            android.os.Process.setThreadPriority(android.os.Process.THREAD_PRIORITY_DISPLAY);
            while (isAlive() && !isInterrupted()) {
                try {
                    long t1 = System.currentTimeMillis();
                    Point screenSize = new Point();
                    Display display = windowManager.getDefaultDisplay();
                    display.getRealSize(screenSize);

                    if (screenWidth != screenSize.x || screenHeight != screenSize.y) {
                        handler.sendEmptyMessage(0);
                    }

                    long td = System.currentTimeMillis() - t1;
                    Thread.sleep(Math.max(Math.min(0, sleepTime - td), sleepTime));
                } catch (Exception ex) {
                    ex.printStackTrace();
                }
            }
        }
    };
}

