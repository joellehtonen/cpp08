#include <stack>
#include <string>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() { };
		~MutantStack() { };
		MutantStack(const MutantStack& copy) { };
		MutantStack& operator=(const MutantStack& cop) { return *this; };

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

		iterator begin() { return this->c.begin(); };
		iterator end() { return this->c.end(); };

		reverse_iterator rbegin() { return this->c.rbegin(); };
		reverse_iterator rend() { return this->c.rend(); };

		const_iterator cbegin() const { return this->c.cbegin(); };
		const_iterator cend() const { return this->c.cend(); };

		const_reverse_iterator crbegin() const { return this->c.crbegin(); };
		const_reverse_iterator crend() const { return this->c.crend(); };
};