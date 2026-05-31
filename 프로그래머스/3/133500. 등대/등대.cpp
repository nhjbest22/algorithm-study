#include <bits/stdc++.h>

using namespace std;

int par[100'005];
int in[100'005];

vector<int> adj[100'005];
bool is_on[100'005];
int ans;

void dfs(int pre,int cur){
    par[cur] = pre;
    in[cur] = adj[cur].size() - 1;
    
    for(auto nxt: adj[cur]){
        if(nxt == pre) continue;
        
        dfs(cur, nxt);
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    int E = lighthouse.size();
    int V = E + 1;
    
    for(auto& e: lighthouse){
        int u = e[0], v= e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    in[1] = adj[1].size();
    
    for(auto nxt: adj[1]) dfs(1, nxt);
    
    queue<int> Q;
    for(int i = 1; i <= V; i++) if(!in[i]) Q.push(i);
    
    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        
        int pre = par[cur];
        
        if(cur == 1) continue;
        if(!is_on[cur] && !is_on[pre]){
            ans++;
            is_on[pre] = true;
        }
        
        in[pre]--;
        if(!in[pre]) Q.push(pre);
    }
    
    return ans;
}