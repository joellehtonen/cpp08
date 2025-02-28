#include "Span.hpp"

Span::Span() : _max(0) {
	std::cout << "Default Span constructor called\n";
};

Span::Span(unsigned int paramMax) : _max(paramMax) {
	std::cout << "Parametered Span constructor called\n";
};

Span::~Span() {
	std::cout << "Span destructor called\n";
};

Span::Span(const Span& copy) {
	std::cout << "Span copy constructor called\n";
	*this = copy;
};

Span& Span::operator=(const Span& copy) {
	if (this != &copy)
	{
		this->_max = copy._max;
	}
	std::cout << "Span copy assignment constructor called\n";
	return *this;
};	

void Span::addNumber(int number)
{
	if (_container.size() == _max)
		throw std::runtime_error("Cannot add new elements, the container is already full");
	else
		_container.push_back(number);
};

size_t Span::shortestSpan() {
	if  (_container.size() < 2)
		throw std::runtime_error("Too few numbers in the array");
	std::vector<int>::const_iterator shortest;
	std::vector<int> result(_container.size());

	std::sort(_container.begin(), _container.end());
	std::adjacent_difference(_container.begin(), _container.end(), result.begin());
	shortest = std::min_element(++result.begin(), result.end());
	return *shortest;
}

size_t Span::longestSpan() {
	if  (_container.size() < 2)
		throw std::runtime_error("Too few numbers in the array");
	std::sort(_container.begin(), _container.end());
	return (*--_container.end() - *_container.begin());
};
 
const int& Span::getContainerElement(const int& i) const
{
	return (this->_container[i]);
};

void Span::setContainerElement(const int& index, const int& newElement)
{
	this->_container[index] = newElement;
};

void Span::findLongestDigit()
{
	size_t maxLen = 0;
	for (std::vector<int>::const_iterator iter = _container.begin(); iter != _container.end(); iter++)
	{
		size_t len = std::to_string(*iter).length();
		if (len > maxLen)
			maxLen = len;
	}
	this->_longestDigit = maxLen;
}

void Span::printContainer()
{
	findLongestDigit();
	int newline = 0;
	const int longest = *std::max_element(_container.begin(), _container.end());
	const int shortest = *std::min_element(_container.begin(), _container.end());
	for (std::vector<int>::const_iterator iter = _container.begin(); iter != _container.end(); iter++)
	{
		if (newline % 10 == 0)
			std::cout << "\n";
		std::cout << " [ ";
		if (*iter == shortest)
			std::cout << BOLD << BLUE  << std::setw(_longestDigit) << *iter << RESET;
		else if (*iter == longest)
			std::cout << BOLD << GREEN << std::setw(_longestDigit) << *iter << RESET;
		else
			std::cout << std::setw(_longestDigit) << *iter;
		std::cout << " ] ";
		newline++;
	}
	std::cout << std::endl;
};

void Span::addRandomNumbers(int min, int max, size_t amount, bool unique)
{
	if (min >= max)
		throw std::runtime_error("Minimum number cannot be bigger than maximum number");
	std::random_device device;
	size_t seed = device();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int>distribution(min, max);

	for (size_t i = 0; i < amount; i++)
	{
		int random = distribution(generator);
		if (unique == true)
		{
			if (std::find(_container.begin(), _container.end(), random) == _container.end())
				addNumber(random);
			else
				i--;
		}
		else
			addNumber(random);
	}
};