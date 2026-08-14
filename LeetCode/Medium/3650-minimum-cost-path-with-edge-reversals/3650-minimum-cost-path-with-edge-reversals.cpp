class Solution {
public:
    vector<pair<int, int>> adj[50'005];

    int minCost(int n, vector<vector<int>>& edges) {
        long long cost[n+5];

        for(int i = 0; i < n; i++)
            adj[i].clear();

        for(auto& e: edges){
            int u = e[0], v = e[1], c = e[2];
            adj[u].push_back({v, c});
            adj[v].push_back({u, 2*c});
        }

        fill(cost, cost + n + 5, INT64_MAX);
        cost[0] = 0;
        
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
        pq.push({0, 0});


        while(!pq.empty()){
            auto [cur_cost, cur_idx] = pq.top();
            pq.pop();

            if(cost[cur_idx] != cur_cost) continue;

            for(auto& [nxt_idx, nxt_cost]: adj[cur_idx]){
                if(cur_cost + nxt_cost >= cost[nxt_idx]) continue;
                
                cost[nxt_idx] = cur_cost + nxt_cost;
                pq.push({cur_cost + nxt_cost, nxt_idx});
            }
        }

        return cost[n-1];
    }
};