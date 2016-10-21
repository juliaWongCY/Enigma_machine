// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "Rotor.hpp"
#include "Utils.hpp"
#include "Checker.hpp"

using namespace std;


//Function declaration
char Encryption(char c);
void RotatingRotors();

vector<Rotor> num_rotors;

Rotor rotor;
Plugboard pb;
Reflector reflector;

int main(int argc, char **argv){

  if(argc < 2){
    cout<< "Please run the program in the form:" << endl;
    cout<< "./enigma <[rotors.rot]> <plugboards.pb" << endl;
    cout<< "<[rotors.rot]> -- valid rotor files, the number of rotors is not fixed." << endl;
    cout<< "<plugboard.pb> -- valid plugboard files." << endl;
    exit(EXIT_FAILURE);

  }


  //To get the rotor files
  for(int i = 1; i < argc - 1; ++i){
   if(isRotorFile(argv[i])){
    rotor.readfile(argv[i]);
    num_rotors.push_back(rotor);
//    cout << num_rotors.size() << endl;
    }

  }

  //To get the plugboard file
  if(isPlugBoardFile(argv[argc-1])){
  pb.readfile(argv[argc-1]);
}
/*
  char currInt;
  string input;
  cin >> ws;
  getline(cin, input);
  string out = "";
  unsigned int rotorSize = num_rotors.size();
  for(unsigned int i = 0; i < input.length(); i++){
  char curr = input[i];
  currInt = CharToInt(curr);
  if(isupper(curr)){
  // pass to PlugBoard
  curr = pb.map(currInt);
    if(rotorSize > 0){
      // pass to rotor (forward)
      for(size_t j = 0; j < rotorSize; j++){
        currInt = num_rotors[j].map(currInt);
      }
    }

  // pass to reflector
  currInt = reflector.map(currInt);

    //pass to rotor(backward)
    if(rotorSize > 0){
      for(unsigned int j =0; j < rotorSize; j++){
        currInt = num_rotors[rotorSize - j - 1].map(currInt);
      }
    }
      

  //Pass to PlugBoard(backward)
  currInt = pb.map(currInt);

  RotatingRotors();
  
  } else {

  cout << " error: input should be capital and non whitespace." << endl;
  exit(EXIT_FAILURE);
  }
}
  cout << currInt << endl;
  exit(EXIT_SUCCESS);

}
*/

  string input;
  cin >> ws;
  getline(cin, input);

  for(string :: iterator iter = input.begin(); iter != input.end(); ++iter){
    if(isupper(*iter)){
  cout << Encryption(*iter);
  } else{
    cout <<"Error: the input should be Upper case and non white space char" << endl;
    exit(EXIT_FAILURE);
  }
}

exit(EXIT_SUCCESS);
//return 0; //TODO
}


char Encryption(char c){

  int input = CharToInt(c);
  size_t rotorSize = num_rotors.size();

// 1st -- after reading the file, pass into plugboard
   input =  pb.map(input);


//2nd -- pass to rotors(forward)
  for(unsigned int i = 0; i < rotorSize; ++i){
  input = num_rotors[i].map(input);
  }

//  cout << "input: " << input << endl;

//3rd -- pass to reflector
  input = reflector.map(input);

//4th -- pass to rotors(backward)
//  for(unsigned int i = num_rotors.size() - 1; i >= 0; i--){
  for(unsigned int i = 0; i < rotorSize; ++i){
  input = num_rotors[rotorSize - i - 1].mapBackward(input);
  }

//5th -- pass through plugboard again
  input = pb.map(input);
    
  RotatingRotors();

  return (char)IntToChar(input);
}


//Manage the rotation of the rotors
void RotatingRotors(){
  for(unsigned int i = 0; i < num_rotors.size(); i++){
    //If the first rotor has rotated one cycle, the next rotor needs to rotate

    num_rotors[i].rotate();
    if(num_rotors[i].rotatedOneRound() && (i+1) < num_rotors.size()){
      num_rotors[i + 1].rotate();
    }

  }

}
