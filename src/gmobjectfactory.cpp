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

#include "gmobjectfactory.h"

#include "gmpointinstanceinfo.h"
#include "gmboxinstanceinfo.h"
#include "gmboneinstanceinfo.h"
#include "gmsoundobjectinforeference.h"
#include "gmtriggerobjectinfo.h"

namespace SpriterEngine
{

	GMObjectFactory::GMObjectFactory()
	{
	}

	PointInstanceInfo * GMObjectFactory::newPointInstanceInfo(int objectID, std::string objectName)
	{
		return new GMPointInstanceInfo(objectID, objectName);
	}

	BoxInstanceInfo * GMObjectFactory::newBoxInstanceInfo(int objectID, std::string objectName, point size)
	{
		return new GMBoxInstanceInfo(objectID, objectName, size);
	}

	BoneInstanceInfo * GMObjectFactory::newBoneInstanceInfo(int objectID, std::string objectName, point size)
	{
		return new GMBoneInstanceInfo(objectID, objectName, size);
	}

	SpriterEngine::TriggerObjectInfo *GMObjectFactory::newTriggerObjectInfo(std::string triggerName)
	{
		return new GMTriggerObjectInfo(triggerName);
	}

}