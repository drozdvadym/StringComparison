#include "Levenshtein.h"

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
	size_t i, j;

	for (i = 0; i <= len1; ++i)
		mat.elem(i, 0) = i;

	for (i = 0; i <= len2; ++i)
		mat.elem(0, i) = i;

	mat.show();

	for (i = 1; i <= len1; ++i) {
		for (j = 1; j <= len2; ++j) {
			if (s1[i - 1] != s2[j - 1]) {
				mat.elem(i, j) = min3(
					mat.elem(i, j - 1),
					mat.elem(i - 1, j),
					mat.elem(i - 1, j - 1)
					);
				if (_T_lower(s1[i - 1]) == _T_lower(s2[j - 1]))
					mat.elem(i, j) += 0.5;
				else
					mat.elem(i, j)++;
			}
			else {
				mat.elem(i, j) = mat.elem(i - 1, j - 1);
			}
			mat.show();
		}
	}

	return mat.elem(len1, len2);
}