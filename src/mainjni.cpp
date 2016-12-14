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
#include "mainjni.h"
#include "maindll.h"
#include "android_fopen.h"
#include <string>

void GetJStringContent(JNIEnv *AEnv, jstring AStr, std::string &ARes) {
    if (!AStr) {
        ARes.clear();
        return;
    }

    const char *s = AEnv->GetStringUTFChars(AStr,NULL);
    ARes=s;
    AEnv->ReleaseStringUTFChars(AStr,s);
}

jstring GetJStringContent(JNIEnv *AEnv, const char *byte)
{
    return AEnv->NewStringUTF(byte);
}

JNIEXPORT void JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetAssetManager
        (JNIEnv *env, jclass obj, jobject assetManager)
{
    AAssetManager *mgr = AAssetManager_fromJava(env, assetManager);

    android_fopen_set_asset_manager(mgr);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1LoadModel
		(JNIEnv *env, jclass object, jstring filePath)
{
    std::string str;
    GetJStringContent(env, filePath, str);

    return spriter_LoadModel(str.c_str());
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1CreateInstance
        (JNIEnv *env, jclass object, jdouble modelIndex, jstring instanceName)
{
    std::string str;
    GetJStringContent(env, instanceName, str);
    return spriter_CreateInstance(modelIndex, str.c_str());
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1Render
        (JNIEnv *env, jclass object, jdouble timeElapsed)
{
    return spriter_Render(timeElapsed);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1RenderInstance
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex)
{
    return spriter_RenderInstance(modelIndex, instanceIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1UpdateInstance
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble timeElapsed)
{
    return spriter_UpdateInstance(modelIndex, instanceIndex, timeElapsed);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoCount
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex)
{
    return spriter_GetSpriteInfoCount(modelIndex, instanceIndex);
}

JNIEXPORT jstring JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoFileName
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
    return GetJStringContent(env, spriter_GetSpriteInfoFileName(modelIndex, instanceIndex, spriteInfoIndex));
}

JNIEXPORT jstring JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoString
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
    return GetJStringContent(env, spriter_GetSpriteInfoFileName(modelIndex, instanceIndex, spriteInfoIndex));
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoPositionX
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
    return spriter_GetSpriteInfoPositionX(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoPositionY
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
    return spriter_GetSpriteInfoPositionY(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoPivotX
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
    return spriter_GetSpriteInfoPivotX(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoPivotY
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
    return spriter_GetSpriteInfoPivotY(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoSizeX
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
    return spriter_GetSpriteInfoSizeX(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoSizeY
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
    return spriter_GetSpriteInfoSizeY(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoScaleX
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
    return spriter_GetSpriteInfoScaleX(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoScaleY
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
    return spriter_GetSpriteInfoScaleY(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoAngle
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
    return spriter_GetSpriteInfoAngle(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1IsGetSpriteInfoRender
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
    return spriter_IsGetSpriteInfoRender(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoGMRenderPositionX
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
    return spriter_GetSpriteInfoGMRenderPositionX(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoGMRenderPositionY
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
    return spriter_GetSpriteInfoGMRenderPositionY(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoAlpha
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
    return spriter_GetSpriteInfoAlpha(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoType
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
    return spriter_GetSpriteInfoType(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetInstanceCurrentAnimation
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jstring animationName, jdouble blendTime)
{
    std::string str;
    GetJStringContent(env, animationName, str);

    return spriter_SetInstanceCurrentAnimation(modelIndex, instanceIndex, str.c_str(), blendTime);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetSpriteInfoImageWidth
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex, jdouble imageWidth)
{
    return spriter_SetSpriteInfoImageWidth(modelIndex, instanceIndex, spriteInfoIndex, imageWidth);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetSpriteInfoImageHeight
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex, jdouble imageHeight)
{
    return spriter_SetSpriteInfoImageHeight(modelIndex, instanceIndex, spriteInfoIndex, imageHeight);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetInstancePosition
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble px, jdouble py)
{
    return  spriter_SetInstancePosition(modelIndex, instanceIndex, px, py);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetInstancePositionX
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex)
{
    return spriter_GetInstancePositionX(modelIndex, instanceIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetInstancePositionY
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex)
{
    return spriter_GetInstancePositionY(modelIndex, instanceIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetInstanceScale
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble sx, jdouble sy)
{
    return spriter_SetInstanceScale(modelIndex, instanceIndex, sx, sy);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetInstanceAngle
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble angle)
{
    return spriter_SetInstanceAngle(modelIndex, instanceIndex, angle);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1ApplyInstanceCharacterMap
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jstring charMap)
{
    std::string str;
    GetJStringContent(env, charMap, str);

    return spriter_ApplyInstanceCharacterMap(modelIndex, instanceIndex, str.c_str());
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1RemoveInstanceCharacterMap
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jstring charMap)
{
    std::string str;
    GetJStringContent(env, charMap, str);

    return spriter_RemoveInstanceCharacterMap(modelIndex, instanceIndex, str.c_str());
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1RemoveInstanceAllCharacterMap
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex)
{
    return spriter_RemoveInstanceAllCharacterMap(modelIndex, instanceIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetInstancePlaybackSpeedRatio
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble playbackSpeedRatio)
{
    return spriter_SetInstancePlaybackSpeedRatio(modelIndex, instanceIndex, playbackSpeedRatio);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1InstanceStartResumePlayback
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex)
{
    return spriter_InstanceStartResumePlayback(modelIndex, instanceIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1InstancePausePlayback
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex)
{
    return spriter_InstancePausePlayback(modelIndex, instanceIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1InstanceSetTimeRatio
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble timeRatio)
{
    return spriter_InstanceSetTimeRatio(modelIndex, instanceIndex, timeRatio);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1InstanceAnimationJustFinished
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble looped)
{
    return spriter_InstanceAnimationJustFinished(modelIndex, instanceIndex, looped);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1InstanceGetTriggerInfoCount
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex)
{
    return spriter_InstanceGetTriggerInfoCount(modelIndex, instanceIndex);
}

JNIEXPORT jstring JNICALL Java_com_libspritergm_spriterGMNative_spriter_1InstanceGetTriggerInfoName
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble triggerIndex)
{
    return GetJStringContent(env, spriter_InstanceGetTriggerInfoName(modelIndex, instanceIndex, triggerIndex));
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1InstanceGetSoundInfoCount
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex)
{
    return spriter_InstanceGetSoundInfoCount(modelIndex, instanceIndex);
}

JNIEXPORT jstring JNICALL Java_com_libspritergm_spriterGMNative_spriter_1InstanceGetSoundInfoName
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble soundIndex)
{
    return GetJStringContent(env, spriter_InstanceGetSoundInfoName(modelIndex, instanceIndex, soundIndex));
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetErrorsCount
        (JNIEnv *env, jclass object)
{
    return spriter_GetErrorsCount();
}

JNIEXPORT jstring JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetLastError
        (JNIEnv *env, jclass object)
{
    return GetJStringContent(env, spriter_GetLastError());
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1ForceGarbageCollection
        (JNIEnv *env, jclass object)
{
    return spriter_ForceGarbageCollection();
}


JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1IsSpriteInfoAtlasFile
(JNIEnv * env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
	return spriter_IsSpriteInfoAtlasFile(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoAtlasFramePositionX
(JNIEnv * env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
	return spriter_GetSpriteInfoAtlasFramePositionX(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoAtlasFramePositionY
(JNIEnv * env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
	return spriter_GetSpriteInfoAtlasFramePositionY(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1IsSpriteInfoAtlasFrameRotated
(JNIEnv * env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
	return spriter_IsSpriteInfoAtlasFrameRotated(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1IsSpriteInfoAtlasFrameTrimmed
(JNIEnv * env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
	return spriter_IsSpriteInfoAtlasFrameTrimmed(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoAtlasFrameFrameSizeX
(JNIEnv * env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
	return spriter_GetSpriteInfoAtlasFrameFrameSizeX(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoAtlasFrameFrameSizeY
(JNIEnv * env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
	return spriter_GetSpriteInfoAtlasFrameFrameSizeY(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoAtlasFrameSourceSizeX
(JNIEnv * env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
	return spriter_GetSpriteInfoAtlasFrameSourceSizeX(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoAtlasFrameSourceSizeY
(JNIEnv * env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
	return spriter_GetSpriteInfoAtlasFrameSourceSizeY(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoAtlasFrameSpriteSourcePositionX
(JNIEnv * env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
	return spriter_GetSpriteInfoAtlasFrameSpriteSourcePositionX(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoAtlasFrameSpriteSourcePositionY
(JNIEnv * env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
	return spriter_GetSpriteInfoAtlasFrameSpriteSourcePositionY(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoAtlasFrameSpriteSourceSizeX
(JNIEnv * env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
	return spriter_GetSpriteInfoAtlasFrameSpriteSourceSizeX(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSpriteInfoAtlasFrameSpriteSourceSizeY
(JNIEnv * env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble spriteInfoIndex)
{
	return spriter_GetSpriteInfoAtlasFrameSpriteSourceSizeY(modelIndex, instanceIndex, spriteInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1AddLoadedSprite
(JNIEnv *env, jclass object, jdouble modelIndex, jstring spriteName, jdouble spritePtr)
{
	std::string str;
	GetJStringContent(env, spriteName, str);
	return spriter_AddLoadedSprite(modelIndex, str.c_str(), spritePtr);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1FindLoadedSprite
(JNIEnv *env, jclass object, jdouble modelIndex, jstring spriteName)
{
	std::string str;
	GetJStringContent(env, spriteName, str);

	return spriter_FindLoadedSprite(modelIndex, str.c_str());
}





