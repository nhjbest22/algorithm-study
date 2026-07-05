class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        int N = nums.size();
        
        sort(nums.begin(), nums.end());

        do{
            ans.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));


        return ans;
    }
};