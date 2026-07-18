class Solution {
public:
    int ans;
    vector<int> adj[100'005];
    int par[100'005];

    void find_pre(int cur, int pre){
        par[cur] = pre;

        for(auto& nxt: adj[cur]){
            if(nxt == pre) continue;

            find_pre(nxt, cur);
        }
    }

    long long dfs(int cur, vector<int>& cost){
        long long MAX = -1;
        int cnt = 0;

        for(auto& nxt: adj[cur]){
            if(nxt == par[cur]) continue;

            auto sum = dfs(nxt, cost);
            
            if(sum < MAX) continue;
            if(sum > MAX) cnt = 0;

            MAX = max(MAX, sum);
            cnt++;
        }

        ans += adj[cur].size() - cnt - 1;
        if(!cur) ans++;

        return MAX + cost[cur];
    }

    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        ans = 0;
        
        int N = cost.size();
        for(int i = 0 ; i < N; i++){
            adj[i].clear();
        }

        for(auto& e: edges){
            int u = e[0], v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        find_pre(0, 0);
        dfs(0, cost);

        return ans;
    }
};