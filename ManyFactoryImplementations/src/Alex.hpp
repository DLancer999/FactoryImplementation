
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Class
    Alex
 
Description
    Potential Child of FamilyA

SourceFiles
    Alex.cpp

\************************************************************************/

#ifndef ALEX_H
#define ALEX_H

#include "FamilyA.hpp"
#include "AddToTable.hpp"

class Alex:
public FamilyA
{
public:
    static std::string name(){return "Alex";}

    //object creator that uses arbitrary constructor
    static FamilyAPtr CreateObject(const std::string& name);

    //default Constructor
    Alex();
    //arbitrary Constructor
    Alex(const std::string&);
    //destructor
    ~Alex();

    //just a test message to show that I am Alex
    virtual void whoAmI();

private:
    //helper class to create Registry
    static AddToTable<FamilyA,Alex> addToTable;
};

#endif
