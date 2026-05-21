#include <bits/stdc++.h>

using namespace std;

int ans;
int cnt;

vector<int> solution(string s) {
    while(s.size() != 1){
        cnt++;
        
        int len = 0;
        
        for(auto& c: s){
            len += (c == '1');
        }
        
        ans += (s.size() - len);
            
        
        s = "";
        while(len){
            s += (len % 2 ? "1" : "0");
            len /= 2;
        }
        
        reverse(s.begin(), s.end());
    }
    
    return {cnt, ans};
}