class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int N = nums.size();
        for(auto& num: nums)
            num %= k;
        
        int dp[1005][1005] = {0, }; // (마지막 값, 목표 합)

        int MAX = -1;

        for(auto& num: nums){
            for(int mod = 0; mod < k; mod++){
                int target = (mod - num + k) % k;
                dp[num][mod] = max(dp[num][mod], dp[target][mod] + 1);

                MAX = max(MAX, dp[num][mod]);
            }
        }

        return MAX;
    }
};