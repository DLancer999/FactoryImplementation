
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.

    This file is part of FactoryImplementation.

    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Namespace
    Create

Description
    functions required for runtime selection of derived classes

SourceFiles
    -

\************************************************************************/

#ifndef CREATE_H
#define CREATE_H

#include <memory>

namespace Create
{
    //create Base Class pointer from argument list constructor
    template <class Base, class Args>
    std::unique_ptr<Base> Abstract(std::string type, const Args& list)
    {
        auto search = Base::Registry().registry.find(type);
        if (search!=Base::Registry().registry.end())
        {
            return search->second(list);
        }
        else
        {
            std::cout<<"Type \""<<type<<"\" not found!"<<std::endl;
            std::cout<<"Available types::"<<std::endl;
            for (auto pair:Base::Registry().registry)
            {
                std::cout<<pair.first<<std::endl;
            }

        }
        return nullptr;
    }

    //create Base Class pointer from default constructor
    template <class Base>
    std::unique_ptr<Base> Abstract(std::string type)
    {
        auto search = Base::Registry().registry.find(type);
        if (search!=Base::Registry().registry.end())
        {
            return search->second();
        }
        else
        {
            std::cout<<"Type \""<<type<<"\" not found!"<<std::endl;
            std::cout<<"Available types::"<<std::endl;
            for (auto pair:Base::Registry().registry)
            {
                std::cout<<pair.first<<std::endl;
            }

        }
        return nullptr;
    }

    //create Derived Class object pointer from argument list constructor
    template <class Base, class Derived, class Args>
    std::unique_ptr<Base> Offspring(const Args& list)
    {
        return std::unique_ptr<Base>(new Derived(list));
    }

    //create Derived Class object pointer from default constructor
    template <class Base, class Derived>
    std::unique_ptr<Base> Offspring()
    {
        return std::unique_ptr<Base>(new Derived());
    }
}

#endif
