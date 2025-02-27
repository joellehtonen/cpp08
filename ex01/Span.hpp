#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
#include <iomanip>
#include <algorithm>
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"

class Span
{
	private:
		unsigned int 		_max;
		std::vector<int>	_container;
		size_t				_longestDigit;

		void				findLongestDigit();

	public:
		Span();
		Span(unsigned int paramMax);
		~Span();
		Span(const Span& copy);
		Span& operator=(const Span& copy);

		void	addNumber(int number);
		size_t	shortestSpan();
		size_t	longestSpan();

		void	printContainer();

		const int&	getContainerElement(const int& i) const;
		void		setContainerElement(const int& index, const int& newElement);
};