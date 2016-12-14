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

    native public static double spriter_CreateInstance(double ModelIndex, String pInstanceName);

    native public static double spriter_Render(double TimeElapsed);

    native public static double spriter_RenderInstance(double ModelIndex, double InstanceIndex);

    native public static double spriter_UpdateInstance(double ModelIndex, double InstanceIndex, double TimeElapsed);

    native public static double spriter_GetSpriteInfoCount(double ModelIndex, double InstanceIndex);

    native public static String spriter_GetSpriteInfoFileName(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

    native public static String spriter_GetSpriteInfoString(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

    native public static double spriter_GetSpriteInfoPositionX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

    native public static double spriter_GetSpriteInfoPositionY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

    native public static double spriter_GetSpriteInfoPivotX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

    native public static double spriter_GetSpriteInfoPivotY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

    native public static double spriter_GetSpriteInfoSizeX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

    native public static double spriter_GetSpriteInfoSizeY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

    native public static double spriter_GetSpriteInfoScaleX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

    native public static double spriter_GetSpriteInfoScaleY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

    native public static double spriter_GetSpriteInfoAngle(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

    native public static double spriter_IsGetSpriteInfoRender(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

    native public static double spriter_GetSpriteInfoGMRenderPositionX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

    native public static double spriter_GetSpriteInfoGMRenderPositionY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

    native public static double spriter_GetSpriteInfoAlpha(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

    native public static double spriter_GetSpriteInfoType(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

    native public static double spriter_SetInstanceCurrentAnimation(double ModelIndex, double InstanceIndex, String pAnimationName, double BlendTime);

    native public static double spriter_SetSpriteInfoImageWidth(double ModelIndex, double InstanceIndex, double SpriteInfoIndex, double ImageWidth);

    native public static double spriter_SetSpriteInfoImageHeight(double ModelIndex, double InstanceIndex, double SpriteInfoIndex, double ImageHeight);

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

	native public static double spriter_IsSpriteInfoAtlasFile(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

	native public static double spriter_GetSpriteInfoAtlasFramePositionX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

	native public static double spriter_GetSpriteInfoAtlasFramePositionY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

	native public static double spriter_IsSpriteInfoAtlasFrameRotated(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

	native public static double spriter_IsSpriteInfoAtlasFrameTrimmed(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

	native public static double spriter_GetSpriteInfoAtlasFrameFrameSizeX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

	native public static double spriter_GetSpriteInfoAtlasFrameFrameSizeY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

	native public static double spriter_GetSpriteInfoAtlasFrameSourceSizeX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

	native public static double spriter_GetSpriteInfoAtlasFrameSourceSizeY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

	native public static double spriter_GetSpriteInfoAtlasFrameSpriteSourcePositionX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

	native public static double spriter_GetSpriteInfoAtlasFrameSpriteSourcePositionY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

	native public static double spriter_GetSpriteInfoAtlasFrameSpriteSourceSizeX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);

	native public static double spriter_GetSpriteInfoAtlasFrameSpriteSourceSizeY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex);
}
