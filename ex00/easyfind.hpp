#pragma once
#include <string>
#include <iostream>
#include <exception>
#include <algorithm>
#include <iterator>
#include <iomanip>
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[32m"
#define RED "\033[31m"

template <typename T>
void printContainer(const T& container, typename T::const_iterator ref, size_t maxLen)
{
	int newline = 0;
	for (typename T::const_iterator iter = container.begin(); iter != container.end(); iter++)
	{
		if (newline % 5 == 0)
			std::cout << "\n";
		std::cout << " [ ";
		if (iter == ref)
			std::cout << BOLD << GREEN << std::setw(maxLen) << *iter << RESET;
		else
			std::cout << std::setw(maxLen) << *iter;
		std::cout << " ] ";
		newline++;
	}
	std::cout << std::endl;
};

template <typename T>
size_t findDigitLen (const T& container)
{
	size_t maxLen = 0;
	for (typename T::const_iterator iter = container.begin(); iter != container.end(); iter++)
	{
		size_t len = std::to_string(*iter).length();
		if (len > maxLen)
			maxLen = len;
	}
	return maxLen;
}

template <typename T>
typename T::const_iterator easyfind(const T& haystack, const int& needle)
{
	typename T::const_iterator it;
	it = std::find(haystack.begin(), haystack.end(), needle);
	if (it == haystack.end())
	{
		size_t maxLen = findDigitLen(haystack);
		printContainer(haystack, it, maxLen);
		throw std::runtime_error("Integer not found");
	}
	else
	{
		std::cout << "Integer found";
		size_t maxLen = findDigitLen(haystack);
		printContainer(haystack, it, maxLen);
		return it;
	}
};