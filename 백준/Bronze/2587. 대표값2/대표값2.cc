#include <bits/stdc++.h>
using namespace std;

int arr[10000];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int cnt;
    int tmp = 0;
    int num = 5;
    while(num--){
        cin>>cnt;
        tmp+=cnt;
        arr[4-num] = cnt;
    }
    sort(arr,arr+5);
    cout<<tmp/5<<'\n'<<arr[2];
    return 0;
}