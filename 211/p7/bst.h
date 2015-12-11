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
    void breadth(std::vector<std::string >&);
    double distance();
    bool balanced();
    void rebalance(std::vector<std::string>&);
    void insertBalanced(std::vector<std::string> &values, int start, int stop);
  private:
    class Node{
      public:
        Node(std::string value){
          mvalue = value;
          mleft = NULL;
          mright = NULL;
        }
        ~Node(){delete mleft; delete mright;}
      std::string mvalue;
      Node *mleft;
      Node *mright;
    };
    Node *mroot;
    int numOfElements;

    bool insert(std::string, Node* &);
    bool find(std::string, Node*);
    void print(std::vector<std::string> &, Node *&);
    double distance(Node*, double, double&);
    bool balanced(Node*);
    int height(Node*);
    void rebalance(std::vector<std::string>&, Node*&);
    void insertBalanced(Node*&, std::vector<std::string>&, int, int);
};
#endif
