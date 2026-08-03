class Solution {
public:
    int maxTotalReward(vector<int>& reward) {
        int N = reward.size();
        sort(reward.begin(), reward.end());
        reward.erase(unique(reward.begin(), reward.end()), reward.end());

        const int SZ = 100001;

        bitset<SZ> dp, ones;
        dp[0] = 1;
        ones.set();

        for(int& cur: reward){
            bitset<SZ> mask = ones >> (SZ - cur);
            dp |= (dp & mask) << cur;
        }

        for(int i = SZ - 1; i >= 0; i--)
            if(dp[i]) return i;

        return 0;
    }
};