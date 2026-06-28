class Solution {
public:
    int dx[4] = {-1, -1, 0, 0};
    int dy[4] = {-1, 0, -1, 0};

    long long INF = 1e5 + 1;

    vector<long long> countBlackBlocks(int M, int N, vector<vector<int>>& coordinates) {
        vector<long long> ans(5, 0);
        ans[0] = (long long)(M-1) * (N-1);

        unordered_set<long long> us;

        for(auto& grid: coordinates){
            us.insert(INF*grid[0] + grid[1]);

            for(int dir = 0; dir < 4; dir++){
                int x = grid[0] + dx[dir];
                int y = grid[1] + dy[dir];

                if(x < 0 || x >= M || y< 0 || y >= N) continue;
                if(x + 1 >= M || y + 1 >= N) continue;

                int cnt = 0;
                for(int i = 0; i < 2; i++){
                    for(int j = 0; j < 2; j++){
                        int curX = x + i;
                        int curY = y + j;

                        if(us.find(INF*curX + curY) != us.end()) cnt++;
                    }
                }

                ans[cnt-1]--;
                ans[cnt]++;
            }
        }

        return ans;
    }
};