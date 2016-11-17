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

#include "spriterGM.h"

DLLEXPORT double spriter_LoadModel(const char *pFile)
{
	return CSpriterGM::GetSingleton()->LoadModel(pFile);
}

DLLEXPORT double spriter_CreateInstance(double ModelIndex, const char *pInstanceName)
{
	return CSpriterGM::GetSingleton()->CreateInstance(ModelIndex, pInstanceName);
}

DLLEXPORT double spriter_Render(double TimeElapsed)
{
	CSpriterGM::GetSingleton()->Render(TimeElapsed);

	return 0;
}

DLLEXPORT double spriter_RenderInstance(double ModelIndex, double InstanceIndex)
{
	CSpriterGM::GetSingleton()->RenderInstance(ModelIndex, InstanceIndex);

	return 0;
}

DLLEXPORT double spriter_UpdateInstance(double ModelIndex, double InstanceIndex, double TimeElapsed)
{
	CSpriterGM::GetSingleton()->UpdateInstance(ModelIndex, InstanceIndex, TimeElapsed);

	return 0;
}

DLLEXPORT double spriter_GetSpriteInfoCount(double ModelIndex, double InstanceIndex)
{
	if (CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetNumInstances() == 0)
	{
		return -1;
	}

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetNumGMSpriteInfo();
}

DLLEXPORT const char *spriter_GetSpriteInfoFileName(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	std::string ImageName = CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetSpriteName();

	const char *pImageName = ImageName.c_str();

	std::string TmpStr = ImageName;
	char *pCopyStr = new char[TmpStr.length() + 1];
	strcpy(pCopyStr, TmpStr.c_str());

	return pCopyStr;
}

DLLEXPORT const char *spriter_GetSpriteInfoString(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	CSpriterGM::CGMSpriteInfo &SpriteInfo = CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex);

	std::string SpriteInfoModel = SpriteInfo.GetSpriteName() + " " +
		" " + std::to_string(SpriteInfo.GetPosition().x) +
		" " + std::to_string(SpriteInfo.GetPosition().y) +
		" " + std::to_string(SpriteInfo.GetPivot().x) +
		" " + std::to_string(SpriteInfo.GetPivot().y) +
		" " + std::to_string(SpriteInfo.GetSize().x) +
		" " + std::to_string(SpriteInfo.GetSize().y) +
		" " + std::to_string(SpriteInfo.GetScale().x) +
		" " + std::to_string(SpriteInfo.GetScale().y) +
		" " + std::to_string(SpriteInfo.GetAngle()) +
		" " + std::to_string(SpriteInfo.IsRender());

	char *pCopyStr = new char[SpriteInfoModel.length() + 1];
	strcpy(pCopyStr, SpriteInfoModel.c_str());

	return pCopyStr;
}

DLLEXPORT double spriter_GetSpriteInfoPositionX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetPosition().x;
}

DLLEXPORT double spriter_GetSpriteInfoPositionY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetPosition().y;
}

DLLEXPORT double spriter_GetSpriteInfoPivotX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetPivot().x;
}

DLLEXPORT double spriter_GetSpriteInfoPivotY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetPivot().y;
}

DLLEXPORT double spriter_GetSpriteInfoSizeX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetSize().x;
}

DLLEXPORT double spriter_GetSpriteInfoSizeY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetSize().y;
}

DLLEXPORT double spriter_GetSpriteInfoScaleX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetScale().x;
}


DLLEXPORT double spriter_GetSpriteInfoScaleY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetScale().y;
}

DLLEXPORT double spriter_GetSpriteInfoAngle(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetAngle();
}

DLLEXPORT double spriter_IsGetSpriteInfoRender(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).IsRender();
}

DLLEXPORT double spriter_GetSpriteInfoGMRenderPositionX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	CSpriterGM::CGMSpriteInfo &Info = CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex);

	const SpriterEngine::point &point = Info.CalculatePosition();

	return point.x;
}

DLLEXPORT double spriter_GetSpriteInfoGMRenderPositionY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	CSpriterGM::CGMSpriteInfo &Info = CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex);

	const SpriterEngine::point &point = Info.CalculatePosition();

	return point.y;
}

