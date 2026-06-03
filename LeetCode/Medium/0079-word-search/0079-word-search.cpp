class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4]= {0, 1, 0, -1};

    int VISIT[10][10];
    bool ans;

    void backtrack(vector<vector<char>>& board, pair<int, int> cur, string& word, int M, int N){
        int len = VISIT[cur.first][cur.second];
        
        if(len == word.size()){
            ans = true;
            return;
        }

        for(int dir = 0; dir < 4; dir++){
            int x = cur.first + dx[dir];
            int y = cur.second + dy[dir];

            if(x < 0 || x>= M || y < 0 || y>= N) continue;
            if(VISIT[x][y] > 0) continue;
            if(board[x][y] != word[len]) continue;

            VISIT[x][y] = len + 1;

            backtrack(board, {x, y}, word, M, N);

            VISIT[x][y] = 0;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        int M = board.size(), N = board[0].size();
        ans = false;

        // queue<pair<int, int>> Q;

        // for(int i = 0; i < M; i++){
        //     for(int j = 0; j < N; j++){
        //         if(board[i][j] != word[0]) continue;

        //         fill(&VISIT[0][0], &VISIT[0][0] + 10*10, 0);

        //         Q.push({i, j});
        //         VISIT[i][j] = 1;

        //         while(!Q.empty()){
        //             auto [curX, curY] = Q.front();
        //             Q.pop();

        //             if(VISIT[curX][curY] == word.size()) return true;

        //             int len = VISIT[curX][curY];

        //             for(int dir = 0; dir < 4; dir++){
        //                 int nxtX = curX + dx[dir];
        //                 int nxtY = curY + dy[dir];

        //                 if(nxtX < 0 || nxtX >= M || nxtY <0 || nxtY >= N) continue;

        //             }
        //         }
        //     }
        // }

        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(board[i][j] != word[0]) continue;

                VISIT[i][j] = 1;
                backtrack(board, {i, j}, word, M, N);
                VISIT[i][j] = 0;
            }
        }

        return ans;
    }
};