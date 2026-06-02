#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int ans = 0;
    // 1 ~ N까지 커버해야 함
    int cur = 1;
    int len = 2*w + 1;
    
    for(auto& idx: stations){
        int st = idx - w;
        int en = idx + w;
        
        if(st <= cur){
            cur = en + 1;
            continue;
        }
        
        int gap = st - cur;
        ans += (gap / len) + (gap % len > 0);
        cur = en + 1;
    }
    
    if(cur <= n){
        ans += (n - cur + 1) / len;
        ans += (n - cur + 1) % len > 0;
    }

    return ans;
}