
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

template <class Base,class Derived>
class AddToTable
{
public:
    AddToTable()
    {
        //track additions
        std::cout<<"Adding \"" <<Derived::name()
                 <<"\" to RuntimeSelectionTable of " <<Base::name()<<std::endl;

        //actual addition
        Base::Registry().registry[Derived::name()] = Derived::CreateObject;
    }
};

#endif
