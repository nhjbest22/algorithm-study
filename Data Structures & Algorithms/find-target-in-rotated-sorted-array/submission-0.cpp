class Solution {
public:
    int search(vector<int>& nums, int target) {
        int N = nums.size();

        int yes = 0, no = N;

        while(yes + 1 < no){
            int mid = (yes + no)/2;
            
            if(nums[mid] >= nums[yes]) yes = mid;
            else no = mid;
        }

        auto it = (nums[0] <= target) 
                    ? lower_bound(nums.begin(), nums.begin() + yes + 1, target)
                    : lower_bound(nums.begin() + yes + 1, nums.end(), target);

        if(it == nums.end() || *it != target) return -1;

        return it - nums.begin();
    }
};
