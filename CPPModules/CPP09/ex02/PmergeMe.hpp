#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <sys/time.h>

class PmergeMe {
private:
    std::vector<int> _vec;
    std::deque<int> _deq;

    std::vector<size_t> build_jacobsthal(size_t max_val);

    void sortVector(std::vector<int>& arr);
    void sortDeque(std::deque<int>& arr);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void parse(int argc, char** argv);
    void sort();
    void printSequence(const std::string& prefix, const std::vector<int>& seq);
};

#endif
