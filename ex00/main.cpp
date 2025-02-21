#include "easyfind.hpp"

int main(void)
{
	std::array<int, 5> intArr = {1, 2, 3, 4, 5};
	try {
		std::cout << "\n===ARRAY TEST #1==\n";
		easyfind(intArr, 3);
		std::cout << "\n===ARRAY TEST #2==\n";
		easyfind(intArr, 6);
	}
	catch (std::exception& e) {
		std::cout << "Error. " << e.what() << std::endl;
	};
}