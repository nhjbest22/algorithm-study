#include <bits/stdc++.h>
using namespace std;

int arr[10000];

void func (int arr[]){
    sort(arr,arr+9);
    for (int i =0;i<7;i++){
        cout<<arr[i]<<'\n';
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int x,y,z;
    int sum = 0;
    int num = 9;
    while(num--){
        cin >> x; sum += x;
        arr[8-num] =x; 
    }
    sum -=100;
    for (int i =0;i<8;i++){
        for (int j = i+1;j<=8;j++){
            if (arr[i] + arr[j] == sum){
                arr[i] = 100; arr[j] = 100;
                func(arr);
                return 0;
            }
        }
    }
}