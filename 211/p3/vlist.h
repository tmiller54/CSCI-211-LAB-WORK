//vlist.h
//Miller, Travis
//travis
#ifndef VLIST_H
#define VLIST_H
#include "video.h"

class Vlist{
  public:
    Vlist();
    ~Vlist();
    void Insert(Video *vidPointer);
    void Print();
    void VideoLookUp(std::string title);
    void NumberOfVideos();
    void Remove(std:string title);
  private:
    class Video{
      public:
        Video(Video *vidPointer, Video *next){
          mvidPointer = vidPointer;
          mnext = next;
        }
        Video *mvidPointer;
        Video *mnext;
    };
    Node *mhead;
};


#endif
