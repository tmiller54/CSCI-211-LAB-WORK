#include<iostream>
#include "video.h"
using namespace std;

Video::Video(string title, string url, string comment, double length, int rating)
{
  mt = title;
  mu = url;
  mc = comment;
  ml = length;
  mr = rating;
}

void Video::print()
{
  cout <<  mt << ", " << mu << ", " << mc << ", " << ml << ", " << string(mr, '*') << endl;
}

<<<<<<< HEAD
bool Video::longer(Video *other)
{
  return ml > other->ml;
}
=======
bool Video::titleComp(Video *other)
{
  return mt > other->mt;
}

bool Video::lengthComp(Video *other)
{
  return ml > other->ml;
}

bool Video::rateComp(Video *other)
{
  return mr > other->mr;
}
>>>>>>> bc55dc3a55c902b7ac8048a342076cb076fd4aa2
