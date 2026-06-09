class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int target = 0;
        for(int i = 0; i < nums.size(); i++){
            target += nums[i];
            target %= p;
        }

        if(target == 0) return 0;

        map<int, int> um;
        um[0] = 0;

        int A = 0;
        int MIN = INT32_MAX;
        for(int i = 0; i < nums.size(); i++){
            A = (A + nums[i]) % p;
            um[A] = i+1;

            int B = (A - target + p)%p;
            if(um.find(B) == um.end()) continue;

            MIN = min(MIN, i+1 - um[B]);
        }

        if(MIN == nums.size()) return -1;
        return MIN;
    }
};