
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Description
    Main source file of FactoryImplementation program. 
    Each RuntimeSelectable abstract class Defines its own Factory

\************************************************************************/
#include <iostream>
#include <iomanip>
#include <memory>
#include <vector>

#include "Base.hpp"
#include "Derived.hpp"
#include "DDerived.hpp"

int main() 
{
    std::cout<<"---Start of Main---"<<'\n';

    std::cout<<'\n';

    {
        std::cout<<"--creating Derived from default constructor"<<'\n';
        BasePtr basePtr = Derived::create();
        basePtr->whoAmI();
    }

    std::cout<<'\n';

    {
        std::cout<<"--creating DDerived from arbitrary constructor"<<'\n';
        BasePtr basePtr = DDerived::create("str");
        basePtr->whoAmI();
    }

    std::string type="";
    while (type!="q")
    {
        std::cout<<'\n';

        std::cout<<"--Give Derived type::";
        std::cin>>type;
        //Create Object of Base from Derived type name
        BasePtr tmp = Base::polymorficCreate(type, "string");
        if (tmp) {
            tmp->whoAmI();
            std::cout<<'\n';

            //Clonable?
            // try Derived:public PolymorphicInheritance<Base,Derived>
            std::cout<<"making clone::\n";
            BasePtr clone = tmp->clone();
            clone->whoAmI();
            std::cout<<'\n';
        }
    }

    std::cout<<"---End of Main---"<<'\n';
    return 0;
}
