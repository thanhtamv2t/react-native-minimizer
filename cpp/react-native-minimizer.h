#pragma once

#include <ReactCommon/TurboModule.h>
#include <react/bridging/Bridging.h>

namespace facebook::react {

class JSI_EXPORT NativeReactNativeMinimizerSpecJSI : public TurboModule {
protected:
  NativeReactNativeMinimizerSpecJSI(std::shared_ptr<CallInvoker> jsInvoker);

public:
  virtual void minimize() = 0;
  virtual void goBack() = 0;
  virtual void exit() = 0;
};

template <>
struct Bridging<NativeReactNativeMinimizerSpecJSI> : BridgingBase<NativeReactNativeMinimizerSpecJSI> {
  static constexpr auto kModuleName = "ReactNativeMinimizer";

  static jsi::Object createObject(jsi::Runtime& rt, std::shared_ptr<NativeReactNativeMinimizerSpecJSI> module) {
    auto obj = jsi::Object(rt);
    obj.setProperty(rt, "minimize", jsi::Function::createFromHostFunction(
        rt, jsi::PropNameID::forAscii(rt, "minimize"), 0,
        [module](jsi::Runtime& rt, const jsi::Value& thisVal, const jsi::Value* args, size_t count) -> jsi::Value {
          module->minimize();
          return jsi::Value::undefined();
        }));
    obj.setProperty(rt, "goBack", jsi::Function::createFromHostFunction(
        rt, jsi::PropNameID::forAscii(rt, "goBack"), 0,
        [module](jsi::Runtime& rt, const jsi::Value& thisVal, const jsi::Value* args, size_t count) -> jsi::Value {
          module->goBack();
          return jsi::Value::undefined();
        }));
    obj.setProperty(rt, "exit", jsi::Function::createFromHostFunction(
        rt, jsi::PropNameID::forAscii(rt, "exit"), 0,
        [module](jsi::Runtime& rt, const jsi::Value& thisVal, const jsi::Value* args, size_t count) -> jsi::Value {
          module->exit();
          return jsi::Value::undefined();
        }));
    return obj;
  }
};

} // namespace facebook::react
