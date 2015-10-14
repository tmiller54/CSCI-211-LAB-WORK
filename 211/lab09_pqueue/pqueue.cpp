#include <iostream>
#include "pqueue.h"
#include "cust.h"
using namespace std;

Pqueue::Pqueue(){
  mhead = NULL;
}

Pqueue::~Pqueue(){


}

void Pqueue::enqueue(Cust *cust, int pri){


}

Cust Pqueue::dequeue(){
  Node *temp = mhead;
  Node *ret = mhead;
  mhead = mhead -> mnext;
  delete temp;
  return *(ret -> mcust);
}

bool Pqueue::empty(){

return true;
}
