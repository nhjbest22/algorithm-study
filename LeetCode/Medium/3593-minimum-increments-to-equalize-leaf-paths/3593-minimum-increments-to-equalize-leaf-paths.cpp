class Solution {
public:
    int ans;
    vector<int> adj[100'005];

    long long dfs(int cur, int pre, vector<int>& cost){
        long long MAX = 0;
        int cnt = 0;
        int children = 0;

        for(auto& nxt: adj[cur]){
            if(nxt == pre) continue;

            children++;
            long long sum = dfs(nxt, cur, cost);

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

        dfs(0, -1, cost);

        return ans;
    }
};