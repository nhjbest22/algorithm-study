class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        int N = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0 ; i < N; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;

            int l = i + 1, r = N - 1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];

                if(sum == 0){
                    ans.push_back({nums[i], nums[l], nums[r]});

                    l++;
                    while(l < N && nums[l-1] == nums[l]) l++;

                    r--;
                    while(r > i && nums[r] == nums[r+1]) r--;

                    continue;
                }
                
                if(sum <= 0) l++;
                else r--;
            }
        }

        return ans;
    }
};