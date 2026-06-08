#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <list>
#include <deque>
#include <limits>
#include <cstdlib>

class Span {
private:
    unsigned int _N; // maximum number of elements
    std::vector<int> _container;    
public:

    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    long int shortestSpan() const;
    long int longestSpan() const;
    void addNumber(int number);

    template <typename InputIterator>
    void addNumbers(InputIterator begin, InputIterator end);
};

// as a template it must be visible in the header file, so we define it here
template <typename InputIterator>
void Span::addNumbers(InputIterator begin, InputIterator end)
{
    for (InputIterator it = begin; it != end; ++it)
    {
        addNumber(*it);
    }
}


#endif
