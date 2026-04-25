#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
    int num,get;
    int m = 10000000,M = -10000000;
    cin>>num;
    for (int i =0; i< num;i++){
        cin >> get;
        if (M < get) M = get;
        if (m > get) m = get;
    }
    cout<<m<<" "<<M;
    return 0;
}