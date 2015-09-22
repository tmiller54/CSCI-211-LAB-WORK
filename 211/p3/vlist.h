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
    void Insert(Video *vid);
    void Print();
    void VideoLookUp(std::string title);
    void NumberOfVideos();
    void Remove(std::string title);
  private:
    class Node{
      public:
        Node(Video *vid, Node *next){
          mvid = vid;
          mnext = next;
        }
        Video *mvid;
        Node *mnext;
    };
    Node *mhead;
};


#endif
