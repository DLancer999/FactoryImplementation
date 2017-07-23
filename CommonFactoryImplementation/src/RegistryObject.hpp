
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

template <class T, class Args=void>
class RegistryObject
{
public:
    typedef std::unique_ptr<T> Tptr;

    std::unordered_map<std::string,std::function<Tptr(const Args&)> > registry;

    RegistryObject():registry()
    {
        std::cout<<"RegistryObject of "<<T::name()<<" initialized"<<std::endl;
    }
    ~RegistryObject()
    {
        std::cout<<"RegistryObject of "<<T::name()<<" terminated"<<std::endl;
    }
};

//Specialization for Default constructor
template <class T>
class RegistryObject<T,void>
{
public:
    typedef std::unique_ptr<T> Tptr;

    std::unordered_map<std::string,std::function<Tptr(void)> > registry;

    RegistryObject():registry()
    {
        std::cout<<"RegistryObject of "<<T::name()<<" initialized"<<std::endl;
    }
    ~RegistryObject()
    {
        std::cout<<"RegistryObject of "<<T::name()<<" terminated"<<std::endl;
    }
};

#endif
