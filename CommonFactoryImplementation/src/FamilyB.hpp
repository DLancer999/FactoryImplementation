
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Class
    FamilyB
 
Description
    Abstract Base Class for FamilyB RuntimeSelectable Objects
    created through arbitrary constructor
    Inherited Classes:
        Maria
        Monica
        Sophia

SourceFiles
    FamilyB.cpp

\************************************************************************/

#ifndef FAMILYB_H
#define FAMILYB_H

#include <iostream>
#include <memory>

#include "RegistryObject.hpp"

class FamilyB;
typedef std::unique_ptr<FamilyB> FamilyBPtr;

class FamilyB
{
public:
    static std::string name(){return "FamilyB";}

    //used for arbitrary arguments to constructor
    struct ConstructorArgs{
        std::string surName;
    };

    //Registry of available inherited classes and a creator for each class
    static RegistryObject<FamilyB>& Registry();

    //member variables
    // .
    // .
    // .

    //default Constructor
    FamilyB();
    //arbitrary Constructor
    FamilyB(const ConstructorArgs&);
    //destructor
    virtual ~FamilyB();

    //just a test message from inherited classes
    virtual void whoAmI()=0;
};

#endif