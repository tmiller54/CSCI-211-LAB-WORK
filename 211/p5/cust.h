#ifndef CUST_H
#define CUST_H

#include <string>

class Cust{
public:
  Cust(std::string name, bool isRobber, int arriveTime, int numItems);
  ~Cust();
  void Print(std::ostream &os);
  void EnterPrint(std::ostream &os, int clock);
  void DoneShoppingPrint(std::ostream &os, int clock);
  void StartCheckoutPrint(std::ostream &os, int clock, int cashier);
  void ExitPrint(std::ostream &os, int clock, int cashier, int numItems, int cash);
  std::string GetName();
  bool GetStatus();
  int GetNumItems();
private:
  std::string mname;
  bool misRobber;
  int marriveTime;
  int mnumItems;
};
#endif
