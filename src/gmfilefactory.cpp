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

#include "gmfilefactory.h"

#include "../spriterengine/override/imagefile.h"
#include "../spriterengine/override/soundfile.h"

// #define __USE_PUGIXML
#ifndef __USE_PUGIXML
#include "tinyxmlspriterfiledocumentwrapper.h"
#else
#include "pugixmlspriterfiledocumentwrapper.h"
#endif

#include "jsonspriterfiledocumentwrapper.h"

#include "gmimagefile.h"
#include "gmatlasfile.h"
#include "gmsoundfile.h"

namespace SpriterEngine
{

	GMFileFactory::GMFileFactory()
	{
	}

	ImageFile * GMFileFactory::newImageFile(const std::string &initialFilePath, point initialDefaultPivot, atlasdata atlasData)
	{
		return new GMImageFile(initialFilePath, initialDefaultPivot);
	}

	AtlasFile *GMFileFactory::newAtlasFile(const std::string &initialFilePath)
	{
		return new GMAtlasFile(initialFilePath);

	}

	SoundFile * GMFileFactory::newSoundFile(const std::string & initialFilePath)
	{
		return new GMSoundFile(initialFilePath);
	}

	SpriterFileDocumentWrapper * GMFileFactory::newScmlDocumentWrapper()
	{
#ifndef __USE_PUGIXML
		return new TinyXmlSpriterFileDocumentWrapper();
#else
		return new PugiXmlSpriterFileDocumentWrapper();		
#endif
	}

	SpriterFileDocumentWrapper *GMFileFactory::newSconDocumentWrapper()
	{
		return new JSONSpriterFileDocumentWrapper();
	}
}
