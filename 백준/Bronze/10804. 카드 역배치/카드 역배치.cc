#include <bits/stdc++.h>
using namespace std;

int arr[30];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int x,y,z;
    for (int i =0;i<20;i++){
        arr[i+1] = i+1;
    }
    int num = 10;
    while(num--){
        cin>>x>>y;
        for (int i = 0;i<(y-x+1)/2;i++){
            swap(arr[x+i],arr[y-i]);
        }
    }
    for (int i =0;i<20;i++){
        cout<<arr[i+1]<<' ';
    }
    return 0;
}