class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int numIslands(vector<vector<char>>& grid) {
        bool VISIT[305][305] = {};
        int ans = 0;

        int M = grid.size(), N = grid[0].size();

        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(VISIT[i][j]) continue;
                if(grid[i][j] == '0') continue;
                queue<pair<int, int>> Q;

                VISIT[i][j] = true;       
                ans++;
                Q.push({i, j});

                while(!Q.empty()){
                    auto cur = Q.front();
                    Q.pop();

                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if(nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                        if(VISIT[nx][ny]) continue;
                        if(grid[nx][ny] == '0') continue;

                        VISIT[nx][ny] = true;
                        Q.push({nx, ny});
                    }
                }
            }
        }

        return ans;
    }
};