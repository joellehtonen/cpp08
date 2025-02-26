#include "easyfind.hpp"
#include <array>
#include <vector>
#include <stack>
#include <list>
#include <random>

int main(void)
{
	std::array<int, 5> intArray = {1, 2, 3, 4, 5};
	std::vector<int> test1 = {1, 3, 6};
	int i = 0;
	// for (int i = 0; i < test.size(); i++)
	// 	int t = test[i];
	for (int t : test1)
	{
		std::cout << "\n===ARRAY TEST #" << i++ << "===\n";
		std::cout << "Searching for " << t << "\n";
		try {
			easyfind(intArray, t);
		}
		catch (std::exception& e) {
			std::cout << "Error. " << e.what() << std::endl;
		};
	}

	std::vector<int> intVector = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3};
	std::vector<int> test2 = {1, 3};
	i = 0;
	for (int t : test2)
	{
		std::cout << "\n===VECTOR TEST #" << i++ << "===\n";
		std::cout << "Searching for " << t << "\n";
		try {
			easyfind(intVector, t);
		}
		catch (std::exception& e) {
			std::cout << "Error. " << e.what() << std::endl;
		};
	}

	std::list<int> intList;
	int l = 0;
	for (int i = 0; i < 100; i++)
	{
		intList.push_back(l);
		l  += 1;
	}
	int test3 = 33;
	i = 0;
	std::cout << "\n===LIST TEST #" << i++ << "===\n";
	std::cout << "Searching for " << test3 << "\n";
	try {
		easyfind(intList, test3);
	}
	catch (std::exception& e) {
		std::cout << "Error. " << e.what() << std::endl;
	};

	i = 0;
	std::deque<int> intDeque;
	std::random_device device;
	size_t toFind = 0;
	for (int i = 0; i < 20; i++)
	{
		size_t seed = device();
		intDeque.push_back(seed);
		if (seed % 10 == 0)
			toFind = seed;
	}
	std::cout << "\n===DEQUE TEST #" << i++ << "===\n";
	std::cout << "Searching for " << toFind << "\n";
	try {
		easyfind(intDeque, toFind);
	}
	catch (std::exception& e) {
		std::cout << "Error. " << e.what() << std::endl;
	};
}