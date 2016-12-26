//-----------------------------------------------------------------------------
// Copyright (c) 2016 Vitaliy Zhygotsky, Leichanka Aliaksandr
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------

#ifndef ANDROID
#define ANDROID
#endif

#include <jni.h>
#include <android/asset_manager.h>
#include <android/asset_manager_jni.h>

#ifndef _Included_com_libspritergm_spriterGMNative
#define _Included_com_libspritergm_spriterGMNative
#ifdef __cplusplus
extern "C" {
#endif
	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_SetAssetManager
	* Signature: (Ljava/lang/Object;)V
	*/
	JNIEXPORT void JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetAssetManager
	(JNIEnv *, jclass, jobject);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_LoadModel
	* Signature: (Ljava/lang/String;)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1LoadModel
	(JNIEnv *, jclass, jstring);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_CreateInstance
	* Signature: (DLjava/lang/String/;)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1CreateInstance
	(JNIEnv *, jclass, jdouble, jstring, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_UpdateInstance
	* Signature: (DDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1UpdateInstance
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetSpriteInfoCount
	* Signature: (DD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoCount
	(JNIEnv *, jclass, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetSpriteInfoFileName
	* Signature: (DDD)Ljava/lang/String;
	*/
	JNIEXPORT jstring JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoFileName
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetSpriteInfoString
	* Signature: (DDD)Ljava/lang/String;
	*/
	JNIEXPORT jstring JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoString
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetSpriteInfoPositionX
	* Signature: (DDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoPositionX
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetSpriteInfoPositionY
	* Signature: (DDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoPositionY
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetSpriteInfoPivotX
	* Signature: (DDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoPivotX
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetSpriteInfoPivotY
	* Signature: (DDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoPivotY
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetSpriteInfoSizeX
	* Signature: (DDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoSizeX
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetSpriteInfoSizeY
	* Signature: (DDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoSizeY
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetSpriteInfoScaleX
	* Signature: (DDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoScaleX
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetSpriteInfoScaleY
	* Signature: (DDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoScaleY
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetSpriteInfoAngle
	* Signature: (DDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoAngle
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_IsGetSpriteInfoRender
	* Signature: (DDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1IsGetSpriteInfoRender
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetSpriteInfoGMRenderPositionX
	* Signature: (DDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoGMRenderPositionX
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetSpriteInfoGMRenderPositionY
	* Signature: (DDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoGMRenderPositionY
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetSpriteInfoAlpha
	* Signature: (DDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoAlpha
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetSpriteInfoType
	* Signature: (DDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoType
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_SetInstanceCurrentAnimation
	* Signature: (DDLjava/lang/String;D)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetInstanceCurrentAnimation
	(JNIEnv *, jclass, jdouble, jdouble, jstring, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_SetInstancePosition
	* Signature: (DDDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetInstancePosition
	(JNIEnv *, jclass, jdouble, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetInstancePositionX
	* Signature: (DD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetInstancePositionX
	(JNIEnv *, jclass, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetInstancePositionY
	* Signature: (DD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetInstancePositionY
	(JNIEnv *, jclass, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_SetInstanceScale
	* Signature: (DDDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetInstanceScale
	(JNIEnv *, jclass, jdouble, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_SetInstanceAngle
	* Signature: (DDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetInstanceAngle
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_ApplyInstanceCharacterMap
	* Signature: (DDLjava/lang/String;)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1ApplyInstanceCharacterMap
	(JNIEnv *, jclass, jdouble, jdouble, jstring);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_RemoveInstanceCharacterMap
	* Signature: (DDLjava/lang/String;)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1RemoveInstanceCharacterMap
	(JNIEnv *, jclass, jdouble, jdouble, jstring);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_RemoveInstanceAllCharacterMap
	* Signature: (DD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1RemoveInstanceAllCharacterMap
	(JNIEnv *, jclass, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_SetInstancePlaybackSpeedRatio
	* Signature: (DDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetInstancePlaybackSpeedRatio
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_InstanceStartResumePlayback
	* Signature: (DD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1InstanceStartResumePlayback
	(JNIEnv *, jclass, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_InstancePausePlayback
	* Signature: (DD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1InstancePausePlayback
	(JNIEnv *, jclass, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_InstanceSetTimeRatio
	* Signature: (DDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1InstanceSetTimeRatio
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_InstanceAnimationJustFinished
	* Signature: (DDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1InstanceAnimationJustFinished
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_InstanceGetTriggerInfoCount
	* Signature: (DD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1InstanceGetTriggerInfoCount
	(JNIEnv *, jclass, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_InstanceGetTriggerInfoName
	* Signature: (DDD)Ljava/lang/String;
	*/
	JNIEXPORT jstring JNICALL Java_com_libspritergm_spriterGMNative_spriter_1InstanceGetTriggerInfoName
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_InstanceGetSoundInfoCount
	* Signature: (DD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1InstanceGetSoundInfoCount
	(JNIEnv *, jclass, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_InstanceGetSoundInfoName
	* Signature: (DDD)Ljava/lang/String;
	*/
	JNIEXPORT jstring JNICALL Java_com_libspritergm_spriterGMNative_spriter_1InstanceGetSoundInfoName
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetErrorsCount
	* Signature: ()D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetErrorsCount
	(JNIEnv *, jclass);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetLastError
	* Signature: ()Ljava/lang/String;
	*/
	JNIEXPORT jstring JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetLastError
	(JNIEnv *, jclass);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_ForceGarbageCollection
	* Signature: ()D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1ForceGarbageCollection
	(JNIEnv *, jclass);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_AddLoadedSprite
	* Signature: (DLjava/lang/String;D)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1AddLoadedSprite
	(JNIEnv *, jclass, jdouble, jstring, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_FindLoadedSprite
	* Signature: (DLjava/lang/String;)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1FindLoadedSprite
	(JNIEnv *, jclass, jdouble, jstring);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetNumSprites
	* Signature: (D)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetNumSprites
	(JNIEnv *, jclass, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetSprite
	* Signature: (DD)Ljava/lang/String;
	*/
	JNIEXPORT jstring JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSprite
	(JNIEnv *, jclass, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetSpriteInfoSpriteIndex
	* Signature: (DDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoSpriteIndex
	(JNIEnv *, jclass, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_SetLoadedSpriteTexelSize
	* Signature: (DLjava/lang/String;DD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetLoadedSpriteTexelSize
	(JNIEnv *, jclass, jdouble, jstring, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_SetLoadedSpriteSize
	* Signature: (DLjava/lang/String;DD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetLoadedSpriteSize
	(JNIEnv *, jclass, jdouble, jstring, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetSpriteInfoMeshPointX
	* Signature: (DDDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoMeshPointX
	(JNIEnv *, jclass, jdouble, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetSpriteInfoMeshPointY
	* Signature: (DDDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoMeshPointY
	(JNIEnv *, jclass, jdouble, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetSpriteInfoMeshUVX
	* Signature: (DDDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoMeshUVX
	(JNIEnv *, jclass, jdouble, jdouble, jdouble, jdouble);

	/*
	* Class:     com_libspritergm_spriterGMNative
	* Method:    spriter_GetSpriteInfoMeshUVY
	* Signature: (DDDD)D
	*/
	JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoMeshUVY
	(JNIEnv *, jclass, jdouble, jdouble, jdouble, jdouble);

#ifdef __cplusplus
}
#endif
#endif

