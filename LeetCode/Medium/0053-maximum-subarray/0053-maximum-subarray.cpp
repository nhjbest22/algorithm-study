class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> sums;
        int N = nums.size();
        
        int sum = 0;
        for(int i = 0; i <N; i++){
            sum += nums[i];
            sums.push_back(sum);
        }

        int ans = sums[0];
        int MIN = min(sums[0], 0);

        for(int i = 1; i < N; i++){
            ans = max(ans, sums[i] - MIN);

            MIN = min(MIN, sums[i]);
        }

        return ans;
    }
};