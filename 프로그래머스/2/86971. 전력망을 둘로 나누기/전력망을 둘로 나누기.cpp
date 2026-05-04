#include <bits/stdc++.h>

using namespace std;

#define visit VISIT

bool visit[105];
vector<int> adj[105];

int U, V;

int dfs(int cur){
    int ret = 1;
    visit[cur] = true;
    
    for(auto& nxt: adj[cur]){
        if(cur == U && nxt == V) continue;
        if(cur == V && nxt == U) continue;
        if(visit[nxt]) continue;
        
        ret += dfs(nxt);
    }
    
    return ret;
}

int ans = INT32_MAX;


int solution(int n, vector<vector<int>> wires) {
    for(auto& e: wires){
        int u = e[0];
        int v = e[1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(auto& e: wires){
        U = e[0];
        V = e[1];

        int ret = dfs(1);        
        
        ans = min(ans, abs(n - 2*ret));        
        
        fill(visit, visit + 105, false);
    }
    return ans;
}