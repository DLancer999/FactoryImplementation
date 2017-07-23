
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

\************************************************************************/

#include "FamilyB.hpp"

FamilyB::FamilyB()
{
    std::cout<<"Default Constructor FamilyB"<<std::endl;
}

FamilyB::FamilyB(const std::string& name)
{
    std::cout<<"Arbitrary Constructor FamilyB"<<std::endl;
}

FamilyB::~FamilyB()
{
    std::cout<<"Destructor FamilyB "<<std::endl;
}

RegistryObject<FamilyB>& FamilyB::Registry()
{
    static RegistryObject<FamilyB> registry;
    return registry;
}

FamilyBPtr FamilyB::Create(std::string type)
{
    auto search = Registry().registry.find(type);
    if (search!= Registry().registry.end())
    {
        //Object of "type" is found.
        //ObjectCreator function is called with no arguments
        //for default constructor
        return search->second();
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
