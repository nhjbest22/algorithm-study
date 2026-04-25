#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> s;
    int num, dat;
    string str;
    cin >>num;
    int sum = 0;
    while (num--){
        cin >>dat;
        if (dat != 0)
            s.push(dat);
        else    
            s.pop();
    }
    while (!s.empty()){
        sum += s.top();
        s.pop();
    }
    cout<<sum;
    return 0;
}