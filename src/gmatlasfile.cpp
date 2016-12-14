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

#include "gmatlasfile.h"

#include "../spriterengine/global/settings.h"

namespace SpriterEngine
{

	GMAtlasFile::GMAtlasFile(const std::string &initialFilePath) :
		AtlasFile(initialFilePath), m_loaded(false)
	{
		initializeFile();
	}

	void GMAtlasFile::initializeFile()
	{
		FILE * pFile;
		pFile = fopen(path().c_str(), "r");

		if (pFile)
		{
			m_loaded = true;
			fclose(pFile);
		}
		else
		{
			m_loaded = false;
			Settings::Settings::error("SfmlAtlasFile::initializeFile - sfml texture unable to load file from path \"" + path() + "\"");
		}
	}

	void GMAtlasFile::renderSprite(UniversalObjectInterface *spriteInfo, const atlasframedata data)
	{
	}

}
