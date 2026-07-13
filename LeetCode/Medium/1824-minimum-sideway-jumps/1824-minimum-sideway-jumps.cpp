class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int dp[3] = {1, 0, 1};
        int N = obstacles.size();

        for(int i = 1; i < N; i++){
            int obs = obstacles[i] - 1;

            if(obs >= 0) dp[obs] = 1e9;

            int min_jump = min({dp[0], dp[1], dp[2]}) + 1;

            for(int j = 0; j < 3; j++){
                if(obs == j) continue;

                dp[j] = min(dp[j], min_jump);
            }
        }

        return min({dp[0], dp[1], dp[2]});
    }
};