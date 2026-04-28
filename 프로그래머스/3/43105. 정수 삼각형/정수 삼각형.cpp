#include <bits/stdc++.h>

using namespace std;

int dp[505][505];

int solution(vector<vector<int>> triangle) {
    dp[0][0] = triangle[0][0];
    
    for(int i = 1; i < triangle.size(); i++){
        for(int j = 0; j<= i; j++){
            dp[i][j] = triangle[i][j];
            if(j == 0){
                dp[i][j] += dp[i-1][j];
                continue;
            }
            
            if(j == i){
                dp[i][j] += dp[i-1][j-1];
                continue;
            }
            
            dp[i][j] += max(dp[i-1][j-1], dp[i-1][j]);
        }
    }
    int height = triangle.size();
    
    return *max_element(dp[height-1], dp[height-1] + height);
}