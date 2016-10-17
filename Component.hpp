#ifndef COMPONENT_H
#define COMPONENT_H

// Created a base class Component because rotors, reflectors and plugboards all have similar behaviour
class Component{
public:
  //All three components map one input to another
  virtual int map(int input) =0;

};

#endif
