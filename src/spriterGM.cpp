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

#include "spriterGM.h"

#include "gmimagefile.h"
#include "gmpointinstanceinfo.h"
#include "gmboxinstanceinfo.h"
#include "gmboneinstanceinfo.h"
#include "gmtriggerobjectinfo.h"
#include "gmsoundobjectinforeference.h"
CSpriterGM *CSpriterGM::m_pInstance = nullptr;

static void SpriterErrorFunction(const std::string &errorMessage)
{
	CSpriterGM::GetSingleton()->Error(errorMessage);
}

void CSpriterGM::Init()
{
	if (m_bInit)
		return;

	m_bInit = true;

	SpriterEngine::Settings::reverseYOnLoad = false;
	SpriterEngine::Settings::reversePivotYOnLoad = false;
	SpriterEngine::Settings::reverseAngleOnLoad = false;

	SpriterEngine::Settings::setErrorFunction(SpriterErrorFunction);
}

int CSpriterGM::LoadModel(const char *pFile)
{
	std::string ModelFile = pFile;

	std::map<std::string, int>::iterator it = m_LoadedModels.find(ModelFile);

	if (it != m_LoadedModels.end())
	{
		return it->second;
	}
	
	SpriterEngine::SpriterModel *pScmlModel = new SpriterEngine::SpriterModel(ModelFile, new SpriterEngine::GMFileFactory, new SpriterEngine::GMObjectFactory);

	m_LastLoadedModel.SetModel(pScmlModel);

	m_Models.push_back(CSpriterGMModel(m_LastLoadedModel));

	m_LoadedModels.insert(std::make_pair(ModelFile, m_Models.size() - 1));

	m_LastLoadedModel.Reset();

	return m_Models.size() - 1;
}

int CSpriterGM::CreateInstance(int ModelIndex, const std::string &InstanceName, bool bEnableBones)
{
	CSpriterGMModel &Model = m_Models[ModelIndex];

	SpriterEngine::SpriterModel *pScmlModel = Model.GetModel();

	bool bSaveEnableDebugBones = SpriterEngine::Settings::enableDebugBones;
	SpriterEngine::Settings::enableDebugBones = bEnableBones;
	SpriterEngine::EntityInstance* pInstance = pScmlModel->getNewEntityInstance(InstanceName);
	SpriterEngine::Settings::enableDebugBones = bSaveEnableDebugBones;
	if (pInstance)
	{
		Model.AddInstance(CSpriterGMInstance(pInstance));
	}
	else
	{
		return -1;
	}

	return Model.GetNumInstances() - 1;
}

void CSpriterGM::UpdateInstance(int ModelIndex, int InstanceIndex, double TimeElapsed)
{
	SpriterEngine::EntityInstance* pInstance = GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance();

	if (pInstance)
	{
		GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).RemoveGarbage();
		GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GMTriggerInfoReset();
		GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GMSoundInfoReset();

		CSpriterGM::GetSingleton()->SetCurrentUpdatedModelIndex(ModelIndex);
		CSpriterGM::GetSingleton()->SetCurrentUpdatedInstanceIndex(InstanceIndex);
		pInstance->setTimeElapsed(TimeElapsed);
		pInstance->playEventTriggers();
		pInstance->playSoundTriggers();
		CSpriterGM::GetSingleton()->SetCurrentUpdatedModelIndex(-1);
		CSpriterGM::GetSingleton()->SetCurrentUpdatedInstanceIndex(-1);

		GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GMSpriteInfoReset();

		if (pInstance->getZOrder())
		{
			for (auto& _it : *pInstance->getZOrder())
			{
				if (dynamic_cast<SpriterEngine::GMBoneInstanceInfo *>(_it))
				{
					SpriterEngine::GMBoneInstanceInfo *pBoneInstance = (SpriterEngine::GMBoneInstanceInfo *)_it;
					pBoneInstance->renderObject(GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex));
				}
				else
				if (dynamic_cast<SpriterEngine::GMPointInstanceInfo *>(_it))
				{
					SpriterEngine::GMPointInstanceInfo *pPointInstance = (SpriterEngine::GMPointInstanceInfo *)_it;

					pPointInstance->renderObject(GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex));
				}
				else
				if (dynamic_cast<SpriterEngine::GMBoxInstanceInfo *>(_it))
				{
					SpriterEngine::GMBoxInstanceInfo *pBoxInstance = (SpriterEngine::GMBoxInstanceInfo *)_it;

					pBoxInstance->renderObject(GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex));
				}
				else
				if (dynamic_cast<SpriterEngine::GMImageFile *>(_it->getImage()))
				{
					SpriterEngine::GMImageFile *pImage = (SpriterEngine::GMImageFile *)_it->getImage();

					pImage->renderSprite(GetSpriterGMModel(ModelIndex), GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex), _it);
				}
				else
				{
					_it->render();
				}
			}
		}
	}
}

