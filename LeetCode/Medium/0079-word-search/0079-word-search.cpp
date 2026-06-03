class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4]= {0, 1, 0, -1};

    int VISIT[10][10];
    bool ans;

    void backtrack(vector<vector<char>>& board, pair<int, int> cur, string& word, int M,  int N){
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

        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(ans) return true;
                if(board[i][j] != word[0]) continue;

                VISIT[i][j] = 1;
                backtrack(board, {i, j}, word, M, N);
                VISIT[i][j] = 0;
            }
        }

        return ans;
    }
};