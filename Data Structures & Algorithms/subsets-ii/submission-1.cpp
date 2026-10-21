class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, vector<int>& v, int k){
        ans.push_back(v);
        int N = nums.size();

        for(int i = k; i < N; i++){
            if(i > k && nums[i-1] == nums[i]) continue;

            v.push_back(nums[i]);
            backtrack(nums, v, i+1);
            v.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v;

        backtrack(nums, v, 0);

        return ans;
    }
};
