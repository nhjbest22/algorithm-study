class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int N = nums.size();
        int f = INT32_MAX, s = INT32_MAX;

        for(auto& num: nums){
            if(s < num) return true;

            if(f >= num){
                f = num;
                continue;
            }

            if(s > num){
                s = num;
                continue;
            }
        }
        
        return false;
    }
};