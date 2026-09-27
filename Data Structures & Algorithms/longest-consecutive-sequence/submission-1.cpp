class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> um;
        int MAX = 0;

        sort(nums.begin(), nums.end());

        for(auto num: nums){
            um[num] = um[num-1] + 1;

            MAX = max(MAX, um[num]);
        }

        return MAX;
    }
};
