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

#ifndef PUGIXMLSPRITERFILEATTRIBUTEWRAPPER_H
#define PUGIXMLSPRITERFILEATTRIBUTEWRAPPER_H

#include "../pugixml/pugixml.hpp"

#include "../spriterengine/override/spriterfileattributewrapper.h"

namespace SpriterEngine
{
    class PugiXmlSpriterFileAttributeWrapper : public SpriterFileAttributeWrapper
    {
        typedef pugi::xml_attribute AttributePtr_t;

    public:
        PugiXmlSpriterFileAttributeWrapper(AttributePtr_t initialAttribute);

        std::string getName() override;

        bool isValid() override;

        real getRealValue() override;
        int getIntValue() override;
        std::string getStringValue() override;

        void advanceToNextAttribute() override;

    private:
        AttributePtr_t attribute;
    };

}

#endif // PUGIXMLSPRITERFILEATTRIBUTEWRAPPER_H
