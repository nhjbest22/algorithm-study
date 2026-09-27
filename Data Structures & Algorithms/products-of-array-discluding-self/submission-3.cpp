class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> ans(N, 1);

        int pre = 1;
        for(int i = 1; i < N; i++){
            pre *= nums[i-1];
            ans[i] = pre;
        }

        int suff = 1;
        for(int i = N-2; i >=0; i--){
            suff *= nums[i+1];
            ans[i] *= suff;
        }

        return ans;
    }
};
