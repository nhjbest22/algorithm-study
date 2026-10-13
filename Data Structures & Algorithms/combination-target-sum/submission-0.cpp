class Solution {
public:
    vector<vector<int>> ans;
    vector<int> v;

    void backtrack(int k, int sum, vector<int>& nums, int target){
        if(sum == target){
            ans.push_back(v);
            return;
        }
        
        for(int i = k; i < nums.size(); i++){
            if(sum + nums[i] > target) continue;
            
            v.push_back(nums[i]);
            backtrack(i, sum + nums[i], nums, target);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(0, 0, nums, target);

        return ans;
    }
};
