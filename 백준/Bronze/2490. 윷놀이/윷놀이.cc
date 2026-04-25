#include <bits/stdc++.h>
using namespace std;

int arr[10000];

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    int cnt;
    int tmp;
    int num = 3;
    while(num--){
        cnt = 0;
        for (int i =0;i<4;i++){
            cin>>tmp;
            if(tmp == 0)
                cnt++;
        }
        if (cnt){

            if (cnt == 1)
                cout<<'A'<<'\n';
            else if (cnt == 2)
                cout<<'B'<<'\n';
            else if (cnt == 3)
                cout<<'C'<<'\n';
            else
                cout<<'D'<<'\n';
        }
        else
            cout<<'E'<<'\n';
    }
    return 0;
}