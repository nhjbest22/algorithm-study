class Solution {
public:
    int INF = 0x3f3f3f3f;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int N = grid.size(), M = grid[0].size();
        int cost[55][55];
        fill(&cost[0][0], &cost[0][0] + 55*55, INF);

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq; // cost, x, y        
        cost[0][0] = grid[0][0] ? 1 : 0;
        pq.push({cost[0][0], 0, 0});

        while(!pq.empty()){
            auto [c, x, y] = pq.top();
            pq.pop();

            if(c != cost[x][y]) continue;

            for(int dir = 0; dir < 4; dir++){
                int nxtX = x + dx[dir];
                int nxtY = y + dy[dir];

                if(nxtX < 0 || nxtX >= N || nxtY < 0 || nxtY >= M) continue;
                if(cost[nxtX][nxtY] <= c + grid[nxtX][nxtY]) continue;

                cost[nxtX][nxtY] = c + grid[nxtX][nxtY];
                pq.push({cost[nxtX][nxtY], nxtX, nxtY});
            }
        }

        return cost[N-1][M-1] < health;
    }
};