#ifndef TREE_H
#define TREE_H
#include <vector>

class Tree{
  public:
    Tree();
    ~Tree();

    std::string echo(std::string);
    bool insert(std::string);
    int size() {return numOfElements;}
    bool find(std::string);
    void print(std::vector<std::string> &);
    void breadth(std::vector<std::string >&);
    int distance();
    bool balanced();
    void rebalance();
  private:
    class Node{
      public:
        Node(int value){
          mvalue = value;
          mleft = NULL;
          mright = NULL;
        }
        ~Node(){delete mleft; delete mright;}
      int mvalue;
      Node *mleft;
      Node *mright;
    };

    Node *mroot;
    int numOfElements;

    bool insert(std::string, Node* &);
    void print(std::vector<std::string> &, Node *&);
    void breadth(std::vector<std::string> &, Node *&);
};
#endif
