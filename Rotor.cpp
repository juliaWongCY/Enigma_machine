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
  numOfRotation = 0;
  int input; //For passing in the data from the file
  ifstream rotor_file(filename);
  //rotor_file.open(filename);

  if(!rotor_file.is_open()){
  cout << "Error: Rotor file cannot be opened." << endl;
  exit(EXIT_FAILURE);
  }


  rotor_file >> input;
  while(!rotor_file.eof()){
    for(int i = 0; i <  Max_input; ++i){
//      moveForward[i] = i;
      moveForward[i] = input - i;
      moveBackward[input] = i - input;
      rotor_file >> input;
    }
  }
rotor_file.close();
}


int Rotor :: map(int input){
  //considering negative input
  if(input < 0){
  return (26 +(input +  moveForward[input])) % Max_input;
  }
 return (input + moveForward[input]) % Max_input;
}

int Rotor :: mapBackward(int input){
//Considering negative output
  if(input < 0){
   return (26 + (input + moveBackward[input])) % Max_input;
  }
  return (input + moveBackward[input]) % Max_input;


}

//Destructor
Rotor :: ~Rotor(){

}


bool Rotor :: rotatedOneRound(){
//  return numOfRotation == Max_input;
  
  if(numOfRotation == Max_input){
    numOfRotation = 0;
    return true;
  }
  return false;
}

//After each input, the rotor will advance one posiiton
void Rotor :: rotate(){

 //We need to shift forward and backward by one
 int ori_last_forward = moveForward[Max_input - 1];
 int ori_last_backward = moveBackward[Max_input - 1];

 for(int i = 0; i < Max_input - 1; i++){
  moveForward[i + 1] = moveForward[i];
  moveBackward[i + 1] = moveBackward[i];
 }

  //The first element in the list now should be the last elem before
  moveForward[0] = ori_last_forward;
  moveBackward[0] = ori_last_backward;

  numOfRotation++;

}
