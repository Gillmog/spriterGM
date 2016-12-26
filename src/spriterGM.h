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
#define _USE_MATH_DEFINES 
#include <math.h>

class CGMGarbageCollector
{
	std::vector<char*> m_Garbage;

public:

	~CGMGarbageCollector()
	{
		RemoveGarbage();
	}

	void AddToGarbage(char *p)
	{
		m_Garbage.push_back(p);
	}

	virtual int RemoveGarbage()
	{
		for (size_t i = 0; i < m_Garbage.size(); i++)
		{
			delete m_Garbage[i];
			m_Garbage[i] = NULL;
		}

		int nCount = m_Garbage.size();
		m_Garbage.clear();

		return nCount;
	}

};

class CSpriterGM : public CGMGarbageCollector
{
	static CSpriterGM *m_pInstance;

	bool m_bInit;

public:

	class CPoint
	{
	public:

		double x = 0.0;
		double y = 0.0;

		CPoint()
		{
		}

		CPoint(double _x, double _y) : x(_x), y(_y)
		{
		}

		CPoint(const SpriterEngine::point &p)
		{
			*this = p;
		}

		CPoint(const CPoint &p) : x(p.x), y(p.y)
		{

		}

		void operator+=(const CPoint &p)
		{
			x += p.x;
			y += p.y;
		}

		CPoint &operator=(const SpriterEngine::point &p)
		{
			x = p.x;
			y = p.y;

			return *this;
		}

		void operator-=(const CPoint &p)
		{
			x -= p.x;
			y -= p.y;
		}

		CPoint operator+(const CPoint &p) const
		{
			return CPoint(x + p.x, y + p.y);
		}

		CPoint operator-(const CPoint &p) const
		{
			return CPoint(x - p.x, y - p.y);
		}

	};


	class CRect
	{
	public:

		double left;
		double right;
		double top;
		double bottom;

		CRect(double _left, double _top, double _right, double _bottom) : left(_left), top(_top), right(_right), bottom(_bottom)
		{

		}

		CRect() : left(0.0), top(0.0), right(0.0), bottom(0.0)
		{

		}

		CPoint GetLeftTop() const
		{
			return CPoint(left, top);
		}

		CPoint GetRightBottom() const
		{
			return CPoint(right, bottom);
		}
	};

	class CMatrix
	{

	public:

		double m00 = 0.0;
		double m01 = 0.0;
		double m02 = 0.0;
		double m10 = 0.0;
		double m11 = 0.0;
		double m12 = 0.0;

		CMatrix()
		{

		}

		void Identity()
		{
			m00 = 1.0;
			m01 = 0.0;
			m02 = 0.0;
			m10 = 0.0;
			m11 = 1.0;
			m12 = 0.0;
		}

		void operator =(const CMatrix &matrix)
		{
			m00 = matrix.m00;
			m01 = matrix.m01;
			m02 = matrix.m02;
			m10 = matrix.m10;
			m11 = matrix.m11;
			m12 = matrix.m12;
		}

		CPoint operator *(const CPoint &p) const
		{
			return CPoint(m00 * p.x + m01 * p.y + m02,
				m10 * p.x + m11 * p.y + m12);
		}

		void PreTranslate(const CPoint &p)
		{
			m02 -= m00 * p.x + m01 * p.y;
			m12 -= m10 * p.x + m11 * p.y;
		}

		void PreTranslate(double x, double y)
		{
			m02 -= m00 * x + m01 * y;
			m12 -= m10 * x + m11 * y;
		}

		void Translate(const CPoint &p)
		{
			m02 += p.x;
			m12 += p.y;
		}

		void Scale(const CPoint &p)
		{
			m00 *= p.x; m01 *= p.x; m02 *= p.x;
			m10 *= p.y; m11 *= p.y; m12 *= p.y;
		}

		void Orientate(double angle)
		{
			double sangle = sin(angle);
			double cangle = cos(angle);

			m00 = cangle;
			m01 = -sangle;
			m02 = 0.0;
			m10 = sangle;
			m11 = cangle;
			m12 = 0.0;
		}

