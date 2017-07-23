
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Class
    George
 
Description
    Potential Child of FamilyA

SourceFiles
    George.cpp

\************************************************************************/

#ifndef GEORGE_H
#define GEORGE_H

#include "FamilyA.hpp"
#include "AddToTable.hpp"

class George:
public FamilyA
{
public:
    static std::string name(){return "George";}

    //default Constructor
    George();
    //arbitrary Constructor
    George(const ConstructorArgs&);
    //destructor
    ~George();

    //just a test message to show that I am George
    virtual void whoAmI();

private:
    //helper class to create Registry
    static AddToTable<FamilyA,George,ConstructorArgs> addToTable;
};

#endif
