
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Class
    AddToTable
 
Description
    Dummy class to create runTimeSelection tables at global initialization stage

SourceFiles
    -

\************************************************************************/

#ifndef ADDTOTABLE_H
#define ADDTOTABLE_H

#include "Create.hpp"

template <class Base,class Derived, class Args=void>
class AddToTable
{
public:
    AddToTable()
    {
        //track additions
        std::cout<<"Adding \"" <<Derived::name()
                 <<"\" to RuntimeSelectionTable of " <<Base::name()<<std::endl;

        //actual addition
        Base::Registry().registry[Derived::name()] = Create::Offspring<Base,Derived,Args>;
    }
};

//Specialization for Default constructor
template <class Base,class Derived>
class AddToTable<Base,Derived,void>
{
public:
    AddToTable()
    {
        //track additions
        std::cout<<"Adding \"" <<Derived::name()
                 <<"\" to RuntimeSelectionTable of " <<Base::name()<<std::endl;

        //actual addition
        Base::Registry().registry[Derived::name()] = Create::Offspring<Base,Derived>;
    }
};
#endif
