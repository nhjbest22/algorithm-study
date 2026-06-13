class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(sum < abs(target) || (sum + target) %2 != 0) return 0;

        target = abs(target);
        int MAX = (target + sum)/2;

        int dp[MAX + 5];

        fill(dp, dp + MAX + 5, 0);
        dp[0] = 1;

        int N = nums.size();
        for(int i = 0; i < N; i++){
            for(int j = MAX; j >= nums[i]; j--){
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[MAX];
    }
};