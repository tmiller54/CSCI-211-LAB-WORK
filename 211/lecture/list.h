#ifndef LIST_H
#define LIST_H

class List{
  private:
    class Node{
      int mvalue;
      Node *mnext;
      Node(int value, Node *next){
        mvalue = value;
        mnext = next;
      }
    };
    Node *mhead;
  public:
    List();
    ~List();
    void insert(int value);
    void print();
};

#endif
