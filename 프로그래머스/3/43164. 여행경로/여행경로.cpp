#include <bits/stdc++.h>

using namespace std;

vector<pair<string, bool>> route[10'005];
vector<string> answer;
unordered_map<string, int> S2I;
int N;

#define visit VISIT

bool dfs(string from){
    answer.push_back(from);
    
    if(answer.size() == N + 1){
        return true;
    }
    
    if(S2I.find(from) == S2I.end()) return false;
    
    int idx = S2I[from];
        
    for(auto& [to, visit]: route[idx]){
        if(visit) continue;
        
        visit = true;
        if(dfs(to)) return true;
        
        visit = false;
        answer.pop_back();
    }
    
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    N = tickets.size();
    int idx = 0;
    
    for(int i = 0; i< N; i++){
        auto& ticket = tickets[i];
        auto from = ticket[0], to = ticket[1];
        
        if(S2I.find(from) == S2I.end()) S2I[from] = idx++;
            
        route[S2I[from]].push_back({to, false});
    }
    
    for(int i = 0;i < idx; i++) 
        sort(route[i].begin(), route[i].end());
    
    string from = "ICN";
    dfs(from);
    
    return answer;
}