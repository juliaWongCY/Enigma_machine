#ifndef ROTOR_H
#define ROTOR_H


#include "Component.hpp"
#include "Utils.hpp"

using namespace std;
extern const int Max_input;

class Rotor : public Component {

 int numOfRotation;
 int move[Max_input];

public:
  Rotor();
  ~Rotor();
  void readfile(char*);
  int map(int);
  int mapBackward(int);
  bool rotatedOneRound();
  void rotate();
};



#endif
