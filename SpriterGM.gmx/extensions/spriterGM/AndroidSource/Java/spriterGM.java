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


package ${YYAndroidPackageName};

import android.util.Log;
import java.io.File;
import java.io.FileReader;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.lang.String;
import com.libspritergm.spriterGMNative;
import android.app.Activity;
import android.content.res.AssetManager;

import ${YYAndroidPackageName}.R;
import com.yoyogames.runner.RunnerJNILib;
import ${YYAndroidPackageName}.RunnerActivity;

public class spriterGM {

    static
    {
        AssetManager manager = RunnerActivity.CurrentActivity.getApplicationContext().getAssets();
        spriterGMNative.spriter_SetAssetManager(manager);
    }

    public double spriter_LoadModel(String file) {
        return spriterGMNative.spriter_LoadModel(file);
    }

    public double spriter_CreateInstance(double ModelIndex, String pInstanceName, double bEnableBones) {
        return spriterGMNative.spriter_CreateInstance(ModelIndex, pInstanceName, bEnableBones);
    }

    public double spriter_UpdateInstance(double ModelIndex, double InstanceIndex, double TimeElapsed) {
        return spriterGMNative.spriter_UpdateInstance(ModelIndex, InstanceIndex, TimeElapsed);
    }

    public double spriter_GetObjectInfoCount(double ModelIndex, double InstanceIndex) {
        return spriterGMNative.spriter_GetObjectInfoCount(ModelIndex, InstanceIndex);
    }

    public String spriter_GetObjectInfoFileName(double ModelIndex, double InstanceIndex, double ObjectInfoIndex) {
        return spriterGMNative.spriter_GetObjectInfoFileName(ModelIndex, InstanceIndex, ObjectInfoIndex);
    }

    public String spriter_GetObjectInfoString(double ModelIndex, double InstanceIndex, double ObjectInfoIndex) {
        return spriterGMNative.spriter_GetObjectInfoString(ModelIndex, InstanceIndex, ObjectInfoIndex);
    }

