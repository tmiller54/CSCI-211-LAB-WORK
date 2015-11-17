#include <iostream>
#include <vector>
#include "location.h"
using namespace std;

int main(){
  vector<Location *> loc;
  double lat, longi;
  while(cin >> lat){
    cin >> longi;
    loc.push_back(new Location(lat,longi));
  }

  for(int i = 0; i<(signed)loc.size(); i++){
    loc[i]->print(cout);
    cout << endl;
  }
  return 0;
}
