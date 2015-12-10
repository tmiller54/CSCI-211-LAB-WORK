//bst.h
//Travis Miller
//Program 7
#ifndef TREE_H
#define TREE_H
#include <vector>

class Tree{
  public:
    Tree();
    ~Tree();

    bool insert(std::string);
    int size() {return numOfElements;}
    bool find(std::string);
    void print(std::vector<std::string> &);
    void PrintParent(std::vector<std::string> &);
    void breadth(std::vector<std::string >&);
    double distance();
    int balanced();
    void rebalance();
  private:
    class Node{
      public:
        Node(std::string value, Node *parent){
          mvalue = value;
          mleft = NULL;
          mright = NULL;
          mparent = parent;
        }
        ~Node(){delete mleft; delete mright;}
      std::string mvalue;
      Node *mleft;
      Node *mright;
      Node *mparent;
    };
    Node *mroot;
    int numOfElements;

    bool insert(std::string, Node* &);
    bool find(std::string, Node*);
    void print(std::vector<std::string> &, Node *&);
    void PrintParent(std::vector<std::string> &, Node *&);
    double distance(Node *, double, double&);
    int balanced(Node *curNode);
};
#endif
