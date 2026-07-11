class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;

        for(auto& num: nums){
            vector<int> tmp;

            while(num){
                tmp.push_back(num % 10);
                num /= 10;
            }

            reverse(tmp.begin(), tmp.end());

            ans.insert(ans.end(), tmp.begin(), tmp.end());
        }

        return ans;
    }
};