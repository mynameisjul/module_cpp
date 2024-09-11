#include <iostream>
#include <list>
#include "MutantStack.hpp"

int main()
{
	{
		std::cout << "With MutantStack" << std::endl;
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << std::endl;
	{
		std::cout << "With list" << std::endl;
		std::list<int> thelist;

		thelist.push_back(5);
		thelist.push_back(17);

		std::cout << thelist.back() << std::endl;
		thelist.pop_back();
		std::cout << thelist.size() << std::endl;
		thelist.push_back(3);
		thelist.push_back(5);
		thelist.push_back(737);
		//[...]
		thelist.push_back(0);
		std::list<int>::iterator it = thelist.begin();
		std::list<int>::iterator ite = thelist.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(thelist);
	}
	return 0;
}