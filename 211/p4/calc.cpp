#include<iostream>
#include<string>
#include<cmath>
#include "dstack.h"
using namespace std;

int main(){
    DStack stack;

    char c = 1;
    while(c){
        c = cin.peek();

        if(c == -1){                                    //if something goes wrong and there's no input, break out of while
            break;
        }

        if(c == ' ' || c == '\n' || c == '\t'){         //ignores any and all whitespace
            cin.ignore();
        }

        else if(isdigit(c)){                            //number entered and popped onto stack
            double num;
            cin >> num;
            stack.Push(num);
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
                double result = sqrt(operand1);
                cout << result << endl;
                stack.Push(result);
            }

            else if(stringInput == "os"){               //if cos, only pop one number off stack
                bool popResult = stack.Pop(operand1);
                if(!popResult){
                    cerr << "No operands" << endl;
                    return 1;
                }
                double result = cos(operand1*(M_PI/180));
                cout << result << endl;
                stack.Push(result);
            }

            else if(stringInput == "in"){               //if sin, only pop one number off stack
                bool popResult = stack.Pop(operand1);
                    if(!popResult){
                        cerr << "No operands" << endl;
                        return 1;
                    }
                double result = sin(operand1*(M_PI/180));
                cout << result << endl;
                stack.Push(result);
            }

            else if(stringInput == "vg"){               //if avg, pop all values off stack
                bool popResult = stack.Pop(operand1);
                    if(!popResult){
                        cerr << "No operands" << endl;
                        return 1;
                    }

                    int numOfValues = stack.Size() + 1;
                while(!stack.Empty()){
                    double tempOperand = 0;
                    stack.Pop(tempOperand);
                    operand1 += tempOperand;
                }

                double result = operand1/numOfValues;
                cout << result << endl;
                stack.Push(result);
            }

            else{
                bool popResult = stack.Pop(operand1);
                if(!popResult){
                    cerr << "No operands" << endl;
                    return 1;
                }
                                                    //checking for not having enough operands
                popResult = stack.Pop(operand2);
                    if(!popResult){
                    cerr << "Error: Invalid expression." << endl;
                    return 1;
                }

                cout << "op1: " << operand1 << endl;
                cout << "op2: " << operand2 << endl;

                if(simpleInput == '+'){               //if adding
                    double result = operand2 + operand1;
                    cout << result << endl;
                    stack.Push(result);
                }
                if(simpleInput == '-'){               //if subtracting
                    double result = operand2 - operand1;
                    cout << result << endl;
                    stack.Push(result);
                }
                if(simpleInput == '*'){               //if multiplying
                    double result = operand2*operand1;
                    cout << result << endl;
                    stack.Push(result);
                }
                if(simpleInput == '/'){               //if dividing
                    double result = operand2/operand1;
                    cout << result << endl;
                    stack.Push(result);
                }
                if(simpleInput == '^'){               //if multiplying
                    double result = pow(operand2,operand1);
                    cout << result << endl;
                    stack.Push(result);
                }
            }
        }
    }
    return 0;
}
