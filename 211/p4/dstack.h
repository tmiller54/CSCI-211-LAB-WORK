#ifndef DSTACK_H
#define DSTACK_H

class DStack {
  public:
    DStack();
    ~DStack();
    int Size() {return msize;}
    void Push(double value);
    bool Pop(double &value);
    bool Empty();

  private:
    class Node
    {
      public:
        Node(double value, Node *next){
          mnext = next;
          mvalue = value;
        }
        double mvalue;
        Node *mnext;
    };
    Node *mhead;
    int msize;
};

#endif
