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

#include "pugixmlspriterfileelementwrapper.h"

#include "pugixmlspriterfileattributewrapper.h"

namespace SpriterEngine
{
    PugiXmlSpriterFileElementWrapper::PugiXmlSpriterFileElementWrapper(ElementPtr_t initialElement):
        element(initialElement)
    {
    }

    std::string PugiXmlSpriterFileElementWrapper::getName()
    {
        return element.name();
    }

    bool PugiXmlSpriterFileElementWrapper::isValid()
    {
        return element;
    }

    void PugiXmlSpriterFileElementWrapper::advanceToNextSiblingElement()
    {
        element = element.next_sibling();
    }

    void PugiXmlSpriterFileElementWrapper::advanceToNextSiblingElementOfSameName()
    {
        element = element.next_sibling(element.name());
    }

    SpriterFileAttributeWrapper * PugiXmlSpriterFileElementWrapper::newAttributeWrapperFromFirstAttribute()
    {
        return new PugiXmlSpriterFileAttributeWrapper(element.first_attribute());
    }

    SpriterFileAttributeWrapper * PugiXmlSpriterFileElementWrapper::newAttributeWrapperFromFirstAttribute(const std::string & attributeName)
    {
        return new PugiXmlSpriterFileAttributeWrapper(element.attribute(attributeName.c_str()));
    }

    SpriterFileElementWrapper * PugiXmlSpriterFileElementWrapper::newElementWrapperFromFirstElement()
    {
        return new PugiXmlSpriterFileElementWrapper(element.first_child());
    }

    SpriterFileElementWrapper * PugiXmlSpriterFileElementWrapper::newElementWrapperFromFirstElement(const std::string & elementName)
    {
        return new PugiXmlSpriterFileElementWrapper(element.child(elementName.c_str()));
    }

    SpriterFileElementWrapper * PugiXmlSpriterFileElementWrapper::newElementWrapperFromNextSiblingElement()
    {
        return new PugiXmlSpriterFileElementWrapper(element.next_sibling(element.name()));
    }

    SpriterFileElementWrapper * PugiXmlSpriterFileElementWrapper::newElementClone()
    {
        return new PugiXmlSpriterFileElementWrapper(element);
    }

    PugiXmlSpriterFileElementWrapper::AttributePtr_t PugiXmlSpriterFileElementWrapper::findAttributeInElement(const std::string & name)
    {
        return element.attribute(name.c_str());
    }

}
