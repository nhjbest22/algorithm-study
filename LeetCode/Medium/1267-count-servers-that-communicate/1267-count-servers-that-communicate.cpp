class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int row[255] = {0, };
        int col[255] = {0, };

        int M = grid.size(), N = grid[0].size();
        int ans = 0;

        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(!grid[i][j]) continue;

                row[i]++;
                col[j]++;
            }
        }

        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(!grid[i][j]) continue;

                ans += (row[i] > 1 || col[j] > 1);
            }
        }

        return ans;
    }
};