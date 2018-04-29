RM=rm
COMP=g++
EDL=g++
RMFLAGS=-f
COMPFLAGS = -ansi -pedantic  -Wall -std=c++11 -g
#retirez yes pour compiler en release
DEBUG=yes
EXE=application
EXEPATH=./
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)


ifeq ($(DEBUG),yes)
	DEFINE=-D MAP	
else
	DEFINE=
endif

all:$(EXEPATH)$(EXE)

$(EXEPATH)$(EXE): $(OBJ)
	$(EDL) -o $(EXEPATH)$(EXE) $(OBJ)

%.o: %.cpp
	$(COMP) -c $< $(COMPFLAGS) $(DEFINE)
	
.PHONY:clean tests

clean:
	$(RM) $(RMFLAGS) *.o $(EXEPATH)$(EXE)
