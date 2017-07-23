
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

\************************************************************************/

#include "George.hpp"

George::George():
FamilyA()
{
    std::cout<<"Default Constructor George"<<std::endl;
}

George::George(const std::string& name):
FamilyA(name)
{
    std::cout<<"Arbitrary Constructor George"<<std::endl;
}

George::~George()
{
    std::cout<<"Destructor George "<<std::endl;
}

void George::whoAmI()
{
    std::cout<<"I am George "<<std::endl;
}

AddToTable<FamilyA,George> George::addToTable;

FamilyAPtr George::CreateObject(const std::string& name)
{
    return FamilyAPtr(new George(name) );
}
