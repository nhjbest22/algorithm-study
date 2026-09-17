class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int N = nums.size();

        int idx = 0;
        for(int x: nums){
            if(x != val) nums[idx++] = x;
        }

        return idx;
    }
};