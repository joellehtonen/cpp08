#pragma once
#include <string>
#include <iostream>
#include <exception>
#include <algorithm>
#include <array>
#include <vector>
#include <iterator>
#define RESET "\033[0m"
#define GREEN "\033[32m"

template <typename T>
void printContainer(const T& container, typename T::const_iterator it)
{
	for (size_t i = 0; i < container.size(); i++)
	{
		for (int j = 0; j < 5; j++)
		{
			std::cout << " [ ";
			if (std::next(container.begin(), i) == it)
				std::cout << GREEN << container[i] << RESET;
			else
				std::cout << container[i];
			std::cout << " ] ";
			i++;
		}
		std::cout << "\n";
	}
};

template <typename T>
auto easyfind(const T& haystack, const int& needle)
{
	auto it = std::find(haystack.begin(), haystack.end(), needle);
	if (it == haystack.end())
		throw std::runtime_error("Integer not found");
	else
	{
		printContainer(haystack, it);
		return it;
	}
};