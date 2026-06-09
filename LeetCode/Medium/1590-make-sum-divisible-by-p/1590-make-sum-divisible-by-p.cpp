class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        vector<pair<int ,int>> sums;

        int target = 0;
        for(int i = 0; i < nums.size(); i++){
            target += nums[i];
            target %= p;
        }

        unordered_map<int, int> um;
        um[0] = 0;

        int A = 0;
        int MIN = INT32_MAX;
        for(int i = 0; i < nums.size(); i++){
            A += nums[i];
            A %= p;
            um[A] = i+1;

            int B = (A - target + p)%p;
            if(um.find(B) == um.end()) continue;

            MIN = min(MIN, i+1 - um[B]);
        }

        // target = 6
        // 0, 1, 3, 6
        // 

        if(MIN == nums.size()) return -1;
        return MIN;
    }
};