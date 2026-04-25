#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int sum = 0;
    bool flag =  true;
    int M = 101;
    int  a,b,c;
    int num = 7;
    while (num--){
        cin>>a;
        if (a%2 == 1){
            if(a < M)
                M = a;
            sum+=a;
            flag = false;
        }
    }
    if (flag){
        cout<<-1; return 0;
    }
    cout<<sum<<'\n'<<M;
    return 0;
}