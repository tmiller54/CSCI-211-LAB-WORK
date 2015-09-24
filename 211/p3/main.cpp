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
  bool error;

  while(getline(cin, input)){

    if(input == "insert"){
      getline(cin, title);
      getline(cin, url);
      getline(cin, comment);
      cin >> length;
      cin >> rating;
      cin.ignore();

      video = new Video(title, url, comment, length, rating);
      error = vlist.Insert(video);
      if(!error){
        cerr << "Could not insert video <" << title << ">, already in list." << endl;
      }
    }

    else if(input =="print"){
      vlist.Print();
    }

    else if(input == "length"){
      cout << vlist.NumberOfVideos() << endl;
    }

    else if(input == "lookup"){
      getline(cin,title);
      error = vlist.VideoLookUp(title);
      if(!error){
        cerr << "Title <" << title << "> not in list." << endl;
      }
    }

    else if (input == "remove"){
      getline(cin,title);
      error = vlist.Remove(title);
      if(!error){
        cerr << "Title <" << title << "> not in list, could not delete." << endl;
      }
    }

    else{
      cerr << "<" << input << "> is not a legal command, giving up." << endl;
      return 1;
    }
  }
  return 0;
}
