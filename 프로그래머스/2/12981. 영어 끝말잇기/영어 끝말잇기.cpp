#include <bits/stdc++.h>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    int N = words.size();
    int idx = 1;
    unordered_set<string> us;
    us.insert(words[0]);
    
    while(idx < N){
        if(us.find(words[idx]) != us.end())
            return {(idx%n)+1, idx/n + 1};
        
        if(words[idx][0] != words[idx-1][words[idx-1].size() - 1])
            return {(idx%n)+1, idx/n + 1};
        
        us.insert(words[idx]);
        
        idx++;
    }
    
    return {0, 0};
}