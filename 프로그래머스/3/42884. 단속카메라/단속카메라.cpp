#include <bits/stdc++.h>

using namespace std;

int ans = -1;
int MIN = INT32_MIN;

int solution(vector<vector<int>> routes) {
    int N = routes.size();
    vector<pair<int, int>> car_routes;
    
    for(int i = 0; i< N; i++) car_routes.push_back({routes[i][0], routes[i][1]});
    sort(car_routes.begin(), car_routes.end());
    
    for(int i = 0; i < N; i++){
        auto [st, en] = car_routes[i];
        
        if(st > MIN){
            ans++;
            MIN = en;
            continue;
        }
    
        MIN = min(MIN, en);
    }
    
    return ans + 1;
}