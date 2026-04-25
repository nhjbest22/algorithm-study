#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int  a,b,c;
    cin>>a>>b>>c;
    if (a < b){
        if (a < c){
            cout<<a<<' '<<min(b,c)<<' '<<max(b,c);
        }
        else
            cout<<c<<' '<<a<<' '<<b;
    }
    else{
        if (a > c)
            cout<<min(b,c)<<' '<<max(b,c)<<' '<<a;
        else
            cout<<b<<' '<<a<<' '<<c;
    }
    return 0;
}