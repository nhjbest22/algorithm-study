class Solution {
public:
    vector<vector<int>> ans;
    vector<int> nums;

    void backtrack(int idx, int sum, const vector<int>& candidates, const int& target){
        if(sum == target){
            ans.push_back(nums);
            return;
        }

        for(int i = idx; i < candidates.size(); i++){
            if(i != idx && candidates[i-1] == candidates[i])
                continue;

            if(sum + candidates[i] > target) break;

            nums.push_back(candidates[i]);
            
            backtrack(i + 1, sum + candidates[i], candidates, target);

            nums.pop_back();
        }

        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        nums.clear();
        ans.clear();

        backtrack(0, 0, candidates, target);

        return ans;
    }
};