cmake_minimum_required(VERSION 3.13)
set(CMAKE_VERBOSE_MAKEFILE on)

add_compile_options(
        -fexceptions
        -frtti
        -std=c++17
        -Wall
        -Wpedantic
        -Wno-gnu-zero-variadic-macro-arguments
)

file(GLOB LIBRN_DIR "${CMAKE_SOURCE_DIR}/../../../React")
file(GLOB LIBFBJNI_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/../../../ReactAndroid/src/main/jni/first-party/fbjni/headers")

target_include_directories(
        ${CMAKE_PROJECT_NAME}
        PRIVATE
        "${LIBRN_DIR}/ReactCommon"
        "${LIBRN_DIR}/ReactCommon/callinvoker"
        "${LIBRN_DIR}/ReactCommon/jsi"
        "${LIBRN_DIR}/ReactCommon/react/renderer/graphics/platform/cxx"
        "${LIBFBJNI_INCLUDE_DIR}"
        "./cpp"
)

target_sources(
        ${CMAKE_PROJECT_NAME}
        PRIVATE
        "./cpp/react-native-minimizer.cpp"
)
