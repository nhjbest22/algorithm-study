#include <iostream>
#include <cstring>
using namespace std;


int main (){
    int count = 0;
    int num;
    int fnum, snum;
    cin >>num;
    snum = num;
    while (1){
        
        fnum = num/ 10 + num%10;
        num = (num%10)*10 + fnum%10;
        count++;
        if (snum == num){
            cout<<count;
            return 0;
        }
    }
}