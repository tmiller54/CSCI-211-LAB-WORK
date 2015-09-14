//main.cpp
//Miller, Travis
//travis
#include <iostream>
using namespace std;

#include "video.h"

int main()
{
  string sortMethod;            //holds the way to sort the video entries
  const int maxVids = 100;            //max number allowed to be entered by user
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

  while(getline(cin,title)){
    if(numVidsEntered == 0)
      getline(cin,title);
    getline(cin,url);
    getline(cin,comment);
    cin >> length;
    cin >> rating;
    cin.ignore();
    if (title == "")
      break;
    videos[numVidsEntered] = new Video(title, url, comment, length, rating);
    numVidsEntered++;
  }

  if(numVidsEntered > maxVids){
    cerr << "Too many videos, giving up." << endl;
    return 1;
  }

  if(sortMethod == "title"){           //Sorts the videos based on method selected
    for (int last = numVidsEntered -1; last > -1; last--)
     for (int cur = 0; cur < last; cur++)
       if (videos[cur]->titleComp(videos[cur+1]))
         swap(videos[cur], videos[cur+1]);
  }

  else if(sortMethod == "length"){
    for (int last = numVidsEntered -1; last > -1; last--)
     for (int cur = 0; cur < last; cur++)
       if (videos[cur]->lengthComp(videos[cur+1]))
         swap(videos[cur], videos[cur+1]);
  }

  else if(sortMethod == "rating"){
    for (int last = numVidsEntered -1; last > 0; last--)
     for (int cur = 0; cur < last; cur++)
       if (videos[cur]->rateComp(videos[cur+1]))
         swap(videos[cur], videos[cur+1]);
  }

  for(int i = 0; i<numVidsEntered; i++){
    videos[i] -> print();
  }

  return 0;
}
