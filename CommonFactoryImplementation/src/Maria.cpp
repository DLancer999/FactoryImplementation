
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

\************************************************************************/

#include "Maria.hpp"

Maria::Maria():
FamilyB()
{
    std::cout<<"Default Constructor Maria"<<std::endl;
}

Maria::Maria(const ConstructorArgs& list):
FamilyB(list)
{
    std::cout<<"Arbitrary Constructor Maria "<<std::endl;
}

Maria::~Maria()
{
    std::cout<<"Destructor Maria"<<std::endl;
}

void Maria::whoAmI()
{
    std::cout<<"I am Maria "<<std::endl;
}

AddToTable<FamilyB,Maria> Maria::addToTable;
