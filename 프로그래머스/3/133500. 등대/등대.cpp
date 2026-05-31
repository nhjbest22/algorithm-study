#include <bits/stdc++.h>

using namespace std;

vector<int> adj[100'005];

int dp[100'005][2];

int dfs(int par, int cur, bool state){
    if(dp[cur][state] != -1) 
        return dp[cur][state];
    
    dp[cur][state] = state;
    
    for(auto& nxt: adj[cur]){
        if(nxt == par) continue;
        
        dp[cur][state] += (
            state 
            ? min(dfs(cur, nxt, false), dfs(cur, nxt, true)) 
            : dfs(cur, nxt, true)
        );
    }
    
    return dp[cur][state];
}

int solution(int n, vector<vector<int>> lighthouse) {
    int E = lighthouse.size();
    int V = E + 1;

    for(auto e: lighthouse){
        auto u = e[0], v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    fill(&dp[0][0], &dp[0][0] + 100'005*2, -1);
    dfs(0, 1, false); 
    dfs(0, 1, true);
    
    return min(dp[1][false], dp[1][true]);
}