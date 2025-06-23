import { NativeModules, Platform } from 'react-native';

const LINKING_ERROR =
  `The package '@kangfenmao/react-native-minimizer' doesn't seem to be linked. Make sure: \n\n` +
  Platform.select({ ios: "- You have run 'pod install'\n", default: '' }) +
  '- You rebuilt the app after installing the package\n' +
  '- You are not using Expo Go\n';

// @ts-expect-error
import NativeReactNativeMinimizer from './NativeReactNativeMinimizer';

const ReactNativeMinimizer = NativeReactNativeMinimizer
  ? NativeReactNativeMinimizer
  : NativeModules.ReactNativeMinimizer
  ? NativeModules.ReactNativeMinimizer
  : new Proxy(
      {},
      {
        get() {
          throw new Error(LINKING_ERROR);
        },
      }
    );

export const minimize = (): void => {
  ReactNativeMinimizer.minimize();
};

export const goBack = (): void => {
  ReactNativeMinimizer.goBack();
};

export const exit = (): void => {
  ReactNativeMinimizer.exit();
};

export default {
  minimize,
  goBack,
  exit,
};
