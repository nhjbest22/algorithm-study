#include <string>
#include <vector>
#include <iostream>

using namespace std;

int hint_cnt[20];
int N;

int backtrack(int idx, int en, vector<vector<int>>& cost, vector<vector<int>>& hint){
    if(idx == en - 1){
        int cur_hint = min(hint_cnt[idx], N-1);
        return cost[idx][cur_hint];
    }
    
    int hint_bak[20];
    for(int i = 0; i <= en; i++) hint_bak[i] = hint_cnt[i];
    
    int ans = INT32_MAX;
    int cur_hint = min(hint_cnt[idx], N-1);
    
    int cur_cost = cost[idx][cur_hint];
    
    ans = min(ans, cur_cost + backtrack(idx+1, en, cost, hint));
    
    for(int i = 0; i <= en; i++) hint_cnt[i] = hint_bak[i];
    
    
    cur_cost += hint[idx][0];
    
    
    for(int j = 1; j < hint[idx].size(); j++){
        int nxt_hint = hint[idx][j] - 1;
        hint_cnt[nxt_hint]++;
    }
    
    ans = min(ans, cur_cost + backtrack(idx+1, en, cost, hint));
    for(int i = 0; i <= en; i++) hint_cnt[i] = hint_bak[i];

    return ans;
    
    
}

int solution(vector<vector<int>> cost, vector<vector<int>> hint) {
    // 힌트권에는 1~n 까지의 번호가 붙어 있음
    // i번 힌트권은 오직 i 번 스테이지에서만 사용 가능
    // 하나의 스테이지에서 사용할 수 있는 힌트권의 최대 개수는 n-1개입니다. (그럼 처음에는 힌트가 0개 인가?)
    
    
    int answer;
    N = cost.size();

    answer = backtrack(0, N, cost, hint);
    return answer;
}