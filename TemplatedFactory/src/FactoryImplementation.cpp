
/*************************************************************************\
License
    Copyright (c) 2018 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Description
    Main source file of FactoryImplementation program. 
    Each RuntimeSelectable object has access to templated creation functions.
    To use them, each derived object has to include an instantiation of
    the AddToRegistry class which builds a factory map.
    Each derived object has to implement its own clone function.

\************************************************************************/
#include <iostream>

#include "CreateFunctions.hpp"
#include "Base.hpp"
#include "Derived.hpp"
#include "DDerived.hpp"

int main() 
{
    std::cout<<"---Start of Main---"<<'\n';

    std::cout<<'\n';

    {
        std::cout<<"--creating Derived from default constructor"<<'\n';
        BasePtr basePtr = create<Derived>();
        basePtr->whoAmI();
    }

    std::cout<<'\n';

    {
        std::cout<<"--creating DDerived from arbitrary constructor"<<'\n';
        BasePtr basePtr = create<DDerived>("str");
        basePtr->whoAmI();
    }

    std::string type="";
    while (type!="q")
    {
        std::cout<<'\n';

        std::cout<<"--Give Derived type::";
        std::cin>>type;
        //Create Object of Base from Derived type name and an arbitrary
        //constructor defined in Base
        BasePtr tmp = pCreate<Base>(type, "string");
        if (tmp) {
            tmp->whoAmI();
            std::cout<<'\n';

            std::cout<<"making clone::"<<'\n';
            BasePtr clone = tmp->clone();
            clone->whoAmI();
            std::cout<<'\n';
        }
    }

    std::cout<<"---End of Main---"<<'\n';
    return 0;
}
