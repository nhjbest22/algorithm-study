#include <bits/stdc++.h>

using namespace std;

int idx = 0;
unordered_map<string, int> um;

void backtrack(string str){
    um[str] = idx++;
    if(str.size() == 5) return;
    
    for(auto ch: {'A', 'E', 'I', 'O', 'U'}){
        backtrack(str + ch);
    }
}

int solution(string word) {
    backtrack("");
    
    return um[word];
}