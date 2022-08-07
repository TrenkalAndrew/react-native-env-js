package com.reactnativeenvjs;

import android.util.Log;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.JavaScriptContextHolder;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.module.annotations.ReactModule;

@ReactModule(name = EnvJsModule.NAME)
public class EnvJsModule extends ReactContextBaseJavaModule {
  public static final String NAME = "EnvJsModule";
  private static final String TAG = "EnvJsModuleRuntime";

  static {
    try {
      System.loadLibrary("EnvJs");
    } catch (Exception ignored) {
      Log.e(TAG, "Failed to load EnvJsModule!");
    }
  }

  public EnvJsModule(ReactApplicationContext reactContext) {
    super(reactContext);
  }

  @Override
  @NonNull
  public String getName() {
    return NAME;
  }

  private native void nativeInstall(long jsi);

  public void installLib(JavaScriptContextHolder reactContext) {
    if (reactContext.get() != 0) {
      this.nativeInstall(
        reactContext.get()
      );
    } else {
      Log.e("EnvJsModule", "JSI Runtime is not available in debug mode");
    }
  }
}
