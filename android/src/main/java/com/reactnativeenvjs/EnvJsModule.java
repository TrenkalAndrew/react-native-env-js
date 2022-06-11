package com.reactnativeenvjs;

import android.util.Log;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.JavaScriptContextHolder;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.module.annotations.ReactModule;

@ReactModule(name = EnvJsModule.NAME)
public class EnvJsModule extends ReactContextBaseJavaModule {
    public static final String NAME = "EnvJsModule";

    public EnvJsModule(ReactApplicationContext reactContext) {
        super(reactContext);
    }

    @Override
    @NonNull
    public String getName() {
        return NAME;
    }

    static {
        try {
            // Used to load the 'native-lib' library on application startup.
            System.loadLibrary("cpp");
        } catch (Exception ignored) {
        }
    }

    private native void nativeInstall(long jsi);

  @ReactMethod(isBlockingSynchronousMethod = true)
  public boolean install() {
    try {
      JavaScriptContextHolder jsContext = getReactApplicationContext().getJavaScriptContextHolder();
      nativeInstall(jsContext.get());
      return true;
    } catch (Exception exception) {
      Log.e(NAME, "Failed to install EnvJS JSI Bindings!", exception);
      return false;
    }
  }
}
