#include <string>
#include <vector>

using namespace std;

const int mod = 1'000'000'007;

int dp[105][105];

int solution(int m, int n, vector<vector<int>> puddles) {
    // 모든 좌표는 y,x 로 주어짐
    for(auto grid: puddles){
        int y = grid[0], x = grid[1];
        dp[x][y] = -1;
    }
    
    for(int i = 1; i <= m; i++) {
        if(dp[1][i] == -1) break;
        dp[1][i] = 1;
    }
    
    for(int i = 1; i <= n; i++){
        if(dp[i][1] == -1) break;
        dp[i][1] = 1;
    }
    
    for(int x = 2; x <= n; x++){
        for(int y = 2; y <= m; y++){
            if(dp[x][y] == -1) continue;
            
            if(dp[x-1][y] != -1){
                dp[x][y] += dp[x-1][y];
            }
            
            if(dp[x][y-1] != -1){
                dp[x][y] += dp[x][y-1];
            }
            
            dp[x][y] %= mod;
        }
    }
    
    return dp[n][m];
}