DLLEXPORT double spriter_SetInstanceCurrentAnimation(double ModelIndex, double InstanceIndex, const char *pAnimationName, double BlendTime)
{
	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->setCurrentAnimation(pAnimationName, BlendTime);

	return 0;
}

DLLEXPORT double spriter_SetSpriteInfoImageWidth(double ModelIndex, double InstanceIndex, double SpriteInfoIndex, double ImageWidth)
{
	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).SetImageWidth(ImageWidth);

	return 0;
}

DLLEXPORT double spriter_SetSpriteInfoImageHeight(double ModelIndex, double InstanceIndex, double SpriteInfoIndex, double ImageHeight)
{
	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).SetImageHeight(ImageHeight);

	return 0;
}

DLLEXPORT double spriter_SetInstancePosition(double ModelIndex, double InstanceIndex, double px, double py)
{
	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->setPosition(SpriterEngine::point(px, -1.0 * py));

	return 0;
}

DLLEXPORT double spriter_GetInstancePositionX(double ModelIndex, double InstanceIndex)
{
	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->getPosition().x;
}

DLLEXPORT double spriter_GetInstancePositionY(double ModelIndex, double InstanceIndex)
{
	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->getPosition().y;
}

DLLEXPORT double spriter_SetInstanceScale(double ModelIndex, double InstanceIndex, double sx, double sy)
{
	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->setScale(SpriterEngine::point(sx, sy));

	return 0;
}

DLLEXPORT double spriter_SetInstanceAngle(double ModelIndex, double InstanceIndex, double angle)
{
	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->setAngle(angle);

	return 0;
}

DLLEXPORT double spriter_ApplyInstanceCharacterMap(double ModelIndex, double InstanceIndex, const char *charMap)
{
	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->applyCharacterMap(charMap);

	return 0;
}

DLLEXPORT double spriter_RemoveInstanceCharacterMap(double ModelIndex, double InstanceIndex, const char *charMap)
{
	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->removeCharacterMap(charMap);

	return 0;
}

DLLEXPORT double spriter_RemoveInstanceAllCharacterMap(double ModelIndex, double InstanceIndex)
{
	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->removeAllCharacterMaps();

	return 0;
}


DLLEXPORT double spriter_SetInstancePlaybackSpeedRatio(double ModelIndex, double InstanceIndex, double PlaybackSpeedRatio)
{
	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->setPlaybackSpeedRatio(PlaybackSpeedRatio);

	return 0;
}

DLLEXPORT double spriter_InstanceStartResumePlayback(double ModelIndex, double InstanceIndex)
{
	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->startResumePlayback();

	return 0;
}

DLLEXPORT double spriter_InstancePausePlayback(double ModelIndex, double InstanceIndex)
{
	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->pausePlayback();

	return 0;
}

DLLEXPORT double spriter_InstanceSetTimeRatio(double ModelIndex, double InstanceIndex, double TimeRatio)
{
	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->setTimeRatio(TimeRatio);

	return 0;
}

DLLEXPORT double spriter_InstanceAnimationJustFinished(double ModelIndex, double InstanceIndex, double bLooped)
{
	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->animationJustFinished(bLooped);
}

DLLEXPORT double spriter_InstanceGetTriggerInfoCount(double ModelIndex, double InstanceIndex)
{
	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetNumGMTriggerInfo();
}

DLLEXPORT const char* spriter_InstanceGetTriggerInfoName(double ModelIndex, double InstanceIndex, double TriggerIndex)
{
	std::string TmpStr = CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMTriggerInfo(TriggerIndex).GetTriggerName();
	char *pCopyStr = new char[TmpStr.length() + 1];
	strcpy(pCopyStr, TmpStr.c_str());

	return pCopyStr;
}

DLLEXPORT double spriter_InstanceGetSoundInfoCount(double ModelIndex, double InstanceIndex)
{
	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetNumGMSoundInfo();
}

DLLEXPORT const char* spriter_InstanceGetSoundInfoName(double ModelIndex, double InstanceIndex, double TriggerIndex)
{
	std::string TmpStr = CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSoundInfo(TriggerIndex).GetSoundFileName();
	char *pCopyStr = new char[TmpStr.length() + 1];
	strcpy(pCopyStr, TmpStr.c_str());

	return pCopyStr;
}







