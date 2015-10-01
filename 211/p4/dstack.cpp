#include <iostream>
using namespace std;
#include "dstack.h"

  DStack::DStack(){
    mhead = NULL;
    msize = 0;
  }

  DStack::~DStack(){
    while(mhead){
      Node *temp = mhead;
      mhead = mhead -> mnext;
      delete temp;
    }
  }

  void DStack::Push(double value){
    mhead = new Node(value, mhead);
    msize++;
  }

  bool DStack::Pop(double &value){
    if(!mhead){
      value = 0;
      return false;
    }

    value = mhead -> mvalue;

    Node *temp = mhead;
    mhead = mhead -> mnext;
    delete temp;

    msize--;

    return true;
  }

  bool DStack::Empty(){
    if(!msize)
      return true;
    else
      return false;
  }
