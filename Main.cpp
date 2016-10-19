// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

#include "Plugboard.hpp"
#include "Reflector.hpp"
#include "Rotor.hpp"

using namespace std;

extern const int Max_input = 26;

int main(int argc, char **argv)
{

  if(argc < 2){
    cout<< "Please run the program in the form:" << endl;
    cout<< "./enigma <[rotors.rot]> <plugboards.pb" << endl;
    cout<< "<[rotors.rot]> -- valid rotor files, the number of rotors is not fixed." << endl;
    cout<< "<plugboard.pb> -- valid plugboard files." << endl;
    exit(EXIT_FAILURE);

  }


  //To get the rotor files
  vector<Rotor> num_rotors;

  for(int i = 0; i < argc -1; ++i){
    num_rotors.push_back(argv[1]);
    //TODO: rotors
  }

  //To get the plugboard file
  Plugboard pb_file = argv[argc - 1];
  pb_file = new Plugboard;

 // cout << "TODO: implement an Enigma machine" << endl;
  //return 0;
}
