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

#ifndef _SPRITER_GM_INCLUDED
#define _SPRITER_GM_INCLUDED

#pragma once

#include "gmobjectfactory.h"
#include "gmfilefactory.h"

#include "../spriterengine/spriterengine.h"
#include "../spriterengine/global/settings.h"

#include<set>
#include<map>
#include<algorithm>

class CSpriterGM
{
	static CSpriterGM *m_pInstance;

public:

	class CGMTriggerInfo
	{
		std::string m_TriggerName;

	public:

		CGMTriggerInfo(const std::string &TriggerName) : m_TriggerName(TriggerName)
		{

		}

		CGMTriggerInfo(const CGMTriggerInfo &GMTriggerInfo) : m_TriggerName(std::move(GMTriggerInfo.m_TriggerName))
		{

		}

		std::string GetTriggerName() const { return m_TriggerName; }
	};

	class CGMSoundInfo
	{
		std::string m_SoundFileName;

	public:

		CGMSoundInfo(const std::string &SoundFileName) : m_SoundFileName(SoundFileName)
		{

		}

		CGMSoundInfo(const CGMSoundInfo &GMSoundInfo) : m_SoundFileName(std::move(GMSoundInfo.m_SoundFileName))
		{

		}

		std::string GetSoundFileName() const { return m_SoundFileName; }
	};

	class CGMSpriteInfo
	{
		std::string m_SpriteName;
		SpriterEngine::point m_Position;
		SpriterEngine::point m_Pivot;
		SpriterEngine::point m_Size;
		SpriterEngine::point m_Scale;
		float m_Angle;
		bool m_bRender;
		int m_ImageWidth;
		int m_ImageHeight;
		float m_Alpha;

	public:

		enum EType
		{
			UNKNOWN = 0,
			IMAGE,
			BOX,
			POINT,
			BONE
		};

	private:

		EType m_Type;

	public:

		CGMSpriteInfo() : m_Angle(0.0f), m_bRender(false), m_ImageWidth(0), m_ImageHeight(0), m_Alpha(1.0f), m_Type(UNKNOWN)
		{

		}

		CGMSpriteInfo(const CGMSpriteInfo &Spriteinfo) :
			m_SpriteName(std::move(Spriteinfo.m_SpriteName)),
			m_Position(Spriteinfo.m_Position),
			m_Pivot(Spriteinfo.m_Pivot),
			m_Size(Spriteinfo.m_Size),
			m_Scale(Spriteinfo.m_Scale),
			m_Angle(Spriteinfo.m_Angle),
			m_bRender(Spriteinfo.m_bRender),
			m_ImageWidth(Spriteinfo.m_ImageWidth),
			m_ImageHeight(Spriteinfo.m_ImageHeight),
			m_Alpha(Spriteinfo.m_Alpha),
			m_Type(Spriteinfo.m_Type)
		{

		}

		~CGMSpriteInfo()
		{
		}

		std::string GetSpriteName() const { return m_SpriteName; }
		void SetSpriteName(std::string val) { m_SpriteName = val; }
		SpriterEngine::point GetPosition() const { return m_Position; }
		void SetPosition(SpriterEngine::point val) { m_Position = val; }
		SpriterEngine::point GetPivot() const { return m_Pivot; }
		void SetPivot(SpriterEngine::point val) { m_Pivot = val; }
		SpriterEngine::point GetSize() const { return m_Size; }
		void SetSize(SpriterEngine::point val) { m_Size = val; }
		SpriterEngine::point GetScale() const { return m_Scale; }
		void SetScale(SpriterEngine::point val) { m_Scale = val; }
		float GetAngle() const { return m_Angle; }
		void SetAngle(float val) { m_Angle = val; }
		bool IsRender() const { return m_bRender; }
		void SetRender(bool val) { m_bRender = val; }
		int GetImageWidth() const { return m_ImageWidth; }
		void SetImageWidth(int val) { m_ImageWidth = val; }
		int GetImageHeight() const { return m_ImageHeight; }
		void SetImageHeight(int val) { m_ImageHeight = val; }

		CSpriterGM::CGMSpriteInfo::EType GetType() const { return m_Type; }
		void SetType(CSpriterGM::CGMSpriteInfo::EType val) { m_Type = val; }

		const SpriterEngine::point & CalculatePosition()
		{
			double _sprite_width = m_ImageWidth * GetScale().x;
			double _sprite_height = m_ImageHeight * GetScale().y;

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

			return SpriterEngine::point(_x, _y);
		}
	
		float GetAlpha() const { return m_Alpha; }
		void SetAlpha(float val) { m_Alpha = val; }
	};

	class CSpriterGMInstance
	{
		SpriterEngine::EntityInstance* m_pInstance;
		std::vector<CGMSpriteInfo> m_Sprites;
		std::vector<CGMTriggerInfo> m_Triggers;
		std::vector<CGMSoundInfo> m_Sounds;

