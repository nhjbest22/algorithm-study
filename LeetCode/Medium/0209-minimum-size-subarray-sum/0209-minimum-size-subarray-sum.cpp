class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int N = nums.size();

        int en = 0, st = 0;
        int sum = 0, ans = INT32_MAX;
        
        while(en < N){
            sum += nums[en];
            
            while(st < en && sum - nums[st] >= target){
                sum -= nums[st++];
            }

            if(sum >= target) ans = min(ans, en - st + 1);

            en++;
        }

        return ans == INT32_MAX ? 0 : ans;
    }
};