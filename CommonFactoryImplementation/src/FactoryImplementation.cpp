
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Description
    Main source file of FactoryImplementation program. 
    All RuntimeSelectable abstract classes use common Factory

\************************************************************************/
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>

#include "Create.hpp"

#include "FamilyA.hpp"
#include "FamilyB.hpp"

int main() 
{
    std::cout<<"---Start of Main---"<<std::endl;

    std::string familyAName = "Boys";
    //std::string familyBName = "Girls"; //not used

    std::string type="";
    while (type!="q")
    {
        std::cout<<std::endl<<"Give FamilyA type::";
        std::cin>>type;
        //Create Object of FamilyA using a constructor with arbitrary arguments
        FamilyAPtr tmpA = Create::Abstract<FamilyA>(type, FamilyA::ConstructorArgs{familyAName});
        if (tmpA) tmpA->whoAmI();
    }

    type="";
    while (type!="q")
    {
        std::cout<<std::endl<<"Give FamilyB type::";
        std::cin>>type;
        //Create Object of FamilyB using the default constructor
        FamilyBPtr tmpB = Create::Abstract<FamilyB>(type);
        if (tmpB) tmpB->whoAmI();
    }

    std::cout<<"---End of Main---"<<std::endl;
    return 0;
}
