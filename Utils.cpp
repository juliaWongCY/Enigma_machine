#include <iostream>
#include <cstring>
#include <stdlib.h>

#include "Utils.hpp"

using namespace std;
extern const int Max_input;

int CharToInt(char character){
  return character - 'A';
}

int IntToChar(int integer){
  return (integer % Max_input) + 'A';
}
