class Solution {
public:
    int maxTotalReward(vector<int>& reward) {
        int N = reward.size();
        sort(reward.begin(), reward.end());
        const int SZ = 4001;

        bitset<SZ> dp, ones;
        dp[0] = 1;
        ones.set();

        for(int& cur: reward){
            bitset<SZ> mask = ones >> (SZ - cur);
            dp |= (dp & mask) << cur;
        }

        for(int i = SZ; i >= 0; i--)
            if(dp[i]) return i;

        return 0;
    }
};