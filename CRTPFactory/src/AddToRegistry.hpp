
/*************************************************************************\
License
    Copyright (c) 2017 Kavvadias Ioannis.
    
    This file is part of FactoryImplementation.
    
    Licensed under the MIT License. See LICENSE file in the project root for 
    full license information.  

Class
    AddToRegistry
 
Description
    Dummy class to create runTimeSelection tables at global initialization stage

SourceFiles
    -

\************************************************************************/

#ifndef ADDREGISTRY_H
#define ADDREGISTRY_H

template < class TOADD, class HASREGISTRY, class OBJECTCREATOR>
class AddToRegistry
{
public:
    AddToRegistry()
    {
        //track additions
        std::cout<<"Adding \"" <<TOADD::name
                 <<"\" to RuntimeSelectionTable of " <<HASREGISTRY::name<<'\n';

        //needed to define which polymorphicCreate instantiation we need
        OBJECTCREATOR createFunc = TOADD::polymorphicCreate;

        //actual addition
        HASREGISTRY::registry().registry[TOADD::name] = createFunc;
    }
};

#endif
