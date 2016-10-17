#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <utility>  //For the std :: pair

#include "Plugboard.hpp"
#include "Checker.hpp"
#include "Utils.hpp"

using namespace std;

vector <pair <int, int> > vec_pair;
pair <int, int> pair;


//Constructor
Plugboard :: Plugboard(){

}

int Plugboard :: map(int input){

}

char Plugboard :: getOutputChar(int input){
  return IntToChar(input);
}

int Plugboard :: transform(char* filename){
  int in_int;
  int out_int;

  int numOfInt = 0;

  ifstream plugboard_file;
  plugboard_file.open(filename);

  if(!plugboard_file.is_open()){
    cout << "Error: Plugboard file cannot be opned." << endl;
    exit(EXIT_FAILURE);
  }

  while(plugboard_file >> in_int){
    numOfInt++;
  }

  if(numOfInt % 2 != 0){
    cout << "Error: A plugboard file should contain an even number of nums." << endl;
    exit(EXIT_FAILURE);
  } else {
    for(int i = 0; i < numOfInt - 1; i++){
      pair = make_pair(in_int[i], in_int[i+1]);
    }
  }


  //vector< pair<int, int> > vec( (istreambuf_iterator<int>(plugboard_file)));


  plugboard_file.close();
  return
}




//Destructor
Plugboard :: ~Plugboard(){

}
