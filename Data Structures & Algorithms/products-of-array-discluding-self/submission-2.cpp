class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> pre(N, 1), suff(N, 1);

        for(int i = 1; i < N; i++){
            pre[i] = pre[i-1] * nums[i-1];
        }

        for(int i = N-2; i >= 0; i--){
            suff[i] = suff[i+1] * nums[i+1];
        }

        vector<int> ans(N, 0);

        ans[0] = suff[0];
        ans[N-1] = pre[N-1];

        for(int i = 1; i < N-1; i++)
            ans[i] = pre[i] * suff[i];

        return ans;
    }
};
