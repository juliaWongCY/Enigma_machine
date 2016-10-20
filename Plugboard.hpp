#ifndef PLUGBOARD_H
#define PLUGBOARD_H

#include <utility>
#include <vector>
#include "Component.hpp"

using namespace std;


class Plugboard : public Component{
  vector <pair <int, int> > PB_vec_pair;

public:
  Plugboard();
  ~Plugboard();
  void readfile(char*);
  int map(int);
};

#endif
