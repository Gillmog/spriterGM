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

#include "jsonspriterfileattributewrapper.h"
#include "jsonspriterfileelementwrapper.h"

namespace SpriterEngine
{
	JSONSpriterFileAttributeWrapper::JSONSpriterFileAttributeWrapper(JSONSpriterFileElementWrapper *parent_object, std::string name, json value):
		m_value(value), m_name(name), m_parent_object(parent_object)
	{

	}

	std::string JSONSpriterFileAttributeWrapper::getName()
	{
		return m_name;
	}

	bool JSONSpriterFileAttributeWrapper::isValid()
	{
		// The default is a null value, if this is set it's invalid
		return !m_value.is_null();
	}

	real JSONSpriterFileAttributeWrapper::getRealValue()
	{
		// implicit convert
		return m_value;
	}

	int JSONSpriterFileAttributeWrapper::getIntValue()
	{
		// Sometimes there are strings like "2" in the scon so try stoi first.
		if(m_value.is_string()) {
			// This will throw std::invalid_argument when not a number.
			std::string str = m_value;
			return std::stoi(str);
		}
		// implicit convert
		return m_value;
	}

	std::string JSONSpriterFileAttributeWrapper::getStringValue()
	{
		// implicit convert
		return m_value;
	}

	void JSONSpriterFileAttributeWrapper::advanceToNextAttribute()
	{
		m_parent_object->advanceToNextAttribute(this);
	}
}
