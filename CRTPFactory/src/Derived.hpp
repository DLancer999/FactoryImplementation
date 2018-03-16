
/*************************************************************************\
License
    Copyright (c) 2018 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Class
    Derived
 
Description
    Concrete class that will be used polymorphically.

\************************************************************************/

#ifndef DERIVED_H
#define DERIVED_H

#include <iostream>
#include <memory>
#include <string>

#include "Base.hpp"
#include "PolymorphicInheritance.hpp"
#include "AddToRegistry.hpp"

class Derived;
using DerivedPtr = std::unique_ptr<Derived>;

class Derived 
: public PolymorphicInheritance<Derived, Base>
{
    //member variables
    // .
    // .
    // .

public:
    static constexpr const char* name = "Derived";

    //default Constructors
    Derived();
    Derived(const Derived&);
    Derived(Derived&&);
    //arbitrary Constructor
    Derived(const std::string&);
    //destructor
    virtual ~Derived();

    //operators ...
    Derived& operator=(const Derived&); 
    Derived& operator=(Derived&&); 
    //... rest of operators

    virtual void whoAmI(void);

private:
    static AddToRegistry<Derived, Base, BaseCreator> addToTable;
};

#endif
