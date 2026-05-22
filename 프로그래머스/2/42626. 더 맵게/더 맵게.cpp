#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<> > pq (scoville.begin(), scoville.end());
    int cnt = 0;
    while(pq.size() > 1){        
        if(pq.top() >= K) break;

        auto F = pq.top(); pq.pop();
        auto S = pq.top(); pq.pop();
        
        pq.push(F + 2*S);
        cnt++;
    }
    
    
    if(pq.top() >= K) return cnt;
    return -1;
}