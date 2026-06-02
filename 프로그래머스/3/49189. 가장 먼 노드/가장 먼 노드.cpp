#include <string>
#include <vector>
#include <queue>

using namespace std;

int cost[20'005];
vector<int> adj[20'005];

int solution(int n, vector<vector<int>> edge) {
    for(auto& e: edge){
        int u = e[0], v = e[1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    queue<int> Q;
    cost[1] = 1;
    Q.push(1);
    
    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        
        for(auto nxt: adj[cur]){
            if(cost[nxt] > 0) continue;
            
            cost[nxt] = cost[cur] + 1;
            Q.push(nxt);
        }
    }
    
    int MAX = -1;
    int cnt = 0;
    
    for(int i = 2; i<= n; i++){
        if(cost[i] < MAX) continue;
        
        cnt = (MAX < cost[i] ? 1 : cnt + 1);
        MAX = max(cost[i], MAX);
    }
    
    return cnt;
}