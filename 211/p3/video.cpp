//video.cpp
//Miller, Travis
//travis
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

void Video::Print()
{
  cout <<  mt << ", " << mu << ", " << mc << ", " << ml << ", " << string(mr, '*') << endl;
}

bool Video::TitleComp(Video *other)
{
  return mt < other->mt;
}

bool Video::LengthComp(Video *other)
{
  return ml > other->ml;
}

bool Video::RateComp(Video *other)
{
  return mr < other->mr;
}
