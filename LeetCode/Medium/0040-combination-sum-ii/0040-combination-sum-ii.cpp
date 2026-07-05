class Solution {
public:
    vector<vector<int>> ans;
    int target;

    void backtrack(int idx, int sum, const vector<int>& candidates, vector<int>& nums, const int& target){
        if(sum == target){
            ans.push_back(nums);
            return;
        }

        for(int i = idx; i < candidates.size(); i++){
            if(i != idx && candidates[i-1] == candidates[i])
                continue;

            if(sum + candidates[i] > target) continue;

            nums.push_back(candidates[i]);
            
            backtrack(i + 1, sum + candidates[i], candidates, nums, target);

            nums.pop_back();
        }

        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> nums;
        ans.clear();

        backtrack(0, 0, candidates, nums, target);

        return ans;
    }
};