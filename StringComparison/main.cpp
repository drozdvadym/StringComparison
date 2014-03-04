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

#include <Windows.h>

///////////////////////////////////////////////////////////////////////////////
// %% BeginSection: definitions
//

void test_similarity(const std::wstring &s1, const std::wstring &s2)
{
    std::cout << "================================================\n";
    std::cout << "Test similarity of:\n";

    std::wcout << s1 << L" and " <<s2 << std::endl;

    float similarity = StringComparison::getSimilarity(
        s1, s2, StringComparison::CASE_SENSITIVE
    );

    std::cout << "Similarity is: " << similarity << std::endl;

}

int main()
{
    //set unicode locale
    setlocale(LC_ALL, ""); 

    test_similarity(L"Корова", L"Корова");
    test_similarity(L"Корова", L"Кырова");
    test_similarity(L"Корова", L"Карова");
    test_similarity(L"Корова", L"КАрова");
    test_similarity(L"Корова", L"КоровА");
    test_similarity(L"Корова", L"КороВА");
    test_similarity(L"Корова", L"Коро1А");
    test_similarity(L"Корова", L"Коров");
    test_similarity(L"Корова", L"К");
    test_similarity(L"Корова", L"КОРОВА");
    test_similarity(L"Корова", L"123345");
    test_similarity(L"Корова", L"окорав");
    test_similarity(L"Корова", L"ОКОРАВ");
    test_similarity(L"Корова", L"кОРОВА");
    test_similarity(L"Корова", L"KOROVA");
    test_similarity(L"korova", L"KOROVA");

    return 0;
}

//
//
//
