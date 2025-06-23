#include "MutantStack.hpp"
#include <iostream>
#include <vector>

int main(){
    std::cout << "========== MUTANT STACK ==========" << std::endl;

	MutantStack<int, std::vector<int> > mstack;
	mstack.push(5); // 5
	mstack.push(17); // 17, 5
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop(); // 5
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3); // 3, 5
	mstack.push(7); // 7, 3, 5
	mstack.push(737); // 737, 7, 3, 5
	mstack.push(0); // 0, 737, 7, 3, 5
	std::cout << "Size: " << mstack.size() << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << std::endl << "ITERATE STACK:" << std::endl;
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	// std::stack<int> s(mstack); //*OK
    // std::stack<int, std::deque<int> > deq;
    // deq.push(10);
    // mstack = deq; //!NOT OK - diff container types
    // std::cout << std::endl << *(mstack.begin()) << std::endl;

	std::cout << "========== VECTOR ==========" << std::endl;
	
	std::vector<int> ls;
	ls.push_back(5);
	ls.push_back(17);
	std::cout << "Back: " << ls.back() << std::endl;
	ls.pop_back();
	std::cout << "Size: " << ls.size() << std::endl;
	ls.push_back(3);
	ls.push_back(7);
	ls.push_back(737);
	ls.push_back(0);
	std::cout << "Size: " << ls.size() << std::endl;
	std::vector<int>::iterator lit = ls.begin();
	std::vector<int>::iterator lite = ls.end();
	++lit;
	--lit;
	std::cout << std::endl << "ITERATE VECTOR:" << std::endl;
	while (lit != lite) {
		std::cout << *lit << std::endl;
		++lit;
	}
}