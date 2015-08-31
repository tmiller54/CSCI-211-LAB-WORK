#include<iostream>
using namespace std;

int main()
{
  int value;
  bool allEven = true;

  while(cin >> value)
  {
    if(value%2 != 0)
      allEven = false;
  }

  if(allEven)
  {
    cout << "all even" << endl;
    return 0;
  }
  else if (!allEven)
  {
    cerr << "not all even" << endl;
    return 1;
  }
}
