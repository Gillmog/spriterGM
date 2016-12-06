NDK_TOOLCHAIN_VERSION := 4.9
APP_OPTIM := release
APP_BUILD_SCRIPT := Android.mk
APP_ABI := armeabi armeabi-v7a x86 mips arm64-v8a
APP_CPPFLAGS += -frtti
APP_CPPFLAGS += -fexceptions
APP_CPPFLAGS += -std=c++11
APP_STL := c++_shared