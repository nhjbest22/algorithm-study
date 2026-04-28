#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)

int dp[20'005];
const int MAX = 0x3f3f3f3f;

int solution(vector<string> strs, string t)
{
    unordered_set<string> us(strs.begin(), strs.end());
    fill(dp, dp+20'005, MAX);
    dp[0] = 0;
    
    rep(i, 1, t.length() + 1){
        for(int len = 1; len <=5; len++){
            if(i - len < 0) continue;
            
            if(us.count(t.substr(i-len, len))){
                dp[i] = min(dp[i], dp[i-len] + 1);
            }
        }
    }
    
    if(dp[t.length()] == MAX) return -1;
    return dp[t.length()];
}