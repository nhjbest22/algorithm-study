#include <bits/stdc++.h>

using namespace std;

#define visit VISIT

vector<int> ban_list[10];
int N;
set<int> s;

void backtrack(int k, int bitmask){
    if(k == N){
        s.insert(bitmask);
        return;
    }
    
    for(auto idx: ban_list[k]){
        int cur = 1 << idx;
        if(bitmask & cur) continue;
        
        backtrack(k+1, bitmask | cur);
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    N = banned_id.size();
    for(int i = 0; i < N; i++){
        const auto& ban = banned_id[i];

        for(int j = 0; j< user_id.size(); j++){
            const auto& user = user_id[j];
        
            if(ban.size() != user.size()) continue;
            
            int len = user.size();
            bool isSame = true;
        
            for(int k = 0; k < len; k++){
                if(ban[k] == '*') continue;
                if(ban[k] != user[k]){
                    isSame = false;
                    break;
                }
            }
            
            if(isSame) ban_list[i].push_back(j);
        }
    }
    
    backtrack(0, 0);
    
    return s.size();
}