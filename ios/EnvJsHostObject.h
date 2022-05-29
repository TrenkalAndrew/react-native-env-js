#import <jsi/jsi.h>
#import <Foundation/Foundation.h>

using namespace facebook;

NS_ASSUME_NONNULL_BEGIN

@interface EnvJsHostObject : NSObject

+ (void) install:(jsi::Runtime &) rt;

@end

NS_ASSUME_NONNULL_END
