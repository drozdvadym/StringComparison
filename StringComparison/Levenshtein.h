#pragma once

#include "Vector2D.h"
#include <algorithm>

#include <cstring>
#include <cctype>

/*
 * Declarations
 */

template <typename _Str_T>
float Levenshtein(_Str_T *s1, _Str_T *s2);

/*
 * Definitions
 */

inline char _T_lower(char c)
{
	return ::tolower(c);
}

inline wchar_t _T_lower(const wchar_t wc)
{
	return ::towlower(wc);
}

inline size_t _T_slen(const char *s)
{
	return strlen(s);
}

inline size_t _T_slen(const wchar_t *ws)
{
	return wcslen(ws);
}

template <typename _Str_T>
float Levenshtein(_Str_T *s1, _Str_T *s2)
{
	size_t len1 = _T_slen(s1);
	size_t len2 = _T_slen(s2);

	if (!len1 || !len2) {
		return std::max(len1, len2);
		//NOTREACHED
	}

	Vector2D<float> mat(len1 + 1, len2 + 1);

	for (size_t i = 0; i <= len1; ++i)
		mat.elem(i, 0) = i;

	for (size_t i = 0; i <= len2; ++i)
		mat.elem(0, i) = i;

#ifdef _DBG_LEVENSTEIN
	mat.show();
#endif
	
	for (size_t i = 1; i <= len1; ++i) {
		for (size_t j = 1; j <= len2; ++j) {
			if (s1[i - 1] != s2[j - 1]) {
				mat.elem(i, j) = std::min(
					std::min(mat.elem(i, j - 1), mat.elem(i - 1, j)),
					mat.elem(i - 1, j - 1)
				);

				mat.elem(i, j)++;
				//Correct if we have same symbol but different case
				if (_T_lower(s1[i - 1]) == _T_lower(s2[j - 1]))
					mat.elem(i, j) -= 0.5;
			}
			else {
				mat.elem(i, j) = mat.elem(i - 1, j - 1);
			}
#ifdef _DBG_LEVENSTEIN
			mat.show();
#endif
		}
	}

	return mat.elem(len1, len2);
}