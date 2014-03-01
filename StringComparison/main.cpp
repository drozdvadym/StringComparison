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

	test_similarity(L"������", L"������");
	test_similarity(L"������", L"������");
	test_similarity(L"������", L"������");
	test_similarity(L"������", L"����1�");
	test_similarity(L"������", L"�����");
	test_similarity(L"������", L"�");
	test_similarity(L"������", L"������");
	test_similarity(L"������", L"123345");
	test_similarity(L"������", L"������");
	test_similarity(L"������", L"������");
	test_similarity(L"������", L"������");
	test_similarity(L"������", L"KOROVA");
	test_similarity(L"korova", L"KOROVA");

	return 0;
}

