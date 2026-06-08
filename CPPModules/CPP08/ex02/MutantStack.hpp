#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>


template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack() {}
    MutantStack(const MutantStack &other) : std::stack<T>(other) {}

    MutantStack &operator=(const MutantStack &other) 
    {
        if (this != &other) {
            std::stack<T>::operator=(other); // Call the base class assignment operator
        }
        return *this;
    }
    ~MutantStack() {}

    // T can be different. container_type that will be used is also can be different
    // There deeper it depends on a type of T, but we can assume that it is a container that supports iterators (like vector, deque, list)
    // If it's not specified exactly container_type is usually deque by defult, but it can be different if we specify it in the template parameters of std::stack

    typename std::stack<T>::container_type::iterator begin() { return this->c.begin(); }
    typename std::stack<T>::container_type::iterator end()   { return this->c.end(); }

    typename std::stack<T>::container_type::const_iterator begin() const { return this->c.begin(); }
    typename std::stack<T>::container_type::const_iterator end()   const { return this->c.end(); }

};


#endif
