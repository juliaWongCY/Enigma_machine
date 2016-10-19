#include <iostream>
#include <string>
#include <cstdlib>

#include "Rotor.hpp"
#include "Checker.hpp"

using namespace std;
extern const int Max_input;

//Constructor
Rotor :: Rotor(char* filename){

  int input; //For passing in the data from the file
  ifstream rotor_file;
  rotor_file.open(filename);

  if(!rotor_file.is_open()){
  cout << "Error: Rotor file cannot be opened." << endl;
  exit(EXIT_FAILURE);
  }


  //TODO: CHEKC!!!
  rotor_file >> input;
  while(!rotor_file.eof()){
    for(int i = 0; i <  Max_input; ++i){
      rotateForward[i] = input - i;
    //  rotateBackward[input] = i - input;
      rotor_file >> input;
    }
  }
rotor_file.close();
}


int Rotor :: map(int input){
  return input + rotateForward[input];

//return 0;

}

int Rotor :: mapBackward(int input){
//TODO
return 0;

}

//Destructor
Rotor :: ~Rotor(){

}


bool Rotor :: rotatedOneRound(){
  return numOfRotation == Max_input;
}


void Rotor :: rotate(){
  
  numOfRotation++;
}
