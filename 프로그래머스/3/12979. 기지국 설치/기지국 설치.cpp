#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int ans = 0;
    // 1 ~ N까지 커버해야 함
    
    vector<pair<int, int>> grid, grid_merge;
    
    for(auto& idx: stations){
        int st = max(1, idx - w);
        int en = min(n, idx + w);
        
        if(grid.empty()) {
           grid.push_back({st, en});
            continue;
        }
        
        if(grid.back().second + 1 < st){
            grid.push_back({st, en});
            continue;
        }
            
        
        auto& G = grid.back();
        G.second = en;
    }
    
    int cur = 1;
    int len = 2*w + 1;
    for(auto& G: grid){
        auto& [st, en] = G;
    
        
        ans += (st - cur)/len;
        ans += ((st - cur) % len > 0);
        
        cur = en + 1;
    }
    
    if(cur <= n){
        ans += (n - cur + 1) / len;
        ans += ((n - cur + 1) % len > 0);
    }

    return ans;
}