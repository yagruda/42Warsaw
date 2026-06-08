#include "RPN.hpp"

int main(int argc, char **argv) 
{
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <RPN expression>" << std::endl;
        return 1;
    }
    
    RPN rpn;
    rpn.evaluate(argv[1]);

    // tester // 
    // rpn.evaluate("8 9 * 9 - 9 - 9 - 4 - 1 +"); // expects output 42 
    // rpn.evaluate("7 7 * 7 -"); // 42
    // rpn.evaluate("1 2 * 2 / 2 * 2 4 - +"); // 0
    // rpn.evaluate("(1 + 1)"); // error
    // rpn.evaluate("9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 - "); 
    // rpn.evaluate("1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 / ");
    // rpn.evaluate("8 9 * 9 - 9 - 9 - 4 - 1 +");

    return 0;
}
