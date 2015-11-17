#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "location.h"
using namespace std;

int main(){
 map<string, Location*> lookup;
 vector<Location *> loc;
 vector<string> titles;
 double lat, longi;
 string title;

 while(cin >> lat){
   if(lat){
     cin >> longi;
     loc.push_back(new Location(lat,longi));

     cin >> title;
     lookup[title] = loc.back();
   }
   else{
     break;
   }
 }

 while(cin >> title){
   titles.push_back(title);
 }

 for(int i = 0; i < (signed)titles.size(); i++){
   if(lookup[titles[i]]){
     cout << titles[i] << " is at ";
     lookup[titles[i]]->print(cout);
     cout << endl;
   }
   else{
     cout << titles[i] << " not in database" << endl;
   }
 }

 return 0;
}
