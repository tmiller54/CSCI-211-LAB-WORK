//chart.cpp
//Miller, Travis
//travis
#include<iostream>
using namespace std;

int FindLargest(int list[], int max) //Finds largest number in list
{
  int winner = 0;

  for(int i = 0; i < max; i++)
  {
    if(list[i]>winner)
    {
      winner = list[i];
    }

    if(list[i] == 0)
      break;
  }
  return winner;
}


int main()
{
  const int maxNumbers = 100;
  int values[maxNumbers];
  int width = 0;

  for(int i=0; i<maxNumbers; i++)
  {
    cin >> values[i];
    if(values[i] == 0)
    {
      width = i;
      break;
    }
  }

  int maxHeight = FindLargest(values, maxNumbers);

  for(int row = maxHeight; row > 0; row--) //combo of values and rows creates grid
  {
    for(int col = 0; col < width; col++)
    {
      if(values[col] >= row)
      {
        cout << "*";
      }
      else
      {
        cout << " ";
      }
    }
    cout << endl;
  }
}
