#include <iostream>
#include <string>

#include <stdlib.h>
#include "Reflector.hpp"
#include "Checker.hpp"

using namespace std;

//Constructor
Reflector :: Reflector(){

}

int Reflector :: map(int input){
  if(! isValidInput(input)){
    cout << "Error: Please enter input in between 0 to 26." << endl;
    exit(EXIT_FAILURE);
  }
  return (input + 13) % 26;
}


//Destructor
Reflector :: ~Reflector(){

}
