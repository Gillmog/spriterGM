#include "transformprocessor.h"

#include <cmath>

#include "../objectinfo/universalobjectinterface.h"

namespace SpriterEngine
{

	TransformProcessor::TransformProcessor(UniversalObjectInterface *hostParentObject) :
		parentObject(hostParentObject),
		angleSin(0),
		angleCos(1)

	{
	}

	void TransformProcessor::setTrigFunctions()
	{
		angleSin = std::sin(parentObject->getAngle());
		angleCos = std::cos(parentObject->getAngle());
	}

	void TransformProcessor::transformChildObject(UniversalObjectInterface *childObject)
	{
		point parentScale = parentObject->getScale();
		childObject->setScale(multiply(childObject->getScale(), parentScale));

		if (childObject->isIKMode() && !parentObject->isManualAngleControl()) 
		{
			real newAngle = atan2(parentObject->getPosition().y - childObject->getIKPosition().y, parentObject->getPosition().x - childObject->getIKPosition().x);

			parentObject->setAngle(newAngle - childObject->getAngle());

			angleSin = std::sin(parentObject->getAngle());
			angleCos = std::cos(parentObject->getAngle());
		}

		if (parentScale.x * parentScale.y < 0)
		{
			childObject->setAngle( - childObject->getAngle());
		}

		childObject->setAngle(childObject->getAngle() + parentObject->getAngle());

		childObject->setAlpha(childObject->getAlpha()*parentObject->getAlpha());
		point childPosition = childObject->getPosition();
		point preMult = multiply(childPosition, parentScale);
		childPosition.x = (preMult.x * angleCos) - (preMult.y * angleSin);
		childPosition.y = (preMult.x * angleSin) + (preMult.y * angleCos);
		childObject->setPosition(add(childPosition, parentObject->getPosition()));
	}

}
