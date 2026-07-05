class Solution {
public:
    bool visit[10];
    vector<int> buffer;
    vector<vector<int>> ans;

    void backtrack(int k, const vector<int>& nums){
        if(k == nums.size()){
            ans.push_back(buffer);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(visit[i]) continue;
            if(i != 0 && nums[i-1] == nums[i] && !visit[i-1]) continue;

            visit[i] = true;
            buffer.push_back(nums[i]);
            backtrack(k+1, nums);

            buffer.pop_back();
            visit[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        ans.clear();
        buffer.clear();
        int N = nums.size();
        
        sort(nums.begin(), nums.end());
        fill(visit, visit + N, false);
        
        backtrack(0, nums);

        return ans;
    }
};