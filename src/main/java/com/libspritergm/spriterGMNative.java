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

package com.libspritergm;

public class spriterGMNative {

    static
    {
        System.loadLibrary("spriterGM");

    }
    native public static void spriter_SetAssetManager(Object mgr);

    native public static double spriter_LoadModel(String file);

    native public static double spriter_CreateInstance(double ModelIndex, String pInstanceName, double bEnableBones);

    native public static double spriter_UpdateInstance(double ModelIndex, double InstanceIndex, double TimeElapsed);

    native public static double spriter_GetObjectInfoCount(double ModelIndex, double InstanceIndex);

    native public static String spriter_GetObjectInfoFileName(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

    native public static String spriter_GetObjectInfoString(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

    native public static double spriter_GetObjectInfoPositionX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

    native public static double spriter_GetObjectInfoPositionY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

    native public static double spriter_GetObjectInfoPivotX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

    native public static double spriter_GetObjectInfoPivotY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

    native public static double spriter_GetObjectInfoSizeX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

    native public static double spriter_GetObjectInfoSizeY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

    native public static double spriter_GetObjectInfoScaleX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

    native public static double spriter_GetObjectInfoScaleY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

    native public static double spriter_GetObjectInfoAngle(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

    native public static double spriter_IsGetObjectInfoRender(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

    native public static double spriter_GetObjectInfoGMRenderPositionX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

    native public static double spriter_GetObjectInfoGMRenderPositionY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

    native public static double spriter_GetObjectInfoAlpha(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

    native public static double spriter_GetObjectInfoType(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

    native public static double spriter_SetInstanceCurrentAnimation(double ModelIndex, double InstanceIndex, String pAnimationName, double BlendTime);

    native public static double spriter_SetInstancePosition(double ModelIndex, double InstanceIndex, double px, double py);

    native public static double spriter_GetInstancePositionX(double ModelIndex, double InstanceIndex);

    native public static double spriter_GetInstancePositionY(double ModelIndex, double InstanceIndex);

    native public static double spriter_SetInstanceScale(double ModelIndex, double InstanceIndex, double sx, double sy);

    native public static double spriter_SetInstanceAngle(double ModelIndex, double InstanceIndex, double angle);

    native public static double spriter_ApplyInstanceCharacterMap(double ModelIndex, double InstanceIndex, String charMap);

    native public static double spriter_RemoveInstanceCharacterMap(double ModelIndex, double InstanceIndex, String charMap);

    native public static double spriter_RemoveInstanceAllCharacterMap(double ModelIndex, double InstanceIndex);

    native public static double spriter_SetInstancePlaybackSpeedRatio(double ModelIndex, double InstanceIndex, double PlaybackSpeedRatio);

    native public static double spriter_InstanceStartResumePlayback(double ModelIndex, double InstanceIndex);

    native public static double spriter_InstancePausePlayback(double ModelIndex, double InstanceIndex);

    native public static double spriter_InstanceSetTimeRatio(double ModelIndex, double InstanceIndex, double TimeRatio);

    native public static double spriter_InstanceAnimationJustFinished(double ModelIndex, double InstanceIndex, double bLooped);

    native public static double spriter_InstanceGetTriggerInfoCount(double ModelIndex, double InstanceIndex);

    native public static String spriter_InstanceGetTriggerInfoName(double ModelIndex, double InstanceIndex, double TriggerIndex);

    native public static double spriter_InstanceGetSoundInfoCount(double ModelIndex, double InstanceIndex);

    native public static String spriter_InstanceGetSoundInfoName(double ModelIndex, double InstanceIndex, double SoundIndex);

    native public static double spriter_GetErrorsCount();

    native public static String spriter_GetLastError();

    native public static double spriter_ForceGarbageCollection();

	native public static double spriter_AddLoadedSprite(double ModelIndex, String pSpriteName, double SpritePtr);

	native public static double spriter_FindLoadedSprite(double ModelIndex, String pSpriteName);

	native public static double spriter_GetNumSprites(double ModelIndex);

	native public static String spriter_GetSprite(double ModelIndex, double SpriteIndex);

	native public static double spriter_GetObjectInfoSpriteIndex(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

	native public static double spriter_SetLoadedSpriteTexelSize(double ModelIndex, String pSpriteName, double TexelWidth, double TexelHeight);

	native public static double spriter_SetLoadedSpriteSize(double ModelIndex, String pSpriteName, double TextureWidth, double TextureHeight);

	native public static double spriter_GetObjectInfoMeshPointX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex, double PointIndex);
	native public static double spriter_GetObjectInfoMeshPointY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex, double PointIndex);

	native public static double spriter_GetObjectInfoMeshUVX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex, double PointIndex);
	native public static double spriter_GetObjectInfoMeshUVY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex, double PointIndex);

	native public static double spriter_DestroyInstance(double ModelIndex, double InstanceIndex);

	native public static double spriter_DestroyModel(double ModelIndex);

	native public static double spriter_DestroyAllModels();

	native public static String spriter_GetObjectInfoName(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);
	
	native public static double spriter_SetLockObjectInstance(double ModelIndex, double InstanceIndex, String ObjectName);

	native public static double spriter_SetUnlockObjectInstance(double ModelIndex, double InstanceIndex);

	native public static double spriter_SetObjectInstanceIKMode(double ModelIndex, double InstanceIndex, double bIKMode, double IKTreshold);

	native public static double spriter_SetObjectInstanceIKPosition(double ModelIndex, double InstanceIndex, double x, double y);

	native public static double spriter_SetObjectInstanceManualAngleControl(double ModelIndex, double InstanceIndex, String ObjectName, double bManualControl);

	native public static double spriter_SetObjectInstanceManualAngle(double ModelIndex, double InstanceIndex, double x, double y);

	native public static double spriter_IsObjectInstanceIKMode(double ModelIndex, double InstanceIndex, String ObjectName);

	native public static double spriter_IsObjectInstanceManualAngleControl(double ModelIndex, double InstanceIndex, String ObjectName);
}
