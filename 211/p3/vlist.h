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
    bool Insert(Video *vid);
    void Print();
    int NumberOfVideos();
    bool VideoLookUp(std::string title);
    bool Remove(std::string title);
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
