class Solution {
public:
    bool VISIT[100'005];
    vector<int> adj[100'005];

    void dfs(int cur){
        if(VISIT[cur]) return;

        VISIT[cur] = true;

        for(auto& nxt: adj[cur]){
            if(VISIT[nxt]) continue;

            dfs(nxt);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<int> ans;
        fill(VISIT, VISIT + n, false);
        for(int i = 0; i < n; i++)
            adj[i].clear();
        
        for(auto& e: invocations){
            int &u = e[0], &v = e[1];
            adj[u].push_back(v);
        }

        dfs(k);
        bool canRemove = true;

        for(const auto& edge: invocations){
            const int &u = edge[0], &v = edge[1];
            if(!VISIT[u] && VISIT[v]){
                canRemove = false;
                break;
            }
        }

        for(int i = 0; i < n; i++){
            if(VISIT[i] && canRemove) continue;

            ans.push_back(i);
        }   

        return ans;
    }
};