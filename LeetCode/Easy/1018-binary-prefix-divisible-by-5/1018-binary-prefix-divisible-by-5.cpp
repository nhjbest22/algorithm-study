class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int buffer = 0;
        for(auto& num: nums){
            buffer <<= 1;
            buffer += num;
            buffer %= 5;

            ans.push_back(buffer == 0);
        }

        return ans;
    }
};