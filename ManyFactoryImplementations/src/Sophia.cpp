
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

\************************************************************************/

#include "Sophia.hpp"

Sophia::Sophia():
FamilyB()
{
    std::cout<<"Default Constructor Sophia"<<std::endl;
}

Sophia::Sophia(const std::string& name):
FamilyB(name)
{
    std::cout<<"Arbitrary Constructor Sophia"<<std::endl;
}

Sophia::~Sophia()
{
    std::cout<<"Destructor Sophia "<<std::endl;
}

void Sophia::whoAmI()
{
    std::cout<<"I am Sophia "<<std::endl;
}

AddToTable<FamilyB,Sophia> Sophia::addToTable;

FamilyBPtr Sophia::CreateObject()
{
    return FamilyBPtr(new Sophia() );
}
