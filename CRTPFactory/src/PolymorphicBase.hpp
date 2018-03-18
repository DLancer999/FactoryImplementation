
/*************************************************************************\
License
    Copyright (c) 2018 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Class
    PolymorphicBase
 
Description
    The Base of every polymorphic inheritance structure has to inherit from
    this class to gain access to a polymorphic factory.

\************************************************************************/

#ifndef RUNTIMECREATOR_H
#define RUNTIMECREATOR_H

#include <iostream>
#include <memory>

#include "RegistryObject.hpp"

template <class BASE, class OBJECTCREATOR>
class PolymorphicBase
{
public:
    using This          = PolymorphicBase<BASE, OBJECTCREATOR>;
    using ObjectCreator = OBJECTCREATOR;

    static constexpr const char* name = BASE::name;

    //Registry of available inherited classes and a creator for each class
    static RegistryObject<This>& registry() 
    {
        static RegistryObject<This> _registry;
        return _registry;
    }

    template <class... ARGS>
    static std::unique_ptr<BASE> create(const std::string& derivedName, ARGS&&... args)
    {
        auto regIt = registry().find(derivedName);
        if (regIt != registry().end())
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
            for (auto it : registry())
            {
                auto& availableName = it.first;
                std::cout<<availableName<<'\n';
            }
        
        }
        return nullptr;
    }

protected:
    ~PolymorphicBase() = default;
};

#endif
