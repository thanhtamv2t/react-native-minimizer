#import "ReactNativeMinimizer.h"

@import UIKit;
@import ObjectiveC.runtime;

@interface UISystemNavigationAction : NSObject

@property(nonatomic, readonly, nonnull) NSArray<NSNumber*>* destinations;
-(BOOL)sendResponseForDestination:(NSUInteger)destination;
@end

@implementation ReactNativeMinimizer

RCT_EXPORT_MODULE()

// TurboModule support
- (std::shared_ptr<facebook::react::TurboModule>)getTurboModule:
    (const facebook::react::ObjCTurboModule::InitParams &)params
{
#ifdef RCT_NEW_ARCH_ENABLED
    return std::make_shared<facebook::react::NativeReactNativeMinimizerSpecJSI>(params);
#else
    return nullptr;
#endif
}

RCT_EXPORT_METHOD(exit)
{
    exit(0);
};

RCT_EXPORT_METHOD(goBack)
{
  Ivar sysNavIvar = class_getInstanceVariable(UIApplication.class, "_systemNavigationAction");
  UIApplication* app = UIApplication.sharedApplication;
  UISystemNavigationAction* action = object_getIvar(app, sysNavIvar);
  if (!action) {
      return;
  }
  NSUInteger destination = action.destinations.firstObject.unsignedIntegerValue;
  [action sendResponseForDestination:destination];
  return;
}

RCT_EXPORT_METHOD(minimize)
{
  UIApplication *app = [UIApplication sharedApplication];
  [app performSelector:@selector(suspend)];
};

@end
