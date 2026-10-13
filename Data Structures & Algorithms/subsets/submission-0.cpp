class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int k, vector<int>& v, vector<int>& nums){
        ans.push_back(v);

        for(int i = k; i < nums.size(); i++){
            v.push_back(nums[i]);

            backtrack(i + 1, v, nums);

            v.pop_back();
        }
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;

        backtrack(0, v, nums);

        return ans;
    }
};
