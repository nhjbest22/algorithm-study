class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int M = grid.size(), N = grid[0].size();
        vector<vector<int>> ans;
        vector<int> buffer(k*k);

        for(int i = 0; i < M - k + 1; i++){
            vector<int> diff;
            for(int j = 0; j < N - k + 1; j++){
                int offSet = 0;

                for(int x = i; x < i + k; x++){
                    for(int y = j; y < j + k; y++){
                        buffer[offSet++] = grid[x][y];
                    }
                }

                int MIN = INT32_MAX;
                sort(buffer.begin(), buffer.end());

                for(int idx = 1; idx < k*k; idx++){
                    if(buffer[idx] == buffer[idx-1]) continue;

                    MIN = min(MIN, abs(buffer[idx] - buffer[idx-1]));
                }

                diff.push_back(MIN == INT32_MAX ? 0 : MIN);
            }

            ans.push_back(diff);
        }

        return ans;
    }
};