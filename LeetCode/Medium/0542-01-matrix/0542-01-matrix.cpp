class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int M = mat.size(), N = mat[0].size();
        vector<vector<int>> dist(M, vector<int>(N, 0));

        queue<int> Q;

        for(int i=0; i < M; i++){
            for(int j=0; j< N; j++){
                if(mat[i][j]) continue;

                for(int dir = 0; dir < 4; dir++){
                    int x = i + dx[dir];
                    int y = j + dy[dir];

                    if(x < 0 || x >= M || y < 0 || y >= N) continue;
                    if(mat[x][y] == 0 || dist[x][y]) continue;

                    dist[x][y] = 1;
                    Q.push(x*N + y);
                }
            }
        }

        while(!Q.empty()){
            auto cur = Q.front();
            Q.pop();

            int curX = cur/N;
            int curY = cur%N;

            for(int dir = 0; dir < 4; dir++){
                int x = curX + dx[dir];
                int y = curY + dy[dir];

                if(x < 0 || x >= M || y < 0 || y >= N) continue;
                if(mat[x][y] == 0 || dist[x][y]) continue;

                dist[x][y] = dist[curX][curY] + 1;
                Q.push(x*N + y);
            }
        }

        return dist;
    }
};