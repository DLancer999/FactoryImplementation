
/*************************************************************************\
License
    Copyright (c) 2018 Kavvadias Ioannis.
    
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

Base::Base(const std::string&)
{
    std::cout<<"Arbitrary Constructor Base Class"<<'\n';
}

Base::Base(const Base&)
{
    std::cout<<"Copy Constructor Base Class"<<'\n';
}

Base::Base(Base&&)
{
    std::cout<<"Move Constructor Base Class"<<'\n';
}

Base& Base::operator=(const Base&)
{
    std::cout<<"Copy Assignment Operator Base Class"<<'\n';
    return *this;
}

Base& Base::operator=(Base&&)
{
    std::cout<<"Move Assignment Operator Base Class"<<'\n';
    return *this;
}

Base::~Base()
{
    std::cout<<"Destructor Base "<<'\n';
}

