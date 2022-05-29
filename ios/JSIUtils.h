#import <Foundation/Foundation.h>
#import <jsi/jsi.h>

using namespace facebook;

NSString* convertJSIStringToNSString(jsi::Runtime &runtime, const jsi::String &value);
jsi::String convertNSStringToJSIString(jsi::Runtime &runtime, NSString *value);
