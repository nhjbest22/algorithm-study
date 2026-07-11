class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for(auto& num: nums){
            string str = to_string(num);

            for(auto& ch: str){
                ans.push_back(ch - '0');
            }
        }

        return ans;
    }
};