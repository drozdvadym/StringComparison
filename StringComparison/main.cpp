//
// -*- Mode: c++; tab-width: 4; -*-
// -*- ex: ts=4 -*-
//

//
// main.cpp	(V. Drozd)
// StringComparison/main.cpp
//

//
// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
// EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A PARTICULAR PURPOSE.
//

///////////////////////////////////////////////////////////////////////////////
// %% BeginSection: includes
//

#include "StringComparison.h"
#include <iostream>

#ifdef _WIN32
# include <Windows.h>
#endif

///////////////////////////////////////////////////////////////////////////////
// %% BeginSection: declarations
//

template <typename Type>
void TestSimilarity(Type s1, Type s2);

///////////////////////////////////////////////////////////////////////////////
// %% BeginSection: definitions
//

int main() {
    //set unicode locale
    setlocale(LC_ALL, ""); 
	setlocale(LC_ALL, "Russian");
	SetConsoleOutputCP(866);

    TestSimilarity(L"Корова", L"Корова");
    TestSimilarity(L"Корова", L"Кырова");
    TestSimilarity(L"Корова", L"Карова");
    TestSimilarity(L"Корова", L"Карафа");
    TestSimilarity(L"Корова", L"КАрова");
    TestSimilarity(L"Корова", L"КоровА");
    TestSimilarity(L"Корова", L"КороВА");
    TestSimilarity(L"Корова", L"Коро1А");
    TestSimilarity(L"Корова", L"Коров");
    TestSimilarity(L"Корова", L"К");
    TestSimilarity(L"Корова", L"КОРОВА");
    TestSimilarity(L"Корова", L"123345");
    TestSimilarity(L"Корова", L"окорав");
    TestSimilarity(L"Корова", L"ОКОРАВ");
    TestSimilarity(L"Корова", L"кОРОВА");
    TestSimilarity(L"Корова", L"KOROVA");

    TestSimilarity("korova", "KOROVA");

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
// %% BeginSection: local definitions
//

template <typename Type>
void TestSimilarity(Type s1, Type s2) {
    std::cout << "================================================\n";
    std::cout << "Test similarity of:\n";

    std::wcout << s1 << L" and " << s2 << std::endl;

    float similarity = StringComparison::GetSimilarity(s1, s2,
		StringComparison::CASE_SENSITIVE);

    std::cout << "Similarity is: " << similarity << std::endl;
}

//
//
//
