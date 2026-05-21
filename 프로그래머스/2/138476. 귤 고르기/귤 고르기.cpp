#include<bits/stdc++.h>

using namespace std;

#define X first
#define Y second

int solution(int k, vector<int> tangerine) {
    sort(tangerine.begin(), tangerine.end());
    
    vector<int> tCount;
    auto p = equal_range(tangerine.begin(), tangerine.end(), tangerine[0]);
    tCount.push_back(p.Y - p.X);
    
    for(int i = 1; i< tangerine.size(); i++){
        if(tangerine[i] == tangerine[i-1]) continue;
        
        p = equal_range(tangerine.begin(), tangerine.end(), tangerine[i]);
        tCount.push_back(p.Y - p.X);
    }
    
    sort(tCount.begin(), tCount.end(), greater<>());
    
    for(int i = 0; i < tCount.size(); i++)    {
        k -= tCount[i];
        if(k <= 0) return i+1;
    }
    
    return 0;    
}