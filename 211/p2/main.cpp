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
  if(sortMethod != "rating" && sortMethod != "length" && sortMethod != "title"){  // error check for sorting method
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
  if(numVidsEntered > maxVids){                   // error check for video cap
    cerr << "Too many videos, giving up." << endl;
    return 1;
  }


  for (int last = numVidsEntered -1; last > 0; last--)
    for (int cur = 0; cur < last; cur++)
    
      if (videos[cur]->lengthCompare(videos[cur+1]))
        swap(videos[cur], videos[cur+1]);

  for(int i = 0; i<numVidsEntered-1; i++){
    videos[i] -> print();
  }



  return 0;
}
