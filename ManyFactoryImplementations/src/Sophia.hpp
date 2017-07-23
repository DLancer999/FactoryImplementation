
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Class
    Sophia
 
Description
    Potential Child of FamilyB

SourceFiles
    Sophia.cpp

\************************************************************************/

#ifndef SOPHIA_H
#define SOPHIA_H

#include "FamilyB.hpp"
#include "AddToTable.hpp"

class Sophia:
public FamilyB
{
public:
    static std::string name(){return "Sophia";}

    //object creator that uses default constructor
    static FamilyBPtr CreateObject();

    //default Constructor
    Sophia();
    //arbitrary Constructor
    Sophia(const std::string&);
    //destructor
    ~Sophia();

    //just a test message to show that I am Sophia
    virtual void whoAmI();

private:
    //helper class to create Registry
    static AddToTable<FamilyB,Sophia> addToTable;
};

#endif
