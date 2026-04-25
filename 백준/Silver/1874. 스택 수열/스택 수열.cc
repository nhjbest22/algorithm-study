#include <bits/stdc++.h>
#define visit VISIT

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> s;
    string str;
    int max(0), dat, K; cin>>K;
    while(K--){
        cin>>dat;
        if (dat > max){
            for (int i = max +1; i<= dat;i++){
                s.push(i); str+="+\n";
            }
        }
        else{
            if (dat != s.top()){
                cout<<"NO"; return 0;
            }
        }
        s.pop(); str+="-\n";
        if (max < dat) max = dat;
    }
    cout<<str;
    return 0;
}