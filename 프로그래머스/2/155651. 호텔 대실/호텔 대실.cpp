#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int time_to_int(string& str){
    return 60*stoi(str.substr(0, 2)) + stoi(str.substr(3, 2));
}

int solution(vector<vector<string>> book_time) {
    int cur = 0;
    int ans = 0;
    vector<pair<int, int>> events;
    
    for(auto& times: book_time){
        int st = time_to_int(times[0]);
        int en = time_to_int(times[1]) + 10;
        
        // events.push_back({st, 1});
        // events.push_back({en, -1});
        
        events.push_back({st, en});
    }
    
    sort(events.begin(), events.end());
    priority_queue<int, vector<int>, greater<>> pq;
    
    for(auto& e: events){
        auto [S, E] = e;
        
        if(pq.empty()){
            pq.push(E);
            continue;
        }
        
        auto cur = pq.top();
        if(S >= cur) pq.pop();
        
        pq.push(E);
    }
    
    return pq.size();
}