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

#include "com_libspritergm_spriterGMNative.h"
#include "spriterGM.h"

void GetJStringContent(JNIEnv *AEnv, jstring AStr, std::string &ARes) {
    if (!AStr) {
        ARes.clear();
        return;
    }

    const char *s = AEnv->GetStringUTFChars(AStr,NULL);
    ARes=s;
    AEnv->ReleaseStringUTFChars(AStr,s);
}

JNIEXPORT jdouble JNICALL Java_com_libspritergm_spriterGMNative_spriter_1LoadModel
		(JNIEnv *env, jclass object, jstring filePath)
{
    std::string str;
    GetJStringContent(env, filePath, str);
    double result = (double)CSpriterGM::GetSingleton()->LoadModel(str.c_str());

    if (CSpriterGM::GetSingleton()->GetNumErrors() > 0)
        result = -1.0;;

    return  result;
}






