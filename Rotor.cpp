#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

#include "Rotor.hpp"
#include "Checker.hpp"
#include "Utils.hpp"


using namespace std;
extern const int Max_input;

//Constructor
Rotor :: Rotor(){

}

void Rotor :: readfile(char* filename){

  //To store the number of rotation in each rotor
  int input; //For passing in the data from the file
  ifstream rotor_file(filename);

  if(!rotor_file.is_open()){
  cout << "Error: Rotor file cannot be opened." << endl;
  exit(EXIT_FAILURE);
  }


  while(!rotor_file.eof()){
    rotor_file >> input;
    for(int i = 0; i <  Max_input; i++){
      move[i] = input;

      rotor_file >> input;
    }
  }
rotor_file.close();
}


int Rotor :: map(int input){
  return ((move[input] - numOfRotation) + Max_input) % Max_input;
}


int Rotor :: mapBackward(int input){
  int output = (input + numOfRotation) % Max_input;
  for(int i = 0; i < Max_input; i++){
    if(output == move[i]){
      return i;
    }
  }
  return 0;
}

//Destructor
Rotor :: ~Rotor(){

}


bool Rotor :: rotatedOneRound(){
  if(numOfRotation == Max_input){
    numOfRotation = 0;
    return true;
  }
  return false;
}

//After each input, the rotor will advance one posiiton
void Rotor :: rotate(){

  int ori_first = move[0];
  for (int i = 0; i < Max_input ; i++) {
    move[i] = move[i + 1];
  }
  move[Max_input - 1] = ori_first;
  numOfRotation++;
}
