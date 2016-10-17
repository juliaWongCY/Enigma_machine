#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include "Component.hpp"


class Plugboard : public Component{
public:
  Plugboard();
  ~Plugboard();
  int map(int);
};

#endif
