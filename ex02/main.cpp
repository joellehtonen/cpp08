#include "MutantStack.hpp"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define PURPLE "\033[35m"
#define CYAN "\033[36m"

int main(void)
{
	MutantStack<int> stackie;
	for (size_t i = 0; i < 10; i++)
	{
		stackie.push(i);
		std::cout << "pushing " << i << " to the stack\n";
	}
	std::cout << "the stack has " << stackie.size() << " elements in it\n";
	MutantStack<int>::const_iterator citb = stackie.cbegin();
	MutantStack<int>::const_iterator cite = stackie.cend();
	std::cout << GREEN << "printing contents using const iterators: \n";
	while (citb != cite)
		std::cout << *citb++ << '\n';
	MutantStack<int>::iterator itb = stackie.begin();
	MutantStack<int>::iterator ite = stackie.end();
	std::cout << BLUE << "printing and doubling contents using normal iterators \n";
	while (itb != ite)
	{
		*itb *= 2;
		std::cout << *itb++ << '\n';
	}
	MutantStack<int>::reverse_iterator ritb = stackie.rbegin(); //the last actual element
	MutantStack<int>::reverse_iterator rite = stackie.rend(); // the one before the first element
	std::cout << PURPLE << "printing doubled contents using reverse iterators: \n";
	while (ritb != rite)
		std::cout << *ritb++ << '\n';
		
}

// //from subject
// int main()
// {
// 	MutantStack<int> mstack;
// 	mstack.push(5);
// 	mstack.push(17);
// 	std::cout << mstack.top() << std::endl;
// 	mstack.pop();
// 	std::cout << mstack.size() << std::endl;
// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);
// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();
// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 	std::cout << *it << std::endl;
// 	++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return 0;
// }