CSpriterGM * CSpriterGM::GetSingleton()
{
	if (!m_pInstance)
	{
		m_pInstance = new CSpriterGM();
		m_pInstance->Init();
	}

	return m_pInstance;
}

int CSpriterGM::ForceGarbageCollection()
{
	int nCount = RemoveGarbage();

	for (size_t nModel = 0; nModel < m_Models.size(); nModel++)
	{
		nCount += m_Models[nModel].RemoveGarbage();

		for (size_t nInstance = 0; nInstance < m_Models[nModel].GetNumInstances(); nInstance++)
		{
			nCount += m_Models[nModel].GetInstance(nInstance).RemoveGarbage();

			for (size_t nImage = 0; nImage < m_Models[nModel].GetInstance(nInstance).GetNumGMSpriteInfo(); nImage++)
			{
				nCount += m_Models[nModel].GetInstance(nInstance).GetGMSpriteInfo(nImage).RemoveGarbage();
			}

			for (size_t nTrigger = 0; nTrigger < m_Models[nModel].GetInstance(nInstance).GetNumGMTriggerInfo(); nTrigger++)
			{
				nCount += m_Models[nModel].GetInstance(nInstance).GetGMTriggerInfo(nTrigger).RemoveGarbage();
			}

			for (size_t nSound = 0; nSound < m_Models[nModel].GetInstance(nInstance).GetNumGMSoundInfo(); nSound++)
			{
				nCount += m_Models[nModel].GetInstance(nInstance).GetGMSoundInfo(nSound).RemoveGarbage();
			}
		}
	}

	return nCount;
}

bool CSpriterGM::IsModelValid(int ModelIndex)
{
	if (ModelIndex >= m_Models.size())
	{
		Error("Model not valid!");
		return false;
	}

	return true;
}

bool CSpriterGM::IsInstanceValid(int ModelIndex, int InstanceIndex)
{
	if (!IsModelValid(ModelIndex))
		return false;

	if (InstanceIndex >= m_Models[ModelIndex].GetNumInstances())
	{
		Error("Instance not valid!");
		return false;
	}

	return true;
}

bool CSpriterGM::IsSpriteInfoValid(int ModelIndex, int InstanceIndex, int SpriteInfoIndex)
{
	if (!IsModelValid(ModelIndex))
		return false;

	if (!IsInstanceValid(ModelIndex, InstanceIndex))
		return false;

	if (SpriteInfoIndex >= m_Models[ModelIndex].GetInstance(InstanceIndex).GetNumGMSpriteInfo())
	{
		Error("ImageFile not valid!");
		return false;
	}

	return true;
}

bool CSpriterGM::IsTriggerInfoValid(int ModelIndex, int InstanceIndex, int TriggerInfoIndex)
{
	if (!IsModelValid(ModelIndex))
		return false;

	if (!IsInstanceValid(ModelIndex, InstanceIndex))
		return false;

	if (TriggerInfoIndex >= m_Models[ModelIndex].GetInstance(InstanceIndex).GetNumGMTriggerInfo())
	{
		Error("Trigger not valid!");
		return false;
	}

	return true;
}

bool CSpriterGM::IsSoundInfoValid(int ModelIndex, int InstanceIndex, int SoundInfoIndex)
{
	if (!IsModelValid(ModelIndex))
		return false;

	if (!IsInstanceValid(ModelIndex, InstanceIndex))
		return false;

	if (SoundInfoIndex >= m_Models[ModelIndex].GetInstance(InstanceIndex).GetNumGMSoundInfo())
	{
		Error("Sound not valid!");
		return false;
	}

	return true;
}

bool CSpriterGM::IsSpriteInfoAtlasFileValid(int ModelIndex, int InstanceIndex, int SpriteInfoIndex)
{
	if (!IsSpriteInfoValid(ModelIndex, InstanceIndex, SpriteInfoIndex))
		return false;

	if (!m_Models[ModelIndex].GetInstance(InstanceIndex).GetGMSpriteInfo(SpriteInfoIndex).IsAtlasFile())
	{
		Error("ImageFile not atlas file!");
		return false;
	}

	return true;
}

