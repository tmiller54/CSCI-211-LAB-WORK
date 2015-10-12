#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


int main(int argc, char *argv[])
{
  int sum = 0;
    string argument;
    for(int i = 1; i < argc; i++){
      argument = argv[i];
      for(unsigned int j = 0; j < argument.length(); j++){
        if(isdigit(argument[j])){
          //do nothing
        }
        else{
          cerr << "Error: illegal integer." << endl;
          return 1;
        }
      }
      sum += atoi(argv[i]);
    }

    cout << sum << endl;

    return 0;
}
