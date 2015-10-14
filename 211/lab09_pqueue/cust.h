#ifndef CUST_H
#define CUST_H

#include <string>

class Cust{
public:
  Cust(std::string name, bool isRobber, int arriveTime, int numItems);
  ~Cust();
  void print(std::ostream &os);
private:
  std::string mname;
  bool misRobber;
  int marriveTime;
  int mnumItems;
};
#endif
