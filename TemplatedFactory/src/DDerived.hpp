
/*************************************************************************\
License
    Copyright (c) 2018 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Class
    DDerived
 
Description
    Further extension of a concrete class that will be used polymorphically.

\************************************************************************/

#ifndef DDERIVED_H
#define DDERIVED_H

#include <iostream>
#include <memory>
#include <string>

#include "Base.hpp"
#include "Derived.hpp"
#include "AddToRegistry.hpp"

class DDerived;
using DDerivedPtr = std::unique_ptr<DDerived>;

class DDerived 
: public Derived
{
    //member variables
    // .
    // .
    // .

public:
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
    virtual BasePtr clone();

private:
    //Add DDerived class to RegistryObject<Base> using
    //a creator function with a signature of"BaseCreator" 
    static AddToRegistry<DDerived, DDerived::ObjectCreator> addToRegistry;
};

#endif
