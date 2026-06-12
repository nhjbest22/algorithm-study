class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size() <= 2) return -1;

        int N = nums.size();

        int MAX = -1, MIN = 105;
        for(int i = 0; i < N; i++){
            MAX = max(MAX, nums[i]);
            MIN = min(MIN, nums[i]);
        }

        for(int i = 0; i < N; i++){
            if(nums[i] != MAX && nums[i] != MIN) return nums[i];
        }

        return 0;
    }
};