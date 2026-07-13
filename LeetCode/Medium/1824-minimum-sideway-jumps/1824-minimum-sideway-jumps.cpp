class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int dp[5*100'005][3];
        fill(&dp[0][0], &dp[0][0] + 5*100'005*3, INT32_MAX);
        
        dp[0][1] = 0;
        dp[0][0] = dp[0][2] = 1;

        int N = obstacles.size();
        for(int i = 1; i < N; i++){
            for(int j = 0; j < 3; j++) {
                if(obstacles[i] -1 == j) continue;
                vector<int> MIN;

                for(int k = 0; k < 3; k++){
                    if(dp[i-1][k] == INT32_MAX || obstacles[i] -1 == k) continue;
                    MIN.push_back(j == k ? dp[i-1][k] : dp[i-1][k] + 1);
                }

                dp[i][j] = *min_element(MIN.begin(), MIN.end());
            }
        }

        return min({dp[N-1][0], dp[N-1][1], dp[N-2][2]});
    }
};