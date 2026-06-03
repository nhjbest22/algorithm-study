class Solution {
private:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4]= {0, 1, 0, -1};

public:
    void setZeroes(vector<vector<int>>& matrix) {
        int M = matrix.size(), N = matrix[0].size();
        vector<int> row(M, 0), col(N, 0);


        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(matrix[i][j]) continue;

                row[i] = col[j] = 1;
            }
        }

        for(int i = 0; i < M; i++){
            if(!row[i]) continue;

            for(int j = 0; j < N; j++) matrix[i][j] = 0;
        }

        for(int j = 0; j < N; j++){
            if(!col[j]) continue;

            for(int i = 0; i < M; i++) matrix[i][j] = 0;
        }
    }
};