class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        priority_queue<int> pq;

        int N = grid.size();
        for(int i = 0; i < N; i++){
            sort(grid[i].begin(), grid[i].end(), greater<int>());
            
            for(int j = 0; j < limits[i]; j++)
                pq.push(grid[i][j]);
        }
            
        long long ans = 0;

        while(k--){
            auto cur = pq.top();
            pq.pop();

            ans += cur;
        }

        return ans;
    }
};