//
//  Some.h
//  react-native-env-js
//
//  Created by at on 29.05.2022.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface EnvJs : NSObject

+ (NSString *) getEnvironmentVariable:(NSString *) environmentVariableName;

@end

NS_ASSUME_NONNULL_END
