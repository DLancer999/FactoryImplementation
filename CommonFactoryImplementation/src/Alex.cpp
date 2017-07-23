
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

\************************************************************************/

#include "Alex.hpp"

Alex::Alex():
FamilyA()
{
    std::cout<<"Default Constructor Alex"<<std::endl;
}

Alex::Alex(const ConstructorArgs& list):
FamilyA(list)
{
    std::cout<<"Arbitrary Constructor Alex "<<std::endl;
}

Alex::~Alex()
{
    std::cout<<"Destructor Alex "<<std::endl;
}

void Alex::whoAmI()
{
    std::cout<<"I am Alex "<<std::endl;
}

AddToTable<FamilyA,Alex,FamilyA::ConstructorArgs> Alex::addToTable;
