//vlist.cpp
//Miller, Travis
//travis
#include<iostream>
using namespace std;
#include "vlist.h"
#include "video.h"

Vlist::Vlist(){
  mhead = NULL;
}

Vlist::~Vlist(){
  Node *cur = mhead;
  while(cur){
    Node *temp = cur;
    cur = cur -> mnext;
    delete temp;
  }
}

bool Vlist::Insert(Video *vid){
  Node *errTemp = mhead;        //check for duplicate title.
  while(errTemp){
    if(vid -> GetTitle() == errTemp -> mvid -> GetTitle()){
      return false;
    }
    errTemp = errTemp -> mnext;
  }

  if(!mhead){                     //if no list, create node.
    mhead = new Node(vid, mhead);
  }

  else if (vid -> GetTitle() < mhead -> mvid -> GetTitle()){   //insert before head.
    mhead = new Node(vid, mhead);
  }
  else{                           //insert everywhere else.
    Node *cur = mhead;
    while(cur -> mnext && vid -> GetTitle() > cur -> mnext -> mvid -> GetTitle()){
      cur = cur -> mnext;
    }
    cur -> mnext = new Node(vid, cur -> mnext);
  }
  return true;
}

void Vlist::Print(){
  Node *cur = mhead;
  while(cur){
    cur -> mvid -> Print();
    cur = cur -> mnext;
  }
}

int Vlist::NumberOfVideos(){
  if(!mhead){
    return 0;
  }
  Node *cur = mhead;
  int numVids;
  while(cur){
    numVids++;
    cur = cur -> mnext;
  }
  return numVids;
}

bool Vlist::VideoLookUp(string title){
  Node *cur = mhead;
  while(cur){
    if(cur -> mvid -> GetTitle() == title){
      cur -> mvid -> Print();
      return true;
    }
    cur = cur -> mnext;
  }
  return false;
}

bool Vlist::Remove(string title){
  if(!mhead){
    return false;
  }

  if(mhead -> mvid -> GetTitle() == title){
    Node *temp = mhead;
    mhead = mhead -> mnext;
    delete temp;
    return true;
  }

  Node *cur = mhead;
  while(cur -> mnext && cur -> mnext -> mvid -> GetTitle() != title){
    cur = cur -> mnext;
  }
  if(!cur -> mnext){
    return false;
  }

  Node *temp = cur -> mnext;
  cur -> mnext = cur -> mnext -> mnext;
  delete temp;
  return true;
}
