#include "PmergeMe.hpp"
#include <sstream>
#include <stdexcept>
#include <iomanip>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) { *this = other; }
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

void PmergeMe::parse(int argc, char** argv) {
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];
        
        // Handle cases like "3 5 9 7 4" as a single argument
        std::istringstream iss(arg);
        std::string token;
        while (iss >> token) {
            std::istringstream tokenStream(token);
            long val;
            tokenStream >> val;
            if (tokenStream.fail() || !tokenStream.eof()) {
                throw std::invalid_argument("Error");
            }
            if (val <= 0 || val > 2147483647) {
                throw std::invalid_argument("Error");
            }
            _vec.push_back(static_cast<int>(val));
            _deq.push_back(static_cast<int>(val));
        }
    }
    if (_vec.empty()) {
        throw std::invalid_argument("Error");
    }
}

void PmergeMe::printSequence(const std::string& prefix, const std::vector<int>& seq) {
    std::cout << prefix;
    size_t count = 0;
    for (std::vector<int>::const_iterator it = seq.begin(); it != seq.end(); ++it) {
        if (count == 4 && seq.size() > 5) {
            std::cout << "[...]";
            break;
        }
        std::cout << *it << " ";
        count++;
    }
    std::cout << std::endl;
}

std::vector<size_t> PmergeMe::build_jacobsthal(size_t max_val) {
    std::vector<size_t> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    size_t last = 1;
    size_t prev = 0;
    while (true) {
        size_t next = last + 2 * prev;
        jacob.push_back(next);
        prev = last;
        last = next;
        if (next >= max_val) break;
    }
    return jacob;
}

void PmergeMe::sortVector(std::vector<int>& arr) {
    if (arr.size() < 2) return;

    bool has_strag = arr.size() % 2 != 0;
    int strag = -1;
    if (has_strag) {
        strag = arr.back();
        arr.pop_back();
    }

    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i+1])
            pairs.push_back(std::make_pair(arr[i], arr[i+1]));
        else
            pairs.push_back(std::make_pair(arr[i+1], arr[i]));
    }

    std::vector<int> larger;
    for (size_t i = 0; i < pairs.size(); ++i) {
        larger.push_back(pairs[i].first);
    }

    sortVector(larger);

    std::vector<int> pend;
    for (size_t i = 0; i < larger.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (pairs[j].first == larger[i]) {
                pend.push_back(pairs[j].second);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    std::vector<int> S;
    S.push_back(pend[0]);
    for (size_t i = 0; i < larger.size(); ++i) {
        S.push_back(larger[i]);
    }

    std::vector<size_t> jacob = build_jacobsthal(pend.size());
    size_t last_jacob = 1; 
    for (size_t i = 3; i < jacob.size(); ++i) {
        size_t current_jacob = jacob[i];
        size_t max_idx = current_jacob - 1;
        if (max_idx >= pend.size()) max_idx = pend.size() - 1;

        for (size_t j = max_idx; j > last_jacob - 1; --j) {
            std::vector<int>::iterator it = std::lower_bound(S.begin(), S.end(), pend[j]);
            S.insert(it, pend[j]);
        }
        last_jacob = current_jacob;
    }

    if (has_strag) {
        std::vector<int>::iterator it = std::lower_bound(S.begin(), S.end(), strag);
        S.insert(it, strag);
    }

    arr = S;
}

void PmergeMe::sortDeque(std::deque<int>& arr) {
    if (arr.size() < 2) return;

    bool has_strag = arr.size() % 2 != 0;
    int strag = -1;
    if (has_strag) {
        strag = arr.back();
        arr.pop_back();
    }

    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i < arr.size(); i += 2) {
        if (arr[i] > arr[i+1])
            pairs.push_back(std::make_pair(arr[i], arr[i+1]));
        else
            pairs.push_back(std::make_pair(arr[i+1], arr[i]));
    }

    std::deque<int> larger;
    for (size_t i = 0; i < pairs.size(); ++i) {
        larger.push_back(pairs[i].first);
    }

    sortDeque(larger);

    std::deque<int> pend;
    for (size_t i = 0; i < larger.size(); ++i) {
        for (size_t j = 0; j < pairs.size(); ++j) {
            if (pairs[j].first == larger[i]) {
                pend.push_back(pairs[j].second);
                pairs.erase(pairs.begin() + j);
                break;
            }
        }
    }

    std::deque<int> S;
    S.push_back(pend[0]);
    for (size_t i = 0; i < larger.size(); ++i) {
        S.push_back(larger[i]);
    }

    std::vector<size_t> jacob = build_jacobsthal(pend.size());
    size_t last_jacob = 1; 
    for (size_t i = 3; i < jacob.size(); ++i) {
        size_t current_jacob = jacob[i];
        size_t max_idx = current_jacob - 1;
        if (max_idx >= pend.size()) max_idx = pend.size() - 1;

        for (size_t j = max_idx; j > last_jacob - 1; --j) {
            std::deque<int>::iterator it = std::lower_bound(S.begin(), S.end(), pend[j]);
            S.insert(it, pend[j]);
        }
        last_jacob = current_jacob;
    }

    if (has_strag) {
        std::deque<int>::iterator it = std::lower_bound(S.begin(), S.end(), strag);
        S.insert(it, strag);
    }

    arr = S;
}

void PmergeMe::sort() {
    printSequence("Before: ", _vec);

    struct timeval start, end;

    gettimeofday(&start, NULL);
    sortVector(_vec);
    gettimeofday(&end, NULL);
    double time_vec = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    gettimeofday(&start, NULL);
    sortDeque(_deq);
    gettimeofday(&end, NULL);
    double time_deq = (end.tv_sec - start.tv_sec) * 1000000.0 + (end.tv_usec - start.tv_usec);

    printSequence("After:  ", _vec);

    std::cout << "Time to process a range of " << _vec.size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(5) << time_vec << " us" << std::endl;
    std::cout << "Time to process a range of " << _deq.size() 
              << " elements with std::deque  : " << std::fixed << std::setprecision(5) << time_deq << " us" << std::endl;
}
