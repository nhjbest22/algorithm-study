class Solution {
private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4]= {0, 1, 0, -1};

public:
    void setZeroes(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        vector<pair<int, int>> grid;


        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(!matrix[i][j]) grid.push_back({i, j});
            }
        }

        for(auto& p: grid){
            for(int dir = 0; dir< 4; dir++){
                int len = 1;
                while(1){
                    int x = p.first + len*dx[dir];
                    int y = p.second + len*dy[dir];

                    len++;

                    if(x < 0 || x >= M || y < 0 || y>= N) break;
                    if(!matrix[x][y]) continue;

                    matrix[x][y] = 0;
                }
            }
        }
    }
};