#ifndef PQUEUE_H
#define PQUEUE_H
#include "cust.h"

class Pqueue{
public:
  Pqueue();
  ~Pqueue();
  void Enqueue(Cust *cust, int pri);
  Cust* Dequeue();
  int PriOfFirstCust();
  bool Empty();
  int Size();
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
