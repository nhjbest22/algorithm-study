class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int N = nums.size();

        int idx = 0;
        for(int i = 0; i < N; i++){
            if(nums[i] == val) continue;

            nums[idx++] = nums[i];
        }

        return idx;
    }
};