
/*************************************************************************\
License
    Copyright (c) 2018 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Class
    PolymorphicInheritance
 
Description
    Every concrete class of a polymorphic inheritance structure should
    delegate its inheritance through this function for creating/cloning
    functionality, either through the base class or directly.

\************************************************************************/

#ifndef RUNTIMECREATABLE_H
#define RUNTIMECREATABLE_H

#include <memory>
#include "PolymorphicBase.hpp"

template <class SELF, class BASE, class POLYMORPHICBASE = BASE>
class PolymorphicInheritance
: public BASE
{
public:
    
    template <class... Args>
    static std::unique_ptr<SELF> create(Args&&... args) { 
      return std::make_unique<SELF>(std::forward<Args>(args)...);
    }

    template <class... Args>
    static std::unique_ptr<POLYMORPHICBASE> polymorphicCreate(Args&&... args) 
    { 
      return std::make_unique<SELF>(std::forward<Args>(args)...);
    }

    virtual std::unique_ptr<POLYMORPHICBASE> clone() override 
    {
      return std::make_unique<SELF>(*(static_cast<SELF*>(this)));
    }

protected:
    //forwarding constructors
    //disable direct construction
    PolymorphicInheritance():
    BASE()
    {
        std::cout<<"Default Constructor PInheritance Class"<<'\n';
    }
    PolymorphicInheritance(const PolymorphicInheritance& other):
    BASE(other)
    {
        std::cout<<"Copy Constructor PInheritance Class"<<'\n';
    }
    PolymorphicInheritance(PolymorphicInheritance&& other):
    BASE(std::move(other))
    {
        std::cout<<"Move Constructor PInheritance Class"<<'\n';
    }

    template <class... Args>
    PolymorphicInheritance(Args&&... args):
    BASE(std::forward<Args>(args)...)
    {
        std::cout<<"Templated Constructor PInheritance Class"<<'\n';
    }
    ~PolymorphicInheritance()
    {
        std::cout<<"Destructor PInheritance"<<'\n';
    }
};

#endif
