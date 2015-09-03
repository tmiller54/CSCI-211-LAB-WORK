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
  cout <<  mt << ", " << mu << ", " << mc << ", " << ml << ", " << this -> StarRating(mr);
}

void Video::StarRating(int r)
{
  for(int i = 0; i < r; i++)
  {
    cout << "*";
  }
}
