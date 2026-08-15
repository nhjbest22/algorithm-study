class Solution {
public:
    int dx[2] = {0, 1};
    int dy[2] = {1, 0};

    int p[10'005];

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

    int minimumEffortPath(vector<vector<int>>& heights) {
        int R = heights.size(), C = heights[0].size();
        fill(p, p + R*C, -1);

        int ans = 0;
        vector<tuple<int, int, int>> edges;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                int c = heights[i][j];

                for(int dir = 0; dir < 2; dir++){
                    int nxtX = i + dx[dir];
                    int nxtY = j + dy[dir];

                    if(nxtX >= R || nxtY >= C) continue;
                    
                    int nxtH = heights[nxtX][nxtY];
                    edges.push_back({abs(c - nxtH), i*C + j, nxtX*C + nxtY});
                }
            }
        }

        sort(edges.begin(), edges.end(), [](const auto& a, const auto& b){
            return get<0>(a) < get<0>(b);
        });

        int st = 0, en = R*C - 1;
        for(auto& [c, u, v]: edges){
            if(!unite(u, v)) continue;

            ans = max(ans, c);
            if(find(st) == find(en)) break;
        }   

        return ans;
    }
};