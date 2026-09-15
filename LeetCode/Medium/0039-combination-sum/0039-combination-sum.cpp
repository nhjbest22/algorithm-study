class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int cur, int sum, int target, vector<int>& candidates, vector<int>& buffer){
        if(sum == target){
            ans.push_back(buffer);
            
            return;
        }

        for(int i = cur; i < candidates.size(); i++){
            if(sum + candidates[i] > target) continue;

            buffer.push_back(candidates[i]);
            backtrack(i, sum + candidates[i], target, candidates, buffer);
            buffer.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {        
        vector<int> buffer;
        backtrack(0, 0, target, candidates, buffer);

        return ans;
    }
};