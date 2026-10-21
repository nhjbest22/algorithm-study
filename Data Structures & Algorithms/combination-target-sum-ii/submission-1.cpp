class Solution {
public:
    vector<vector<int>> ans;
    
    void backtrack(vector<int>& v, vector<int>& candidates, int sum, int k, int target){
        if(sum == target){
            ans.push_back(v);
            return;
        }

        int N = candidates.size();
        for(int i = k; i < N; i++){
            if(i != k && candidates[i-1] == candidates[i]) continue;
            if(sum + candidates[i] > target) continue;

            v.push_back(candidates[i]);
            backtrack(v, candidates, sum + candidates[i], i + 1, target);
            v.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        sort(candidates.begin(), candidates.end());

        int N = candidates.size();
        vector<int> v;

        backtrack(v, candidates, 0, 0, target);

        return ans;
    }
};
