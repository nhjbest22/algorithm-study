#include <bits/stdc++.h>

using namespace std;

int total = 10;
unordered_map<string, int> um;
int ans;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    for(int i = 0; i< want.size(); i++){
        string& food = want[i];
        int cnt = number[i];
        
        um[food] = cnt;
    }
    
    for(int i = 0; i < 10; i++){
        string& food = discount[i];
        if(um.find(food) == um.end()) continue;
        
        if(um[food] > 0) total--;
        um[food]--;
    }
    
    if(total == 0) ans++;
    
    int en = 10, st = 0;
    while(en < discount.size()){
        if(um.find(discount[en]) != um.end()){
            um[discount[en]]--;
            
            total -= (um[discount[en]] >= 0);
        }
        
        if(um.find(discount[st]) != um.end()){
            um[discount[st]]++;
            
            total += (um[discount[st]] > 0);
        }
        
        if(!total) ans++;
        
        en++;
        st++;
    }
    
    return ans;
}