class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size() <= 2) return -1;

        // int MAX = -1, MIN = 105;
        // for(int i = 0; i < nums.size(); i++){
        //     MAX = max(MAX, nums[i]);
        //     MIN = min(MIN, nums[i]);
        // }

        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] != MAX && nums[i] != MIN) return nums[i];
        // }

        sort(nums.begin(), nums.end());
        return nums[1];
    }
};