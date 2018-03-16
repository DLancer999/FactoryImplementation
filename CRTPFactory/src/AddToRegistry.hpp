
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

template < class ADDED, class HASREGISTRY, class OBJECTCREATOR>
class AddToRegistry
{
public:
    AddToRegistry()
    {
        //track additions
        std::cout<<"Adding \"" <<ADDED::name
                 <<"\" to RuntimeSelectionTable of " <<HASREGISTRY::name<<'\n';

        //needed to define which polymorphicCreate instantiation we need
        OBJECTCREATOR createFunc = ADDED::polymorphicCreate;

        //actual addition
        HASREGISTRY::registry()[ADDED::name] = createFunc;
    }
};

#endif
