#include <bits/stdc++.h>

using namespace std;

int answer;

int solution(int n) {
    vector<int> sums;
    int acc = 0;
    
    for(int i = 0; i<=n;i++){
        acc += i;
        sums.push_back(acc);
    }
    
    for(auto& acc: sums){
        if(acc < n) continue;
        
        if(binary_search(sums.begin(), sums.end(), acc - n)) answer++;
    }
    
    return answer;
}