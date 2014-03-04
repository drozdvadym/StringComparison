//
// -*- Mode: c++; tab-width: 4; -*-
// -*- ex: ts=4 -*-
//

//
// StringComparison.h	(V. Drozd)
// StringComparison/StringComparison.h
//

//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
//

///////////////////////////////////////////////////////////////////////////////
// %% BeginSection: includes
//

#pragma once

#include "Levenshtein.h"

#include <string>
#include <cctype>
#include <algorithm>

///////////////////////////////////////////////////////////////////////////////
// %% BeginSection: type definition
//

namespace StringComparison
{
    enum MODE { CASE_SENSITIVE, CASE_INSENSITIVE };

    template <class Type>
    class ToLowerFunctor
    {
    public:
        Type operator ( ) (Type& elem) const
        {
            return _T_lower(elem);
        }
    };

    template <typename _String_T>
    float getSimilarity(_String_T &s1, _String_T &s2, MODE mode = CASE_SENSITIVE)
    {
        auto lstr = s1;
        auto rstr = s2;

        using SymType = typename std::remove_reference<decltype(lstr[0])>::type;

        if (CASE_INSENSITIVE == mode) {
            std::transform(lstr.begin(), lstr.end(), lstr.begin(), ToLowerFunctor<SymType>());
            std::transform(rstr.begin(), rstr.end(), rstr.begin(), ToLowerFunctor<SymType>());
        }

        float levenshtein = Levenshtein(lstr.c_str(), rstr.c_str());

        int maxLen = std::max(lstr.length(), rstr.length());

        return (maxLen - levenshtein) / maxLen;
    }

}

//
//
//
