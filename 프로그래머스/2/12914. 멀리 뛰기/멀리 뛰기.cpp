#include <string>
#include <vector>

using namespace std;

const int mod = 1234567;

int dp[2005];

long long solution(int n) {
    dp[1] = 1;
    dp[2] = 2;
    
    for(int i = 3; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] %= mod;
    }
    
    return dp[n];
}