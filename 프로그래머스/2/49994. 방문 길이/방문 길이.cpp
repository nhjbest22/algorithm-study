#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int ans;

bool route[11][11][11][11];

// 0 ~ 10

int solution(string dirs) {
    int curX = 5, curY = 5;
    
    unordered_map<char, int> um;
    um['U'] = 0; um['D'] = 1;
    um['R'] = 2; um['L'] = 3;
    
    for(auto& ch: dirs){
        int dir = um[ch];
        int nxtX = curX + dx[dir];
        int nxtY = curY + dy[dir];
        
        if(nxtX < 0 || nxtX > 10 || nxtY < 0 || nxtY > 10) continue;
        if(!route[curX][curY][nxtX][nxtY]) ans++;
        
        route[curX][curY][nxtX][nxtY] = true;
        route[nxtX][nxtY][curX][curY] = true;
        
        curX = nxtX;
        curY = nxtY;
    }
    
    return ans;
}