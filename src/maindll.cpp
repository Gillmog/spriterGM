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

double spriter_CreateInstance(double ModelIndex, const char *pInstanceName, double bEnableBones)
{
	return CSpriterGM::GetSingleton()->CreateInstance(ModelIndex, pInstanceName, bEnableBones);
}

double spriter_UpdateInstance(double ModelIndex, double InstanceIndex, double TimeElapsed)
{
	if (!CSpriterGM::GetSingleton()->IsInstanceValid(ModelIndex, InstanceIndex))
		return 0;

	CSpriterGM::GetSingleton()->UpdateInstance(ModelIndex, InstanceIndex, TimeElapsed);

	return 0;
}

double spriter_GetObjectInfoCount(double ModelIndex, double InstanceIndex)
{
	if (!CSpriterGM::GetSingleton()->IsInstanceValid(ModelIndex, InstanceIndex))
	{
		return -1;
	}

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetNumGMObjectInfo();
}

#if defined(ANDROID)
std::string spriter_GetObjectInfoFileName(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).GetSpriteName();
}
#else
const char *spriter_GetObjectInfoFileName(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	std::string ImageName = CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).GetSpriteName();

	char *pCopyStr = new char[ImageName.length() + 1];
	strcpy(pCopyStr, ImageName.c_str());

	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).AddToGarbage(pCopyStr);

	return pCopyStr;
}
#endif

#if defined(ANDROID)
std::string spriter_GetObjectInfoString(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	CSpriterGM::CGMObjectInfo &ObjectInfo = CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex);

	std::string ObjectInfoModel = ObjectInfo.GetSpriteName() + " " +
		" " + std::to_string(ObjectInfo.GetPosition().x) +
		" " + std::to_string(ObjectInfo.GetPosition().y) +
		" " + std::to_string(ObjectInfo.GetPivot().x) +
		" " + std::to_string(ObjectInfo.GetPivot().y) +
		" " + std::to_string(ObjectInfo.GetSize().x) +
		" " + std::to_string(ObjectInfo.GetSize().y) +
		" " + std::to_string(ObjectInfo.GetScale().x) +
		" " + std::to_string(ObjectInfo.GetScale().y) +
		" " + std::to_string(ObjectInfo.GetAngle()) +
		" " + std::to_string(ObjectInfo.IsRender());

	return ObjectInfoModel;
}
#else
const char *spriter_GetObjectInfoString(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	CSpriterGM::CGMObjectInfo &ObjectInfo = CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex);

	std::string ObjectInfoModel = ObjectInfo.GetSpriteName() + " " +
		" " + std::to_string(ObjectInfo.GetPosition().x) +
		" " + std::to_string(ObjectInfo.GetPosition().y) +
		" " + std::to_string(ObjectInfo.GetPivot().x) +
		" " + std::to_string(ObjectInfo.GetPivot().y) +
		" " + std::to_string(ObjectInfo.GetSize().x) +
		" " + std::to_string(ObjectInfo.GetSize().y) +
		" " + std::to_string(ObjectInfo.GetScale().x) +
		" " + std::to_string(ObjectInfo.GetScale().y) +
		" " + std::to_string(ObjectInfo.GetAngle()) +
		" " + std::to_string(ObjectInfo.IsRender());

	char *pCopyStr = new char[ObjectInfoModel.length() + 1];
	strcpy(pCopyStr, ObjectInfoModel.c_str());

	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).AddToGarbage(pCopyStr);

	return pCopyStr;
}
#endif

double spriter_GetObjectInfoPositionX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).GetPosition().x;
}

double spriter_GetObjectInfoPositionY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).GetPosition().y;
}

double spriter_GetObjectInfoPivotX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).GetPivot().x;
}

double spriter_GetObjectInfoPivotY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).GetPivot().y;
}

double spriter_GetObjectInfoSizeX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).GetSize().x;
}

double spriter_GetObjectInfoSizeY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).GetSize().y;
}

double spriter_GetObjectInfoScaleX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).GetScale().x;
}


double spriter_GetObjectInfoScaleY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).GetScale().y;
}

