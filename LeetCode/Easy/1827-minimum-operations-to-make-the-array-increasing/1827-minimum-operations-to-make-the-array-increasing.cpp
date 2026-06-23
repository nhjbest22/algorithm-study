class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int N = nums.size();
        
        for(int i = 1; i < N; i++){
            if(nums[i] > nums[i-1]) continue;

            ans += (nums[i-1] - nums[i] + 1);
            nums[i] = nums[i-1] + 1;
        }

        return ans;
    }
};