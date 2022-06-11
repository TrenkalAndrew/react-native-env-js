cmake_minimum_required(VERSION 3.4.1)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 11)
set (PACKAGE_NAME "EnvJs")

add_library(
            ${PACKAGE_NAME}
            SHARED
            src/main/cpp/react-native-env-js.cpp
            cpp-adapter.cpp
            ../node_modules/react-native/ReactCommon/jsi/jsi/jsi.cpp
)

# Specifies a path to native header files.
include_directories(
            src/main/cpp
            ../node_modules/react-native/React
            ../node_modules/react-native/React/Base
            ../node_modules/react-native/ReactCommon/jsi
)
