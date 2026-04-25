#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,x,y;
    cin>>t>>x>>y;
    if (t==x && x==y){
        cout<<10000+x*1000;
    }
    else if (t ==x || x==y ||t==y){
        if (t ==x)
            cout<<1000+t*100;
        else if (t == y)
            cout<<1000+y*100;
        else 
            cout<<1000+x*100;
    }
    else
        cout<<max(max(t,x),y)*100;
}