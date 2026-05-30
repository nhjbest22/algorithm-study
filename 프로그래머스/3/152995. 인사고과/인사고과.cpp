#include <bits/stdc++.h>

using namespace std;

#define MAX 100'001
#define rank RANK

int rank[100'005];

int solution(vector<vector<int>> scores) {
    int N = scores.size();
    vector<tuple<int, int, int>> v; //x, y, index
    vector<pair<int, int>> res;
    
    for(int i = 0; i < N; i++)
        v.push_back({scores[i][0], scores[i][1], i});
    
    sort(v.begin(), v.end(), [](const tuple<int, int, int>& a, const tuple<int, int , int>& b){
        if(get<0>(a) != get<0>(b)) 
            return get<0>(a) > get<0>(b);
        if(get<1>(a) != get<1>(b))
            return get<1>(a) < get<1>(b);
        return get<2>(a) < get<2>(b);
    });
    
    int cur_max = -1;
    for(int i = 0; i < N; i++){
        auto& [cur_x, cur_y, cur_idx] = v[i];
        
        if(cur_y < cur_max) continue;
        
        cur_max = max(cur_max, cur_y);
        res.push_back({cur_x + cur_y, cur_idx});
    }
    
    res.push_back({MAX + MAX, MAX});
    
    sort(res.begin(), res.end(), [](const pair<int, int>& a, const pair<int , int>& b){
        if(a.first != b.first) 
            return a.first > b.first;
        
        return a.second < b.second;
    });
    
    // for(auto& [sum, index]: res) cout<<sum<<' '<<index<<endl;
    
    int cnt = 0;
    for(int i = 1; i < res.size(); i++){
        int& pre_idx = res[i-1].second;
        int& cur_idx = res[i].second;

        cnt++;
        
        if(res[i-1].first == res[i].first){            
            rank[cur_idx] = rank[pre_idx];
            continue;
        }
        
        rank[cur_idx] = cnt;
    }
    
    return rank[0] > 0 ? rank[0] : -1;
}