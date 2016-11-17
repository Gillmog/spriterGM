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

#include "gmsoundobjectinforeference.h"
#include "spriterGM.h"

namespace SpriterEngine
{

	GMSoundObjectInfoReference::GMSoundObjectInfoReference(const std::string &SoundFileName) : m_SoundFileName(SoundFileName)
	{
	
	}

	void GMSoundObjectInfoReference::playTrigger()
	{
		if (getTriggerCount())
		{
			if (this->getTriggerCount() > 0)
			{
				int ModelIndex = CSpriterGM::GetSingleton()->GetCurrentUpdatedModelIndex();
				int InstanceIndex = CSpriterGM::GetSingleton()->GetCurrentUpdatedInstanceIndex();

				if (ModelIndex != -1 && InstanceIndex != -1)
				{
					std::set<char> delims{ '/' };

					std::vector<std::string> path = CSpriterGM::SplitPath(m_SoundFileName, delims);

					std::string SoundFileName = path.back();

					size_t lastindex = SoundFileName.find_last_of(".");
					SoundFileName = SoundFileName.substr(0, lastindex);

					CSpriterGM::GetSingleton()->GetSpriterGMModel(ModelIndex).GetInstance(InstanceIndex).AddGMSoundInfo(CSpriterGM::CGMSoundInfo(SoundFileName));
				}
			}
		}
	}

	void GMSoundObjectInfoReference::setPlaybackVolume()
	{
		
	}

	void GMSoundObjectInfoReference::setPlaybackPanning()
	{
		
	}

}
