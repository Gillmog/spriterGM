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

		const std::string &GetTriggerName() const { return m_TriggerName; }
	};

	class CGMSoundInfo : public CGMGarbageCollector
	{
		std::string m_SoundFileName;

	public:

		CGMSoundInfo(const std::string &SoundFileName) : m_SoundFileName(SoundFileName)
		{

		}

		const std::string &GetSoundFileName() const { return m_SoundFileName; }
	};

	class CGMObjectInfo : public CGMGarbageCollector
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
		int m_ObjectID;
		std::string m_ObjectName;

		CPoint CalculatePosition(const CSprite &Sprite);

	public:

		CGMObjectInfo() :
			m_Angle(0.0f),
			m_bRender(false),
			m_Alpha(1.0f),
			m_Type(UNKNOWN),
			m_bAtlasFile(false),
			m_GMSpriteIndex(-1),
			m_ObjectID(-1)
		{

		}

		const std::string &GetSpriteName() const { return m_SpriteName; }
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

		CSpriterGM::CGMObjectInfo::EType GetType() const { return m_Type; }
		void SetType(CSpriterGM::CGMObjectInfo::EType val) { m_Type = val; }

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

		int GetObjectID() const { return m_ObjectID; }
		void SetObjectID(int val) { m_ObjectID = val; }

		const std::string &GetObjectName() const { return m_ObjectName; }
		void SetObjectName(const std::string &val) { m_ObjectName = val; }
	};

	class CSpriterGMInstance : public CGMGarbageCollector
	{
		SpriterEngine::EntityInstance* m_pInstance;
		std::vector<CGMObjectInfo> m_Objects;
		std::vector<CGMTriggerInfo> m_Triggers;
		std::vector<CGMSoundInfo> m_Sounds;

		SpriterEngine::UniversalObjectInterface * m_pLockedObjectInstance;

	public:

		CSpriterGMInstance() : m_pInstance(NULL), m_pLockedObjectInstance(NULL)
		{

		}

		CSpriterGMInstance(SpriterEngine::EntityInstance* pInstance) : 
			m_pInstance(pInstance), m_pLockedObjectInstance(NULL)
		{

		}

		~CSpriterGMInstance()
		{
			m_pLockedObjectInstance = NULL;
			Destroy();
		}

		void Destroy()
		{
			m_pInstance = NULL;
			RemoveGarbage();
			GMSoundInfoReset();
			GMTriggerInfoReset();
			GMObjectInfoReset();
		}

		int GetNumGMObjectInfo() const { return m_Objects.size(); }
		int GetNumGMTriggerInfo() const { return m_Triggers.size(); }
		int GetNumGMSoundInfo() const { return m_Sounds.size(); }

		CGMObjectInfo &GetGMObjectInfo(int Index)
		{
			return m_Objects[Index];
		}

		void AddGMObjectInfo(const CGMObjectInfo &ObjectInfo)
		{
			m_Objects.push_back(ObjectInfo);
		}

		void GMObjectInfoReset()
		{
			m_Objects.clear();
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

		//IK
		void SetLockObjectInstance(const std::string &ObjectName);

		void SetUnlockObjectInstance();

		void SetObjectInstanceIKMode(const std::string &ObjectName, bool bIKMode);

		void SetObjectInstanceIKPosition(const SpriterEngine::point &position);

		void SetObjectInstanceManualAngleControl(const std::string &ObjectName, bool bManualControl);

		void SetObjectInstanceManualAngle(const SpriterEngine::point &position);

		bool IsObjectInstanceIKMode(const std::string &ObjectName) const;

		bool IsObjectInstanceManualAngleControl(const std::string &ObjectName) const;
	};

	class CSpriterGMModel : public CGMGarbageCollector
	{
		SpriterEngine::SpriterModel* m_pModel;
		std::string m_FileName;
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

		int AddInstance(const CSpriterGMInstance &Instance)
		{
			int nInstanceIndex = -1;

			for (int nInstance = 0; nInstance < m_Instances.size(); nInstance++)
			{
				if (m_Instances[nInstance].GetInstance() == NULL)
				{
					m_Instances[nInstance] = Instance;
					nInstanceIndex = nInstance;
					break;
				}
			}

			if (nInstanceIndex == -1)
			{
				m_Instances.push_back(Instance);
				nInstanceIndex = m_Instances.size() - 1;
			}

			return nInstanceIndex;
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

		const std::string &GetSprite(int Index) const { return m_Sprites[Index]; }
		bool IsAtlas() const { return m_bAtlas; }
		void SetAtlas(bool val) { m_bAtlas = val; }

		void DestroyAllInstances()
		{
			for (int nInstance = 0; nInstance < GetNumInstances(); nInstance++)
			{
				SpriterEngine::EntityInstance* pInstance = GetInstance(nInstance).GetInstance();

				if (pInstance)
					delete pInstance;
			}

			m_Instances.clear();
		}

		bool DestroyInstance(int InstanceIndex)
		{
			SpriterEngine::EntityInstance* pInstance = GetInstance(InstanceIndex).GetInstance();

			if (pInstance)
				delete pInstance;

			m_Instances[InstanceIndex].Destroy();

			m_Instances[InstanceIndex] = CSpriterGMInstance();

			int nEmptyCount = 0;

			for (int nInstance = 0; nInstance < GetNumInstances(); nInstance++)
			{
				SpriterEngine::EntityInstance* pInstance = GetInstance(nInstance).GetInstance();

				if (!pInstance)
					nEmptyCount++;
			}

			if (nEmptyCount == GetNumInstances())
			{
				m_Instances.clear();
				return true;
			}

			return false;
		}

		const std::string &GetFileName() const { return m_FileName; }
		void SetFileName(const std::string &val) { m_FileName = val; }
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
		RemoveGarbage();
		m_ErrorsList.clear();
		DestroyAllModels();
		m_pInstance = nullptr;
	}

	void Init();

	CSpriterGMModel &GetSpriterGMModel(int Index)
	{
		return m_Models[Index];
	}

	void DestroyAllModels()
	{
		m_LoadedModels.clear();

		for (int nModel = 0; nModel < m_Models.size(); nModel++)
		{
			m_Models[nModel].DestroyAllInstances();

			SpriterEngine::SpriterModel *pModel = m_Models[nModel].GetModel();

			if (pModel)
				delete pModel;
		}

		m_Models.clear();
	}

	void DestroyModel(int ModelIndex)
	{
		std::map<std::string, int>::iterator it = m_LoadedModels.find(m_Models[ModelIndex].GetFileName());

		if (it != m_LoadedModels.end())
		{
			m_LoadedModels.erase(it);
		}

		m_Models[ModelIndex].DestroyAllInstances();

		SpriterEngine::SpriterModel *pModel = m_Models[ModelIndex].GetModel();

		if (pModel)
			delete pModel;

		m_Models[ModelIndex] = CSpriterGMModel();

		int nEmptyCount = 0;

		for (int nModel = 0; nModel < m_Models.size(); nModel++)
		{
			SpriterEngine::SpriterModel *pModel = m_Models[nModel].GetModel();

			if (!pModel)
				nEmptyCount++;
		}

		if (nEmptyCount == m_Models.size())
		{
			m_Models.clear();
		}
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
		const std::string &Error = m_ErrorsList.back();

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

	bool IsObjectInfoValid(int ModelIndex, int InstanceIndex, int ObjectInfoIndex);

	bool IsTriggerInfoValid(int ModelIndex, int InstanceIndex, int TriggerInfoIndex);

	bool IsSoundInfoValid(int ModelIndex, int InstanceIndex, int SoundInfoIndex);

	bool IsObjectInfoAtlasFileValid(int ModelIndex, int InstanceIndex, int ObjectInfoIndex);

	CSpriterGMModel &GetLastLoadedModel() { return m_LastLoadedModel; }
};

#endif //_SPRITER_GM_INCLUDED