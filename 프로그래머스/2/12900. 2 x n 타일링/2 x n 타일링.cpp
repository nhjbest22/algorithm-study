#include <string>
#include <vector>

using namespace std;

int dp[60'005];
int mod = 1'000'000'007;

int solution(int n) {
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= mod;
    }
    
    return dp[n];
}