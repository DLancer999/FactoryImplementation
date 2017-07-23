
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Class
    Monica
 
Description
    Potential Child of FamilyB

SourceFiles
    Monica.cpp

\************************************************************************/

#ifndef MONICA_H
#define MONICA_H

#include "FamilyB.hpp"
#include "AddToTable.hpp"

class Monica:
public FamilyB
{
public:
    static std::string name(){return "Monica";}

    //object creator that uses default constructor
    static FamilyBPtr CreateObject();

    //default Constructor
    Monica();
    //arbitrary Constructor
    Monica(const std::string&);
    //destructor
    ~Monica();

    //just a test message to show that I am Monica
    virtual void whoAmI();

private:
    //helper class to create Registry
    static AddToTable<FamilyB,Monica> addToTable;
};

#endif
