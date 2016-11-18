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

#include "tinyxmlspriterfileelementwrapper.h"

#include "tinyxmlspriterfileattributewrapper.h"

namespace SpriterEngine
{
	TinyXmlSpriterFileElementWrapper::TinyXmlSpriterFileElementWrapper(tinyxml2::XMLElement *initialElement):
		element(initialElement)
	{
	}

	std::string TinyXmlSpriterFileElementWrapper::getName()
	{
		return element->Value();
	}

	bool TinyXmlSpriterFileElementWrapper::isValid()
	{
		return element;
	}

	void TinyXmlSpriterFileElementWrapper::advanceToNextSiblingElement()
	{
		element = element->NextSiblingElement();
	}

	void TinyXmlSpriterFileElementWrapper::advanceToNextSiblingElementOfSameName()
	{
		element = element->NextSiblingElement(getName().c_str());
	}

	SpriterFileAttributeWrapper * TinyXmlSpriterFileElementWrapper::newAttributeWrapperFromFirstAttribute()
	{
		return new TinyXmlSpriterFileAttributeWrapper(element->FirstAttribute());
	}

	SpriterFileAttributeWrapper * TinyXmlSpriterFileElementWrapper::newAttributeWrapperFromFirstAttribute(const std::string & attributeName)
	{
		return new TinyXmlSpriterFileAttributeWrapper(findAttributeInElement(attributeName));
	}

	SpriterFileElementWrapper * TinyXmlSpriterFileElementWrapper::newElementWrapperFromFirstElement()
	{
		return new TinyXmlSpriterFileElementWrapper(element->FirstChildElement());
	}

	SpriterFileElementWrapper * TinyXmlSpriterFileElementWrapper::newElementWrapperFromFirstElement(const std::string & elementName)
	{
		return new TinyXmlSpriterFileElementWrapper(element->FirstChildElement(elementName.c_str()));
	}

	SpriterFileElementWrapper * TinyXmlSpriterFileElementWrapper::newElementWrapperFromNextSiblingElement()
	{
		return new TinyXmlSpriterFileElementWrapper(element->NextSiblingElement(getName().c_str()));
	}

	SpriterFileElementWrapper * TinyXmlSpriterFileElementWrapper::newElementClone()
	{
		return new TinyXmlSpriterFileElementWrapper(element);
	}

	const tinyxml2::XMLAttribute * TinyXmlSpriterFileElementWrapper::findAttributeInElement(const std::string & name)
	{
		const tinyxml2::XMLAttribute *attribute =  element->FirstAttribute();

		while (attribute)
		{
			if (attribute->Name() == name)
			{
				return attribute;
			}

			attribute = attribute->Next();
		}

		return 0;
	}

}