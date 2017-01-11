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

#include "gmimagefile.h"

#include "../spriterengine/global/settings.h"

#include "../spriterengine/objectinfo/universalobjectinterface.h"

#include "gmatlasfile.h"

#include "spriterGM.h"

namespace SpriterEngine
{

	GMImageFile::GMImageFile(std::string initialFilePath, point initialDefaultPivot) :
		ImageFile(initialFilePath,initialDefaultPivot)
	{
		initializeFile();
		
		if (!CSpriterGM::GetSingleton()->GetLastLoadedModel().IsAtlas())
			CSpriterGM::GetSingleton()->GetLastLoadedModel().AddSprite(initialFilePath);
	}

	void GMImageFile::initializeFile()
	{
		
	}

	void GMImageFile::renderObject(int ModelIndex, int InstanceIndex, UniversalObjectInterface *spriteInfo)
	{
		CSpriterGM::CSpriterGMModel &Model = CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex);
		CSpriterGM::CSpriterGMInstance &Instance = Model.GetInstance(InstanceIndex);

		CSpriterGM::CGMObjectInfo GMObjectInfo;

		CSpriterGM::CSprite *pSprite = NULL;
		
		if (atlasFile)
		{
			GMObjectInfo.SetSpriteName(atlasFile->path());
			GMObjectInfo.SetAtlasFile(true);
			GMObjectInfo.GetAtlasFrame().m_bRotated = atlasFrameData.rotated;
			GMObjectInfo.GetAtlasFrame().m_bTrimmed = atlasFrameData.trimmed;
			GMObjectInfo.GetAtlasFrame().m_FramePositionX = atlasFrameData.framePosition.x;
			GMObjectInfo.GetAtlasFrame().m_FramePositionY = atlasFrameData.framePosition.y;
			GMObjectInfo.GetAtlasFrame().m_FrameSizeX = atlasFrameData.frameSize.x;
			GMObjectInfo.GetAtlasFrame().m_FrameSizeY = atlasFrameData.frameSize.y;
			GMObjectInfo.GetAtlasFrame().m_SourceSizeX = atlasFrameData.sourceSize.x;
			GMObjectInfo.GetAtlasFrame().m_SourceSizeY = atlasFrameData.sourceSize.y;
			GMObjectInfo.GetAtlasFrame().m_SpriteSourcePositionX = atlasFrameData.spriteSourcePosition.x;
			GMObjectInfo.GetAtlasFrame().m_SpriteSourcePositionY = atlasFrameData.spriteSourcePosition.y;
			GMObjectInfo.GetAtlasFrame().m_SpriteSourceSizeX = atlasFrameData.spriteSourceSize.x;
			GMObjectInfo.GetAtlasFrame().m_SpriteSourceSizeY = atlasFrameData.spriteSourceSize.y;

			pSprite = Model.FindLoadedSprite(atlasFile->path());
			
		}
		else
		{
			pSprite = Model.FindLoadedSprite(spriteInfo->getImage()->path());
		}

		GMObjectInfo.SetSpriteName(spriteInfo->getImage()->path());
		GMObjectInfo.SetPosition(spriteInfo->getPosition());
		GMObjectInfo.SetPivot(spriteInfo->getPivot());
		GMObjectInfo.SetScale(spriteInfo->getScale());
		GMObjectInfo.SetAngle(spriteInfo->getAngle());
		GMObjectInfo.SetAlpha(spriteInfo->getAlpha());
		GMObjectInfo.SetRender(true);
		GMObjectInfo.SetType(CSpriterGM::CGMObjectInfo::IMAGE);

		if (pSprite)
		{
			GMObjectInfo.SetGMSpriteIndex(pSprite->GetPointer());
			GMObjectInfo.CalculateShape(*pSprite, true);
		}


		Instance.AddGMObjectInfo(GMObjectInfo);

	}

	void GMImageFile::renderSprite(UniversalObjectInterface * spriteInfo)
	{
		
	}

	// Overwritten so we can create the sprite from the texture.
	void GMImageFile::setAtlasFile(AtlasFile *initialAtlasFile, atlasframedata initialAtlasFrameData) 
	{
		if (!CSpriterGM::GetSingleton()->GetLastLoadedModel().IsAtlas())
		{
			CSpriterGM::GetSingleton()->GetLastLoadedModel().SetAtlas(true);
			CSpriterGM::GetSingleton()->GetLastLoadedModel().ClearSprites();
		}

		ImageFile::setAtlasFile(initialAtlasFile, initialAtlasFrameData);

		CSpriterGM::GetSingleton()->GetLastLoadedModel().AddSprite(initialAtlasFile->path());
	}
}
