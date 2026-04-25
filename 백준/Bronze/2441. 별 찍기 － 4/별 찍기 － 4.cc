#include <bits/stdc++.h>

using namespace std;

int main (){
    int num,save; cin>>num; save = num;
    while(num--){
        for(int i =0; i < save-num-1;i++){
            cout<<' ';
        }
        for (int i =0;i<num+1;i++){
            cout<<'*';
        }
        cout<<'\n';
    }
    return 0;
}