double spriter_GetObjectInfoAngle(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).GetAngle();
}

double spriter_IsGetObjectInfoRender(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).IsRender();
}

double spriter_GetObjectInfoGMRenderPositionX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	CSpriterGM::CGMObjectInfo &Info = CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex);

	return Info.GetRenderPosition().x;
}

double spriter_GetObjectInfoGMRenderPositionY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	CSpriterGM::CGMObjectInfo &Info = CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex);

	return Info.GetRenderPosition().y;
}

double spriter_GetObjectInfoAlpha(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).GetAlpha();
}

double spriter_GetObjectInfoType(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).GetType();
}

double spriter_SetInstanceCurrentAnimation(double ModelIndex, double InstanceIndex, const char *pAnimationName, double BlendTime)
{
	if (!CSpriterGM::GetSingleton()->IsInstanceValid(ModelIndex, InstanceIndex))
		return 0;

	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance()->setCurrentAnimation(pAnimationName, BlendTime);

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

	if (!CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).FindLoadedSprite(pSpriteName))
		return -1;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).FindLoadedSprite(pSpriteName)->GetPointer();
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

double spriter_GetObjectInfoSpriteIndex(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).GetGMSpriteIndex();
}

double spriter_SetLoadedSpriteTexelSize(double ModelIndex, const char *pSpriteName, double TexelWidth, double TexelHeight)
{
	if (!CSpriterGM::GetSingleton()->IsModelValid(ModelIndex))
		return 0;

	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).SetLoadedSpriteTexelSize(pSpriteName, TexelWidth, TexelHeight);

	return 0;
}

double spriter_SetLoadedSpriteSize(double ModelIndex, const char *pSpriteName, double TextureWidth, double TextureHeight)
{
	if (!CSpriterGM::GetSingleton()->IsModelValid(ModelIndex))
		return 0;

	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).SetLoadedSpriteSize(pSpriteName, TextureWidth, TextureHeight);

	return 0;
}

double spriter_GetObjectInfoMeshPointX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex, double PointIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).GetMeshX(false, PointIndex);
}

double spriter_GetObjectInfoMeshPointY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex, double PointIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).GetMeshY(false, PointIndex);
}

double spriter_GetObjectInfoMeshUVX(double ModelIndex, double InstanceIndex, double ObjectInfoIndex, double PointIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).GetMeshX(true, PointIndex);
}

double spriter_GetObjectInfoMeshUVY(double ModelIndex, double InstanceIndex, double ObjectInfoIndex, double PointIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).GetMeshY(true, PointIndex);
}

double spriter_DestroyInstance(double ModelIndex, double InstanceIndex)
{
	if (!CSpriterGM::GetSingleton()->IsInstanceValid(ModelIndex, InstanceIndex))
		return 0;

	if (CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).DestroyInstance(InstanceIndex))
	{
		CSpriterGM::GetSingleton()->DestroyModel(ModelIndex);
	}

	return 0;
}

double spriter_DestroyModel(double ModelIndex)
{
	if (!CSpriterGM::GetSingleton()->IsModelValid(ModelIndex))
		return 0;

	CSpriterGM::GetSingleton()->DestroyModel(ModelIndex);

	return 0;
}

double spriter_DestroyAllModels()
{
	CSpriterGM::GetSingleton()->DestroyAllModels();
	return 0;
}

#if defined(ANDROID)
std::string spriter_GetObjectInfoName(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	return CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).GetObjectName();
}
#else
const char* spriter_GetObjectInfoName(double ModelIndex, double InstanceIndex, double ObjectInfoIndex)
{
	if (!CSpriterGM::GetSingleton()->IsObjectInfoValid(ModelIndex, InstanceIndex, ObjectInfoIndex))
		return 0;

	std::string TmpStr = CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).GetObjectName();
	char *pCopyStr = new char[TmpStr.length() + 1];
	strcpy(pCopyStr, TmpStr.c_str());
	CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetGMObjectInfo(ObjectInfoIndex).AddToGarbage(pCopyStr);
	return pCopyStr;
}
#endif