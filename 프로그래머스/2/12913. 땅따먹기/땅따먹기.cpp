#include <bits/stdc++.h>

using namespace std;

int dp[100'005][4];
int ans;

int solution(vector<vector<int>> land)
{
    int N = land.size();
    
    for(int i = 0; i < 4; i++) dp[0][i] = land[0][i];
    
    for(int i = 1; i < N; i++){
        for(int j = 0; j < 4; j++){
            for(int k = 0; k < 4; k++){
                if(j == k) continue;
                
                dp[i][j] = max(dp[i][j], dp[i-1][k]);
            }
            
            dp[i][j] += land[i][j];
        }

    }
    
    ans = *max_element(&dp[N-1][0], &dp[N-1][0] + 4);
    
    return ans;
}