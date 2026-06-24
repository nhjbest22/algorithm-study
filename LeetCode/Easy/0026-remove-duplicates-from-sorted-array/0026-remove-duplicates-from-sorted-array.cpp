class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> us;
        int N = nums.size();
        us.insert(nums[0]);

        int idx = 1;
        for(int i = 1; i < N; i++){
            if(us.find(nums[i]) != us.end()) continue;

            us.insert(nums[i]);
            swap(nums[idx++], nums[i]);
        }

        return idx;
    }
};