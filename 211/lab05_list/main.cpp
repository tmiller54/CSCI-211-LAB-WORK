#include <iostream>
using namespace std;
#include "list.h"

int main()
{
  // instantiate a List class (the constructor takes NO arguments)
  List list;

  int num = 0;;

  while(cin >> num){
    list.insertAtEnd(num);
  }

  list.print();
  cout << "sum = " << list.sum() << endl;
  return 0;
}
