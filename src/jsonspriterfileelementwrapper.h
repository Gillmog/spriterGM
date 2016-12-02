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

#ifndef JSONSPRITERFILEELEMENTWRAPPER_H
#define JSONSPRITERFILEELEMENTWRAPPER_H

#include "../spriterengine/override/spriterfileelementwrapper.h"
#include "../nlohmann-json/json.hpp"

using json = nlohmann::json;

namespace SpriterEngine
{
	class JSONSpriterFileAttributeWrapper;

	class JSONSpriterFileElementWrapper : public SpriterFileElementWrapper
	{
	public:
		JSONSpriterFileElementWrapper(JSONSpriterFileElementWrapper* parent=nullptr, std::string name = "", json array = json::array(), int index = 0);

		std::string getName() override;

		bool isValid() override;

		void advanceToNextSiblingElement() override;
		void advanceToNextSiblingElementOfSameName() override;

		void advanceToNextAttribute(JSONSpriterFileAttributeWrapper* from_attribute);

	private:
		SpriterFileAttributeWrapper *newAttributeWrapperFromFirstAttribute() override;
		SpriterFileAttributeWrapper *newAttributeWrapperFromFirstAttribute(const std::string & attributeName) override;

		SpriterFileElementWrapper *newElementWrapperFromFirstElement() override;
		SpriterFileElementWrapper *newElementWrapperFromFirstElement(const std::string & elementName) override;

		SpriterFileElementWrapper *newElementWrapperFromNextSiblingElement() override;

		SpriterFileElementWrapper *newElementClone() override;

		json m_array; // Array of elements with the same name
		int m_index; // Index of the current element
		std::string m_name;

		JSONSpriterFileElementWrapper *m_parent;
	};

}

#endif // JSONSPRITERFILEELEMENTWRAPPER_H
