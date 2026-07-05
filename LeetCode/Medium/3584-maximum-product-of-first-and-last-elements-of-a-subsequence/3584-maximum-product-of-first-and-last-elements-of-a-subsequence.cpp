class Solution {
public:
    long long maximumProduct(vector<int>& nums, int m) {
        long long MAX = -1e11;
        int N = nums.size();

        int suffix[100'005][2]; //MAX, MIN;

        suffix[N-1][0] = suffix[N-1][1] = nums[N-1];
        for(int i = N-2; i>=0; i--){
            suffix[i][0] = max(suffix[i+1][0], nums[i]);
            suffix[i][1] = min(suffix[i+1][1], nums[i]);
        }

        if(m == 1)
            return max({(long long)suffix[0][0] * suffix[0][0], (long long)suffix[0][1] * suffix[0][1]});
        

        for(int i = 0; i < N; i++){
            if(i + m-1 >= N) break;

            int& target = nums[i] > 0 ? suffix[i + m - 1][0] : suffix[i + m - 1][1];
            MAX = max(MAX, (long long)nums[i]*target);
        }

        return MAX;
    }
};