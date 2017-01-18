#include "boneinstanceinfo.h"

#include "../objectref/objectrefinstance.h"

namespace SpriterEngine
{

	real BoneInstanceInfo::getAngleBetween(const point &position1, const point &position2)
	{
		real newAngle = atan2(position1.y - position2.y, position1.x - position2.x);

		if (newAngle < 0.0)
			newAngle += 3.14159265358979323846 * 2.0;

		if (getScale().x * getScale().y < 0.0)
			newAngle -= 3.14159265358979323846;

		return newAngle;
	}

	BoneInstanceInfo::BoneInstanceInfo(point initialSize) :
		scale(1, 1),
		alpha(1),
		size(initialSize),
		bIKMode(false),
		bManualAngleControl(false)
	{
	}

	point BoneInstanceInfo::getPosition()
	{
		return position;
	}

	real BoneInstanceInfo::getAngle()
	{
		if (isManualAngleControl())
			return getManualAngle();

		if (isIKMode())
			return getIKAngle(position);

		return angle.angle;
	}

	point BoneInstanceInfo::getScale()
	{
		return scale;
	}

	real BoneInstanceInfo::getAlpha()
	{
		return alpha;
	}

	point BoneInstanceInfo::getSize()
	{
		return size;
	}


	void BoneInstanceInfo::setPosition(const point &newPosition)
	{
		position = newPosition;
	}

	void BoneInstanceInfo::setAngle(real newAngle)
	{
		angle.angle = newAngle;
	}

	void BoneInstanceInfo::setScale(const point &newScale)
	{
		scale = newScale;
	}

	void BoneInstanceInfo::setAlpha(real newAlpha)
	{
		alpha = newAlpha;
	}

	void BoneInstanceInfo::setToBlendedLinear(UniversalObjectInterface *aObject, UniversalObjectInterface *bObject, real t, real blendRatio, ObjectRefInstance *blendedRefInstance)
	{
		real tempAngle = angle.angle;
		point tempPosition = position;
		point tempScale = scale;
		real tempAlpha = alpha;

		aObject->setObjectToLinear(bObject, t, this);

		setAngle(shortestAngleLinear(tempAngle, angle.angle, blendRatio));
		setPosition(linear(tempPosition, position, blendRatio));
		setScale(linear(tempScale, scale, blendRatio));
		setAlpha(linear(tempAlpha, alpha, blendRatio));
	}

	void BoneInstanceInfo::render()
	{
		// if (renderDebugBones)
		// TODO: override and add drawing code here to enable bone debug rendering

		// getPosition()
		// getAngle();
		// getScale() * getSize().x;
	}

	void BoneInstanceInfo::setIKMode(bool newbIKMode)
	{
		if (!bIKMode)
		{
			real angle = getAngle();

			if (scale.x * scale.y < 0.0)
				angle *= -1.0;

			IKposition.x = position.x + cos(angle) * (size.x) * scale.x;
			IKposition.y = position.y + sin(angle) * (size.x) * scale.y;
		}

		bIKMode = newbIKMode;
	}

	void BoneInstanceInfo::setIKPosition(point newPosition)
	{

		IKposition = newPosition;
	}

	real BoneInstanceInfo::getIKAngle(point newPosition)
	{
		return getAngleBetween(IKposition, newPosition);
	}

	void BoneInstanceInfo::setManualAngle(point newPosition)
	{
		manualAngle = newPosition;
	}

	real BoneInstanceInfo::getManualAngle()
	{
		return getAngleBetween(manualAngle, position);
	}

}
