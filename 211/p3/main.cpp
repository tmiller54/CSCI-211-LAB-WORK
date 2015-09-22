//main.cpp
//Miller, Travis
//travis
#include<iostream>
using namespace std;
#include "vlist.h"
#include "video.h"

int main(){
  Vlist vlist;
  Video *video;

  string input;
  string title;
  string url;
  string comment;
  double length;
  int rating;

  while(getline(cin, input)){

    if(input == "insert"){
      getline(cin, title);
      getline(cin, url);
      getline(cin, comment);
      cin >> length;
      cin >> rating;
      cin.ignore();

      video = new Video(title, url, comment, length, rating);
      vlist.Insert(video);
    }

    else if(input =="print"){
      vlist.Print();
    }

    else if(input == "length"){

    }

    else if(input == "lookup"){

    }

    else if (input == "remove"){

    }

    else{
      cerr << "<" << input << "> is not a legal command, giving up." << endl;
      return 1;
    }
  }
  return 0;
}
