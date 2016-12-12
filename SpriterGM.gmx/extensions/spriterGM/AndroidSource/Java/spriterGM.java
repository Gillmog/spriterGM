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

    //For test only
    public void init(Activity activity)
    {
        AssetManager manager = activity.getApplicationContext().getAssets();
        spriterGMNative.spriter_SetAssetManager(manager);
    }

    public double spriter_LoadModel(String file) {
        return spriterGMNative.spriter_LoadModel(file);
    }

    public double spriter_CreateInstance(double ModelIndex, String pInstanceName) {
        return spriterGMNative.spriter_CreateInstance(ModelIndex, pInstanceName);
    }

    public double spriter_Render(double TimeElapsed) {
        return spriterGMNative.spriter_Render(TimeElapsed);
    }

    public double spriter_RenderInstance(double ModelIndex, double InstanceIndex) {
        return spriterGMNative.spriter_RenderInstance(ModelIndex, InstanceIndex);
    }

    public double spriter_UpdateInstance(double ModelIndex, double InstanceIndex, double TimeElapsed) {
        return spriterGMNative.spriter_UpdateInstance(ModelIndex, InstanceIndex, TimeElapsed);
    }

    public double spriter_GetSpriteInfoCount(double ModelIndex, double InstanceIndex) {
        return spriterGMNative.spriter_GetSpriteInfoCount(ModelIndex, InstanceIndex);
    }

    public String spriter_GetSpriteInfoFileName(double ModelIndex, double InstanceIndex, double SpriteInfoIndex) {
        return spriterGMNative.spriter_GetSpriteInfoFileName(ModelIndex, InstanceIndex, SpriteInfoIndex);
    }

    public String spriter_GetSpriteInfoString(double ModelIndex, double InstanceIndex, double SpriteInfoIndex) {
        return spriterGMNative.spriter_GetSpriteInfoString(ModelIndex, InstanceIndex, SpriteInfoIndex);
    }

    public double spriter_GetSpriteInfoPositionX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex) {
        return spriterGMNative.spriter_GetSpriteInfoPositionX(ModelIndex, InstanceIndex, SpriteInfoIndex);
    }

    public double spriter_GetSpriteInfoPositionY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex) {
        return spriterGMNative.spriter_GetSpriteInfoPositionY(ModelIndex, InstanceIndex, SpriteInfoIndex);
    }

    public double spriter_GetSpriteInfoPivotX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex) {
        return spriterGMNative.spriter_GetSpriteInfoPivotX(ModelIndex, InstanceIndex, SpriteInfoIndex);
    }

    public double spriter_GetSpriteInfoPivotY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex) {
        return spriterGMNative.spriter_GetSpriteInfoPivotY(ModelIndex, InstanceIndex, SpriteInfoIndex);
    }

    public double spriter_GetSpriteInfoSizeX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex) {
        return spriterGMNative.spriter_GetSpriteInfoSizeX(ModelIndex, InstanceIndex, SpriteInfoIndex);
    }

    public double spriter_GetSpriteInfoSizeY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex) {
        return spriterGMNative.spriter_GetSpriteInfoSizeY(ModelIndex, InstanceIndex, SpriteInfoIndex);
    }

    public double spriter_GetSpriteInfoScaleX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex) {
        return spriterGMNative.spriter_GetSpriteInfoScaleX(ModelIndex, InstanceIndex, SpriteInfoIndex);
    }

    public double spriter_GetSpriteInfoScaleY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex) {
        return spriterGMNative.spriter_GetSpriteInfoScaleY(ModelIndex, InstanceIndex, SpriteInfoIndex);
    }

    public double spriter_GetSpriteInfoAngle(double ModelIndex, double InstanceIndex, double SpriteInfoIndex) {
        return spriterGMNative.spriter_GetSpriteInfoAngle(ModelIndex, InstanceIndex, SpriteInfoIndex);
    }

    public double spriter_IsGetSpriteInfoRender(double ModelIndex, double InstanceIndex, double SpriteInfoIndex) {
        return spriterGMNative.spriter_IsGetSpriteInfoRender(ModelIndex, InstanceIndex, SpriteInfoIndex);
    }

    public double spriter_GetSpriteInfoGMRenderPositionX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex) {
        return spriterGMNative.spriter_GetSpriteInfoGMRenderPositionX(ModelIndex, InstanceIndex, SpriteInfoIndex);
    }

    public double spriter_GetSpriteInfoGMRenderPositionY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex) {
        return spriterGMNative.spriter_GetSpriteInfoGMRenderPositionY(ModelIndex, InstanceIndex, SpriteInfoIndex);
    }

    public double spriter_GetSpriteInfoAlpha(double ModelIndex, double InstanceIndex, double SpriteInfoIndex) {
        return spriterGMNative.spriter_GetSpriteInfoAlpha(ModelIndex, InstanceIndex, SpriteInfoIndex);
    }

    public double spriter_GetSpriteInfoType(double ModelIndex, double InstanceIndex, double SpriteInfoIndex) {
        return spriterGMNative.spriter_GetSpriteInfoType(ModelIndex, InstanceIndex, SpriteInfoIndex);
    }

    public double spriter_SetInstanceCurrentAnimation(double ModelIndex, double InstanceIndex, String pAnimationName, double BlendTime) {
        return spriterGMNative.spriter_SetInstanceCurrentAnimation(ModelIndex, InstanceIndex, pAnimationName, BlendTime);
    }

    public double spriter_SetSpriteInfoImageWidth(double ModelIndex, double InstanceIndex, double SpriteInfoIndex, double ImageWidth) {
        return spriterGMNative.spriter_SetSpriteInfoImageWidth(ModelIndex, InstanceIndex, SpriteInfoIndex, ImageWidth);
    }

    public double spriter_SetSpriteInfoImageHeight(double ModelIndex, double InstanceIndex, double SpriteInfoIndex, double ImageHeight) {
        return spriterGMNative.spriter_SetSpriteInfoImageHeight(ModelIndex, InstanceIndex, SpriteInfoIndex, ImageHeight);
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
}
