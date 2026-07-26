class Solution {
    int[] dx = {-1, 0, 1, 0};
    int[] dy = {0, 1, 0, -1};

    public int orangesRotting(int[][] grid) {
        int N = grid.length;
        int M = grid[0].length;

        Queue<int[]> Q = new ArrayDeque<>();
        
        int cnt = 0, MAX = 0;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                if(grid[i][j] == 1){
                    cnt++;
                    continue;
                }

                if(grid[i][j] == 2)
                    Q.offer(new int[]{i, j, 0});
            }
        }

        while(!Q.isEmpty()){
            int[] cur = Q.poll();

            MAX = Math.max(MAX, cur[2]);

            for(int dir = 0; dir < 4; dir++){
                int x = cur[0] + dx[dir];
                int y = cur[1] + dy[dir];

                if(x < 0 || x >= N || y < 0 || y>= M) continue;
                if(grid[x][y] == 0 || grid[x][y] == 2) continue;

                grid[x][y] = 0;
                cnt--;

                Q.offer(new int[]{x, y, cur[2] + 1});
            }
        }

        return cnt == 0 ? MAX : -1;
    }
}