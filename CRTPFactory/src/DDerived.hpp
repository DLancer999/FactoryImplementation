
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Class
    DDerived
 
Description

SourceFiles

\************************************************************************/

#ifndef DDERIVED_H
#define DDERIVED_H

#include <iostream>
#include <memory>

#include "Base.hpp"
#include "Derived.hpp"
#include "PolymorphicInheritance.hpp"
#include "AddToRegistry.hpp"

class DDerived;
using DDerivedPtr = std::unique_ptr<DDerived>;

class DDerived 
: public PolymorphicInheritance<DDerived,Derived,Base>
{
public:
    //member variables
    // .
    // .
    // .

    static constexpr const char* name = "DDerived";

    //default Constructors
    DDerived();
    DDerived(const DDerived&);
    DDerived(DDerived&&);
    //arbitrary Constructor
    DDerived(const std::string&);
    //destructor
    virtual ~DDerived();

    //operators ...
    DDerived& operator=(const DDerived&); 
    DDerived& operator=(DDerived&&); 
    //... rest of operators

    virtual void whoAmI(void);

private:
    static AddToRegistry<DDerived, Base, BaseCreator> addToTable;
};

#endif