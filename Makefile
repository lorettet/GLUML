RM=rm
COMP=g++
EDL=g++
RMFLAGS=-f
COMPFLAGS = -ansi -pedantic  -Wall -std=c++11 -g
#make DEBUG=no pour compiler en release.
DEBUG=yes
LOGIN=yes
EXE=application
EXEPATH=./
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)


ifeq ($(DEBUG),yes)
	DEFINE_DEBUG=-D MAP	
else
	DEFINE_DEBUG=
endif

ifeq ($(LOGIN),yes)
	DEFINE_LOGIN=-D LOGIN
else
	DEFINE_LOGIN=
endif

all:$(EXEPATH)$(EXE)

$(EXEPATH)$(EXE): $(OBJ)
	$(EDL) -o $(EXEPATH)$(EXE) $(OBJ)

%.o: %.cpp
	$(COMP) -c $< $(COMPFLAGS) $(DEFINE_DEBUG) $(DEFINE_LOGIN)
	
.PHONY:clean tests

clean:
	$(RM) $(RMFLAGS) *.o $(EXEPATH)$(EXE)
