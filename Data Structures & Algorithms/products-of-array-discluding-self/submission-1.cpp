class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(N, 0);
        
        int zeroCnt = 0;
        int mul = 1;

        for(auto num: nums){
            if(num == 0){
                zeroCnt++;
                continue;
            }

            mul *= num;
        }

        if(zeroCnt > 1) return ans;

        for(int i = 0; i < N; i++){
            ans[i] = nums[i] ? mul / nums[i] * (!zeroCnt) : mul;
        }

        return ans;
    }
};
