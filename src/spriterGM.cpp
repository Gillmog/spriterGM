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

CSpriterGM *CSpriterGM::m_pInstance = nullptr;

int CSpriterGM::LoadModel(const char *pFile)
{
	std::string ModelFile = pFile;

	std::map<std::string, int>::iterator it = m_LoadedModels.find(ModelFile);

	if (it != m_LoadedModels.end())
	{
		return it->second;
	}

	SpriterEngine::Settings::reverseYOnLoad = false;
	SpriterEngine::Settings::reversePivotYOnLoad = false;
	SpriterEngine::Settings::reverseAngleOnLoad = false;
	
	SpriterEngine::SpriterModel *pScmlModel = new SpriterEngine::SpriterModel(ModelFile, new SpriterEngine::GMFileFactory, new SpriterEngine::GMObjectFactory);

	m_Models.push_back(CSpriterGMModel(pScmlModel));

	m_LoadedModels.insert(std::make_pair(ModelFile, m_Models.size() - 1));

	return m_Models.size() - 1;
}

int CSpriterGM::CreateInstance(int ModelIndex, const std::string &InstanceName)
{
	CSpriterGMModel &Model = m_Models[ModelIndex];

	SpriterEngine::SpriterModel *pScmlModel = Model.GetModel();

	SpriterEngine::EntityInstance* pInstance = pScmlModel->getNewEntityInstance(InstanceName);

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

void CSpriterGM::Render(double timeElapsed)
{
	std::vector<CSpriterGMModel>::iterator it = m_Models.begin();

	while (it != m_Models.end())
	{
		if (it->GetModel())
		{
			for (int i = 0; i < it->GetNumInstances(); i++)
			{
				it->GetInstance(i).GetInstance()->setTimeElapsed(timeElapsed);

				it->GetInstance(i).GMSpriteInfoReset();

				if (it->GetInstance(i).GetInstance()->getZOrder())
				{
					for (auto& _it : *it->GetInstance(i).GetInstance()->getZOrder())
					{
						SpriterEngine::GMImageFile *pImage = (SpriterEngine::GMImageFile *)_it->getImage();

						pImage->renderSprite(it->GetInstance(i), _it);
					}
				}
			}
		}

		++it;
	}
}

void CSpriterGM::RenderInstance(int ModelIndex, int InstanceIndex)
{
	
	SpriterEngine::EntityInstance* pInstance = GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance();
	
	if (pInstance)
	{
		GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GMSpriteInfoReset();
	
		if (pInstance->getZOrder())
		{
			for (auto& _it : *pInstance->getZOrder())
			{
				SpriterEngine::GMImageFile *pImage = (SpriterEngine::GMImageFile *)_it->getImage();

				pImage->renderSprite(GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex), _it);
			}
		}
	}
}

void CSpriterGM::UpdateInstance(int ModelIndex, int InstanceIndex, double TimeElapsed)
{
	SpriterEngine::EntityInstance* pInstance = GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GetInstance();

	if (pInstance)
	{
		GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GMTriggerInfoReset();
		GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).GMSoundInfoReset();

		CSpriterGM::GetSingleton()->SetCurrentUpdatedModelIndex(ModelIndex);
		CSpriterGM::GetSingleton()->SetCurrentUpdatedInstanceIndex(InstanceIndex);
		pInstance->setTimeElapsed(TimeElapsed);
		pInstance->playEventTriggers();
		pInstance->playSoundTriggers();
		CSpriterGM::GetSingleton()->SetCurrentUpdatedModelIndex(-1);
		CSpriterGM::GetSingleton()->SetCurrentUpdatedInstanceIndex(-1);
	}
}
