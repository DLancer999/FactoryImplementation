
/*************************************************************************\
License
    Copyright (c) 2018 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Class
    Base
 
Description
    Base class of polymorphic structure

\************************************************************************/

#ifndef BASE_H
#define BASE_H

#include <string>

#include "PolymorphicBase.hpp"

class Base;
using BasePtr = std::unique_ptr<Base>;
    //signature of each creator function used to create BasePtr
    //objects polymorphically
using BaseCreator = BasePtr(*)(const std::string&);

class Base
: public PolymorphicBase<Base, BaseCreator>
{
    //member variables
    // .
    // .
    // .

public:
    //this is used only for logging
    static constexpr const char* name = "Base";

    //destructor
    virtual ~Base();

    virtual void whoAmI() = 0;
    virtual BasePtr clone() = 0;

protected:
    //polymorphic class!
    //disable direct construction

    //default Constructors
    Base();
    Base(const Base&);
    Base(Base&&);
    //arbitrary Constructor
    Base(const std::string&);

    //disable direct assignment operators
    Base& operator=(const Base&); 
    Base& operator=(Base&&); 
};

#endif
