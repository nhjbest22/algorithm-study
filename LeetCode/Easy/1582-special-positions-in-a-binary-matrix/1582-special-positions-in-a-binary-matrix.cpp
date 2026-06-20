class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row[105], col[105];
        fill(row, row + 105, 0);
        fill(col, col + 105, 0);

        int ans = 0;

        int M = mat.size(), N = mat[0].size();

        for(int i = 0; i < M ; i++){
            for(int j = 0; j < N; j++){
                row[i] += mat[i][j];
                col[j] += mat[i][j];
            }
        }

        for(int i = 0; i < M ; i++){
            for(int j = 0; j < N; j++){
                if(!mat[i][j]) continue;

                ans += (row[i] == 1 && col[j] == 1);
            }
        }

        return ans;
    }
};