class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int N = grid.size();
        vector<int> cands;

        if(!k) return 0;

        for(int i = 0; i < N; i++){
            nth_element(grid[i].begin(), grid[i].begin() + limits[i]
            , grid[i].end(), greater<int>());

            for(int j = 0; j < limits[i]; j++)
                cands.push_back(grid[i][j]);
        }

        long long ans = 0;

        nth_element(cands.begin(), cands.begin() + k, cands.end(), greater<>());

        for(int i = 0; i < k; i++)
            ans += cands[i];

        return ans;
    }
};