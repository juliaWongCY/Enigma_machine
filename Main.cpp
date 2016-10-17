// skeleton C++ file, you will need to edit this and other files to implement your enigma machine
#include <stdexcept>
#include <iostream>
#include <fstream>

#include <stdlib.h>

using namespace std;

int main(int argc, char **argv)
{

  if(argc < 2){
    cout<< "Please run the program in the form:" << endl;
    cout<< "./enigma <[rotors.rot]> <plugboards.pb" << endl;
    cout<< "<[rotors.rot]> -- valid rotor files, the number of rotors is not fixed." << endl;
    cout<< "<plugboard.pb> -- valid plugboard files." << endl;
    exit(EXIT_FAILURE);

  }

  for(int i = 0; i < argc -1; ++i){
    //TODO: rotors
  }

 // cout << "TODO: implement an Enigma machine" << endl;
  //return 0;
}
