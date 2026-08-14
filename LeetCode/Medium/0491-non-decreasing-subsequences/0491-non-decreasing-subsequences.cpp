class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int idx, vector<int>& v, vector<int>& nums){
        if(v.size() > 1) ans.push_back(v);
        if(idx >= nums.size()) return;

        bool used[205] = {false, };
        int prev = v.size() > 0 ? v[v.size()-1] : -101;

        for(int i = idx; i < nums.size(); i++){
            if(nums[i] < prev) continue;
            if(used[nums[i] + 100]) continue;

            used[nums[i] + 100] = true;
            v.push_back(nums[i]);

            backtrack(i + 1, v, nums);

            v.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        ans.clear();
        vector<int> v;

        backtrack(0, v, nums);
        return ans;
    }
};