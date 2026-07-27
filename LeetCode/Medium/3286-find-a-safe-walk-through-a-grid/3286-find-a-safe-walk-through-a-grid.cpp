class Solution {
public:
    int INF = 0x3f3f3f3f;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int N = grid.size(), M = grid[0].size();
        int cost[55][55];
        fill(&cost[0][0], &cost[0][0] + 55*55, INF);

        deque<pair<int, int>> D;
        cost[0][0] = grid[0][0] ? 1 : 0;
        D.push_back({0, 0});

        while(!D.empty()){
            auto [x, y] = D.front();
            D.pop_front();

            for(int dir = 0; dir < 4; dir++){
                int nxtX = x + dx[dir];
                int nxtY = y + dy[dir];

                if(nxtX < 0 || nxtX >= N || nxtY < 0 || nxtY >= M) continue;
                if(cost[nxtX][nxtY] <= cost[x][y] + grid[nxtX][nxtY]) continue;

                cost[nxtX][nxtY] = cost[x][y] + grid[nxtX][nxtY];

                if(grid[nxtX][nxtY]) D.push_back({nxtX, nxtY});
                else D.push_front({nxtX, nxtY});
            }
        }

        return cost[N-1][M-1] < health;
    }
};