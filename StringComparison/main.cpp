#define _CRT_SECURE_NO_WARNINGS


#include "StringComparison.h"
#include <iostream>
#include <string>

# include <Windows.h>


void test_similarity(std::wstring s1, std::wstring s2)
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

