package com.reactnativeenvjs;

import android.util.Log;

import javax.annotation.Nullable;

public class EnvJs {
  @Nullable
  public static String getEnvironmentVariable(String environmentVariableName) {
    try {
      return System.getenv(environmentVariableName);
    } catch (SecurityException e) {
      Log.e("EnvJsModule", e.getLocalizedMessage());
      return null;
    }

  }
}
