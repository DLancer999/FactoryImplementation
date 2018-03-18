
/*************************************************************************\
License
    Copyright (c) 2018 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

\************************************************************************/

#include "Derived.hpp"
#include "CreateFunctions.hpp"

AddToRegistry<Derived, Derived::ObjectCreator> Derived::addToRegistry;

Derived::Derived()
: Base()
{
    std::cout<<"Default Constructor Derived Class"<<'\n';
}

Derived::Derived(const std::string& str)
: Base(str)
{
    std::cout<<"Arbitrary Constructor Derived Class"<<'\n';
}

Derived::Derived(const Derived& o)
: Base(o)
{
    std::cout<<"Copy Constructor Derived Class"<<'\n';
}

Derived::Derived(Derived&& o)
: Base(std::move(o))
{
    std::cout<<"Move Constructor Derived Class"<<'\n';
}

Derived& Derived::operator=(const Derived& o)
{
    (void)o;
    std::cout<<"Copy Assignment Operator Derived Class"<<'\n';
    return *this;
}

Derived& Derived::operator=(Derived&& o)
{
    (void)o;
    std::cout<<"Move Assignment Operator Derived Class"<<'\n';
    return *this;
}

Derived::~Derived()
{
    std::cout<<"Destructor Derived "<<'\n';
}

void Derived::whoAmI(void)
{
    std::cout<<"I am Derived Class!!"<<'\n';
}

BasePtr Derived::clone()
{
    return create<Derived>(*this);
}
