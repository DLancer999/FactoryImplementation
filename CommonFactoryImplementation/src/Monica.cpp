
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

\************************************************************************/

#include "Monica.hpp"

Monica::Monica():
FamilyB()
{
    std::cout<<"Default Constructor Monica"<<std::endl;
}

Monica::Monica(const ConstructorArgs& list):
FamilyB(list)
{
    std::cout<<"Arbitrary Constructor Monica "<<std::endl;
}

Monica::~Monica()
{
    std::cout<<"Destructor Monica"<<std::endl;
}

void Monica::whoAmI()
{
    std::cout<<"I am Monica "<<std::endl;
}

AddToTable<FamilyB,Monica> Monica::addToTable;
