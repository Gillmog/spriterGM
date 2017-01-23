#include "boneinstanceinfo.h"

#include "../objectref/objectrefinstance.h"

namespace SpriterEngine
{
	BoneInstanceInfo::BoneInstanceInfo(point initialSize) :
		scale(1, 1),
		alpha(1),
		size(initialSize),
		bIKMode(false),
		bManualAngleControl(false),
		bIKModeFromChild(false),
		IKTreshhold(0.01)
	{
			IKangle.angle = 0;
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
		{
			real distance = distance_squared(getCurrentIKposition(), IKposition);

			if (distance > getIKTreshhold())
			{
				point rootPos = getPosition();
				point curEnd = getCurrentIKposition();
				point endPos = getIKPosition();

				point curVector, targetVector;

				curVector.x = curEnd.x - rootPos.x;
				curVector.y = curEnd.y - rootPos.y;

				targetVector.x = endPos.x - rootPos.x;
				targetVector.y = endPos.y - rootPos.y;

				normalize(curVector);
				normalize(targetVector);

				real cosAngle = dot_product(targetVector, curVector);

				if (cosAngle < 0.9999999999999999)
				{
					real crossResult = cross_product(targetVector, curVector);

					IKangle.angle = angle.angle;

					if (crossResult >= 0.0)
					{
						IKangle.angle = angle.angle - acos(cosAngle);
					}
					else
					if (crossResult < 0.0)
					{
						IKangle.angle = angle.angle + acos(cosAngle);
					}
				}
			}

			if (IKangle.angle != IKangle.angle)
				IKangle.angle = 0.0;

			return IKangle.angle;
		}

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

		real currentAngle = angle.angle;

		if (isManualAngleControl())
			currentAngle = getManualAngle();

		if (scale.x * scale.y < 0.0)
			currentAngle *= -1.0;

		framePosition.x = position.x + cos(currentAngle) * (size.x) * scale.x;
		framePosition.y = position.y + sin(currentAngle) * (size.x) * scale.y;
	}

	void BoneInstanceInfo::setAngle(real newAngle)
	{	
		if (isIKMode())
		{
			angle.angle = getAngle();
			return;
		}

		if (isIKModeFromChild())
			return;

		angle.angle = newAngle;

		IKangle.angle = newAngle;

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
		point tempScale = scale;
		real tempAlpha = alpha;

		bool bIKMode = isIKMode();

		if (!bIKMode)
			bIKMode = isIKModeFromChild();

		if (!bIKMode)
		{
			real tempAngle = angle.angle;
			point tempPosition = position;
			aObject->setObjectToLinear(bObject, t, this);
			setAngle(shortestAngleLinear(tempAngle, angle.angle, blendRatio));
			setPosition(linear(tempPosition, position, blendRatio));
		}

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

	void BoneInstanceInfo::setIKMode(bool newbIKMode, real IKTreshhold)
	{
		if (!bIKMode)
		{
			real angle = getAngle();
			IKangle.angle = angle;

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

	void BoneInstanceInfo::setManualAngle(point newPosition)
	{
		manualAngle = newPosition;
	}

	SpriterEngine::point BoneInstanceInfo::getCurrentIKposition()
	{
		return framePosition;
	}

	real BoneInstanceInfo::getManualAngle()
	{
		return angleBetween(manualAngle, position, scale);
	}

}
