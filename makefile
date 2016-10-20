# edit this makefile so that running make compiles your enigma program

#compiler
CXX = g++

#compiler flags:
CXXFLAGS = -Wall -Werror -pedantic -std=c++11

default: enigma


enigma:Checker.o Utils.o Reflector.o Rotor.o Plugboard.o Main.o
	$(CXX) $(CXXFLAGS) -o enigma Main.o Checker.o Utils.o Reflector.o Rotor.o Plugboard.o

#enigma: Main.o
#	g++ -o enigma Main.o

Main.o: Main.cpp
	$(CXX) $(CXXFLAGS) -c Main.cpp

#Main.o: Main.cpp Checker.hpp Reflector.hpp Rotor.hpp Plugboard.hpp Utils.hpp
#	$(CXX) $(CXXFLAGS) -c Main.cpp Checker.hpp Reflector.hpp Rotor.hpp Plugboard.hpp Utils.hpp

Checker.o: Checker.hpp Checker.cpp
	$(CXX) $(CXXFLAGS) -c Checker.cpp

Utils.o: Utils.hpp Utils.cpp
	$(CXX) $(CXXFLAGS) -c Utils.cpp

Reflector.o: Reflector.hpp Reflector.cpp
	$(CXX) $(CXXFLAGS) -c Reflector.cpp

Rotor.o: Rotor.hpp Rotor.cpp
	$(CXX) $(CXXFLAGS) -c Rotor.cpp

Plugboard.o: Plugboard.hpp Plugboard.cpp
	$(CXX) $(CXXFLAGS) -c Plugboard.cpp

#Main.o: Main.cpp
#	g++ -c Main.cpp

clean:
	rm -rf enigma *.o

.PHONY: clean
