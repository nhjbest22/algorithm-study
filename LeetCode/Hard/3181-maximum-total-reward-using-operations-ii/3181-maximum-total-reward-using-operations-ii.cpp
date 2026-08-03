class Solution {
public:
    int maxTotalReward(vector<int>& reward) {
        sort(reward.begin(), reward.end());
        auto it = unique(reward.begin(), reward.end());
        int N = it - reward.begin();

        const int SZ = 100001;

        bitset<SZ> dp, ones;
        dp[0] = 1;
        ones.set();

        for(int i = 0; i < N; i++){
            int& cur = reward[i];
            
            bitset<SZ> mask = ones >> (SZ - cur);
            dp |= (dp & mask) << cur;
        }

        for(int i = SZ - 1; i >= 0; i--)
            if(dp[i]) return i;

        return 0;
    }
};