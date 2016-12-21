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
#include "maindll.h"
#include "spriterGM.h"

double spriter_LoadModel(const char *pFile)
{
	double modelIndex = CSpriterGM::GetSingleton()->LoadModel(pFile);

	if (spriter_GetErrorsCount() > 0)
		modelIndex = -1.0;

	return modelIndex;
}

double spriter_CreateInstance(double ModelIndex, const char *pInstanceName)
{
	return CSpriterGM::GetSingleton()->CreateInstance(ModelIndex, pInstanceName);
}

double spriter_Render(double TimeElapsed)
{
	CSpriterGM::GetSingleton()->Render(TimeElapsed);

	return 0;
}

double spriter_RenderInstance(double ModelIndex, double InstanceIndex)
{
	if (!CSpriterGM::GetSingleton()->IsInstanceValid(ModelIndex, InstanceIndex))
		return 0;

	CSpriterGM::GetSingleton()->RenderInstance(ModelIndex, InstanceIndex);

	return 0;
}

double spriter_UpdateInstance(double ModelIndex, double InstanceIndex, double TimeElapsed)
{
	if (!CSpriterGM::GetSingleton()->IsInstanceValid(ModelIndex, InstanceIndex))
		return 0;

	CSpriterGM::GetSingleton()->UpdateInstance(ModelIndex, InstanceIndex, TimeElapsed);

	return 0;
}

double spriter_GetSpriteInfoCount(double ModelIndex, double InstanceIndex)
{
	if (!CSpriterGM::GetSingleton()->IsModelValid(ModelIndex))
		return -1;

	if (CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetNumInstances() == 0)
	{
		return -1;
	}

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetNumGMSpriteInfo();
}

#if defined(ANDROID)
std::string spriter_GetSpriteInfoFileName(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetSpriteName();
}
#else
const char *spriter_GetSpriteInfoFileName(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	std::string ImageName = CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetSpriteName();

	char *pCopyStr = new char[ImageName.length() + 1];
	strcpy(pCopyStr, ImageName.c_str());

	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).AddToGarbage(pCopyStr);

	return pCopyStr;
}
#endif

#if defined(ANDROID)
std::string spriter_GetSpriteInfoString(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

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

	return SpriteInfoModel;
}
#else
const char *spriter_GetSpriteInfoString(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

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

	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).AddToGarbage(pCopyStr);

	return pCopyStr;
}
#endif

double spriter_GetSpriteInfoPositionX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetPosition().x;
}

double spriter_GetSpriteInfoPositionY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetPosition().y;
}

double spriter_GetSpriteInfoPivotX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetPivot().x;
}

double spriter_GetSpriteInfoPivotY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetPivot().y;
}

double spriter_GetSpriteInfoSizeX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetSize().x;
}

double spriter_GetSpriteInfoSizeY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetSize().y;
}

double spriter_GetSpriteInfoScaleX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetScale().x;
}


double spriter_GetSpriteInfoScaleY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetScale().y;
}

double spriter_GetSpriteInfoAngle(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetAngle();
}

double spriter_IsGetSpriteInfoRender(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).IsRender();
}

double spriter_GetSpriteInfoGMRenderPositionX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	CSpriterGM::CGMSpriteInfo &Info = CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex);

	return Info.CalculatePosition().x;
}

double spriter_GetSpriteInfoGMRenderPositionY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	CSpriterGM::CGMSpriteInfo &Info = CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex);

	return Info.CalculatePosition().y;
}

double spriter_GetSpriteInfoAlpha(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetAlpha();
}

double spriter_GetSpriteInfoType(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetType();
}

double spriter_SetInstanceCurrentAnimation(double ModelIndex, double InstanceIndex, const char *pAnimationName, double BlendTime)
{
	if (!CSpriterGM::GetSingleton()->IsInstanceValid(ModelIndex, InstanceIndex))
		return 0;

	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->setCurrentAnimation(pAnimationName, BlendTime);

	return 0;
}

double spriter_SetSpriteInfoImageWidth(double ModelIndex, double InstanceIndex, double SpriteInfoIndex, double ImageWidth)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).SetImageWidth(ImageWidth);

	return 0;
}

double spriter_SetSpriteInfoImageHeight(double ModelIndex, double InstanceIndex, double SpriteInfoIndex, double ImageHeight)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).SetImageHeight(ImageHeight);

	return 0;
}

double spriter_SetInstancePosition(double ModelIndex, double InstanceIndex, double px, double py)
{
	if (!CSpriterGM::GetSingleton()->IsInstanceValid(ModelIndex, InstanceIndex))
		return 0;

	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->setPosition(SpriterEngine::point(px, -1.0 * py));

	return 0;
}

