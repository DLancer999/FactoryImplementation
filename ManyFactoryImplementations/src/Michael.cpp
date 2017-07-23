
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

\************************************************************************/

#include "Michael.hpp"

Michael::Michael():
FamilyA()
{
    std::cout<<"Default Constructor Michael"<<std::endl;
}

Michael::Michael(const std::string& name):
FamilyA(name)
{
    std::cout<<"Arbitrary Constructor Michael"<<std::endl;
}

Michael::~Michael()
{
    std::cout<<"Destructor Michael "<<std::endl;
}

void Michael::whoAmI()
{
    std::cout<<"I am Michael "<<std::endl;
}

AddToTable<FamilyA,Michael> Michael::addToTable;

FamilyAPtr Michael::CreateObject(const std::string& name)
{
    return FamilyAPtr(new Michael(name) );
}