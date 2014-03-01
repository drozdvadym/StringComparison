#pragma once

#include "Levenshtein.h"

#include <string>
#include <cctype>
#include <algorithm>

namespace StringComparison
{
    enum MODE { CASE_SENSITIVE, CASE_INSENSITIVE };

    template <typename _String_T>
    float getSimilarity(_String_T &s1, _String_T &s2, MODE mode = CASE_INSENSITIVE);


    template <typename _String_T>
    float getSimilarity(_String_T &s1, _String_T &s2, MODE mode)
    {
        _String_T lstr = s1;
        _String_T rstr = s2;

        if (mode == StringComparison::CASE_INSENSITIVE) {
            std::transform(lstr.begin(), lstr.end(), lstr.begin(), ::tolower);
            std::transform(rstr.begin(), rstr.end(), rstr.begin(), ::tolower);
        }

        float levenshtein = Levenshtein(lstr.c_str(), rstr.c_str());

        int maxLen = std::max(lstr.length(), rstr.length());
		
        return  (maxLen - levenshtein) / maxLen;
    }

}
