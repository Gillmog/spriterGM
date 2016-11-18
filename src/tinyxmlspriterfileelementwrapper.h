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

#ifndef TINYXMLSPRITERFILEELEMENTWRAPPER_H
#define TINYXMLSPRITERFILEELEMENTWRAPPER_H

#include "../tinyxml2/tinyxml2.h"

#include "../spriterengine/override/spriterfileelementwrapper.h"

namespace SpriterEngine
{
	class TinyXmlSpriterFileElementWrapper : public SpriterFileElementWrapper
	{
	public:
		TinyXmlSpriterFileElementWrapper(tinyxml2::XMLElement *initialElement);

		std::string getName() override;

		bool isValid() override;

		void advanceToNextSiblingElement() override;
		void advanceToNextSiblingElementOfSameName() override;

	private:
		SpriterFileAttributeWrapper *newAttributeWrapperFromFirstAttribute() override;
		SpriterFileAttributeWrapper *newAttributeWrapperFromFirstAttribute(const std::string & attributeName) override;

		SpriterFileElementWrapper *newElementWrapperFromFirstElement() override;
		SpriterFileElementWrapper *newElementWrapperFromFirstElement(const std::string & elementName) override;

		SpriterFileElementWrapper *newElementWrapperFromNextSiblingElement() override;

		SpriterFileElementWrapper *newElementClone() override;

		const tinyxml2::XMLAttribute * findAttributeInElement(const std::string & name);

		tinyxml2::XMLElement *element;
	};

}

#endif // TINYXMLSPRITERFILEELEMENTWRAPPER_H