		void Rotate(double angle)
		{
			double sangle = sin(angle);
			double cangle = cos(angle);

			double _m00 = 0.0;
			double _m01 = 0.0;
			double _m10 = 0.0;
			double _m11 = 0.0;

			_m00 = m00 * cangle + m01 * sangle;

			_m01 = -m00 * sangle + m01 * cangle;

			_m10 = m10 * cangle + m11 * sangle;

			_m11 = -m10 * sangle + m11 * cangle;

			m00 = _m00;
			m01 = _m01;
			m10 = _m10;
			m11 = _m11;
		}

	};

	class CSprite
	{
		std::string m_FileName;
		int m_Pointer = -1;
		CPoint m_Size;
		CPoint m_TexelSize;

	public:

		const std::string &GetFileName() const { return m_FileName; }
		void SetFileName(const std::string &val) { m_FileName = val; }
		int GetPointer() const { return m_Pointer; }
		void SetPointer(int val) { m_Pointer = val; }
		CPoint GetSize() const { return m_Size; }
		void SetSize(CPoint val) { m_Size = val; }
		CPoint GetTexelSize() const { return m_TexelSize; }
		void SetTexelSize(CPoint val) { m_TexelSize = val; }
	};

	class CGMTriggerInfo : public CGMGarbageCollector
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

	class CGMSoundInfo : public CGMGarbageCollector
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

	class CGMSpriteInfo : public CGMGarbageCollector
	{
		std::string m_SpriteName;
		CPoint m_Position;
		CPoint m_Pivot;
		CPoint m_Size;
		CPoint m_Scale;
		float m_Angle;
		bool m_bRender;
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

		struct CAtlasFrame
		{
			double m_FramePositionX = -1.0;
			double m_FramePositionY = -1.0;
			double m_FrameSizeX = -1.0;
			double m_FrameSizeY = -1.0;
			double m_SourceSizeX = -1.0;
			double m_SourceSizeY = -1.0;
			double m_SpriteSourcePositionX = -1.0;
			double m_SpriteSourcePositionY = -1.0;
			double m_SpriteSourceSizeX = -1.0;
			double m_SpriteSourceSizeY = -1.0;
			bool m_bRotated = false;
			bool m_bTrimmed = false;
		};

		bool m_bAtlasFile;

		CAtlasFrame m_AtlasFrame;

		int m_GMSpriteIndex;

		class CMesh
		{
		public:

			std::vector<CPoint> m_Points;
			std::vector<CPoint> m_UV;

			CMesh(const CMesh &Mesh) : m_Points(std::move(Mesh.m_Points)), m_UV(std::move(Mesh.m_UV))
			{

			}

			CMesh()
			{
			}

			void Reset()
			{
				m_Points.clear();
				m_UV.clear();
			}
		};

		CMesh m_Mesh;
		CPoint m_RenderPosition;

		CPoint CalculatePosition(const CSprite &Sprite);

	public:

		CGMSpriteInfo() :
			m_Angle(0.0f),
			m_bRender(false),
			m_Alpha(1.0f),
			m_Type(UNKNOWN),
			m_bAtlasFile(false),
			m_GMSpriteIndex(-1)
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
			m_Alpha(Spriteinfo.m_Alpha),
			m_Type(Spriteinfo.m_Type),
			m_bAtlasFile(Spriteinfo.m_bAtlasFile),
			m_AtlasFrame(Spriteinfo.m_AtlasFrame),
			m_GMSpriteIndex(Spriteinfo.m_GMSpriteIndex),
			m_Mesh(Spriteinfo.m_Mesh),
			m_RenderPosition(Spriteinfo.m_RenderPosition)
		{

		}

		~CGMSpriteInfo()
		{
			RemoveGarbage();
		}

		std::string GetSpriteName() const { return m_SpriteName; }
		void SetSpriteName(const std::string &val) { m_SpriteName = val; }
		CPoint GetPosition() const { return m_Position; }
		void SetPosition(const CPoint &val) { m_Position = val; }
		CPoint GetPivot() const { return m_Pivot; }
		void SetPivot(const CPoint &val) { m_Pivot = val; }
		CPoint GetSize() const { return m_Size; }
		void SetSize(const CPoint &val) { m_Size = val; }
		CPoint GetScale() const { return m_Scale; }
		void SetScale(const CPoint &val) { m_Scale = val; }
		float GetAngle() const { return m_Angle; }
		void SetAngle(float val) { m_Angle = val; }
		bool IsRender() const { return m_bRender; }
		void SetRender(bool val) { m_bRender = val; }

