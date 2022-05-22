//
//  react-native-env-js.hpp
//  Pods
//
//  Created by at on 22.05.2022.
//

#include <jsi/jsilib.h>
#include <jsi/jsi.h>

#ifndef react_native_env_js_h
#define react_native_env_js_h

#include <stdio.h>

using namespace facebook;

void installSequel(jsi::Runtime &rt);
void cleanUpSequel();

#endif /* react_native_env_js_h */
