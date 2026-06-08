#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>


class RPN {
private:
    std::stack<int> _operands;
    
public:
    RPN();
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

    void evaluate(const std::string& expression);


};

#endif