		CSpriterGM::CGMSpriteInfo::EType GetType() const { return m_Type; }
		void SetType(CSpriterGM::CGMSpriteInfo::EType val) { m_Type = val; }

		void CalculateShape(const CSprite &Sprite, bool bHasTexture);
	
		float GetAlpha() const { return m_Alpha; }
		void SetAlpha(float val) { m_Alpha = val; }

		bool IsAtlasFile() const { return m_bAtlasFile; }
		void SetAtlasFile(bool val) { m_bAtlasFile = val; }

		CAtlasFrame &GetAtlasFrame() { return m_AtlasFrame; }

		int GetGMSpriteIndex() const { return m_GMSpriteIndex; }
		void SetGMSpriteIndex(int val) { m_GMSpriteIndex = val; }

		const CPoint &GetRenderPosition() const { return m_RenderPosition; }

		double GetMeshX(bool bGetUV, int PointIndex) { return bGetUV ? m_Mesh.m_UV[PointIndex].x : m_Mesh.m_Points[PointIndex].x; }
		double GetMeshY(bool bGetUV, int PointIndex) { return bGetUV ? m_Mesh.m_UV[PointIndex].y : m_Mesh.m_Points[PointIndex].y; }
	};

	class CSpriterGMInstance : public CGMGarbageCollector
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
			GMSoundInfoReset();
			GMTriggerInfoReset();
			RemoveGarbage();
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
			for (size_t nTrigger = 0; nTrigger < m_Triggers.size(); nTrigger++)
			{
				m_Triggers[nTrigger].RemoveGarbage();
			}

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
			for (size_t nSound = 0; nSound < m_Sounds.size(); nSound++)
			{
				m_Sounds[nSound].RemoveGarbage();
			}

