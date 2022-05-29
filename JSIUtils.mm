//
//  JSIUtils.m
//  react-native-env-js
//
//  Created by at on 29.05.2022.
//

#import "JSIUtils.h"
#import <jsi/jsi.h>

using namespace facebook;

NSString *convertJSIStringToNSString(jsi::Runtime &runtime, const jsi::String &value) {
    return [NSString stringWithUTF8String:value.utf8(runtime).c_str()];
}

jsi::String convertNSStringToJSIString(jsi::Runtime &runtime, NSString *value) {
    return jsi::String::createFromUtf8(runtime, [value UTF8String] ?: "");
}
