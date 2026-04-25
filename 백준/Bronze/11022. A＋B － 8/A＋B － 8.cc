#include <iostream>
#include <cstring>
using namespace std;


int main (){
    int num;
    int fnum, snum;
    cin>>num;
    for (int i = 0; i < num;i++){
        cin>>fnum>>snum;
        cout<<"Case #"<<i+1<<": "<<fnum<<" + "<<snum<<" = "<<fnum+snum
        <<endl;
    }
    return 0;
}