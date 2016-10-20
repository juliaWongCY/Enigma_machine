#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <utility>  //For the std :: pair

#include "Plugboard.hpp"
#include "Checker.hpp"
#include "Utils.hpp"

using namespace std;
extern const int Max_Input;

//Constructor
Plugboard :: Plugboard(){

}

void Plugboard :: readfile(char* filename){
  int input1;
  int input2;

//  int numOfInt = 0;

//Reading the plugboard file
  ifstream plugboard_file;
  plugboard_file.open(filename);


  if(!plugboard_file.is_open()){
    cout << "Error: Plugboard file cannot be opned." << endl;
    exit(EXIT_FAILURE);
  }

  //TODO: CHEKC!!
  //Insert the vector pair into the list of vectors

  plugboard_file >> input1;
  plugboard_file >> input2;



  while(!plugboard_file.eof()){
    PB_vec_pair.push_back(make_pair(input1, input2));
    plugboard_file >> input1;
    plugboard_file >> input2;

  }
/*
if(PB_vec_pair.size() % 2 != 0){
  cout << "Error: A plugboard file should contain an even number of numbers." << endl;
}
*/
/*
//The plugboard file should contain an even number of numbers
  if(numOfInt % 2 != 0){
    cout << "Error: A plugboard file should contain an even number of nums." << endl;
    exit(EXIT_FAILURE);
  } else {
    for(int i = 0; i < numOfInt - 1; i++){
      pair = make_pair(in_int[i], in_int[i+1]);
    }
  }

*/
  //vector< pair<int, int> > vec( (istreambuf_iterator<int>(plugboard_file)));


  plugboard_file.close();

}





typedef vector < pair<int, int> > vecPair;

int Plugboard :: map(int input){
 /* if(! isValidInput(input)){
  cout << "Error:Plugboard input out of bound." << endl;
  exit(EXIT_FAILURE);
  }
*/
  for(vecPair::const_iterator iter = PB_vec_pair.begin(); iter != PB_vec_pair.end(); iter++){
  if(iter->first == input){
    return iter->second;
  }
  if(iter->second == input){
    return iter->first;
  }
  }
  return input;
}

/*
char Plugboard :: getOutputChar(int input){
  return IntToChar(input);
}
*/


//Destructor
Plugboard :: ~Plugboard(){


}
