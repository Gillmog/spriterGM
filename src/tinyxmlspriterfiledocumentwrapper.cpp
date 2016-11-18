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

#include "tinyxmlspriterfiledocumentwrapper.h"

#include "tinyxmlspriterfileelementwrapper.h"

namespace SpriterEngine
{
	TinyXmlSpriterFileDocumentWrapper::TinyXmlSpriterFileDocumentWrapper()
	{
	}

	void TinyXmlSpriterFileDocumentWrapper::loadFile(std::string fileName)
	{
		tinyxml2::XMLError Error =  doc.LoadFile(fileName.c_str());

		if (Error == tinyxml2::XMLError::XML_ERROR_FILE_NOT_FOUND)
		{
			std::string Message = "XML Error: File not founded " + fileName;
		}
		else
		if (Error > 0)
		{
			std::string Message = "XML Error: " + std::to_string((int)Error);
		}
	}

	SpriterFileElementWrapper * TinyXmlSpriterFileDocumentWrapper::newElementWrapperFromFirstElement()
	{
		return new TinyXmlSpriterFileElementWrapper(doc.FirstChildElement());
	}

	SpriterFileElementWrapper * TinyXmlSpriterFileDocumentWrapper::newElementWrapperFromFirstElement(const std::string & elementName)
	{
		return new TinyXmlSpriterFileElementWrapper(doc.FirstChildElement(elementName.c_str()));
	}

}