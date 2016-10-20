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
  //TODO: Need to check if the file is valdi?
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
//  pb_file = new Plugboard(argv[argc-1]);

   //Set up the reflector
//  reflector = new Reflector();

  string input;
  cin >> ws;
  cin >> input;

  for(string :: iterator iter = input.begin(); iter != input.end(); ++iter){
    cout << Encryption(*iter);
    RotatingRotors();
  }




/*
  while(cin >> ws){
  //  cout << "inside while"<< endl;
    cin >> input;
    //input = cin.get();
//    cout << "input: " << input << endl;
    cout << Encryption(input);
    RotatingRotors();

  }*/
exit(EXIT_SUCCESS);
//return 0; //TODO
}


char Encryption(char c){

  int input = CharToInt(c);

// 1st -- after reading the file, pass into plugboard
   input =  pb.map(input);
// cout << "after pb map 1st" << input << endl;
//   pb_ptr->map(input);

//2nd -- pass to rotors(forward)
  for(unsigned int i = 0; i < num_rotors.size(); ++i){
  input = rotor.map(input);
  }
// cout << "after rotor mapforward: " << input << endl;
//  rotor_ptr->map(input);

//3rd -- pass to reflector
  input = reflector.map(input);
//  cout << "after reflector map: " << input << endl;
//  reflector->map(input);

//4th -- pass to rotors(backward)
  for(unsigned int i = 0; i < num_rotors.size(); ++i){
  input = rotor.mapBackward(input);
  }
//  cout << " after rotor mapback: " << input << endl;
//  rotor_ptr->mapBackward(input);

//5th -- pass throught plugboard again
  input = pb.map(input);
//  cout << " finish all process: " << input << endl;
//  pb_ptr->map(input);
//return result
  return (char)IntToChar(input);


}


//Manage the rotation of the rotors
void RotatingRotors(){
  for(unsigned int i = 0; i < num_rotors.size(); i++){
    //If the first rotor has rotated one cycle, the next rotor needs to rotate

    //num_rotors[i].rotate();
    if(num_rotors[i].rotatedOneRound()){
      num_rotors[i + 1].rotate();
    }

  }

}
