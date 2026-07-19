class Solution {
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    public int numIslands(char[][] grid) {
        int ans = 0;
        int N = grid.length, M = grid[0].length;

        Queue<int[]> Q = new ArrayDeque<>();
        
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(grid[i][j] == '0') continue;

                ans++;

                grid[i][j] = '0';
                Q.offer(new int[]{i, j});

                while(!Q.isEmpty()){
                    int[] cur = Q.poll();
                    int curX = cur[0], curY = cur[1];

                    for(int dir = 0; dir < 4; dir++){
                        int nxtX = curX + dx[dir];
                        int nxtY = curY + dy[dir];

                        if(nxtX < 0 || nxtX >= N || nxtY < 0 || nxtY >= M) continue;
                        if(grid[nxtX][nxtY] == '0') continue;

                        grid[nxtX][nxtY] = '0';
                        Q.offer(new int[]{nxtX, nxtY});
                    }
                }

            }
        }
        
        return ans;
    }
}