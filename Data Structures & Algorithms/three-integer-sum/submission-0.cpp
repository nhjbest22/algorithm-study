class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();

        vector<vector<int>> ans;

        for(int i = 0; i < N; i++){
            if(i && nums[i-1] == nums[i]) continue;
            
            for(int j = i + 1; j < N; j++){
                if(j != i+1 && nums[j-1] == nums[j]) continue;

                int sum = nums[i] + nums[j];
                if(!binary_search(nums.begin() + j + 1, nums.end(), -sum)) continue;

                ans.push_back({nums[i], nums[j], -sum});
            }
        }

        return ans;
    }
};
