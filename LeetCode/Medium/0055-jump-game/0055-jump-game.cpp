class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();

        int MAX = 0;
        for(int i = 0; i < N; i++){
            if(i > MAX) break;
            if(MAX >= N-1) break;

            MAX = max(MAX, i + nums[i]);
        }

        return MAX >= N-1;
    }
};