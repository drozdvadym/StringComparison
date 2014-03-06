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
// %% BeginSection: declarations
//

template <typename Type>
void test_similarity(Type s1, Type s2);

template <typename Type>
void printString(Type& s);

///////////////////////////////////////////////////////////////////////////////
// %% BeginSection: definitions
//

int main()
{
    //set unicode locale
    setlocale(LC_ALL, ""); 

    test_similarity(L"Корова", L"Корова");
    test_similarity(L"Корова", L"Кырова");
    test_similarity(L"Корова", L"Карова");
    test_similarity(L"Корова", L"Карафа");
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

    test_similarity("korova", "KOROVA");

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
// %% BeginSection: local definitions
//

template <typename Type>
void printString(Type &s)
{
    if (sizeof(wchar_t) == sizeof(s[0]))
        std::wcout << s;
    else
        std::cout << s;
}

template <typename Type>
void test_similarity(Type s1, Type s2)
{
    std::cout << "================================================\n";
    std::cout << "Test similarity of:\n";

    printString(s1);
    std::cout << " and ";
    printString(s2);
    std::cout << std::endl;

    float similarity = StringComparison::getSimilarity(
        s1, s2, StringComparison::CASE_SENSITIVE
    );

    std::cout << "Similarity is: " << similarity << std::endl;

}

//
//
//
