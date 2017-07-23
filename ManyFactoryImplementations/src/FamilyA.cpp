
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

\************************************************************************/

#include "FamilyA.hpp"

FamilyA::FamilyA()
{
    std::cout<<"Default Constructor FamilyA"<<std::endl;
}

FamilyA::FamilyA(const std::string& name)
{
    std::cout<<"Arbitrary Constructor FamilyA"<<std::endl;
}

FamilyA::~FamilyA()
{
    std::cout<<"Destructor FamilyA "<<std::endl;
}

RegistryObject<FamilyA>& FamilyA::Registry()
{
    static RegistryObject<FamilyA> registry;
    return registry;
}

FamilyAPtr FamilyA::Create(std::string type, std::string name)
{
    auto search = Registry().registry.find(type);
    if (search!= Registry().registry.end())
    {
        //Object of "type" is found.
        //ObjectCreator function is called with arguments
        //for arbitrary constructor
        return search->second(name);
    }
    else
    {
        //Object of "type" is not found.
        //Print error message, available types
        //and return null pointer
        std::cout<<"Type \""<<type<<"\" not found!"<<std::endl;
        std::cout<<"Available types::"<<std::endl;
        for (auto pair : Registry().registry)
        {
            std::cout<<pair.first<<std::endl;
        }
    
    }
    return nullptr;
}
