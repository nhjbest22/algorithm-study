class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int N = nums.size();

        int target = 0;
        for(int i = 0; i < N; i++){
            if(!nums[i]) continue;

            swap(nums[i], nums[target++]);
        }
    }
};