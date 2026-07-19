class Solution {
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    public int numIslands(char[][] grid) {
        record Grid(int x, int y) {};

        int ans = 0;
        int N = grid.length, M = grid[0].length;
        boolean[][] visit = new boolean[N+5][M+5];

        Queue<Grid> Q = new ArrayDeque<>();
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(visit[i][j]) continue;
                if(grid[i][j] == '0') continue;

                ans++;

                visit[i][j] = true;
                Q.offer(new Grid(i, j));

                while(!Q.isEmpty()){
                    Grid cur = Q.poll();
                    int curX = cur.x, curY = cur.y;

                    for(int dir = 0; dir < 4; dir++){
                        int nxtX = curX + dx[dir];
                        int nxtY = curY + dy[dir];

                        if(nxtX < 0 || nxtX >= N || nxtY < 0 || nxtY >= M) continue;
                        if(visit[nxtX][nxtY]) continue;
                        if(grid[nxtX][nxtY] == '0') continue;

                        visit[nxtX][nxtY] = true;
                        Q.offer(new Grid(nxtX, nxtY));
                    }
                }

            }
        }
        
        return ans;
    }
}