
#*************************************************************************#
#License
#    Copyright (c) 2017 Kavvadias Ioannis.
#    
#    This file is part of FactoryImplementation.
#    
#    Licensed under the MIT License. See LICENSE file in the project root for 
#    full license information.  
#
#Description
#    Makefile for FactoryImplementation.
#
#************************************************************************#

#insert project name here
MYPROGRAM = FactoryImplementation

#objects to be compiled for this project
OBJ= $(MYPROGRAM).o \
	Base.o \
	Derived.o \
	DDerived.o

#libraries to be included and where to find them
LIBS = 
LDIR =

#compilization flags

#use either optimization or debug flags, not both
OPTFLAGS= -O3 -flto #-march=native #-mtune=native
DEBUGFLAGS= -g -O0 

ERRORFLAGS= -pedantic-errors

OTHERFLAGS= -std=c++14

WARNFLAGS= -Wall -Weffc++ -pedantic \
	-Wextra -Wcast-align -Wcast-qual \
	-Wchar-subscripts  -Wcomment -Wconversion \
	-Wdisabled-optimization -Wfloat-equal  -Wformat  -Wformat=2 \
	-Wformat-nonliteral -Wformat-security -Wformat-y2k \
	-Wimport  -Winit-self  -Winvalid-pch   \
	-Wlong-long -Wmissing-braces \
	-Wmissing-field-initializers -Wmissing-format-attribute   \
	-Wmissing-include-dirs -Wmissing-noreturn \
	-Wpacked  -Wparentheses  -Wpointer-arith \
	-Wredundant-decls -Wreturn-type \
	-Wsequence-point  -Wshadow -Wsign-compare  -Wstack-protector \
	-Wstrict-aliasing -Wstrict-aliasing=2 -Wswitch  -Wswitch-default \
	-Wswitch-enum -Wtrigraphs  -Wuninitialized \
	-Wunknown-pragmas  -Wunreachable-code -Wunused \
	-Wunused-function  -Wunused-label  -Wunused-parameter \
	-Wunused-value  -Wunused-variable  -Wvariadic-macros \
	-Wvolatile-register-var  -Wwrite-strings 

CXXFLAGS= $(OPTFLAGS) $(OTHERFLAGS) $(WARNFLAGS) $(ERRORFLAGS)

###########################################
### NOT TO BE CHANGED BEYOND THIS LINE  ### 
###########################################

MYFOLDER = $(shell pwd)
ODIR    = obj
DEPSDIR = deps
SRCDIR  = src
IDIR    = $(MYFOLDER)/$(SRCDIR)

SRC_INC = \
	-I$(IDIR)

_OBJ =  $(patsubst %,$(ODIR)/%,$(OBJ))
_DEPS = $(patsubst %,$(DEPSDIR)/%,$(OBJ:.o=.dep))

all: compileExe

ifneq ($(MAKECMDGOALS),clean)
-include $(_DEPS)
endif

$(DEPSDIR)/%.dep: $(SRCDIR)/%.cpp | $(DEPSDIR)
	@echo "Generating Dependencies for" $<
	@set -e; rm -f $*.dep; \
	$(CXX) -MM $(SRC_INC) $(CXXFLAGS) $< > $(DEPSDIR)/$*.dep.$$$$; \
	sed 's,\($*\)\.o[ :]*,$(ODIR)/\1.o $(DEPSDIR)/$*.dep : ,g' < $(DEPSDIR)/$*.dep.$$$$ > $(DEPSDIR)/$*.dep; \
	rm -f $(DEPSDIR)/$*.dep.$$$$

$(ODIR):
	@echo  "-----> Creating Objects Directory <-----"
	@mkdir $(ODIR)

$(DEPSDIR):
	@echo  "---> Creating Dependecies Directory <---"
	@mkdir $(DEPSDIR)

$(ODIR)/%.o: $(SRCDIR)/%.cpp | $(ODIR)
	@echo "Compiling Object" $<
	@$(CXX) $(SRC_INC) $(CXXFLAGS) -c $< -o $@

$(MYPROGRAM).exe : $(_OBJ)  
	@echo  "--------------> Linking <---------------"
	@$(CXX) $(_OBJ) $(CXXFLAGS) $(LDIR) $(LIBS)  -o $@

compileExe: $(MYPROGRAM).exe 
	@echo  "-------> Compilation Successful <-------" 

.PRECIOUS: %.dep
.PHONY: clean

clean:
	@rm -rf $(ODIR) $(DEPSDIR) $(MYPROGRAM).exe 

