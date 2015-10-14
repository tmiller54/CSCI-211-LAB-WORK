#include <iostream>
#include <string>
#include "cust.h"
using namespace std;

Cust::Cust(string name, bool isRobber, int arriveTime, int numItems){
  mname = name;
  misRobber = isRobber;
  marriveTime = arriveTime;
  mnumItems = numItems;
}

Cust::~Cust(){

}

void Cust::print(ostream &os){
  string status;
  if(misRobber)
    status = "robber";
  else
    status = "shopper";

  os << mname << " " << status << " " << marriveTime << " " << mnumItems << endl;

}
