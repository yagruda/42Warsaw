#include "easyfind.hpp"
#include <vector>

int main() {

    try {
        std::vector<int> vec;
        vec.push_back(1);
        vec.push_back(2);
        vec.push_back(3);
        vec.push_back(4);
        vec.push_back(5);
        easyfind(vec, 4); // find the value
        easyfind(vec, 99); // throw an exception
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
