class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        int MAX = -1e6, MIN = 1e6;
        long long ans = -1e11;
        int N = nums.size();

        if(m == 1){
            long long MAX = *max_element(nums.begin(), nums.end());
            long long MIN = *min_element(nums.begin(), nums.end());

            return max(MAX*MAX, MIN*MIN);
        }

        for(int i = N-1; i >= 0; i--){
            if(i - m + 1 < 0) break;

            MAX = max(MAX, nums[i]);
            MIN = min(MIN, nums[i]);

            ans = max(ans, (long long)nums[i-m+1] * (nums[i-m+1] > 0 ? MAX : MIN));
        }

        return ans;
    }
};