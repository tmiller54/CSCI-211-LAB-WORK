#ifndef PQUEUE_H
#define PQUEUE_H
#include "cust.h"

class Pqueue{
public:
  Pqueue();
  ~Pqueue();
  void enqueue(Cust *cust, int pri);
  Cust* dequeue();
  bool empty();
private:
  class Node
  {
    public:
      Node(Cust *cust, int pri, Node *next)
      {mcust = cust; mpri = pri; mnext = next;}
      Cust *mcust;
      int mpri;
      Node *mnext;
  };
  Node *mhead;
};
#endif
