#import "EnvJs.h"
#import "react-native-env-js.h"

#import <React/RCTBridge+Private.h>
#import <jsi/jsi.h>

#import <React/RCTUtils.h>

@implementation EnvJs 

@synthesize bridge = _bridge;
@synthesize methodQueue = _methodQueue;

RCT_EXPORT_MODULE()

+ (BOOL)requiresMainQueueSetup {
  return YES;
}

- (void)setBridge:(RCTBridge *)bridge {
  _bridge = bridge;
  _setBridgeOnMainQueue = RCTIsMainQueue();

  RCTCxxBridge *cxxBridge = (RCTCxxBridge *)self.bridge;
  if (!cxxBridge.runtime) {
    return;
  }


  installSequel(*(facebook::jsi::Runtime *)cxxBridge.runtime);
}

@end
