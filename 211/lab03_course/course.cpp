#include<iostream>
#include "course.h"
using namespace std;

Course::Course(string dept,int number, int time)
{
  md = dept;
  mn = number;
  mt = time;
}

void Course::print()
{
  cout << md << " " << mn << " at " << mt << endl;
}
