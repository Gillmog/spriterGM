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

void GetJStringContent(JNIEnv *AEnv, jstring AStr, std::string &ARes) {
    if (!AStr) {
        ARes.clear();
        return;
    }

    const char *s = AEnv->GetStringUTFChars(AStr,NULL);
    ARes=s;
    AEnv->ReleaseStringUTFChars(AStr,s);
}

jstring GetJStringContent(JNIEnv *AEnv, const std::string &ARes)
{
	jstring r = AEnv->NewStringUTF(ARes.c_str());

	return r;
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
        (JNIEnv *env, jclass object, jdouble modelIndex, jstring instanceName, jdouble bEnableBones)
{
    std::string str;
    GetJStringContent(env, instanceName, str);
    return spriter_CreateInstance(modelIndex, str.c_str(), bEnableBones);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1UpdateInstance
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble timeElapsed)
{
    return spriter_UpdateInstance(modelIndex, instanceIndex, timeElapsed);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetObjectInfoCount
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex)
{
    return spriter_GetObjectInfoCount(modelIndex, instanceIndex);
}

JNIEXPORT jstring JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetObjectInfoFileName
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble ObjectInfoIndex)
{
    return GetJStringContent(env, spriter_GetObjectInfoFileName(modelIndex, instanceIndex, ObjectInfoIndex));
}

