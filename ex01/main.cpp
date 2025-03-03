#include "Span.hpp"

int main (void)
{
	Span span(10000);

	try {
		//span.addRandomNumbers(1, 9, 3, true);
		// span.addRandomNumbers(1, 99, 10, true);
		span.addRandomNumbers(INT_MIN, INT_MAX, 10000, true);
		// std::vector<int> anotherArray;
		// span.addRange<std::vector<int>>(anotherArray.begin(), anotherArray.end());
		// anotherArray.push_back(1);
		// anotherArray.push_back(2);
		// anotherArray.push_back(3);
		std::cout << "Unsorted container: \n";
		span.printContainer();
		std::cout << "Shortest span between two numbers is " << span.shortestSpan() << '\n';
		std::cout << "Longest span between two numbers is " << span.longestSpan() << '\n';
		std::cout << "Sorted container: \n";
		span.printContainer();
	}
	catch (std::exception &e) {
		std::cerr << "Error. " << e.what() << std::endl;
	}
}



// int main()
// {
// 	Span sp = Span(5);
// 	sp.addNumber(6);
// 	sp.addNumber(3);
// 	sp.addNumber(17);
// 	sp.addNumber(9);
// 	sp.addNumber(11);
// 	std::cout << sp.shortestSpan() << std::endl;
// 	std::cout << sp.longestSpan() << std::endl;
// }