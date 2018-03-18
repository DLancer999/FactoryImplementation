
/*************************************************************************\
License
    Copyright (c) 2018 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Class
    AddToRegistry
 
Description
    Dummy class to create runTimeSelection tables at global initialization stage

\************************************************************************/

#ifndef ADDTOREGISTRY_H
#define ADDTOREGISTRY_H

#include "CreateFunctions.hpp"

template <class,class>
class AddToRegistry; //no implementation

//weird specialization syntax required to extract ARGS pack
//out of ObjectCreator instead of passing the same argument pack
//around for each AddToRegistry object
template <class ADDED, class HASREGISTRY, class... ARGS>
class AddToRegistry<ADDED, std::unique_ptr<HASREGISTRY>(*)(ARGS...)>
{
public:
    AddToRegistry()
    {
        //track additions
        std::cout<<"Adding \"" <<ADDED::name
                 <<"\" to RuntimeSelectionTable of " <<HASREGISTRY::name<<'\n';

        //actual addition
        registry<HASREGISTRY>()[ADDED::name] = polymorphicCreate<ADDED, HASREGISTRY, ARGS...>;
    }
};

#endif
