//bst.cpp
//Travis Miller
//Program 7
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include "bst.h"
using namespace std;

//****************************PUBLIC METHODS********************************//
Tree::Tree(){
  mroot = NULL;
  numOfElements = 0;
}

Tree::~Tree(){
  delete mroot;
  mroot = NULL;
}

bool Tree::insert(string value){
  return insert(value, mroot);
}

bool Tree::find(string value){
  return find(value, mroot);
}

void Tree::print(vector<string> &values){
  print(values, mroot);
}

void Tree::breadth(vector<string> &values){
  if(!mroot){
    return;
  }
  queue<Node*> q;

  q.push(mroot);
  while(!q.empty()){
    Node* temp = q.front();
    q.pop();
    values.push_back(temp->mvalue);
    if(temp->mleft){
      q.push(temp->mleft);
    }
    if(temp->mright){
      q.push(temp->mright);
    }
  }
}

double Tree::distance(){
  double total = 0;
  return distance(mroot, 0, total);
}

int Tree::balanced(){
  return balanced(mroot);
}

void Tree::rebalance(){

}

//***************************************************************************//
//****************************PRIVATE METHODS********************************//

bool Tree::insert(string value, Node *&curNode){
  if(!curNode){
    curNode = new Node(value);
    numOfElements++;
    return true;
  }
  if(value == curNode->mvalue){
    return false;
  }
  if(value < curNode->mvalue){
    return insert(value, curNode->mleft);
  }
  if(value > curNode->mvalue){
    return insert(value, curNode->mright);
  }
  return false;
}

bool Tree::find(string value, Node *curNode){
  if(!curNode){
    return false;
  }
  if(value == curNode -> mvalue){
    return true;
  }
  if(value < curNode -> mvalue){
    return find(value, curNode -> mleft);
  }
  if(value > curNode -> mvalue){
    return find(value, curNode -> mright);
  }
  return false;
}

void Tree::print(vector<string> &values, Node *&curNode){
  if(!curNode){
    return;
  }
  print(values, curNode -> mleft);
  values.push_back(curNode -> mvalue);
  print(values, curNode -> mright);
}

double Tree::distance(Node *curNode, double layer, double &total){
  if(!curNode){
    return layer;
  }
  distance(curNode -> mleft, layer+1, total);
  total += layer;
  distance(curNode -> mright, layer+1, total);
  return total/numOfElements;
}

int Tree::balanced(Node *curNode){
  return 0;
}
