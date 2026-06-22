class Solution {
public:
    const int dx[4] = {-1, 0, 1, 0};
    const int dy[4] = {0, 1, 0, -1};

    int maxDistance(vector<vector<int>>& grid) {
        // 0 -> 물, 1 -> 땅

        int cost[105][105];
        fill(&cost[0][0], &cost[0][0] + 105*105, -1);
        
        int N = grid.size();
        int MAX = -1;

        queue<pair<int, int>> Q;
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] == 0) continue;
                
                cost[i][j] = 0;
                Q.push({i, j});
            }
        }

        while(!Q.empty()){
            auto cur = Q.front();
            Q.pop();

            for(int dir = 0; dir < 4; dir++){
                int x = cur.first + dx[dir];
                int y = cur.second + dy[dir];

                if(x < 0 || x >= N || y < 0 || y >= N) continue;
                if(grid[x][y] == 1) continue;
                if(cost[x][y] != -1) continue;

                cost[x][y] = cost[cur.first][cur.second] + 1;
                Q.push({x, y});
            }
        }

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] == 1) continue;

                MAX = max(MAX, cost[i][j]);
            }
        }


        return MAX;
    }
};