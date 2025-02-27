 #include "Span.hpp"
 #include <random>

 int main (void)
 {
	Span span(150);

	std::random_device device;
	size_t seed = device();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int>distribution(0, 99);

	try {
		for (int i = 0; i < 150; i++)
		{
			int random = distribution(generator);
			span.addNumber(random);
		}
		span.printContainer();
		std::cout << "Shortest span between two numbers is " << span.shortestSpan() << std::endl;
		std::cout << "Longest span between two numbers is " << span.longestSpan() << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error. " << e.what() << std::endl;
	}

 }