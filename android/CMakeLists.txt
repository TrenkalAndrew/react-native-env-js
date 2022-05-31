cmake_minimum_required(VERSION 3.4.1)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 11)

add_library(cpp
            SHARED
            ../cpp/react-native-env-js.cpp
            cpp-adapter.cpp
            ../node_modules/react-native/ReactCommon/jsi/jsi/jsi.cpp
)

# Specifies a path to native header files.
include_directories(
            ../cpp
            ../node_modules/react-native/React
            ../node_modules/react-native/React/Base
            ../node_modules/react-native/ReactCommon/jsi
)
