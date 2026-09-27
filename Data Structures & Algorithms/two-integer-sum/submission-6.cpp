class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N = nums.size();
        unordered_map<int, int> um;

        for(int i = 0; i < N; i++){
            int nxt = target - nums[i];

            if(um.find(nxt) != um.end()) return {um[nxt], i};

            if(um.find(nums[i]) != um.end()) continue;
            um[nums[i]] = i;
        }

        return {0, 0};
    }
};
