#ifndef ROTOR_H
#define ROTOR_H


#include "Component.hpp"
#include "Main.cpp"

extern const int Max_input;

class Rotor : public Component {

 int numOfRotation;
 int rotateForward[Max_input];//There will be 26 numbers for forward instr
 int rotateBackward[Max_input];//There will be 26 numbers for backward instr
public:
  Rotor(char* filename);
  ~Rotor();
  int map(int);
  int mapBackward(int);
  bool rotatedOneRound();
  void rotate();
};



#endif
