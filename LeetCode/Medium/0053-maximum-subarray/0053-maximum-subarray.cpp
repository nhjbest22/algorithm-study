class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int N = nums.size();

        int sum = nums[0];
        int ans = sum;

        for(int i = 1; i < N; i++){
            sum += nums[i];

            if(sum < nums[i]) sum = nums[i];
            ans = max(ans, sum);
        }

        return ans;
    }
};