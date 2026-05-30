#include <bits/stdc++.h>

using namespace std;

#define MAX 100'001
#define rank RANK

int solution(vector<vector<int>> scores) {
    int N = scores.size();
    
    int a = scores[0][0], b = scores[0][1];
    
    sort(scores.begin(), scores.end(), [](const vector<int>& a, const vector<int>& b){
        if(a[0] != b[0]) return a[0] > b[0];
        return a[1] < b[1];
    });
        
    int cur_max = -1;
    int wanho_rank = 1;
    for(auto& score: scores){
        if(score[1] < cur_max){
            if(score[0] == a && score[1] == b) return -1;
            
            continue;
        }
        
        cur_max = max(cur_max, score[1]);
        if(score[0] + score[1] > a + b) wanho_rank++;
    }
    
    return wanho_rank;
}