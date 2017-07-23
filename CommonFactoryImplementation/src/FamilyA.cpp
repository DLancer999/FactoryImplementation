
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

FamilyA::FamilyA(const FamilyA::ConstructorArgs& list)
{
    std::cout<<"Arbitrary Constructor FamilyA"<<std::endl;
}

FamilyA::~FamilyA()
{
    std::cout<<"Destructor FamilyA "<<std::endl;
}

RegistryObject<FamilyA,FamilyA::ConstructorArgs>& FamilyA::Registry()
{
    static RegistryObject<FamilyA,ConstructorArgs> registry;
    return registry;
}