			m_Sounds.clear();
		}

		SpriterEngine::EntityInstance* GetInstance() const
		{
			return m_pInstance;
		}
	};

	class CSpriterGMModel : public CGMGarbageCollector
	{
		SpriterEngine::SpriterModel* m_pModel;
		std::vector<CSpriterGMInstance> m_Instances;
		std::map<std::string, CSprite> m_MapSprites;
		std::vector<std::string> m_Sprites;
		bool m_bAtlas = false;

	public:

		CSpriterGMModel() : m_pModel(NULL)
		{

		}

		CSpriterGMModel(SpriterEngine::SpriterModel* pModel) : m_pModel(pModel)
		{

		}

		CSpriterGMModel(const CSpriterGMModel &Model) :
			m_pModel(Model.m_pModel),
			m_Instances(std::move(Model.m_Instances)),
			m_MapSprites(std::move(Model.m_MapSprites)),
			m_Sprites(std::move(Model.m_Sprites)),
			m_bAtlas(Model.m_bAtlas)
		{

		}

		void Reset()
		{
			m_pModel = NULL;
			m_Instances.clear();
			m_MapSprites.clear();
			m_Sprites.clear();
			m_bAtlas = false;
		}

		~CSpriterGMModel()
		{
			RemoveGarbage();
		}

		SpriterEngine::SpriterModel* GetModel()
		{
			return m_pModel;
		}

		void SetModel(SpriterEngine::SpriterModel* val)
		{
			m_pModel = val;
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

		CSprite *FindLoadedSprite(const std::string &SpriteName)
		{
			auto Iter = m_MapSprites.find(SpriteName);

			if (Iter != m_MapSprites.end())
			{
				return &Iter->second;
			}

			return NULL;
		}

		bool AddLoadedSprite(const std::string &SpriteName, int SpritePtr)
		{
			if (!FindLoadedSprite(SpriteName))
			{
				CSprite Sprite;
				Sprite.SetFileName(SpriteName);
				Sprite.SetPointer(SpritePtr);
				m_MapSprites.insert(std::pair<std::string, CSprite>(SpriteName, Sprite));

				return true;
			}

			return false;
		}

		void SetLoadedSpriteTexelSize(const std::string &SpriteName, double TexelWidth, double TexelHeight)
		{
			CSprite *pSprite = FindLoadedSprite(SpriteName);

			if (pSprite)
			{
				pSprite->SetTexelSize(CPoint(TexelWidth, TexelHeight));
			}
		}

		void SetLoadedSpriteSize(const std::string &SpriteName, double TextureWidth, double TextureHeight)
		{
			CSprite *pSprite = FindLoadedSprite(SpriteName);

			if (pSprite)
			{
				pSprite->SetSize(CPoint(TextureWidth, TextureHeight));
			}
		}

		void ClearSprites()
		{
			m_Sprites.clear();
			m_MapSprites.clear();
		}

		bool AddSprite(const std::string &SpriteName)
		{
			for (size_t n = 0; n < m_Sprites.size(); n++)
			{
				if (m_Sprites[n] == SpriteName)
					return false;
			}

			m_Sprites.push_back(SpriteName);

			return true;
		}

		int GetNumSprites() const { return (int)m_Sprites.size(); }

		std::string GetSprite(int Index) const { return m_Sprites[Index]; }
		bool IsAtlas() const { return m_bAtlas; }
		void SetAtlas(bool val) { m_bAtlas = val; }
	};

private:

	std::vector<CSpriterGMModel> m_Models;
	std::map<std::string, int> m_LoadedModels;

	int m_CurrentUpdatedModelIndex;
	int m_CurrentUpdatedInstanceIndex;

	std::vector<std::string> m_ErrorsList;

	CSpriterGMModel m_LastLoadedModel;

public:

	CSpriterGM() : m_CurrentUpdatedModelIndex(-1), m_CurrentUpdatedInstanceIndex(-1), m_bInit(false)
	{

	}

	~CSpriterGM()
	{
		m_ErrorsList.clear();
		RemoveGarbage();
		m_pInstance = nullptr;
	}

	void Init();

	CSpriterGMModel &GetSpriterGMModel(int Index)
	{
		return m_Models[Index];
	}

	int LoadModel(const char *pFile);

	int CreateInstance(int ModelIndex, const std::string &InstanceName, bool bEnableBones);

	void UpdateInstance(int ModelIndex, int InstanceIndex, double TimeElapsed);

	int GetCurrentUpdatedModelIndex() const { return m_CurrentUpdatedModelIndex; }
	void SetCurrentUpdatedModelIndex(int val) { m_CurrentUpdatedModelIndex = val; }

	int GetCurrentUpdatedInstanceIndex() const { return m_CurrentUpdatedInstanceIndex; }
	void SetCurrentUpdatedInstanceIndex(int val) { m_CurrentUpdatedInstanceIndex = val; }

	static CSpriterGM *GetSingleton();

	void Error(const std::string &ErrorMessage)
	{
		m_ErrorsList.push_back(ErrorMessage);
	}

	int GetNumErrors()
	{
		return m_ErrorsList.size();
	}

#if defined(ANDROID)
	std::string GetLastError()
	{
		std::string Error = m_ErrorsList.back();

		m_ErrorsList.pop_back();

		return Error;
	}
#else
	const char *GetLastError()
	{
		std::string Error = m_ErrorsList.back();

		char *pCopyStr = new char[Error.length() + 1];
		strcpy(pCopyStr, Error.c_str());

		AddToGarbage(pCopyStr);

		m_ErrorsList.pop_back();

		return pCopyStr;
	}
#endif

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

	int ForceGarbageCollection();

	bool IsModelValid(int ModelIndex);

	bool IsInstanceValid(int ModelIndex, int InstanceIndex);

	bool IsSpriteInfoValid(int ModelIndex, int InstanceIndex, int SpriteInfoIndex);

	bool IsTriggerInfoValid(int ModelIndex, int InstanceIndex, int TriggerInfoIndex);

	bool IsSoundInfoValid(int ModelIndex, int InstanceIndex, int SoundInfoIndex);

	bool IsSpriteInfoAtlasFileValid(int ModelIndex, int InstanceIndex, int SpriteInfoIndex);

	CSpriterGMModel &GetLastLoadedModel() { return m_LastLoadedModel; }
};

#endif //_SPRITER_GM_INCLUDED