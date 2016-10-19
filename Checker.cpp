#include <iostream>
#include <cstring>

#include "Checker.hpp"


using namespace std;
extern const int Max_input;

bool isValidInput(int input){
  return input >= 0 && input < Max_input;
}

bool isRotorFile(char* filename){
  int filename_len = strlen(filename);
  return filename[filename_len - 1] == 't'\
      && filename[filename_len - 2] == 'o'\
      && filename[filename_len - 3] == 'r'\
      && filename[filename_len - 4] == '.';

}
bool isPlugBoardFile(char* filename){
  int filename_len = strlen(filename);
  return filename[filename_len - 1] == 'b'\
      && filename[filename_len - 2] == 'p'\
      && filename[filename_len - 3] == '.';

}
