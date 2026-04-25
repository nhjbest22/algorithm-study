#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main (){
    int num,casenum;
    string str;
   cin>>casenum;
   for (int z = 0; z< casenum; z++){
       cin >> num >> str;
        for (int i = 0; i <str.size(); i++){
            for (int j = 0; j< num;j++){
                cout<<str[i];
            }
        }
       cout<<endl;
   }
   return 0;

}