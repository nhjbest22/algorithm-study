class Solution {
public:
    int maxTotalReward(vector<int>& reward) {
        int N = reward.size();
        sort(reward.begin(), reward.end());

        bool dp[4005] = {false, };
        dp[0] = true;
        
        for(int i = 0; i < N; i++){
            int& cur = reward[i];
            for(int j = 2*cur -1; j >= cur; j--){
                if(dp[j-cur])
                    dp[j] = true;
            }
        }

        for(int i = 4004; i >= 0; i--)
            if(dp[i]) return i;
        
        return 0;
    }
};