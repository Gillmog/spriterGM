#ifndef BONEINSTANCEINFO_H
#define BONEINSTANCEINFO_H

#include "universalobjectinterface.h"

#include "angleinfo.h"


namespace SpriterEngine
{

	class BoneInstanceInfo : public UniversalObjectInterface
	{
		real getManualAngle();

	public:
		BoneInstanceInfo(point initialSize);

		point getPosition() override;
		real getAngle() override;
		point getScale() override;
		real getAlpha() override;

		point getSize() override;

		void setPosition(const point &newPosition) override;
		void setAngle(real newAngle) override;
		void setScale(const point &newScale) override;
		void setAlpha(real newAlpha) override;

		void setToBlendedLinear(UniversalObjectInterface *aObject, UniversalObjectInterface *bObject, real t, real blendRatio, ObjectRefInstance *blendedRefInstance = 0) override;

		void render() override;

		void setIKMode(bool newbIKMode, real IKTreshhold) override;

		void setIKPosition(point newPosition) override;

		bool isIKMode() override { return bIKMode; }

		point getIKPosition() override { return IKposition; }

		void setManualAngleControl(bool bAngleControl) override { bManualAngleControl = bAngleControl; }
		bool isManualAngleControl() override { return bManualAngleControl; }

		void setManualAngle(point newPosition) override;

		point getCurrentIKposition() override;

		void setIKModeFromChild(bool bIKMode) { bIKModeFromChild = bIKMode; }

		bool isIKModeFromChild() override  { return bIKModeFromChild; }

		real getIKTreshhold() { return IKTreshhold; }

	private:
		point position;
		AngleInfo angle;
		point scale;
		real alpha;

		point size;

		bool bIKMode;
		point IKposition;
		point manualAngle;
		bool bManualAngleControl;
		bool bIKModeFromChild;
		point framePosition;
		AngleInfo IKangle;
		real IKTreshhold;
	};

}

#endif // BONEINSTANCEINFO_H
