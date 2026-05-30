#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> prices) {
    int N = prices.size();
    
    vector<int> res(N, 0);
    stack<pair<int, int>> s;
    
    for(int i =0; i < N; i++){
        int& cur_price = prices[i];
        
        while(!s.empty() && s.top().first > cur_price){
            auto [price, day] = s.top();
            s.pop();
            
            res[day] = i - day;
        }
        
        s.push({cur_price, i});
    }
    
    while(!s.empty()){
        auto [price, day] = s.top();
        s.pop();
        
        res[day] = N - day - 1;
    }
    
    return res;
}