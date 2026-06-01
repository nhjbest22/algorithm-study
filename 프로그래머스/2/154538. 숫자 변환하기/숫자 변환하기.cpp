#include <bits/stdc++.h>

using namespace std;

#define visit VISIT

int visit[1'000'005];

int solution(int x, int y, int n) {
    queue<int> Q;
    Q.push(x);
    
    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        
        if(cur == y) return visit[y];
        
        for(auto nxt: {cur + n, 2*cur, 3*cur}){
            if(visit[nxt] > 0) continue;
            if(nxt > y) continue;
            
            visit[nxt] = visit[cur] + 1;
            Q.push(nxt);
        }
    }
    
    return -1;
}