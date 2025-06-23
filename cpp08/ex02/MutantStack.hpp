#pragma once
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack: public std::stack<T>
{
public:
    MutantStack(){};
    ~MutantStack(){};
    MutantStack(const MutantStack& other): std::stack<T, Container>(other){};
    MutantStack&    operator=(const MutantStack& other)
    {
        if (this != &other)
            this->std::stack<T, Container>::operator=(other);
        return *this;
    };

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator    begin(){return this->c.begin();};
    iterator    end(){return this->c.end();};
};

 //c = Container (in this->c.begin())
 //(accessible only bcs we build on top of stack)
 // c - protected in stack (the container on which stack - which is and adapter of (deque(default), list or vector) is built).
 //c in MutantStack is private.