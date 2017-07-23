
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Class
    Michael
 
Description
    Potential Child of FamilyA

SourceFiles
    Michael.cpp

\************************************************************************/

#ifndef MICHAEL_H
#define MICHAEL_H

#include "FamilyA.hpp"
#include "AddToTable.hpp"

class Michael:
public FamilyA
{
public:
    static std::string name(){return "Michael";}

    //default Constructor
    Michael();
    //arbitrary Constructor
    Michael(const ConstructorArgs&);
    //destructor
    ~Michael();

    //just a test message to show that I am Michael
    virtual void whoAmI();

private:
    //helper class to create Registry
    static AddToTable<FamilyA,Michael,ConstructorArgs> addToTable;
};

#endif
