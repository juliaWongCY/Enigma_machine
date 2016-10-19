# edit this makefile so that running make compiles your enigma program

#compiler
CXX = g++

#compiler flags:
CXXFLAGS = -Wall -Werror -pedantic -std=c++11


enigma: Main.o Checker.o Reflector.o Rotor.o Plugboard.o
	$(CXX) $(CXXFLAGS) -o enigma Main.o Checker.o Reflector.o Rotor.o Plugboard.o

#enigma: Main.o
#	g++ -o enigma Main.o

Main.o: Main.cpp
	$(CXX) $(CXXFLAGS) -c Main.cpp

#Main.o: Main.cpp Checker.hpp Reflector.hpp Rotor.hpp Plugboard.hpp Utils.hpp
#	$(CXX) $(CXXFLAGS) -c Main.cpp Checker.hpp Reflector.hpp Rotor.hpp Plugboard.hpp Utils.hpp

Checker.o: Checker.hpp

Reflector.o: Reflector.hpp

Rotor.o: Rotor.hpp

Plugboard.o: Plugboard.hpp

#Main.o: Main.cpp
#	g++ -c Main.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
