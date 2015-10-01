#include<iostream>
#include<string>
#include <stdlib.h> // for atoi
#include "dstack.h"
using namespace std;

int main(){
  DStack stack;

  char c = 1;
  while(c){
    c = cin.peek();

    if(c == -1){
      break;
    }

    if(c == ' ' || c == '\n' || c == '\t'){
      cin.ignore();
    }

    else if(isdigit(c)){
      double num;
      cin >> num;
      stack.Push(num);
    }
    else{
      string stringInput;
      double operand1;
      double operand2;

      cin >> stringInput;

      if(stack.Empty()){
        cerr << "No operands" << endl;
        return 1;
      }

      stack.Pop(operand1);
      stack.Pop(operand2);
      cout << stack.Size() << endl;
      cout << "op1: " << operand1 << endl;
      cout << "op2: " << operand2 << endl;

      if(stringInput == "+"){               //if adding
        double result = operand1 + operand2;
        cout << result << endl;
        stack.Push(result);
      }
    }
  }
  return 0;
}
