
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

\************************************************************************/

#include "Base.hpp"
#include <string>

Base::Base()
{
    std::cout<<"Default Constructor Base Class"<<'\n';
}

Base::Base(const std::string& str)
{
    (void)str;
    std::cout<<"Arbitrary Constructor Base Class"<<'\n';
}

Base::Base(const Base& o)
{
    (void)o;
    std::cout<<"Copy Constructor Base Class"<<'\n';
}

Base::Base(Base&& o)
{
    (void)o;
    std::cout<<"Move Constructor Base Class"<<'\n';
}

Base& Base::operator=(const Base& o)
{
    (void)o;
    std::cout<<"Copy Assignment Operator Base Class"<<'\n';
    return *this;
}

Base& Base::operator=(Base&& o)
{
    (void)o;
    std::cout<<"Move Assignment Operator Base Class"<<'\n';
    return *this;
}

Base::~Base()
{
    std::cout<<"Destructor Base "<<'\n';
}

