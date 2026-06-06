class Solution {
public:
    const int mod = 1e9 + 7;

    int countGoodStrings(int low, int high, int zero, int one) {
        int dp[100'005];

        fill(dp, dp + 100'005, 0);
        dp[0] = 1;

        for(int i =0; i <= high; i++){
            for(int nxt: {i + zero, i + one}){
                if(nxt > high) continue;

                dp[nxt] += dp[i];
                dp[nxt] %= mod;
            }
        }

        int ans = 0;
        for(int i = low; i <= high; i++){
            ans += dp[i];
            ans %= mod;
        }

        return ans;
    }
};