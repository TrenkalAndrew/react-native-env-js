//
//  EnvJsHostObject.m
//  react-native-env-js
//
//  Created by at on 29.05.2022.
//

#import "EnvJsHostObject.h"
#import "EnvJs.h"
#import "JSIUtils.h"
#import <jsi/jsi.h>

using namespace std;
using namespace facebook;

@implementation EnvJsHostObject

+ (void) install:(jsi::Runtime &) rt {
    auto getEnvironmentVariableLambda = [](jsi::Runtime &rt,
                                           const jsi::Value & thisValue,
                                           const jsi::Value *args,
                                           size_t count) -> jsi::Value {
        if (count < 1) {
            jsi::detail::throwJSError(rt, "[react-native-env-js]: environment variable name is not defined.");
        }

        if (!args[0].isString()) {
            jsi::detail::throwJSError(rt, "[react-native-env-js]: environment variable name should be string.");
        }

        NSString* environmentVariableName = convertJSIStringToNSString(rt, args[0].getString(rt));
        NSString* environmentVariable = [EnvJs getEnvironmentVariable:environmentVariableName];

        
        return convertNSStringToJSIString(rt, environmentVariable);
    };

    jsi::Function getEnvironmentVariable = jsi::Function::createFromHostFunction(
       rt,
       jsi::PropNameID::forAscii(rt, "getEnvironmentVariable"),
       1,
       move(getEnvironmentVariableLambda));

    rt.global().setProperty(rt, "getEnvironmentVariable", move(getEnvironmentVariable));
}

@end
