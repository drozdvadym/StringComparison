//
// -*- Mode: c++; tab-width: 4; -*-
// -*- ex: ts=4 -*-
//

//
// Levenshtein.h	(V. Drozd)
// StringComparison/Levenshtein.h
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

#include <cctype>
#include <cwctype>
#include <cwchar>
#include <cstring>

///////////////////////////////////////////////////////////////////////////////
// %% BeginSection: declarations
//


//
// Get modified Levenshtein distance for to strings
// this distance depends of symbol register and phonetic group 
//
// available _Str_T types:
//  - char
//  - const char
//  - wchar_t
//  - const wchar_t
//

template <typename _Str_T>
float Levenshtein(_Str_T* s1, _Str_T* s2);

//
// Get  phonetic group for symbol
// NOTE!!! now support only russian wide char symbols
//

wchar_t getMetaphone(wchar_t wsym);

///////////////////////////////////////////////////////////////////////////////
// %% BeginSection: inline function
//

inline char _T_lower(char c)
{
    return std::tolower(c);
}

inline wchar_t _T_lower(const wchar_t wc)
{
    return std::towlower(wc);
}

inline size_t _T_slen(const char *s)
{
    return std::strlen(s);
}

inline size_t _T_slen(const wchar_t *ws)
{
    return std::wcslen(ws);
}

//
//
//
