class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int N = nums.size();

        vector<vector<int>> ans;

        for(int i = 0; i < N; i++){
            if(nums[i] > 0) break;
            if(i && nums[i-1] == nums[i]) continue;
            
            int l = i + 1, r = N-1;
            while(l < r){
                if(nums[i] + nums[l] > 0) break;
                int sum = nums[i] + nums[l] + nums[r];

                if(l != i + 1 && nums[l-1] == nums[l]){
                    l++;
                    continue;
                }

                if(sum > 0) r--;
                else if(sum < 0) l++;
                else{
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++; r--;
                }
            }
        }

        return ans;
    }
};
