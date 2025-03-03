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
#include <cstdlib>
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"

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

		void		addNumber(int number);
		size_t		shortestSpan();
		size_t		longestSpan();
		const int&	getContainerElement(const int& i) const;
		void		setContainerElement(const int& index, const int& newElement);
		void		printContainer();
		void		addRandomNumbers(int min, int max, size_t amount, bool unique);

		template <typename T>
		void addRange(typename T::const_iterator begin, typename T::const_iterator end)
		{
			size_t distance = std::distance(begin, end);
			if (distance > this->_max - this->_container.size())
				throw std::runtime_error("Not enough space left for an insert");
			else
				_container.insert(_container.end(), begin, end);
		}
};