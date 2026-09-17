class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int N = nums.size();
        int l = 0, r = N-1;

        while(l <= r){
            while(r >= 0 && nums[r] == val) r--;
            while(l < N && nums[l] != val) l++;

            if(l > r) break;

            swap(nums[l], nums[r]);
        }

        return r + 1;
    }
};