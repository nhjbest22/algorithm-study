#include <iostream>
#include <vector>
using namespace std;
int main (){
    int num;
    int fnum, snum, tnum;
    cin >> num;
    int Result = 0;
    for (int i = 1; i<= num;i++){
        if (i <= 99)
            Result++;
        else if (i <1000){
            fnum = i / 100; snum = i%100;snum /=10; tnum = i%10;
            if ((fnum - snum) == (snum-tnum))
                Result++;
        }
    }
    cout<<Result;
    return 0;
}
