
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Class
    RegistryObject
 
Description
    Extension of unordered_map to track Constructor/Destructor

SourceFiles
    -

\************************************************************************/

#ifndef REGISTRYOBJECT_H
#define REGISTRYOBJECT_H

#include <iostream>
#include <memory>
#include <unordered_map>
#include <functional>

template <class T>
class RegistryObject
{
public:
    std::unordered_map<std::string,typename T::ObjectCreator> registry;

    RegistryObject():registry()
    {
        std::cout<<"RegistryObject of "<<T::name<<" initialized"<<'\n';
    }
    ~RegistryObject()
    {
        std::cout<<"RegistryObject of "<<T::name<<" terminated"<<'\n';
    }
};

#endif
