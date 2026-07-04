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
        bool isContaminated = true;

        for(int i = 0; i < n; i++){
            if(VISIT[i]) continue;
            if(!isContaminated) break;

            for(auto& nxt: adj[i]){
                if(VISIT[nxt]){
                    isContaminated = false;
                    break;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(VISIT[i] && isContaminated) continue;

            ans.push_back(i);
        }   

        return ans;
    }
};