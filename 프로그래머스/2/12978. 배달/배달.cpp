#include <bits/stdc++.h>

using namespace std;

#define cost COST

vector<pair<int, int>> adj[55];
int cost[55];

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    fill(cost, cost + 55, INT32_MAX);
    
    for(auto& e: road){
        int u = e[0], v = e[1], c = e[2];
        
        adj[u].push_back({c, v});
        adj[v].push_back({c, u});
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    cost[1] = 0;
    pq.push({0, 1});
    
    while(!pq.empty()){
        auto [cur_cost, cur_idx] = pq.top();
        pq.pop();
        
        if(cur_cost != cost[cur_idx]) continue;
        
        for(auto& [nxt_cost, nxt_idx]: adj[cur_idx]){
            if(cost[nxt_idx] <= cur_cost + nxt_cost) continue;
            
            cost[nxt_idx] = cur_cost + nxt_cost;
            pq.push({cost[nxt_idx], nxt_idx});
        }
    }
    
    for(int i = 1; i <= N; i++) answer += cost[i] <= K;

    return answer;
}