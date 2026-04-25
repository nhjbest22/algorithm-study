#include <bits/stdc++.h>
using namespace std;

int arr[10000];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int x = 0,y = 0,z;
    int var;
    int num;
    cin>>num;
    x = num; y = num;
    while(num--){
        cin>>var;
        x += var/30;
        y += var/60;
    }
    if (x*10 < y*15){
        cout<<'Y'<<' '<<x*10;
    }
    else if (x*10 == y*15)
        cout<<'Y'<<' '<<'M'<<' '<<x*10;
    else
        cout<<'M'<<' '<<y*15;
    return 0;
}