#import <React/RCTBridgeModule.h>

@interface EnvJsModule : NSObject <RCTBridgeModule>

@property(nonatomic, assign) BOOL setBridgeOnMainQueue;

@end
