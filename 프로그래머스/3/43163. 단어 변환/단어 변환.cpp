#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout<<#x<<" is "<<x<<endl;

int solution(string begin, string target, vector<string> words) {
    int N = words[0].size();
    
    queue<pair<string, int>> Q;    
    Q.push({target, 0});
    
    unordered_map<string, int> um;
    
    for(auto word: words)
        um[word] = -1;
    
    
    bool isFind = false;
    for(const auto& word: words) {
        if(word == target) isFind = true;
    }
    
    if(!isFind) return 0;
    
    while(!Q.empty()){
        auto [cur_word, cnt] = Q.front();
        Q.pop();
        
        int diff = 0;
        for(int i =0; i< N; i++) diff += (begin[i] != cur_word[i]);
        
        if(diff == 1) return cnt + 1;
        
        for(const auto& word: words){
            if(um[word] > -1) continue;
            
            diff = 0;
            for(int i =0; i< N; i++) diff += (word[i] != cur_word[i]);
            if(diff > 1) continue;
            
            um[word] = cnt + 1;
            Q.push({word, cnt + 1});
        }
    }
    
    return 0;
}