#import <React/RCTBridgeModule.h>

@interface EnvJs : NSObject <RCTBridgeModule>

@property(nonatomic, assign) BOOL setBridgeOnMainQueue;

@end
