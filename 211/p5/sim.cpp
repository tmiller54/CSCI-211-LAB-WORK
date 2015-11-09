#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include "cust.h"
#include "pqueue.h"
using namespace std;

struct cashiers{
  Cust *curCust;
  int cash;
  int onBreak;
  int checkOutTime;
};

void Simulation(Pqueue &arrivalQ, int numCashiers, int breakLen, ostream &os);

int main(int argc, char *argv[]){

  if(argc != 5){
    cerr << "Error: invalid number of command line arguments." << endl;
    return 1;
  }

  ifstream inFile(argv[3], ios::in);
  if(!inFile){
    cerr << "Error: could not open input file <" << argv[3] << ">." << endl;
    return 1;
  }

  ofstream outFile(argv[4], ios::out);
  if(!outFile){
    cerr << "Error: could not open output file <" << argv[4] << ">." << endl;
    return 1;
  }

  char *buf = argv[1];
  char check = 0;
  for(int i = 0; check = buf[ i ], check ; ++i ){
    if(!isdigit(check)){

      cerr <<"Error: invalid number of checkers specified." << endl;
      return 1;
    }
  }
  if(atoi(argv[1]) < 1){
    cerr <<"Error: invalid number of checkers specified." << endl;
    return 1;
  }

  buf = argv[2];
  check = 0;
  for(int i = 0; check = buf[ i ], check ; ++i ){
    if(!isdigit(check)){
      cerr <<"Error: invalid checker break duration specified." << endl;
      return 1;
    }
  }
  if(atoi(argv[2]) < 0){
    cerr <<"Error: invalid checker break duration specified." << endl;
    return 1;
  }

  Pqueue arrivalQ;

  string name;
  string robberCon;
  int arrivalTime;
  int numItems;

  while(inFile >> name){
    inFile >> robberCon;
    inFile >> arrivalTime;
    inFile >> numItems;

    Cust *newCust = new Cust(name, (robberCon == "robber" ? 1:0), arrivalTime, numItems);

    arrivalQ.Enqueue(newCust, arrivalTime);
  }

  Simulation(arrivalQ, atoi(argv[1]), atoi(argv[2]), outFile);
  return 0;
}


void Simulation(Pqueue &arrivalQ, int numCashiers, int breakLen, ostream &os){
  int clock;
  int numCust = arrivalQ.Size();
  Pqueue shoppingQ;
  Pqueue checkerQ;
  cashiers *cashier = new cashiers[numCashiers];

  for(int i = 0; i < numCashiers; i++){
    cashier[i].curCust = NULL;                          //initially serving no customers
    cashier[i].cash = 100;                              //set initial cash to 100 for each
    cashier[i].checkOutTime = 0;
  }

  for(clock = 1; numCust > 0; clock++){
    while(arrivalQ.Size() && (arrivalQ.PriOfFirstCust() == clock)){          //custs enter and begin shopping when arrive
      Cust *temp = arrivalQ.Dequeue();
      temp -> EnterPrint(os, clock);
      shoppingQ.Enqueue(temp, temp -> GetNumItems()*2 + clock);              //priority while shopping is number of items multiplied by two
    }

    while(shoppingQ.Size() && (shoppingQ.PriOfFirstCust() == clock)){
      Cust *temp = shoppingQ.Dequeue();
      temp -> DoneShoppingPrint(os, clock);
      checkerQ.Enqueue(temp, 1);
    }
    // while(!checkerQ.Empty()){
    //   Cust *temp = checkerQ.Dequeue();
    //   temp -> Print(cout);
    // }


    for(int i = 0; i < numCashiers; i++){
      int tempCash = 0;
      if(cashier[i].checkOutTime == clock){
        if(cashier[i].curCust && !cashier[i].curCust -> GetStatus()){       //customer exists and is shopper
          cashier[i].cash += (cashier[i].curCust -> GetNumItems()*3);
        }
        else if(cashier[i].curCust && cashier[i].curCust -> GetStatus()){   //customer exists and is robber
          tempCash = cashier[i].cash;                                   //used for robber's output
          cashier[i].cash = 0;
          cashier[i].onBreak = breakLen;
        }
        cashier[i].curCust -> ExitPrint(os,  clock,  i,  cashier[i].curCust->GetNumItems(),  tempCash);
        Cust *temp = cashier[i].curCust;                                    //deleting customer
        cashier[i].curCust = NULL;
        delete temp;
        numCust--;
      }
    }

    for(int i = 0; i < numCashiers; i++){
      while((!checkerQ.Empty()) && (cashier[i].onBreak <= 0 && !cashier[i].curCust)){
        cashier[i].curCust = checkerQ.Dequeue();
        cashier[i].curCust -> StartCheckoutPrint(os, clock, i);
        if(cashier[i].curCust->GetStatus()){
          cashier[i].checkOutTime = clock + 4;
        }
        else{
          cashier[i].checkOutTime = cashier[i].curCust -> GetNumItems() + clock;
        }
      }
    }

    for(int i = 0; i < numCashiers; i++){                                 //counts down checkers' breaktime
      cashier[i].onBreak--;
    }
  }

  // while(!checkerQ.Empty()){
  //   Cust *temp = checkerQ.Dequeue();
  //   temp -> Print(cout);
  // }

  for(int i = 0; i < numCashiers; i++){
    os << "registers[" << i << "] = $" << cashier[i].cash << endl;  //output final amounts in registers
  }
  os << "time = " << clock << endl;
}
