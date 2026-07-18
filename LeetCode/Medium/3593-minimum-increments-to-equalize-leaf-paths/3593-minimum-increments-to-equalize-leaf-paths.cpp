class Solution {
public:
    long long dfs(int cur, int pre, int& ans, vector<vector<int>>& adj, vector<int>& cost){
        long long MAX = 0;
        int cnt = 0;
        int children = 0;

        for(auto& nxt: adj[cur]){
            if(nxt == pre) continue;

            children++;
            long long sum = dfs(nxt, cur, ans, adj, cost);

            if(sum < MAX) continue;

            if (sum > MAX) {
                MAX = sum;
                cnt = 1;
            } else if (sum == MAX) {
                cnt++;
            }
        }

        ans += (children - cnt);

        return MAX + cost[cur];
    }

    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<vector<int>> adj(n);
        int ans = 0;

        for(auto& e: edges){
            int u = e[0], v = e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(0, -1, ans, adj, cost);

        return ans;
    }
};