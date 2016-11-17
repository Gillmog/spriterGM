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

#include "gmtriggerobjectinfo.h"

#include "../spriterengine/global/settings.h"

#include "spriterGM.h"

namespace SpriterEngine
{

	GMTriggerObjectInfo::GMTriggerObjectInfo(std::string triggerName) : SpriterEngine::TriggerObjectInfo(), m_TriggerName(triggerName)
	{

	}

	void GMTriggerObjectInfo::playTrigger()
	{
		if (this->getTriggerCount() > 0)
		{
			int ModelIndex = CSpriterGM::GetSingleton()->GetCurrentUpdatedModelIndex();
			int InstanceIndex = CSpriterGM::GetSingleton()->GetCurrentUpdatedInstanceIndex();

			if (ModelIndex != -1 && InstanceIndex != -1)
			{
				CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).AddGMTriggerInfo(CSpriterGM::CGMTriggerInfo(m_TriggerName));
			}
		}
	}

}
