class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> v;

        int prev = -1;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == prev) continue;

            prev = nums[i];
            v.push_back(nums[i]);
        }

        int N = v.size();

        int ans = 0;
        for(int i = 1; i < N-1; i++){
            if(min({v[i-1], v[i], v[i+1]}) == v[i])
                ans++;
            
            if(max({v[i-1], v[i], v[i+1]}) == v[i]) 
                ans++;
        }

        return ans;
    }
};