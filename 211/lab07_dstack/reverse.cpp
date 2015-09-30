#include <iostream>
using namespace std;
#include "dstack.h"

int main()
{
    double value;
    DStack stack;

    // as long as there is input
    while (cin >> value)
      stack.Push(value);

    cout << "There are " << stack.Size() << " numbers in the stack." << endl;
    // as long as the stack is not empty, pop numbers and print them
    // pop return false if the pop failed
    while (stack.Pop(value))
      cout << value << endl;
    cout << "There are " << stack.Size() << " numbers in the stack." << endl;


    return 0;
}
