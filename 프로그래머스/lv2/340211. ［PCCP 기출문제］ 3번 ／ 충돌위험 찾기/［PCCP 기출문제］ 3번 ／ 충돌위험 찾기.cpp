#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define X first
#define Y second

vector<pair<int, int>> make_path(vector<vector<int>>& points, vector<int>& routes){
    vector<pair<int, int>> path;
    
    int x = points[routes[0] - 1][0];
    int y = points[routes[0] - 1][1];
    
    path.push_back({x, y});
    
    for(int i= 1; i < routes.size(); i++){
        int target_x = points[routes[i] - 1][0];
        int target_y = points[routes[i] - 1][1];
        
        while(x != target_x){
            x += (target_x > x ? 1 : -1);
            path.push_back({x, y});
        }
        
        while(y != target_y){
            y += (target_y > y ? 1 : -1);
            path.push_back({x, y});
        }
    }
    
    return path;
}


int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    // routes의 index가 1부터 시작함!!!!
    // 위 아래 움직임을 좌우 움직임 보다 더 먼저 함
    
    int ans = 0;
    
    vector<vector<pair<int, int>>> paths;
    int max_time = 0;
    for(int i = 0; i< routes.size(); i++){
        auto path = make_path(points, routes[i]);
        paths.push_back(path);
        max_time = max(max_time, (int)path.size());
    }
    
    for(int t = 0; t < max_time; t++){
        int board[105][105] = {0, };
        
        for(int robot = 0; robot < routes.size(); robot++){
            auto& path = paths[robot];
            if(t >= path.size()) continue;
            
            auto& cur = path[t];
            board[cur.X][cur.Y]++;
            
            if(board[cur.X][cur.Y] == 2) ans++;
        }
    }
    
    return ans;
}