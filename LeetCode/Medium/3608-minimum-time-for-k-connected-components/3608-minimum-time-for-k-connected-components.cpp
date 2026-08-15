class Solution {
public:
    int p[100'005];

    int find(int x){
        if(p[x] < 0) return x;

        return p[x] = find(p[x]);
    }

    bool is_diff_group(int u, int v){
        u = find(u);
        v = find(v);

        if(u == v) return false;
        if(p[u] == p[v]) p[u]--;

        if(p[u] < p[v]) p[v] = u;
        else p[u] = v;

        return true;
    }

    int minTime(int n, vector<vector<int>>& edges, int k) {
        fill(p, p + n, -1);
        sort(edges.begin(), edges.end(), [&](const auto& a, const auto& b){
            return a[2] > b[2];
        });
        
        int cnt = n;
        int m = edges.size();
        for(int i = 0; i < m;){
            int c = edges[i][2];
            int j = i;

            while(j < m && edges[j][2] == c){
                if(is_diff_group(edges[j][0], edges[j][1])) cnt--;
                j++;
            }

            if(cnt < k) return c;
            i = j;
        }

        return 0;
    }
};