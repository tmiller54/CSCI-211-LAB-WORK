#include<iostream>
#include<string>
#include<cmath>
#include "dstack.h"
using namespace std;

int main(){
    DStack stack;
    bool numberJustRead = false;                                //check to make sure inputs such as 1.2.3.4 don't occur w/o spaces
    double result;

    char c = 1;
    while(c){
        c = cin.peek();

        if(c == -1){                                    //if something goes wrong and there's no input, break out of while
            break;
        }

        if(c == ' ' || c == '\n' || c == '\t'){         //ignores any and all whitespace
            cin.ignore();
            numberJustRead = false;
        }

        else if(isdigit(c) || c == '.'){               //number entered and popped onto stack
            if(c == '.' && numberJustRead){
              cerr << "Error: Invalid expression." << endl;
              return 1;
            }
            double num;
            cin >> num;
            stack.Push(num);
            numberJustRead = true;
        }

        else if (c == '-'){
            char temp = cin.get();
            char negativeCheck = cin.peek();

            if(isdigit(negativeCheck)){                //if char after '-' is a number,
                cin.putback(temp);                     //then read in negative number

                if(numberJustRead){                    //stops inputs like 1.2-3 w/o spaces to differ subracting from negatives
                  cerr << "Error: Invalid expression." << endl;
                  return 1;
                }
                double num;
                cin >> num;
                stack.Push(num);
                numberJustRead = true;
            }

            else if(!isdigit(negativeCheck) && negativeCheck){  //if character after '-' is not number and exists,
                cin.putback(temp);                                //subtract first two on stack
                bool popResult;
                double operand1;
                double operand2;

                popResult = stack.Pop(operand1);
                if(!popResult){
                    cerr << "Error: Invalid expression." << endl;
                    return 1;
                }

                popResult = stack.Pop(operand2);
                    if(!popResult){
                    cerr << "Error: Invalid expression." << endl;
                    return 1;
                    }

                char operation = cin.get();
                if(operation == '-'){                 //if subtracting
                    result = operand2 - operand1;
                    stack.Push(result);
                }
                numberJustRead = false;
            }
        }

        else{                                           //everything not a number or blank space goes here
            char simpleInput;                           //for +,-,*,/, and ^
            string stringInput;                         //for sqrt, sin, cos, and avg
            double operand1;
            double operand2;

            cin >> simpleInput;
            char nextInput = cin.peek();                //this allows inputs such as ++ or -- without spaces to work properly.
            if(nextInput == '+' || nextInput == '-' || nextInput == '*' || nextInput == '/' || nextInput == '^'){
                // skip next cin
            }
            else if(nextInput == ' ' || nextInput == '\n' || nextInput == '\t'){
                cin.ignore();
            }
            else{
                cin >> stringInput;
            }

            if(stringInput == "ize"){                   //for debugging purposes
                cout << stack.Size() << endl;
            }

            else if(stringInput == "qrt"){              //if sqrt, only pop one number off stack
                bool popResult = stack.Pop(operand1);
                if(!popResult){
                    cerr << "No operands" << endl;
                    return 1;
                }
                result = sqrt(operand1);
                stack.Push(result);
            }

            else if(stringInput == "os"){               //if cos, only pop one number off stack
                bool popResult = stack.Pop(operand1);
                if(!popResult){
                    cerr << "No operands" << endl;
                    return 1;
                }
                result = cos(operand1*(M_PI/180));
                stack.Push(result);
            }

            else if(stringInput == "in"){               //if sin, only pop one number off stack
                bool popResult = stack.Pop(operand1);
                    if(!popResult){
                        cerr << "No operands" << endl;
                        return 1;
                    }
                result = sin(operand1*(M_PI/180));
                stack.Push(result);
            }

            else if(stringInput == "ve"){               //if avg, pop all values off stack
                int numOfValues = stack.Size();
                bool popResult = stack.Pop(operand1);
                    if(!popResult){
                        cerr << "No operands" << endl;
                        return 1;
                    }

                while(!stack.Empty()){
                    double tempOperand = 0;
                    stack.Pop(tempOperand);
                    operand1 += tempOperand;
                }

                result = operand1/numOfValues;
                stack.Push(result);
            }

            else{
                bool popResult = stack.Pop(operand1);
                if(!popResult){
                    cerr << "Error: Invalid expression." << endl;
                    return 1;
                }
                                                    //checking for not having enough operands
                popResult = stack.Pop(operand2);
                    if(!popResult){
                    cerr << "Error: Invalid expression." << endl;
                    return 1;
                }

                if(simpleInput == '+'){               //if adding
                    result = operand2 + operand1;
                    stack.Push(result);
                }

                //!!!!!subtracting done in negative check

                if(simpleInput == '*'){               //if multiplying
                    result = operand2*operand1;
                    stack.Push(result);
                }
                if(simpleInput == '/'){               //if dividing
                    if(!operand1){                    //dividing by 0
                        cerr << "Error: Invalid expression." << endl;
                        return 1;
                    }
                    result = operand2/operand1;
                    stack.Push(result);
                }
                if(simpleInput == '^'){               //if multiplying
                    if(!operand1){                    //n^0
                        result = 1;
                        stack.Push(result);
                    }
                    else if(!operand2 && operand1 < 0){    //0^(-n) = 1/0 error
                        cerr << "Error: Invalid expression." << endl;
                        return 1;
                    }
                    else if(operand2 < 0 && operand1 - floor(operand1)){ // -n^(decimal m)
                        operand2 *= -1;
                        result = -1 * pow(operand2,operand1);
                        stack.Push(result);
                    }
                    else{
                        result = pow(operand2,operand1);
                        stack.Push(result);
                    }
                }
            }
            numberJustRead = false;
        }
    }
    if(stack.Size() == 1){
      double output;
      stack.Pop(output);
      cout << output << endl;
    }
    else{
      cerr << "Error: Invalid expression." << endl;
      return 1;
    }

    return 0;
}
