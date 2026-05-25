#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> numbers) {
    // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    stack<pair<int, int>> s;
    vector<int> res(numbers.size(), -1);
    
    for(int i = 0; i < numbers.size(); i++){
        while(!s.empty()){
            auto cur = s.top();
            if(cur.first >= numbers[i]) break;
            
            s.pop();
            
            res[cur.second] = numbers[i];
        }
        
        s.push({numbers[i], i});
    }
    
    return res;
}