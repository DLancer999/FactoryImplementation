
/*************************************************************************\
License
    Copyright (c) 2018 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

\************************************************************************/

#include "DDerived.hpp"
#include "CreateFunctions.hpp"

AddToRegistry<DDerived, DDerived::ObjectCreator> DDerived::addToRegistry;

DDerived::DDerived()
: Derived()
{
    std::cout<<"Default Constructor DDerived Class"<<'\n';
}

DDerived::DDerived(const std::string& str)
: Derived(str)
{
    std::cout<<"Arbitrary Constructor DDerived Class"<<'\n';
}

DDerived::DDerived(const DDerived& o)
: Derived(o)
{
    std::cout<<"Copy Constructor DDerived Class"<<'\n';
}

DDerived::DDerived(DDerived&& o)
: Derived(std::move(o))
{
    std::cout<<"Move Constructor DDerived Class"<<'\n';
}

DDerived& DDerived::operator=(const DDerived& o)
{
    (void)o;
    std::cout<<"Copy Assignment Operator DDerived Class"<<'\n';
    return *this;
}

DDerived& DDerived::operator=(DDerived&& o)
{
    (void)o;
    std::cout<<"Move Assignment Operator DDerived Class"<<'\n';
    return *this;
}

DDerived::~DDerived()
{
    std::cout<<"Destructor DDerived "<<'\n';
}

void DDerived::whoAmI(void)
{
    std::cout<<"I am DDerived Class!!"<<'\n';
}

BasePtr DDerived::clone()
{
    return create<DDerived>(*this);
}
