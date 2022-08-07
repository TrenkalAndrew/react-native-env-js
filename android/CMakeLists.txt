cmake_minimum_required(VERSION 3.4.1)

set (CMAKE_VERBOSE_MAKEFILE ON)
set (CMAKE_CXX_STANDARD 14)
set (PACKAGE_NAME "EnvJs")

set(build_DIR ${CMAKE_SOURCE_DIR}/build)

file(GLOB libfbjni_link_DIRS "${build_DIR}/fbjni*.aar/jni/${ANDROID_ABI}")
file(GLOB libfbjni_include_DIRS "${build_DIR}/fbjni-*-headers.jar/")

find_library(FBJNI_LIBRARY fbjni PATHS ${libfbjni_link_DIRS} NO_CMAKE_FIND_ROOT_PATH)

add_library(
            ${PACKAGE_NAME}
            SHARED
            src/main/cpp/react-native-env-js.cpp
            cpp-adapter.cpp
            "${NODE_MODULES_DIR}/react-native/ReactCommon/jsi/jsi/jsi.cpp"
            src/main/cpp/java-bindings/JEnvJs.cpp
)

# Specifies a path to native header files.
include_directories(
            src/main/cpp
            "${NODE_MODULES_DIR}/react-native/React"
            "${NODE_MODULES_DIR}/react-native/React/Base"
            "${NODE_MODULES_DIR}/react-native/ReactCommon/jsi"
)

target_include_directories(
    ${PACKAGE_NAME} 
    PRIVATE
    ${libfbjni_include_DIRS}
    "${NODE_MODULES_DIR}/react-native/ReactAndroid/src/main/jni"
    "${NODE_MODULES_DIR}/react-native/ReactAndroid/src/main/java/com/facebook/react/turbomodule/core/jni"
)

target_link_libraries(
    ${PACKAGE_NAME} 
    ${FBJNI_LIBRARY} 
    android
)
