class Solution {
public: 
    int p[1'005];
    
    int find(int x){
        if(p[x] < 0) return x;

        return p[x] = find(p[x]);
    }

    bool unite(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v) return false;
        if(p[u] == p[v]) p[u]--;

        if(p[u] < p[v]) p[v] = u;
        else p[u] = v;

        return true;
    }

    int cost(vector<int>& p1, vector<int>& p2){
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int N = points.size();
        fill(p, p + N, -1);

        vector<tuple<int, int, int>> edges;
        edges.reserve(N*N/2);

        for(int i = 0; i < N; i++){
            for(int j= i+1; j < N; j++){
                edges.push_back({cost(points[i], points[j]), i, j});
            }
        }

        sort(edges.begin(), edges.end());

        int cnt = 0, ans = 0;
        for(auto& [c, u, v]: edges){
            if(!unite(u, v)) continue;

            cnt++;
            ans += c;
            if(cnt == N-1) break;
        }

        return ans;
    }
};