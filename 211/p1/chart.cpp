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

int FindWidth(int list[], int max)// finds how many values there are in values array before the '0'
{

}


int main()
{
  const int maxNumbers = 100;
  int values[maxNumbers];

  for(int i=0; i<maxNumbers; i++)
  {
    cin >> values[i];
    if(values[i] == 0)
      break;
  }

  int maxHeight = FindLargest(values, maxNumbers);
  int bars[maxHeight];

  for(int i = 0; i < maxHeight; i++)  //fills bars with ascending numers up to the maxheigt
  {
    bars[i] = i;
  }

  for(int i = 0; i<maxHeight; i++)
  {cout << bars[i] << " ";}

  for(int i = 0; i<maxHeight; i++)
  {
    for(int j = 0; j<maxNumbers; j++)
    {
      if(values[i] <= bars[j])
      {
        cout << "*";
      }

    }
  }

}
