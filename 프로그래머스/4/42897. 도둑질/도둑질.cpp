#include <bits/stdc++.h>

using namespace std;

int dp[1'000'005][2];
int ans;

int solution(vector<int> money) {
    int N = money.size();
    
    // 첫 집을 안 털고 진행
    
    for(int i = 1; i< N; i++){
        dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
        dp[i][1] = dp[i-1][0] + money[i];
    }
    
    ans = max(dp[N-1][0], dp[N-1][1]);
    
    fill(&dp[0][0], &dp[0][0] + 1'000'005*2, 0);
    
    dp[0][1] = money[0];
    for(int i = 1; i< N; i++){
        dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
        dp[i][1] = dp[i-1][0] + money[i];
    }
    
    ans = max(ans, dp[N-1][0]);
    
    return ans;
}