double spriter_GetInstancePositionX(double ModelIndex, double InstanceIndex)
{
	if (!CSpriterGM::GetSingleton()->IsInstanceValid(ModelIndex, InstanceIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->getPosition().x;
}

double spriter_GetInstancePositionY(double ModelIndex, double InstanceIndex)
{
	if (!CSpriterGM::GetSingleton()->IsInstanceValid(ModelIndex, InstanceIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->getPosition().y;
}

double spriter_SetInstanceScale(double ModelIndex, double InstanceIndex, double sx, double sy)
{
	if (!CSpriterGM::GetSingleton()->IsInstanceValid(ModelIndex, InstanceIndex))
		return 0;

	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->setScale(SpriterEngine::point(sx, sy));

	return 0;
}

double spriter_SetInstanceAngle(double ModelIndex, double InstanceIndex, double angle)
{
	if (!CSpriterGM::GetSingleton()->IsInstanceValid(ModelIndex, InstanceIndex))
		return 0;

	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->setAngle(angle);

	return 0;
}

double spriter_ApplyInstanceCharacterMap(double ModelIndex, double InstanceIndex, const char *charMap)
{
	if (!CSpriterGM::GetSingleton()->IsInstanceValid(ModelIndex, InstanceIndex))
		return 0;

	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->applyCharacterMap(charMap);

	return 0;
}

double spriter_RemoveInstanceCharacterMap(double ModelIndex, double InstanceIndex, const char *charMap)
{
	if (!CSpriterGM::GetSingleton()->IsInstanceValid(ModelIndex, InstanceIndex))
		return 0;

	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->removeCharacterMap(charMap);

	return 0;
}

double spriter_RemoveInstanceAllCharacterMap(double ModelIndex, double InstanceIndex)
{
	if (!CSpriterGM::GetSingleton()->IsInstanceValid(ModelIndex, InstanceIndex))
		return 0;

	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->removeAllCharacterMaps();

	return 0;
}


double spriter_SetInstancePlaybackSpeedRatio(double ModelIndex, double InstanceIndex, double PlaybackSpeedRatio)
{
	if (!CSpriterGM::GetSingleton()->IsInstanceValid(ModelIndex, InstanceIndex))
		return 0;

	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->setPlaybackSpeedRatio(PlaybackSpeedRatio);

	return 0;
}

double spriter_InstanceStartResumePlayback(double ModelIndex, double InstanceIndex)
{
	if (!CSpriterGM::GetSingleton()->IsInstanceValid(ModelIndex, InstanceIndex))
		return 0;

	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->startResumePlayback();

	return 0;
}

double spriter_InstancePausePlayback(double ModelIndex, double InstanceIndex)
{
	if (!CSpriterGM::GetSingleton()->IsInstanceValid(ModelIndex, InstanceIndex))
		return 0;

	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->pausePlayback();

	return 0;
}

double spriter_InstanceSetTimeRatio(double ModelIndex, double InstanceIndex, double TimeRatio)
{
	if (!CSpriterGM::GetSingleton()->IsInstanceValid(ModelIndex, InstanceIndex))
		return 0;

	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->setTimeRatio(TimeRatio);

	return 0;
}

double spriter_InstanceAnimationJustFinished(double ModelIndex, double InstanceIndex, double bLooped)
{
	if (!CSpriterGM::GetSingleton()->IsInstanceValid(ModelIndex, InstanceIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->animationJustFinished(bLooped);
}

double spriter_InstanceGetTriggerInfoCount(double ModelIndex, double InstanceIndex)
{
	if (!CSpriterGM::GetSingleton()->IsInstanceValid(ModelIndex, InstanceIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetNumGMTriggerInfo();
}

#if defined(ANDROID)
std::string spriter_InstanceGetTriggerInfoName(double ModelIndex, double InstanceIndex, double TriggerIndex)
{
	if (!CSpriterGM::GetSingleton()->IsTriggerInfoValid(ModelIndex, InstanceIndex, TriggerIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMTriggerInfo(TriggerIndex).GetTriggerName();
}
#else
const char* spriter_InstanceGetTriggerInfoName(double ModelIndex, double InstanceIndex, double TriggerIndex)
{
	if (!CSpriterGM::GetSingleton()->IsTriggerInfoValid(ModelIndex, InstanceIndex, TriggerIndex))
		return 0;

	std::string TmpStr = CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMTriggerInfo(TriggerIndex).GetTriggerName();
	char *pCopyStr = new char[TmpStr.length() + 1];
	strcpy(pCopyStr, TmpStr.c_str());
	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMTriggerInfo(TriggerIndex).AddToGarbage(pCopyStr);
	return pCopyStr;
}
#endif

double spriter_InstanceGetSoundInfoCount(double ModelIndex, double InstanceIndex)
{
	if (!CSpriterGM::GetSingleton()->IsInstanceValid(ModelIndex, InstanceIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetNumGMSoundInfo();
}

#if defined(ANDROID)
std::string spriter_InstanceGetSoundInfoName(double ModelIndex, double InstanceIndex, double SoundIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSoundInfoValid(ModelIndex, InstanceIndex, SoundIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSoundInfo(SoundIndex).GetSoundFileName();
}
#else
const char* spriter_InstanceGetSoundInfoName(double ModelIndex, double InstanceIndex, double SoundIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSoundInfoValid(ModelIndex, InstanceIndex, SoundIndex))
		return 0;

	std::string TmpStr = CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSoundInfo(SoundIndex).GetSoundFileName();
	char *pCopyStr = new char[TmpStr.length() + 1];
	strcpy(pCopyStr, TmpStr.c_str());
	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSoundInfo(SoundIndex).AddToGarbage(pCopyStr);
	return pCopyStr;
}
#endif

double spriter_GetErrorsCount()
{
	return CSpriterGM::GetSingleton()->GetNumErrors();
}

#if defined(ANDROID)
std::string spriter_GetLastError()
{
	return CSpriterGM::GetSingleton()->GetLastError();
}
#else
const char* spriter_GetLastError()
{
	return CSpriterGM::GetSingleton()->GetLastError();
}
#endif

double spriter_ForceGarbageCollection()
{
	return CSpriterGM::GetSingleton()->ForceGarbageCollection();
}

//atlas file

double spriter_IsSpriteInfoAtlasFile(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).IsAtlasFile();
}

double spriter_GetSpriteInfoAtlasFramePositionX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoAtlasFileValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetAtlasFrame().m_FramePositionX;
}

double spriter_GetSpriteInfoAtlasFramePositionY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoAtlasFileValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetAtlasFrame().m_FramePositionY;
}

double spriter_IsSpriteInfoAtlasFrameRotated(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoAtlasFileValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetAtlasFrame().m_bRotated;
}

double spriter_IsSpriteInfoAtlasFrameTrimmed(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoAtlasFileValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetAtlasFrame().m_bTrimmed;
}

double spriter_GetSpriteInfoAtlasFrameFrameSizeX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoAtlasFileValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetAtlasFrame().m_FrameSizeX;
}

double spriter_GetSpriteInfoAtlasFrameFrameSizeY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoAtlasFileValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetAtlasFrame().m_FrameSizeY;
}

double spriter_GetSpriteInfoAtlasFrameSourceSizeX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoAtlasFileValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetAtlasFrame().m_SourceSizeX;
}

double spriter_GetSpriteInfoAtlasFrameSourceSizeY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoAtlasFileValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetAtlasFrame().m_SourceSizeY;
}

double spriter_GetSpriteInfoAtlasFrameSpriteSourcePositionX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoAtlasFileValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetAtlasFrame().m_SpriteSourcePositionX;
}

double spriter_GetSpriteInfoAtlasFrameSpriteSourcePositionY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoAtlasFileValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetAtlasFrame().m_SpriteSourcePositionY;
}

double spriter_GetSpriteInfoAtlasFrameSpriteSourceSizeX(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoAtlasFileValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetAtlasFrame().m_SpriteSourceSizeX;
}

double spriter_GetSpriteInfoAtlasFrameSpriteSourceSizeY(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoAtlasFileValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetAtlasFrame().m_SpriteSourceSizeY;
}

double spriter_AddLoadedSprite(double ModelIndex, const char *pSpriteName, double SpritePtr)
{
	if (!CSpriterGM::GetSingleton()->IsModelValid(ModelIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).AddLoadedSprite(pSpriteName, SpritePtr);
}

double spriter_FindLoadedSprite(double ModelIndex, const char *pSpriteName)
{
	if (!CSpriterGM::GetSingleton()->IsModelValid(ModelIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).FindLoadedSprite(pSpriteName);
}

double spriter_GetNumSprites(double ModelIndex)
{
	if (!CSpriterGM::GetSingleton()->IsModelValid(ModelIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetNumSprites();
}

#if defined(ANDROID)
std::string spriter_GetSprite(double ModelIndex, double SpriteIndex)
{
	if (!CSpriterGM::GetSingleton()->IsModelValid(ModelIndex))
		return "";

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetSprite(SpriteIndex);
}
#else
const char* spriter_GetSprite(double ModelIndex, double SpriteIndex)
{
	if (!CSpriterGM::GetSingleton()->IsModelValid(ModelIndex))
		return "";

	std::string TmpStr = CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetSprite(SpriteIndex);
	char *pCopyStr = new char[TmpStr.length() + 1];
	strcpy(pCopyStr, TmpStr.c_str());
	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).AddToGarbage(pCopyStr);
	return pCopyStr;
}
#endif

double spriter_GetSpriteInfoSpriteIndex(double ModelIndex, double InstanceIndex, double SpriteInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).GetGMSpriteIndex();
}

