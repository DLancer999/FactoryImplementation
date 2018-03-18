
/*************************************************************************\
License
    Copyright (c) 2018 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Description
    Available templated creator functions

\************************************************************************/

#ifndef CREATEFUNCTIONS_H
#define CREATEFUNCTIONS_H

#include <memory>

#include "RegistryObject.hpp"

template <class T, class... ARGS>
std::unique_ptr<T> create(ARGS&&... args) 
{
  return std::make_unique<T>(std::forward<ARGS>(args)...);
}

template <class DERIVED, class BASE, class... ARGS>
std::unique_ptr<BASE> polymorphicCreate(ARGS&&... args)
{
  return std::make_unique<DERIVED>(std::forward<ARGS>(args)...);
}

template <class BASE, class... ARGS>
std::unique_ptr<BASE> pCreate(const std::string& derivedName, ARGS&&... args)
{
    auto regIt = registry<BASE>().find(derivedName);
    if (regIt != registry<BASE>().end())
    {
        //Object of "derivedName" is found.
        //ObjectCreator function is called with arguments
        //for arbitrary constructor
        auto& cnstr = regIt->second;
        return cnstr(std::forward<ARGS>(args)...);
    }
    else
    {
        //Object of "derivedName" is not found.
        //Print error message, available types
        //and return null pointer
        std::cout<<"Type \""<<derivedName<<"\" not found!"<<'\n';
        std::cout<<"Available types::"<<'\n';
        for (auto it : registry<BASE>())
        {
            auto& availableName = it.first;
            std::cout<<availableName<<'\n';
        }
    
    }
    return nullptr;
}


#endif
