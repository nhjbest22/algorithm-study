class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int st = 1, prev = nums[0];
        int N = nums.size();

        for(int i = 0; i < N; i++){
            if(nums[i] == prev) continue;

            prev = nums[i];
            swap(nums[st++], nums[i]);
        }

        return st;
    }
};