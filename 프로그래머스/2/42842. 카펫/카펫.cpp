#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)

vector<int> solution(int brown, int yellow) {
    // 가로 - 1: y, 세로 - 1: x
    // 
    
    int x = 2;
    int y = brown/2 - x;
    
    while(1){
        if((x-1)*(y-1) == yellow) return {y + 1, x + 1};
        
        x++;
        y--;
    }
    
    return {};
}