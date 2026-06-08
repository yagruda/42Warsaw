/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 13:54:17 by yhruda            #+#    #+#             */
/*   Updated: 2026/05/21 14:10:04 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Base* generate()
{
    int randomValue = std::rand() % 3;
    std::cout << "Generated random value: " << randomValue << std::endl;

    switch(randomValue)
    {
        case 0:
            return(new A());
        case 1:
            return(new B());
        case 2:
            return(new C());
        default:
            return nullptr;
            break;
    }
}

// dynamic_cast<T*>(ptr) on failure returns nullptr
void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
        std::cout << "Identified type: A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "Identified type: B" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "Identified type: C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

// dynamic_cast<T&>(ref) on failure throws std::bad_cast
// The pattern is: attempt cast if it doesn't throw, you've identified the type otherwise catch and try the next candidate.
void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Identified type: A" << std::endl;
    }
    catch (std::bad_cast&) {
        try {
            (void)dynamic_cast<B&>(p);
            std::cout << "Identified type: B" << std::endl;
        }
        catch (std::bad_cast&) {
            try {
                (void)dynamic_cast<C&>(p);
                std::cout << "Identified type: C" << std::endl;
            }
            catch (std::bad_cast&) {
                std::cout << "Unknown type" << std::endl;
            }
        }
    }
}

int main() {

    Base *base = generate();
    if (base == nullptr)
    {
        std::cerr << "Failed to generate a valid object." << std::endl;
        return 1;
    }

    identify(base);
    identify(*base);
    delete base;
    
    Base *invalidBase = nullptr;
    std::cout << "\nTesting with nullptr:" << std::endl;
    identify(invalidBase);
    // identify(*invalidBase); // This will cause a segmentation fault, so we won't call
    
    return 0;
}
