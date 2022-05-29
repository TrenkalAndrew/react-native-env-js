//
//  Some.m
//  react-native-env-js
//
//  Created by at on 29.05.2022.
//

#import "EnvJs.h"

@implementation EnvJs

+ (NSString *)getEnvironmentVariable:(NSString *)environmentVariableName {
    return [[[NSProcessInfo processInfo] environment] objectForKey:environmentVariableName];
}

@end
