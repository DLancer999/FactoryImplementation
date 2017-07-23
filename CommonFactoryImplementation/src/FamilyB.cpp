
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

FamilyB::FamilyB(const FamilyB::ConstructorArgs& list)
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


