#include <iostream>
using namespace std;

#include "video.h"

int main()
{
  string sortMethod;            //holds the way to sort the video entries
  int maxVids = 100;            //max number allowed to be entered by user
  int numVidsEntered = 0;       //used to confirm number of entries

  string title;
  string url;
  string comment;               //Variables needed to store into video objects
  double length;
  int rating;

  Video *videos[maxVids];

  cin >> sortMethod;
  if(sortMethod != "rating" && sortMethod != "length" && sortMethod != "title"){
    cerr << sortMethod << " is not a legal sorting method, giving up." << endl;
    return 1;
  }

  while(getline(cin,title) || cin >> length || cin >> rating){
    getline(cin,title);
    getline(cin,url);
    getline(cin,comment);
    cin >> length;
    cin >> rating;

    videos[numVidsEntered] = new Video(title, url, comment, length, rating);

    numVidsEntered++;
  }
  if(numVidsEntered > maxVids){
    cerr << "Too many videos, giving up." << endl;
    return 1;
  }

  for(int i = 0; i<numVidsEntered-1; i++){
    videos[i] -> print();
  }



  return 0;
}
