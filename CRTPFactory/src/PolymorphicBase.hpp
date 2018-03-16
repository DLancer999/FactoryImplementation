
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Class
    PolymorphicBase
 
Description
    Extension of unordered_map to track Constructor/Destructor

SourceFiles
    -

\************************************************************************/

#ifndef RUNTIMECREATOR_H
#define RUNTIMECREATOR_H

#include <iostream>
#include <memory>
#include <unordered_map>
#include <functional>

#include "RegistryObject.hpp"

template <class BASE, class OBJECTCREATOR>
class PolymorphicBase
{
public:
    using This          = PolymorphicBase<BASE, OBJECTCREATOR>;
    using ObjectCreator = OBJECTCREATOR;

    static constexpr const char* name = BASE::name;

    //Registry of available inherited classes and a creator for each class
    static RegistryObject<This>& registry() {
      static RegistryObject<This> _registry;
      return _registry;
    }

    template <class... Args>
    static std::unique_ptr<BASE> polymorficCreate(const std::string& derivedName, Args&&... args)
    {
        auto regIt = registry().registry.find(derivedName);
        if (regIt != registry().registry.end())
        {
            //Object of "derivedName" is found.
            //ObjectCreator function is called with arguments
            //for arbitrary constructor
            auto& cnstr = regIt->second;
            return cnstr(std::forward<Args>(args)...);
        }
        else
        {
            //Object of "derivedName" is not found.
            //Print error message, available types
            //and return null pointer
            std::cout<<"Type \""<<derivedName<<"\" not found!"<<'\n';
            std::cout<<"Available types::"<<'\n';
            for (auto it : registry().registry)
            {
                auto& name = it.first;
                std::cout<<name<<'\n';
            }
        
        }
        return nullptr;
    }

protected:
    ~PolymorphicBase() = default;
};

#endif
