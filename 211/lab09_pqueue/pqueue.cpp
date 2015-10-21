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

void Pqueue::enqueue(Cust *cust, int pri){
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

Cust* Pqueue::dequeue(){
  if(!mhead){
    return NULL;
  }
  Node *temp = mhead;
  Cust *ret = mhead -> mcust;
  mhead = mhead -> mnext;
  delete temp;
  return ret;
}

bool Pqueue::empty(){
  if(!mhead){
    return true;
  }
  else
    return false;
}
