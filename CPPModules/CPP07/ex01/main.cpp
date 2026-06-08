#include "iter.hpp"

void markov(int& n) {
    n += 1; 
    std::cout << "Markov function called, new value: " << n << std::endl;
}

int main() {
    int intArray[] = {12, 15, 3, 4, 5};
    size_t length = sizeof(intArray) / sizeof(intArray[0]);

    iter(intArray, length, markov);

    return 0;
}
