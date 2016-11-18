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
	}

	void GMImageFile::initializeFile()
	{
		
	}

	void GMImageFile::renderSprite(CSpriterGM::CSpriterGMInstance &Instance, UniversalObjectInterface *spriteInfo)
	{
		std::set<char> delims{ '/' };

		if (!spriteInfo->getImage())
			return;

		CSpriterGM::CGMSpriteInfo GMSpriteInfo;

		std::vector<std::string> path = CSpriterGM::SplitPath(spriteInfo->getImage()->path(), delims);

		if (path.size() > 1)
			GMSpriteInfo.SetSpriteName(path[path.size() - 2] + "/" + path[path.size() - 1]);
		else
		{
			GMSpriteInfo.SetSpriteName(path.back());
		}

		GMSpriteInfo.SetPosition(spriteInfo->getPosition());
		GMSpriteInfo.SetPivot(spriteInfo->getPivot());
		GMSpriteInfo.SetScale(spriteInfo->getScale());
		GMSpriteInfo.SetSize(spriteInfo->getSize());
		GMSpriteInfo.SetAngle(spriteInfo->getAngle());
		GMSpriteInfo.SetAlpha(spriteInfo->getAlpha());
		GMSpriteInfo.SetRender(true);
		GMSpriteInfo.SetType(CSpriterGM::CGMSpriteInfo::IMAGE);
		Instance.AddGMSpriteInfo(GMSpriteInfo);

	}

	void GMImageFile::renderSprite(UniversalObjectInterface * spriteInfo)
	{
		
	}

	// Overwritten so we can create the sprite from the texture.
	void GMImageFile::setAtlasFile(AtlasFile *initialAtlasFile, atlasframedata initialAtlasFrameData) 
	{
		
	}
}
