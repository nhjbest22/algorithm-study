#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> numbers) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> res(numbers.size(), -1);
    
    for(int i = 0; i < numbers.size(); i++){
        while(!pq.empty()){
            auto cur = pq.top();
            if(cur.first >= numbers[i]) break;
            
            pq.pop();
            
            res[cur.second] = numbers[i];
        }
        
        pq.push({numbers[i], i});
    }
    
    return res;
}