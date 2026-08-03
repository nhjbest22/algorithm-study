class Solution {
public:
    int maxTotalReward(vector<int>& reward) {
        bool dp[2005][4005] = {false, };
        sort(reward.begin(), reward.end());
        dp[0][reward[0]] = true;

        int MAX = reward[0];

        int N = reward.size();
        for(int i = 1; i < N; i++){
            int& cur = reward[i];
            int& prev = reward[i-1];
            dp[i][cur] = true;

            for(int j = 0; j< 2*prev; j++){
                if(!dp[i-1][j]) continue;

                dp[i][j] = true;
                if(j < cur) dp[i][j + cur] = true;
            }
        }

        int& en = reward[N-1];
        for(int i = en; i < 2*en; i++)
            if(dp[N-1][i]) 
                MAX = i;
        
        return MAX;
    }
};