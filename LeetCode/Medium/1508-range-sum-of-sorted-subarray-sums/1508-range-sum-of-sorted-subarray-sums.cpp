class Solution {
public:
    const int mod = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int sum[500'505];
        int idx = 0, ans = 0;;
        
        for(int i = 0; i < n; i++){
            int tot = 0;

            for(int j = i; j < n; j++){
                tot += nums[j];
                sum[idx++] = tot;
            }
        }

        sort(sum, sum + idx);
        for(int i = left-1; i < right; i++){
            ans += sum[i];
            ans %= mod;
        }

        return ans;
    }
};