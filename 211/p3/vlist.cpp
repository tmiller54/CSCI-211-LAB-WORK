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

void Vlist::Insert(Video *vid){
  if(!mhead)
    mhead = new Node(vid, mhead);

  Node *cur = mhead;
  while(cur -> mnext && cur -> mvid->TitleComp(vid)){
    cur = cur -> mnext;
  }
  cur -> mnext = new Node(vid, cur -> mnext);
}

void Vlist::Print(){
  Node *cur = mhead;
  while(cur){
    cur -> mvid -> Print();
    cur = cur -> mnext;
  }
}

void Vlist::VideoLookUp(string title){

}

void Vlist::NumberOfVideos(){

}

void Vlist::Remove(string title){

}
