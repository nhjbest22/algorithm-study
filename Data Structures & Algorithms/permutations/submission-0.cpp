class Solution {
public:
    bool visit[10];
    vector<vector<int>> ans;

    void backtrack(vector<int>& v, vector<int>& nums){
        if(v.size() == nums.size()){
            ans.push_back(v);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(visit[i]) continue;

            visit[i] = true;
            v.push_back(nums[i]);
            backtrack(v, nums);

            visit[i] = false;
            v.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int N = nums.size();
        ans.clear();
        fill(visit, visit + N, false);

        vector<int> v;

        backtrack(v, nums);

        return ans;
    }
};