    public double spriter_GetObjectInfoPositionX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex) {
        return spriterGMNative.spriter_GetObjectInfoPositionX(ModelIndex, InstanceIndex, ObjectInfoIndex);
    }

    public double spriter_GetObjectInfoPositionY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex) {
        return spriterGMNative.spriter_GetObjectInfoPositionY(ModelIndex, InstanceIndex, ObjectInfoIndex);
    }

    public double spriter_GetObjectInfoPivotX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex) {
        return spriterGMNative.spriter_GetObjectInfoPivotX(ModelIndex, InstanceIndex, ObjectInfoIndex);
    }

    public double spriter_GetObjectInfoPivotY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex) {
        return spriterGMNative.spriter_GetObjectInfoPivotY(ModelIndex, InstanceIndex, ObjectInfoIndex);
    }

    public double spriter_GetObjectInfoSizeX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex) {
        return spriterGMNative.spriter_GetObjectInfoSizeX(ModelIndex, InstanceIndex, ObjectInfoIndex);
    }

    public double spriter_GetObjectInfoSizeY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex) {
        return spriterGMNative.spriter_GetObjectInfoSizeY(ModelIndex, InstanceIndex, ObjectInfoIndex);
    }

    public double spriter_GetObjectInfoScaleX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex) {
        return spriterGMNative.spriter_GetObjectInfoScaleX(ModelIndex, InstanceIndex, ObjectInfoIndex);
    }

    public double spriter_GetObjectInfoScaleY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex) {
        return spriterGMNative.spriter_GetObjectInfoScaleY(ModelIndex, InstanceIndex, ObjectInfoIndex);
    }

    public double spriter_GetObjectInfoAngle(double ModelIndex, double InstanceIndex, double ObjectInfoIndex) {
        return spriterGMNative.spriter_GetObjectInfoAngle(ModelIndex, InstanceIndex, ObjectInfoIndex);
    }

    public double spriter_IsGetObjectInfoRender(double ModelIndex, double InstanceIndex, double ObjectInfoIndex) {
        return spriterGMNative.spriter_IsGetObjectInfoRender(ModelIndex, InstanceIndex, ObjectInfoIndex);
    }

    public double spriter_GetObjectInfoGMRenderPositionX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex) {
        return spriterGMNative.spriter_GetObjectInfoGMRenderPositionX(ModelIndex, InstanceIndex, ObjectInfoIndex);
    }

    public double spriter_GetObjectInfoGMRenderPositionY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex) {
        return spriterGMNative.spriter_GetObjectInfoGMRenderPositionY(ModelIndex, InstanceIndex, ObjectInfoIndex);
    }

    public double spriter_GetObjectInfoAlpha(double ModelIndex, double InstanceIndex, double ObjectInfoIndex) {
        return spriterGMNative.spriter_GetObjectInfoAlpha(ModelIndex, InstanceIndex, ObjectInfoIndex);
    }

    public double spriter_GetObjectInfoType(double ModelIndex, double InstanceIndex, double ObjectInfoIndex) {
        return spriterGMNative.spriter_GetObjectInfoType(ModelIndex, InstanceIndex, ObjectInfoIndex);
    }

    public double spriter_SetInstanceCurrentAnimation(double ModelIndex, double InstanceIndex, String pAnimationName, double BlendTime) {
        return spriterGMNative.spriter_SetInstanceCurrentAnimation(ModelIndex, InstanceIndex, pAnimationName, BlendTime);
    }

    public double spriter_SetInstancePosition(double ModelIndex, double InstanceIndex, double px, double py) {
        return spriterGMNative.spriter_SetInstancePosition(ModelIndex, InstanceIndex, px, py);
    }

    public double spriter_GetInstancePositionX(double ModelIndex, double InstanceIndex) {
        return spriterGMNative.spriter_GetInstancePositionX(ModelIndex, InstanceIndex);
    }

    public double spriter_GetInstancePositionY(double ModelIndex, double InstanceIndex) {
        return spriterGMNative.spriter_GetInstancePositionY(ModelIndex, InstanceIndex);
    }

    public double spriter_SetInstanceScale(double ModelIndex, double InstanceIndex, double sx, double sy) {
        return spriterGMNative.spriter_SetInstanceScale(ModelIndex, InstanceIndex, sx, sy);
    }

    public double spriter_SetInstanceAngle(double ModelIndex, double InstanceIndex, double angle) {
        return spriterGMNative.spriter_SetInstanceAngle(ModelIndex, InstanceIndex, angle);
    }

    public double spriter_ApplyInstanceCharacterMap(double ModelIndex, double InstanceIndex, String charMap) {
        return spriterGMNative.spriter_ApplyInstanceCharacterMap(ModelIndex, InstanceIndex, charMap);
    }

    public double spriter_RemoveInstanceCharacterMap(double ModelIndex, double InstanceIndex, String charMap) {
        return spriterGMNative.spriter_RemoveInstanceCharacterMap(ModelIndex, InstanceIndex, charMap);
    }

    public double spriter_RemoveInstanceAllCharacterMap(double ModelIndex, double InstanceIndex) {
        return spriterGMNative.spriter_RemoveInstanceAllCharacterMap(ModelIndex, InstanceIndex);
    }

    public double spriter_SetInstancePlaybackSpeedRatio(double ModelIndex, double InstanceIndex, double PlaybackSpeedRatio) {
        return spriterGMNative.spriter_SetInstancePlaybackSpeedRatio(ModelIndex, InstanceIndex, PlaybackSpeedRatio);
    }

    public double spriter_InstanceStartResumePlayback(double ModelIndex, double InstanceIndex) {
        return spriterGMNative.spriter_InstanceStartResumePlayback(ModelIndex, InstanceIndex);
    }

    public double spriter_InstancePausePlayback(double ModelIndex, double InstanceIndex) {
        return spriterGMNative.spriter_InstancePausePlayback(ModelIndex, InstanceIndex);
    }

    public double spriter_InstanceSetTimeRatio(double ModelIndex, double InstanceIndex, double TimeRatio) {
        return spriterGMNative.spriter_InstanceSetTimeRatio(ModelIndex, InstanceIndex, TimeRatio);
    }

    public double spriter_InstanceAnimationJustFinished(double ModelIndex, double InstanceIndex, double bLooped) {
        return spriterGMNative.spriter_InstanceAnimationJustFinished(ModelIndex, InstanceIndex, bLooped);
    }

    public double spriter_InstanceGetTriggerInfoCount(double ModelIndex, double InstanceIndex) {
        return spriterGMNative.spriter_InstanceGetTriggerInfoCount(ModelIndex, InstanceIndex);
    }

    public String spriter_InstanceGetTriggerInfoName(double ModelIndex, double InstanceIndex, double TriggerIndex) {
        return spriterGMNative.spriter_InstanceGetTriggerInfoName(ModelIndex, InstanceIndex, TriggerIndex);
    }

    public double spriter_InstanceGetSoundInfoCount(double ModelIndex, double InstanceIndex) {
        return spriterGMNative.spriter_InstanceGetSoundInfoCount(ModelIndex, InstanceIndex);
    }

    public String spriter_InstanceGetSoundInfoName(double ModelIndex, double InstanceIndex, double SoundIndex) {
        return spriterGMNative.spriter_InstanceGetSoundInfoName(ModelIndex, InstanceIndex, SoundIndex);
    }

    public double spriter_GetErrorsCount() {
        return spriterGMNative.spriter_GetErrorsCount();
    }

    public String spriter_GetLastError() {
        return spriterGMNative.spriter_GetLastError();
    }

    public double spriter_ForceGarbageCollection() {
        return spriterGMNative.spriter_ForceGarbageCollection();
    }

	public double spriter_AddLoadedSprite(double ModelIndex, String pSpriteName, double SpritePtr) {
		return spriterGMNative.spriter_AddLoadedSprite(ModelIndex, pSpriteName, SpritePtr);
	}

	public double spriter_FindLoadedSprite(double ModelIndex, String pSpriteName) {
		return spriterGMNative.spriter_FindLoadedSprite(ModelIndex, pSpriteName);
	}
	
	public double spriter_GetNumSprites(double ModelIndex)
    {
        return spriterGMNative.spriter_GetNumSprites(ModelIndex);
    }

    public String spriter_GetSprite(double ModelIndex, double SpriteIndex)
    {
        return spriterGMNative.spriter_GetSprite(ModelIndex, SpriteIndex);
    }

    public double spriter_GetObjectInfoSpriteIndex(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
    {
        return spriterGMNative.spriter_GetObjectInfoSpriteIndex(ModelIndex, InstanceIndex, ObjectInfoIndex);
    }

	public double spriter_SetLoadedSpriteTexelSize(double ModelIndex, String pSpriteName, double TexelWidth, double TexelHeight)
	{
		return spriterGMNative.spriter_SetLoadedSpriteTexelSize(ModelIndex, pSpriteName, TexelWidth, TexelHeight);
	}

	public double spriter_SetLoadedSpriteSize(double ModelIndex, String pSpriteName, double TextureWidth, double TextureHeight)
	{
		return spriterGMNative.spriter_SetLoadedSpriteSize(ModelIndex, pSpriteName, TextureWidth, TextureHeight);
	}

	public double spriter_GetObjectInfoMeshPointX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex, double PointIndex)
	{
		return spriterGMNative.spriter_GetObjectInfoMeshPointX(ModelIndex, InstanceIndex, ObjectInfoIndex, PointIndex);
	}

	public double spriter_GetObjectInfoMeshPointY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex, double PointIndex)
	{
		return spriterGMNative.spriter_GetObjectInfoMeshPointY(ModelIndex, InstanceIndex, ObjectInfoIndex, PointIndex);
	}

	public double spriter_GetObjectInfoMeshUVX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex, double PointIndex)
	{
		return spriterGMNative.spriter_GetObjectInfoMeshUVX(ModelIndex, InstanceIndex, ObjectInfoIndex, PointIndex);
	}

	public double spriter_GetObjectInfoMeshUVY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex, double PointIndex)
	{
		return spriterGMNative.spriter_GetObjectInfoMeshUVY(ModelIndex, InstanceIndex, ObjectInfoIndex, PointIndex);
	}

	public double spriter_DestroyInstance(double ModelIndex, double InstanceIndex)
	{
		return spriterGMNative.spriter_DestroyInstance(ModelIndex, InstanceIndex);
	}

	public double spriter_DestroyModel(double ModelIndex)
	{
		return spriterGMNative.spriter_DestroyModel(ModelIndex);
	}

	public double spriter_DestroyAllModels()
	{
		return spriterGMNative.spriter_DestroyAllModels();
	}

	public String spriter_GetObjectInfoName(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
	{
		return spriterGMNative.spriter_GetObjectInfoName(ModelIndex, InstanceIndex, ObjectInfoIndex);
	}
	
	public double spriter_SetLockObjectInstance(double ModelIndex, double InstanceIndex, String ObjectName)
	{
		return spriterGMNative.spriter_SetLockObjectInstance(ModelIndex, InstanceIndex, ObjectName);
	}

	public double spriter_SetUnlockObjectInstance(double ModelIndex, double InstanceIndex)
	{
		return spriterGMNative.spriter_SetUnlockObjectInstance(ModelIndex, InstanceIndex);
	}

	public double spriter_SetObjectInstanceIKMode(double ModelIndex, double InstanceIndex, double bIKMode, double IKTreshold)
	{
		return spriterGMNative.spriter_SetObjectInstanceIKMode(ModelIndex, InstanceIndex, bIKMode, IKTreshold);
	}

	public double spriter_SetObjectInstanceIKPosition(double ModelIndex, double InstanceIndex, double x, double y)
	{
		return spriterGMNative.spriter_SetObjectInstanceIKPosition(ModelIndex, InstanceIndex, x, y);
	}

	public double spriter_SetObjectInstanceManualAngleControl(double ModelIndex, double InstanceIndex, String ObjectName, double bManualControl)
	{
		return spriterGMNative.spriter_SetObjectInstanceManualAngleControl(ModelIndex, InstanceIndex, ObjectName, bManualControl);
	}

	public double spriter_SetObjectInstanceManualAngle(double ModelIndex, double InstanceIndex, double x, double y)
	{
		return spriterGMNative.spriter_SetObjectInstanceManualAngle(ModelIndex, InstanceIndex, x, y);
	}

	public double spriter_IsObjectInstanceIKMode(double ModelIndex, double InstanceIndex, String ObjectName)
	{
		return spriterGMNative.spriter_IsObjectInstanceIKMode(ModelIndex, InstanceIndex, ObjectName);
	}

	public double spriter_IsObjectInstanceManualAngleControl(double ModelIndex, double InstanceIndex, String ObjectName)
	{
		return spriterGMNative.spriter_IsObjectInstanceManualAngleControl(ModelIndex, InstanceIndex, ObjectName);
	}
}
