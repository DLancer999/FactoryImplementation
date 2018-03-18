
/*************************************************************************\
License
    Copyright (c) 2018 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Class
    RegistryObject
 
Description
    Wrapper object to unordered_map to log operations.

\************************************************************************/

#ifndef REGISTRYOBJECT_H
#define REGISTRYOBJECT_H

#include <iostream>
#include <unordered_map>

template <class T>
class RegistryObject;
template <class T>
RegistryObject<T>& registry();

template <class T>
class RegistryObject
{
    //needs to be friend to access private constructor
    friend RegistryObject<T>& registry<T>();
    //usefull alias
    using ObjectCreator = typename T::ObjectCreator;
    using Registry = std::unordered_map<std::string, ObjectCreator>;
    using iterator = typename Registry::iterator;

    //member variables
    Registry registry;

    RegistryObject():registry()
    {
        std::cout<<"RegistryObject of "<<T::name<<" initialized"<<'\n';
    }
    ~RegistryObject()
    {
        std::cout<<"RegistryObject of "<<T::name<<" terminated"<<'\n';
    }

public:
    iterator find(const std::string& name)
    {
        return registry.find(name);
    }

    iterator begin()
    {
        return registry.begin();
    }

    iterator end()
    {
        return registry.end();
    }

    ObjectCreator& operator[](const std::string& name)
    {
        return registry[name];
    }
};

//each RegistryObject is a singleton
template <class T>
RegistryObject<T>& registry() 
{
    static RegistryObject<T> _registry;
    return _registry;
}

#endif
