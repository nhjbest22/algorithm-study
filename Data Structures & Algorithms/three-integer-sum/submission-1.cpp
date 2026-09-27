class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();

        vector<vector<int>> ans;

        for(int i = 0; i < N; i++){
            if(i && nums[i-1] == nums[i]) continue;
            
            int l = i + 1, r = N-1;
            while(l < r){
                int sum = nums[l] + nums[r];

                if(l != i + 1 && nums[l-1] == nums[l]){
                    l++;
                    continue;
                }

                if(sum + nums[i] == 0) ans.push_back({nums[i], nums[l], nums[r]});
                if(sum + nums[i] > 0) r--;
                else l++;
            }
        }

        return ans;
    }
};
