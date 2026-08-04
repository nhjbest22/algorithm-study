class Solution {
public:
    long long dfs(vector<int>& nums, int pos, bool skip, vector<vector<long long>>& dp){
        if(pos >= nums.size() - 1) return 0;
        if(dp[skip][pos] != -1) return dp[skip][pos];

        long long ans = max(0, max(nums[pos-1], nums[pos+1]) - nums[pos] + 1);

        if(skip) return dp[skip][pos] = ans + dfs(nums, pos + 2, skip, dp);

        dp[true][pos] = ans + dfs(nums, pos + 3, true, dp);
        dp[false][pos] = ans + dfs(nums, pos + 2, false, dp);

        return min(dp[true][pos], dp[false][pos]);
    }

    long long minIncrease(vector<int>& nums) {
        int N = nums.size();

        if(N % 2){
            long long ans = 0;

            for(int i = 1; i < N; i+= 2)
                ans += max(0, max(nums[i-1], nums[i+1]) - nums[i] + 1);

            return ans;
        }

        vector<vector<long long>> dp(2, vector<long long>(N, -1));

        return min(dfs(nums, 1, false, dp), dfs(nums, 2, true, dp));
    }
};