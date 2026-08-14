#define visit VISIT

class Solution {
public:
    vector<pair<int, int>> adj[100'005]; // cost, nxt
    
    void dfs(int cur, int mid, vector<bool>& visit){
        for(auto& [cost, nxt]: adj[cur]){
            if(cost <= mid) continue;
            if(visit[nxt]) continue;

            visit[nxt] = true;
            dfs(nxt, mid, visit);
        }
    }

    bool check(int mid, int k, int n){
        vector<bool> visit(n+5, false);
        int cnt = 0;

        for(int i = 0; i < n; i++){
            if(visit[i]) continue;

            cnt++;
            visit[i] = true;
            dfs(i, mid, visit);
        }

        return cnt >= k;
    }

    int minTime(int n, vector<vector<int>>& edges, int k) {
        int yes = 1e9 + 1, no = -1; // connnected components가 k개 이상이 되도록 하는 최소
        for(int i = 0; i < n; i++) adj[i].clear();

        for(auto& e: edges){
            int u = e[0], v = e[1], c = e[2];
            adj[u].push_back({c, v});
            adj[v].push_back({c, u});
        }

        while(yes > no + 1){
            int mid = (yes + no)/2;

            if(check(mid, k, n)) yes = mid;
            else no = mid;
        }

        return yes;
    }
};