#include <iostream>
#include "pqueue.h"
#include "cust.h"
using namespace std;

Pqueue::Pqueue(){
  mhead = NULL;
}

Pqueue::~Pqueue(){
  while(mhead){
    Node *temp = mhead;
    mhead = mhead -> mnext;
    delete temp;
  }
}

void Pqueue::Enqueue(Cust *cust, int pri){
  if(!mhead || (pri < mhead -> mpri)){
    mhead = new Node(cust, pri, mhead);
  }
  else{
    Node *cur = mhead;
    while (cur -> mnext && (pri >= cur -> mnext -> mpri)){
      cur = cur -> mnext;
    }
    cur -> mnext = new Node (cust, pri, cur -> mnext);
  }
}

Cust* Pqueue::Dequeue(){
  if(!mhead){
    return NULL;
  }
  Node *temp = mhead;
  Cust *ret = mhead -> mcust;
  mhead = mhead -> mnext;
  delete temp;
  return ret;
}

int Pqueue::PriOfFirstCust(){
  return mhead -> mpri;
}

int Pqueue::Size(){
  if(!mhead){
    return 0;
  }
  Node *cur = mhead;
  int num = 0;
  while(cur){
    num++;
    cur = cur -> mnext;
  }
  return num;
}

bool Pqueue::Empty(){
  if(!mhead){
    return true;
  }
  else
    return false;
}