JNIEXPORT jstring JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetObjectInfoString
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble ObjectInfoIndex)
{
    return GetJStringContent(env, spriter_GetObjectInfoFileName(modelIndex, instanceIndex, ObjectInfoIndex));
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetObjectInfoPositionX
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble ObjectInfoIndex)
{
    return spriter_GetObjectInfoPositionX(modelIndex, instanceIndex, ObjectInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetObjectInfoPositionY
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble ObjectInfoIndex)
{
    return spriter_GetObjectInfoPositionY(modelIndex, instanceIndex, ObjectInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetObjectInfoPivotX
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble ObjectInfoIndex)
{
    return spriter_GetObjectInfoPivotX(modelIndex, instanceIndex, ObjectInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetObjectInfoPivotY
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble ObjectInfoIndex)
{
    return spriter_GetObjectInfoPivotY(modelIndex, instanceIndex, ObjectInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetObjectInfoSizeX
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble ObjectInfoIndex)
{
    return spriter_GetObjectInfoSizeX(modelIndex, instanceIndex, ObjectInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetObjectInfoSizeY
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble ObjectInfoIndex)
{
    return spriter_GetObjectInfoSizeY(modelIndex, instanceIndex, ObjectInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetObjectInfoScaleX
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble ObjectInfoIndex)
{
    return spriter_GetObjectInfoScaleX(modelIndex, instanceIndex, ObjectInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetObjectInfoScaleY
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble ObjectInfoIndex)
{
    return spriter_GetObjectInfoScaleY(modelIndex, instanceIndex, ObjectInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetObjectInfoAngle
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble ObjectInfoIndex)
{
    return spriter_GetObjectInfoAngle(modelIndex, instanceIndex, ObjectInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1IsGetObjectInfoRender
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble ObjectInfoIndex)
{
    return spriter_IsGetObjectInfoRender(modelIndex, instanceIndex, ObjectInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetObjectInfoGMRenderPositionX
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble ObjectInfoIndex)
{
    return spriter_GetObjectInfoGMRenderPositionX(modelIndex, instanceIndex, ObjectInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetObjectInfoGMRenderPositionY
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble ObjectInfoIndex)
{
    return spriter_GetObjectInfoGMRenderPositionY(modelIndex, instanceIndex, ObjectInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetObjectInfoAlpha
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble ObjectInfoIndex)
{
    return spriter_GetObjectInfoAlpha(modelIndex, instanceIndex, ObjectInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetObjectInfoType
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble ObjectInfoIndex)
{
    return spriter_GetObjectInfoType(modelIndex, instanceIndex, ObjectInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetInstanceCurrentAnimation
        (JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jstring animationName, jdouble blendTime)
{
    std::string str;
    GetJStringContent(env, animationName, str);

    return spriter_SetInstanceCurrentAnimation(modelIndex, instanceIndex, str.c_str(), blendTime);
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

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetNumSprites
(JNIEnv *env, jclass object, jdouble modelIndex)
{
	return spriter_GetNumSprites(modelIndex);
}

JNIEXPORT jstring JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetSprite
(JNIEnv *env, jclass object, jdouble modelIndex, jdouble spriteIndex)
{
	return GetJStringContent(env, spriter_GetSprite(modelIndex, spriteIndex));
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetObjectInfoSpriteIndex
(JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble ObjectInfoIndex)
{
	return spriter_GetObjectInfoSpriteIndex(modelIndex, instanceIndex, ObjectInfoIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetLoadedSpriteTexelSize
(JNIEnv *env, jclass object, jdouble modelIndex, jstring spriteName, jdouble texelWidth, jdouble texelHeight)
{
	std::string str;
	GetJStringContent(env, spriteName, str);
	return spriter_SetLoadedSpriteTexelSize(modelIndex, str.c_str(), texelWidth, texelHeight);
}


JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetLoadedSpriteSize
(JNIEnv *env, jclass object, jdouble modelIndex, jstring spriteName, jdouble spriteWidth, jdouble spriteHeight)
{
	std::string str;
	GetJStringContent(env, spriteName, str);
	return spriter_SetLoadedSpriteSize(modelIndex, str.c_str(), spriteWidth, spriteHeight);
}


JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetObjectInfoMeshPointX
(JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble ObjectInfoIndex, jdouble pointIndex)
{
	return spriter_GetObjectInfoMeshPointX(modelIndex, instanceIndex, ObjectInfoIndex, pointIndex);
}


JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetObjectInfoMeshPointY
(JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble ObjectInfoIndex, jdouble pointIndex)
{
	return spriter_GetObjectInfoMeshPointY(modelIndex, instanceIndex, ObjectInfoIndex, pointIndex);
}


JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetObjectInfoMeshUVX
(JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble ObjectInfoIndex, jdouble pointIndex)
{
	return spriter_GetObjectInfoMeshUVX(modelIndex, instanceIndex, ObjectInfoIndex, pointIndex);
}


JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetObjectInfoMeshUVY
(JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble ObjectInfoIndex, jdouble pointIndex)
{
	return spriter_GetObjectInfoMeshUVY(modelIndex, instanceIndex, ObjectInfoIndex, pointIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1DestroyInstance
(JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex)
{
	return spriter_DestroyInstance(modelIndex, instanceIndex);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1DestroyModel
(JNIEnv *env, jclass object, jdouble modelIndex)
{
	return spriter_DestroyModel(modelIndex);
}


JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1DestroyAllModels
(JNIEnv *env, jclass object)
{
	return spriter_DestroyAllModels();
}

JNIEXPORT jstring JNICALL Java_com_libspritergm_spriterGMNative_spriter_1GetObjectInfoName
(JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble objectInfoIndex)
{
	return GetJStringContent(env, spriter_GetObjectInfoName(modelIndex, instanceIndex, objectInfoIndex));
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetLockObjectInstance
(JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jstring objectName)
{
	std::string str;
	GetJStringContent(env, objectName, str);

	return spriter_SetLockObjectInstance(modelIndex, instanceIndex, str.c_str());
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetUnlockObjectInstance
(JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex)
{
	return spriter_SetUnlockObjectInstance(modelIndex, instanceIndex);
}


JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetObjectInstanceIKMode
(JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble IKMode, jdouble IKTreshold)
{
	return spriter_SetObjectInstanceIKMode(modelIndex, instanceIndex, IKMode, IKTreshold);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetObjectInstanceIKPosition
(JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble x, jdouble y)
{
	return spriter_SetObjectInstanceIKPosition(modelIndex, instanceIndex, x, y);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetObjectInstanceManualAngleControl
(JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jstring objectName, jdouble manualCOntrol)
{
	std::string str;
	GetJStringContent(env, objectName, str);

	return spriter_SetObjectInstanceManualAngleControl(modelIndex, instanceIndex, str.c_str(), manualCOntrol);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1SetObjectInstanceManualAngle
(JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jdouble x, jdouble y)
{
	return spriter_SetObjectInstanceManualAngle(modelIndex, instanceIndex, x, y);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1IsObjectInstanceIKMode
(JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jstring objectName)
{
	std::string str;
	GetJStringContent(env, objectName, str);

	return spriter_IsObjectInstanceIKMode(modelIndex, instanceIndex, str.c_str());
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1IsObjectInstanceManualAngleControl
(JNIEnv *env, jclass object, jdouble modelIndex, jdouble instanceIndex, jstring objectName)
{
	std::string str;
	GetJStringContent(env, objectName, str);

	return spriter_IsObjectInstanceManualAngleControl(modelIndex, instanceIndex, str.c_str());
}