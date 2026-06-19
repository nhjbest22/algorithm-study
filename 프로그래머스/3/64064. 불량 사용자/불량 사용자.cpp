#include <bits/stdc++.h>

using namespace std;

#define visit VISIT

vector<int> ban_list[10], choose(10, 0);
bool visit[10];
int ans, N;
set<int> s;

void backtrack(int k){
    if(k == N){
        int bitmask = 0;
        
        for(int i = 0; i < k; i++)
            bitmask += (1 << choose[i]);
        s.insert(bitmask);
        
        return;
    }
    
    for(auto idx: ban_list[k]){
        if(visit[idx]) continue;
        
        visit[idx] = true;
        choose[k] = idx;
        backtrack(k+1);
        visit[idx] = false;
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
    
    backtrack(0);
    
    return s.size();
}