CSpriterGM::CPoint CSpriterGM::CGMSpriteInfo::CalculatePosition(const CSprite &Sprite)
{
	double _sprite_width = 0.0;
	double _sprite_height = 0.0;

	if (IsAtlasFile())
	{
		_sprite_width = m_AtlasFrame.m_FrameSizeX * GetScale().x;
		_sprite_height = m_AtlasFrame.m_FrameSizeY * GetScale().y;
	}
	else
	{
		_sprite_width = Sprite.GetSize().x * GetScale().x;
		_sprite_height = Sprite.GetSize().y * GetScale().y;
	}

	double bitmap_center_x = _sprite_width * 0.5;
	double bitmap_center_y = _sprite_height * 0.5;

	double pivotOffset_x = (_sprite_width * GetPivot().x) - bitmap_center_x;
	double pivotOffset_y = (_sprite_height * GetPivot().y) - bitmap_center_y;

	double rad = GetAngle();
	double _cos = cos(rad);
	double _sin = sin(rad);
	double _x = pivotOffset_x;
	double _y = pivotOffset_y;

	double pivotOffsetAdjustment_x = (_x - ((_x * _cos) - (_y * _sin)));
	double pivotOffsetAdjustment_y = (_y - ((_y * _cos) + (_x * _sin)));

	_x = (GetPosition().x - pivotOffset_x + pivotOffsetAdjustment_x);
	_y = (GetPosition().y - pivotOffset_y + pivotOffsetAdjustment_y) * -1.0;

	return CPoint(_x, _y);
}

void CSpriterGM::CGMSpriteInfo::CalculateShape(const CSpriterGM::CSprite &Sprite, bool bHasTexture)
{
	m_RenderPosition = CalculatePosition(Sprite);

	CPoint SpriteSize;

	if (IsAtlasFile())
	{
		SpriteSize.x = m_AtlasFrame.m_FrameSizeX;
		SpriteSize.y = m_AtlasFrame.m_FrameSizeY;
	}
	else
	{
		SpriteSize.x = Sprite.GetSize().x;
		SpriteSize.y = Sprite.GetSize().y;
	}


	CPoint PivotOffset;
	CPoint Size;
	
	Size.x = SpriteSize.x * abs(GetScale().x);
	Size.y = SpriteSize.y * abs(GetScale().y);

	PivotOffset.x = -Size.x * 0.5;
	PivotOffset.y = -Size.y * 0.5;

	double angle = -GetAngle();

	CMatrix m;

	m.Identity();

	m.Orientate(angle);

	m_Mesh.Reset();

	m_Mesh.m_Points.resize(4);

	m_Mesh.m_Points[0] = m * PivotOffset + m_RenderPosition;

	m_Mesh.m_Points[1] = m * CPoint(PivotOffset.x + Size.x, PivotOffset.y) + m_RenderPosition;

	m_Mesh.m_Points[2] = m * (PivotOffset + Size) + m_RenderPosition;

	m_Mesh.m_Points[3] = m * CPoint(PivotOffset.x, PivotOffset.y + Size.y) + m_RenderPosition;

	if (GetScale().x < 0.0)
	{
		std::swap(m_Mesh.m_Points[0], m_Mesh.m_Points[1]);
		std::swap(m_Mesh.m_Points[2], m_Mesh.m_Points[3]);
	}

	if (GetScale().y < 0.0)
	{
		std::swap(m_Mesh.m_Points[0], m_Mesh.m_Points[3]);
		std::swap(m_Mesh.m_Points[1], m_Mesh.m_Points[2]);
	}

	if (!bHasTexture)
		return;

	double FramePositionX = 0.0;
	double FramePositionY = 0.0;

	if (IsAtlasFile())
	{
		FramePositionX = m_AtlasFrame.m_FramePositionX;
		FramePositionY = m_AtlasFrame.m_FramePositionY;
	}
	CPoint TexLeftTop;
	CPoint TexRightBottom;
	TexLeftTop.x = FramePositionX * Sprite.GetTexelSize().x - 0.001,
	TexLeftTop.y = FramePositionY * Sprite.GetTexelSize().y;

	TexRightBottom.x = (FramePositionX + SpriteSize.x) * Sprite.GetTexelSize().x;
	TexRightBottom.y = (FramePositionY + SpriteSize.y) * Sprite.GetTexelSize().y - 0.001;

	m.Identity();

	if (m_AtlasFrame.m_bRotated)
	{
		double sy = SpriteSize.y * Sprite.GetTexelSize().y;
		m.Translate(TexLeftTop);
		m.Rotate((90 * M_PI) / 180);
		m.PreTranslate(TexLeftTop.x, TexLeftTop.y + sy);
	}

	m_Mesh.m_UV.resize(4);

	m_Mesh.m_UV[0] = m * TexLeftTop;

	m_Mesh.m_UV[1] = m * CPoint(TexRightBottom.x, TexLeftTop.y);

	m_Mesh.m_UV[2] = m * TexRightBottom;

	m_Mesh.m_UV[3] = m * CPoint(TexLeftTop.x, TexRightBottom.y);
}
