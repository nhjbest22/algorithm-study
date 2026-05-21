#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int ans;

int solution(int N) {
    for(int i = 1; i*i <= N; i++){    
        if(N % i != 0) continue;
        
        ans += i;
        
        if(i*i == N) break;
        
        ans += N/i;
    }
    
    return ans;
}