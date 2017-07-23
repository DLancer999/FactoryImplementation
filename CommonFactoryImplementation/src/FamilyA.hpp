
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Class
    FamilyA
 
Description
    Abstract Base Class for FamilyA RuntimeSelectable Objects
    created through arbitrary constructor
    Inherited Classes:
        Alex
        George
        Michael

SourceFiles
    FamilyA.cpp

\************************************************************************/

#ifndef FAMILYA_H
#define FAMILYA_H

#include <iostream>
#include <memory>

#include "RegistryObject.hpp"

class FamilyA;
typedef std::unique_ptr<FamilyA> FamilyAPtr;

class FamilyA
{
public:
    static std::string name(){return "FamilyA";}

    //used for arbitrary arguments to constructor
    struct ConstructorArgs{
        std::string surName;
    };

    //Registry of available inherited classes and a creator for each class
    static RegistryObject<FamilyA,ConstructorArgs>& Registry();

    //member variables
    // .
    // .
    // .

    //default Constructor
    FamilyA();
    //arbitrary Constructor
    FamilyA(const ConstructorArgs&);
    //destructor
    virtual ~FamilyA();

    //just a test message from inherited classes
    virtual void whoAmI()=0;
};

#endif
