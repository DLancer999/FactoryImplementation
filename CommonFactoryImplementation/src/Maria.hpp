
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Class
    Maria
 
Description
    Potential Child of FamilyB

SourceFiles
    Maria.cpp

\************************************************************************/

#ifndef MARIA_H
#define MARIA_H

#include "FamilyB.hpp"
#include "AddToTable.hpp"

class Maria:
public FamilyB
{
public:
    static std::string name(){return "Maria";}

    //default Constructor
    Maria();
    //arbitrary Constructor
    Maria(const ConstructorArgs&);
    //destructor
    ~Maria();

    //just a test message to show that I am Alex
    virtual void whoAmI();

private:
    //helper class to create Registry
      static AddToTable<FamilyB,Maria> addToTable;
};

#endif
