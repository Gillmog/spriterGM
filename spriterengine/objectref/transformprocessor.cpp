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
		parentObject->setIKModeFromChild(false);
	}

	void TransformProcessor::transformChildObject(UniversalObjectInterface *childObject)
	{
		point parentScale = parentObject->getScale();
		childObject->setScale(multiply(childObject->getScale(), parentScale));
	
		if (childObject->isIKMode() && !parentObject->isManualAngleControl())
		{
			point savePos = childObject->getPosition();

			point childPosition = childObject->getPosition();
			point preMult = multiply(childPosition, parentScale);
			childPosition.x = (preMult.x * angleCos) - (preMult.y * angleSin);
			childPosition.y = (preMult.x * angleSin) + (preMult.y * angleCos);
			childObject->setPosition(add(childPosition, parentObject->getPosition()));

			parentObject->setIKModeFromChild(false);
			point rootPos = parentObject->getPosition();
			point curEnd = childObject->getCurrentIKposition();
			point endPos = childObject->getIKPosition();

			childObject->setPosition(savePos);

			real distance = distance_squared(curEnd, endPos);

			if (distance > parentObject->getIKTreshhold())
			{
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

					if (crossResult >= 0.0)
					{
						real rotAng = parentObject->getAngle() - acos(cosAngle);

						parentObject->setAngle(rotAng);
					}
					else
					if (crossResult < 0.0)
					{
						real rotAng = parentObject->getAngle() + acos(cosAngle);

						parentObject->setAngle(rotAng);
					}

					angleSin = std::sin(parentObject->getAngle());
					angleCos = std::cos(parentObject->getAngle());
				}
			}
			
			parentObject->setIKModeFromChild(true);
		}
	
		if (parentScale.x * parentScale.y < 0)
		{
			childObject->setAngle(-childObject->getAngle());
		}

		if (!childObject->isIKModeFromChild())
			childObject->setAngle(childObject->getAngle() + parentObject->getAngle());

		childObject->setAlpha(childObject->getAlpha()*parentObject->getAlpha());
		point childPosition = childObject->getPosition();
		point preMult = multiply(childPosition, parentScale);
		childPosition.x = (preMult.x * angleCos) - (preMult.y * angleSin);
		childPosition.y = (preMult.x * angleSin) + (preMult.y * angleCos);
		childObject->setPosition(add(childPosition, parentObject->getPosition()));
	}

}
