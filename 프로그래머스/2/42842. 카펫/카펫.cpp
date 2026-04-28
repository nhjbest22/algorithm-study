#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    // 가로: y, 세로: x y >= x >= 3
    // 갈색: xy - (x-2)*(y-2) = xy - (xy - 2x - 2y + 4) = 2x + 2y - 4 <= 5000
    // 3 + y <= x + y <= 2502
    // 노란색: (x-2)*(y-2)
    
    // return {y, x}
    
    for(int y = 2499; y >= 3 ;y--){
        int x = (brown + 4 - 2*y) / 2;
        
        if (yellow != (x-2)*(y-2)) continue;
        
        answer.push_back(max(x, y));
        answer.push_back(min(x, y));
        break;
    }
    
    
    return answer;
}