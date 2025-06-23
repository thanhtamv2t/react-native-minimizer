#include "react-native-minimizer.h"

namespace facebook::react {

NativeReactNativeMinimizerSpecJSI::NativeReactNativeMinimizerSpecJSI(std::shared_ptr<CallInvoker> jsInvoker)
    : TurboModule("ReactNativeMinimizer", jsInvoker) {}

} // namespace facebook::react
