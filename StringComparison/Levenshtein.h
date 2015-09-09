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
// Get modified Levenshtein distance for two strings
// this distance depends on symbol register and phonetic group 
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
// Get phonetic group for symbol
// NOTE!!! now support only russian wide char symbols
//

wchar_t GetMetaphone(wchar_t wsym);
char GetMetaphone(char sym);

//
//
//
