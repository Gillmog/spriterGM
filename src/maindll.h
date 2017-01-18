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
#ifdef _WIN32

#define WIN32_LEAN_AND_MEAN 

#include <windows.h>

#define DLLEXPORT extern "C" __declspec(dllexport)

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

#endif

#if defined(__linux__) || defined(__unix__ )
#define DLLEXPORT extern "C"
#endif

#include <string>

DLLEXPORT double spriter_LoadModel(const char *pFile);

DLLEXPORT double spriter_CreateInstance(double ModelIndex, const char *pInstanceName, double bEnableBones);

DLLEXPORT double spriter_UpdateInstance(double ModelIndex, double InstanceIndex, double TimeElapsed);

DLLEXPORT double spriter_GetObjectInfoCount(double ModelIndex, double InstanceIndex);

#if defined(ANDROID)
DLLEXPORT std::string spriter_GetObjectInfoFileName(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

DLLEXPORT std::string spriter_GetObjectInfoString(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);
#else
DLLEXPORT const char *spriter_GetObjectInfoFileName(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

DLLEXPORT const char *spriter_GetObjectInfoString(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);
#endif

DLLEXPORT double spriter_GetObjectInfoPositionX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

DLLEXPORT double spriter_GetObjectInfoPositionY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

DLLEXPORT double spriter_GetObjectInfoPivotX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

DLLEXPORT double spriter_GetObjectInfoPivotY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

DLLEXPORT double spriter_GetObjectInfoSizeX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

DLLEXPORT double spriter_GetObjectInfoSizeY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

DLLEXPORT double spriter_GetObjectInfoScaleX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

DLLEXPORT double spriter_GetObjectInfoScaleY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

DLLEXPORT double spriter_GetObjectInfoAngle(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

DLLEXPORT double spriter_IsGetObjectInfoRender(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

DLLEXPORT double spriter_GetObjectInfoGMRenderPositionX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

DLLEXPORT double spriter_GetObjectInfoGMRenderPositionY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

DLLEXPORT double spriter_GetObjectInfoAlpha(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

DLLEXPORT double spriter_GetObjectInfoType(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

DLLEXPORT double spriter_SetInstanceCurrentAnimation(double ModelIndex, double InstanceIndex, const char *pAnimationName, double BlendTime);

DLLEXPORT double spriter_SetInstancePosition(double ModelIndex, double InstanceIndex, double px, double py);

DLLEXPORT double spriter_GetInstancePositionX(double ModelIndex, double InstanceIndex);

DLLEXPORT double spriter_GetInstancePositionY(double ModelIndex, double InstanceIndex);

DLLEXPORT double spriter_SetInstanceScale(double ModelIndex, double InstanceIndex, double sx, double sy);

DLLEXPORT double spriter_SetInstanceAngle(double ModelIndex, double InstanceIndex, double angle);

DLLEXPORT double spriter_ApplyInstanceCharacterMap(double ModelIndex, double InstanceIndex, const char *charMap);

DLLEXPORT double spriter_RemoveInstanceCharacterMap(double ModelIndex, double InstanceIndex, const char *charMap);

DLLEXPORT double spriter_RemoveInstanceAllCharacterMap(double ModelIndex, double InstanceIndex);

DLLEXPORT double spriter_SetInstancePlaybackSpeedRatio(double ModelIndex, double InstanceIndex, double PlaybackSpeedRatio);

DLLEXPORT double spriter_InstanceStartResumePlayback(double ModelIndex, double InstanceIndex);

DLLEXPORT double spriter_InstancePausePlayback(double ModelIndex, double InstanceIndex);

DLLEXPORT double spriter_InstanceSetTimeRatio(double ModelIndex, double InstanceIndex, double TimeRatio);

DLLEXPORT double spriter_InstanceAnimationJustFinished(double ModelIndex, double InstanceIndex, double bLooped);

DLLEXPORT double spriter_InstanceGetTriggerInfoCount(double ModelIndex, double InstanceIndex);

#if defined(ANDROID)
DLLEXPORT std::string spriter_InstanceGetTriggerInfoName(double ModelIndex, double InstanceIndex, double TriggerIndex);
#else
DLLEXPORT const char* spriter_InstanceGetTriggerInfoName(double ModelIndex, double InstanceIndex, double TriggerIndex);
#endif

DLLEXPORT double spriter_InstanceGetSoundInfoCount(double ModelIndex, double InstanceIndex);

#if defined(ANDROID)
DLLEXPORT std::string spriter_InstanceGetSoundInfoName(double ModelIndex, double InstanceIndex, double SoundIndex);
#else
DLLEXPORT const char* spriter_InstanceGetSoundInfoName(double ModelIndex, double InstanceIndex, double SoundIndex);
#endif

DLLEXPORT double spriter_GetErrorsCount();

#if defined(ANDROID)
DLLEXPORT std::string spriter_GetLastError();
#else
DLLEXPORT const char* spriter_GetLastError();
#endif

DLLEXPORT double spriter_ForceGarbageCollection();

DLLEXPORT double spriter_AddLoadedSprite(double ModelIndex, const char *pSpriteName, double SpritePtr);

DLLEXPORT double spriter_FindLoadedSprite(double ModelIndex, const char *pSpriteName);

DLLEXPORT double spriter_GetNumSprites(double ModelIndex);

#if defined(ANDROID)
DLLEXPORT std::string spriter_GetSprite(double ModelIndex, double SpriteIndex);
#else
DLLEXPORT const char* spriter_GetSprite(double ModelIndex, double SpriteIndex);
#endif

DLLEXPORT double spriter_GetObjectInfoSpriteIndex(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);

DLLEXPORT double spriter_SetLoadedSpriteTexelSize(double ModelIndex, const char *pSpriteName, double TexelWidth, double TexelHeight);

DLLEXPORT double spriter_SetLoadedSpriteSize(double ModelIndex, const char *pSpriteName, double TextureWidth, double TextureHeight);

DLLEXPORT double spriter_GetObjectInfoMeshPointX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex, double PointIndex);
DLLEXPORT double spriter_GetObjectInfoMeshPointY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex, double PointIndex);

DLLEXPORT double spriter_GetObjectInfoMeshUVX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex, double PointIndex);
DLLEXPORT double spriter_GetObjectInfoMeshUVY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex, double PointIndex);

DLLEXPORT double spriter_DestroyInstance(double ModelIndex, double InstanceIndex);

DLLEXPORT double spriter_DestroyModel(double ModelIndex);

DLLEXPORT double spriter_DestroyAllModels();

#if defined(ANDROID)
DLLEXPORT std::string spriter_GetObjectInfoName(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);
#else
DLLEXPORT const char* spriter_GetObjectInfoName(double ModelIndex, double InstanceIndex, double ObjectInfoIndex);
#endif

DLLEXPORT double spriter_SetLockObjectInstance(double ModelIndex, double InstanceIndex, const char *ObjectName);

DLLEXPORT double spriter_SetUnlockObjectInstance(double ModelIndex, double InstanceIndex);

DLLEXPORT double spriter_SetObjectInstanceIKMode(double ModelIndex, double InstanceIndex, const char *ObjectName, double bIKMode);

DLLEXPORT double spriter_SetObjectInstanceIKPosition(double ModelIndex, double InstanceIndex, double x, double y);

DLLEXPORT double spriter_SetObjectInstanceManualAngleControl(double ModelIndex, double InstanceIndex, const char *ObjectName, double bManualControl);

DLLEXPORT double spriter_SetObjectInstanceManualAngle(double ModelIndex, double InstanceIndex, double x, double y);

DLLEXPORT double spriter_IsObjectInstanceIKMode(double ModelIndex, double InstanceIndex, const char *ObjectName);

DLLEXPORT double spriter_IsObjectInstanceManualAngleControl(double ModelIndex, double InstanceIndex, const char *ObjectName);