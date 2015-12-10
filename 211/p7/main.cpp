//main.cpp
//Travis Miller
//Program 7
#include <iostream>
#include <string>
#include <vector>
#include "bst.h"
using namespace std;

int main(){
  Tree tree;
  string input;
  string argument;

  while(cin >> input){
    if(input == "echo"){
      cin.ignore();
      getline(cin,argument);
      cout << argument << endl;
    }

    else if(input == "insert"){
      cin.ignore();
      getline(cin,argument);
      bool errCheck = tree.insert(argument);
      if(!errCheck){
        cerr << "insert <" << argument << "> failed. String already in tree.\n" << endl;
      }
    }

    else if(input == "size"){
      cout << tree.size() << endl;
    }

    else if(input == "find"){
      cin.ignore();
      getline(cin,argument);
      bool found = tree.find(argument);
      if(found){
        cout << "<" << argument << "> is in tree.\n";
      }
      else{
        cout << "<" << argument << "> is not in tree.\n";
      }
    }

    else if(input == "print"){
      vector<string> strings;
      tree.print(strings);
      cout << "{";
      for(unsigned int i = 0; i < strings.size(); i++){
        cout << strings[i];
        if(i < strings.size()-1){
          cout << ", ";
        }
      }
      cout << "}" << endl;
    }

    else if(input == "breadth"){
      vector<string> strings;
      tree.breadth(strings);
      cout << "{";
      for(unsigned int i = 0; i < strings.size(); i++){
        cout << strings[i];
        if(i < strings.size()-1){
          cout << ", ";
        }
      }
      cout << "}" << endl;
    }

    else if(input == "distance"){
      cout << "Average distance of nodes to root = " << tree.distance() << endl;
    }

    else if(input == "balanced"){

    }

    else if(input == "rebalance"){

    }
    else if(input == "print parent"){
      vector<string> strings;
      tree.PrintParent(strings);
      cout << "{";
      for(unsigned int i = 0; i < strings.size(); i++){
        cout << strings[i];
        if(i < strings.size()-1){
          cout << ", ";
        }
      }
      cout << "}" << endl;
    }

    else{
      cerr << "Illegal command <" << input << ">.\n";
      getline(cin,argument);                   //eating up rest of line
    }
  }

  return 0;
}
