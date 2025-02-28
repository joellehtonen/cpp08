#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <numeric>
#include <iterator>
#include <iomanip>
#include <algorithm>
#include <random>
#include <climits>
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"

//TODO check if works with int max and int min
//TODO check if works with small ranges (1-3)

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
		void	addRandomNumbers(int min, int max, size_t amount, bool unique);

		const int&	getContainerElement(const int& i) const;
		void		setContainerElement(const int& index, const int& newElement);

};