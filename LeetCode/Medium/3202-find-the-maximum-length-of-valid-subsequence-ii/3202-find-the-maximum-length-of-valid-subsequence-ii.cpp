class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int N = nums.size();
        for(auto& num: nums)
            num %= k;

        int MAX = -1;
        int dp[k + 5];

        for(int C = 0; C < k; C++){
            fill(dp, dp + k, 0);

            for(auto& num: nums){
                int target = (C - num + k) % k;
                dp[num] = dp[target] + 1;
            }

            MAX = max(MAX, *max_element(dp, dp + k));
        }

        return MAX;
    }
};