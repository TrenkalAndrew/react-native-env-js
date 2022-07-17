import { Platform } from 'react-native';
import { NativeModules } from 'react-native';
import type { TResult } from './types';

const LINKING_ERROR =
  `The package 'react-native-env-js' doesn't seem to be linked. Make sure: \n\n` +
  Platform.select({ ios: "- You have run 'pod install'\n", default: '' }) +
  '- You rebuilt the app after installing the package\n' +
  '- You are not using Expo managed workflow\n';

const RNEnvJs = global.RNEnvJs;

if (!RNEnvJs) {
  const EnvJsModule = NativeModules.EnvJsModule;

  if (!EnvJsModule) {
    throw new Error(LINKING_ERROR);
  }

  EnvJsModule.install();
}

export function getEnvironmentVariable(variableName: string): TResult {
  return global.RNEnvJs.getEnvironmentVariable(variableName);
}
