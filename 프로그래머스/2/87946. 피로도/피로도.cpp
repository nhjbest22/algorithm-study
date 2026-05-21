#include <bits/stdc++.h>

using namespace std;

bool isVisit[10];
int ans;

void backtrack(int cur, int k, vector<vector<int>>& dungeons){
    ans = max(cur, ans);
    
    for(int i = 0; i < dungeons.size(); i++){
        if(isVisit[i]) continue;
        if(k < dungeons[i][0]) continue;
        
        isVisit[i] = true;
        backtrack(cur + 1, k - dungeons[i][1], dungeons);
        
        isVisit[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    backtrack(0, k, dungeons);
    return ans;
}