	public:

		CSpriterGMInstance(SpriterEngine::EntityInstance* pInstance) : 
			m_pInstance(pInstance)
		{

		}

		CSpriterGMInstance(const CSpriterGMInstance &Instance) :
			m_pInstance(Instance.m_pInstance),
			m_Sprites(std::move(Instance.m_Sprites)),
			m_Triggers(std::move(Instance.m_Triggers)),
			m_Sounds(std::move(Instance.m_Sounds))
		{

		}

		~CSpriterGMInstance()
		{
			m_Sprites.clear();
			m_pInstance = NULL;
		}

		int GetNumGMSpriteInfo() const { return m_Sprites.size(); }
		int GetNumGMTriggerInfo() const { return m_Triggers.size(); }
		int GetNumGMSoundInfo() const { return m_Sounds.size(); }

		CGMSpriteInfo &GetGMSpriteInfo(int Index)
		{
			return m_Sprites[Index];
		}

		void AddGMSpriteInfo(const CGMSpriteInfo &SpriteInfo)
		{
			m_Sprites.push_back(SpriteInfo);
		}

		void GMSpriteInfoReset()
		{
			m_Sprites.clear();
		}

		CGMTriggerInfo &GetGMTriggerInfo(int Index)
		{
			return m_Triggers[Index];
		}

		void AddGMTriggerInfo(const CGMTriggerInfo &TriggerInfo)
		{
			m_Triggers.push_back(TriggerInfo);
		}

		void GMTriggerInfoReset()
		{
			m_Triggers.clear();
		}

		CGMSoundInfo &GetGMSoundInfo(int Index)
		{
			return m_Sounds[Index];
		}

		void AddGMSoundInfo(const CGMSoundInfo &SoundInfo)
		{
			m_Sounds.push_back(SoundInfo);
		}

		void GMSoundInfoReset()
		{
			m_Sounds.clear();
		}

		SpriterEngine::EntityInstance* GetInstance() const
		{
			return m_pInstance;
		}
	};

	class CSpriterGMModel
	{
		SpriterEngine::SpriterModel* m_pModel;
		std::vector<CSpriterGMInstance> m_Instances;

	public:

		CSpriterGMModel(SpriterEngine::SpriterModel* pModel) : m_pModel(pModel)
		{

		}

		CSpriterGMModel(const CSpriterGMModel &Model) : 
			m_pModel(Model.m_pModel),
			m_Instances(std::move(Model.m_Instances))
		{

		}

		SpriterEngine::SpriterModel* GetModel()
		{
			return m_pModel;
		}

		int GetNumInstances() const { return m_Instances.size();  }

		CSpriterGMInstance &GetInstance(int Index)
		{
			return m_Instances[Index];
		}

		void AddInstance(const CSpriterGMInstance &Instance)
		{
			m_Instances.push_back(Instance);
		}
	};

private:

	std::vector<CSpriterGMModel> m_Models;
	std::map<std::string, int> m_LoadedModels;

	int m_CurrentUpdatedModelIndex;
	int m_CurrentUpdatedInstanceIndex;

public:

	CSpriterGM() : m_CurrentUpdatedModelIndex(-1), m_CurrentUpdatedInstanceIndex(-1)
	{

	}

	~CSpriterGM()
	{
		m_pInstance = nullptr;
	}

	CSpriterGMModel &GetSpriterGMModel(int Index)
	{
		return m_Models[Index];
	}

	int LoadModel(const char *pFile);

	int CreateInstance(int ModelIndex, const std::string &InstanceName);

	void Render(double timeElapsed);

	void RenderInstance(int ModelIndex, int InstanceIndex);

	void UpdateInstance(int ModelIndex, int InstanceIndex, double TimeElapsed);

	int GetCurrentUpdatedModelIndex() const { return m_CurrentUpdatedModelIndex; }
	void SetCurrentUpdatedModelIndex(int val) { m_CurrentUpdatedModelIndex = val; }

	int GetCurrentUpdatedInstanceIndex() const { return m_CurrentUpdatedInstanceIndex; }
	void SetCurrentUpdatedInstanceIndex(int val) { m_CurrentUpdatedInstanceIndex = val; }

	static CSpriterGM *GetSingleton()
	{
		if (!m_pInstance)
			m_pInstance = new CSpriterGM();

		 return m_pInstance;
	}

	static std::vector<std::string> SplitPath(
		const std::string& str
		, const std::set<char> delimiters)
	{
		std::vector<std::string> result;

		char const* pch = str.c_str();
		char const* start = pch;
		for (; *pch; ++pch)
		{
			if (delimiters.find(*pch) != delimiters.end())
			{
				if (start != pch)
				{
					std::string str(start, pch);
					result.push_back(str);
				}
				else
				{
					result.push_back("");
				}
				start = pch + 1;
			}
		}
		result.push_back(start);

		return result;
	}
};
#endif //_SPRITER_GM_INCLUDED