#include <iostream>
#include <string>
#include <vector>
#include "bst.h"
using namespace std; 

//****************************PUBLIC METHODS********************************//
Tree::Tree(){
  mroot = NULL;
}

Tree::~Tree(){
  delete mroot;
  mroot = NULL;
}

string Tree::echo(string value){
  return value;
}
bool Tree::insert(string value){
  return insert(value, mroot);
}
bool Tree::find(string value){
  return true;
}
void Tree::print(vector<string> &values){
  print(values, mroot);
}
void Tree::breadth(vector<string> &values){
  breadth(values, mroot);
}
int Tree::distance(){
  return 0;
}
bool Tree::balanced(){
  return true;
}
void Tree::rebalance(){

}
//***************************************************************************//
//****************************PRIVATE METHODS********************************//

bool Tree::insert(string str, Node *&curNode){
  return true;
}

void Tree::print(vector<string> &values, Node *&curNode){

}
void Tree::breadth(vector<string> &values, Node *&curNode){

}
