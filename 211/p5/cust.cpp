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

int Cust::GetNumItems(){
  return mnumItems;
}
string Cust::GetName(){
  return mname;
}

bool Cust::GetStatus(){
  if(misRobber){
    return true;
  }
  else{
    return false;
  }
}

void Cust::Print(ostream &os){
  string status;
  if(misRobber)
    status = "robber";
  else
    status = "shopper";

  os << mname << " " << status << " " << marriveTime << " " << mnumItems << endl;
}

void Cust::EnterPrint(std::ostream &os, int clock){
  os << clock << ": " << mname << " entered store" << endl;
}

void Cust::DoneShoppingPrint(std::ostream &os, int clock){
  os << clock << ": " << mname << " done shopping" << endl;
}

void Cust::StartCheckoutPrint(std::ostream &os, int clock, int cashier){
  os << clock << ": " << mname << " started checkout with checker " << cashier << endl;
}

void Cust::ExitPrint(std::ostream &os, int clock, int cashier, int numItems, int cash){
  if(misRobber){
    os << clock << ": " << mname << " stole $" << cash << " and " << mnumItems << " " << (mnumItems == 1 ? "item":"items") << " from checker " << cashier << endl;
  }
  else{
    os << clock << ": " << mname << " paid $" << mnumItems*3 << " for " << mnumItems << " " << (mnumItems == 1 ? "item":"items") << " to checker " << cashier << endl;
  }
}
