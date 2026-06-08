#include "Span.hpp"

int main()
{
    try {
        
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;

        // Trigger overflow exception
        try {
            sp.addNumber(42);
        } catch (std::exception &e) {
            std::cout << "Expected exception: " << e.what() << std::endl;
        }

        Span big(10001);
        srand(time(0)); // Seed for random number generation
        for (int i = 0; i < 10001; ++i)
            big.addNumber(std::rand());

        std::cout << "Big shortest span: " << big.shortestSpan() << std::endl;
        std::cout << "Big longest span: " << big.longestSpan() << std::endl;

    } catch (std::exception &e) {
        std::cerr << "Test failed: " << e.what() << std::endl;
        return 1;
    }

    Span testSpan(5);
    std::vector<int> myVec;
    myVec.push_back(1);
    myVec.push_back(2);
    myVec.push_back(3);
    myVec.push_back(4);
    myVec.push_back(5);
    testSpan.addNumbers(myVec.begin(), myVec.end());

    return 0;
}