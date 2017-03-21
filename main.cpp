//
//  main.cpp
//  CRTPComparable
//
//  Created by Udit Anand on 3/19/17.
//  Copyright © 2017 Udit Anand. All rights reserved.
//

#include <iostream>
#include "Comparable.hpp"

int main(int argc, const char * argv[]) {
    
    Person p1;
    Person p2;
    
    p1.size = 9;
    p2.size = 10;
    
    if (p1 == p2)
    {
        std::cout << "Equality operation." << std::endl;
    }
    
    if (p1 != p2)
    {
        std::cout << "InEquality operation." << std::endl;
    }
    
    if (p1 > p2)
    {
        std::cout << "Greater than operation." << std::endl;
    }
    
    if (p1 < p2)
    {
        std::cout << "Less than operation." << std::endl;
    }
    
    if (p1 <= p2)
    {
        std::cout << "Less than equal to operation." << std::endl;
    }
    
    if (p1 >= p2)
    {
        std::cout << "Greater than equal to operation." << std::endl;
    }
    
    return 0;
}
