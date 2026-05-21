#include <bits/stdc++.h>

using namespace std;

#define visit VISIT
#define endl '\n'
#define rep(i,a,b) for(int i =a;i<b;i++)

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

bool visit[5][5];
int isSafe = true;

void bfs(int x, int y, vector<string>& place){
    visit[x][y] = 1;
    queue<tuple<int, int, int>> Q; //x,y,cnt
    Q.push({x,y, 0});
    
    while(!Q.empty()){
        auto [curX, curY, cnt] = Q.front();
        Q.pop();
        
        if(place[curX][curY] == 'P' && cnt > 0){
            isSafe = false;
            return;
        }
        
        if(cnt >= 2) continue;

        
        rep(dir,0,4){
            int nxtX = curX + dx[dir];
            int nxtY = curY + dy[dir];
            
            if(nxtX < 0 || nxtX >= 5 || nxtY <0 || nxtY >= 5) continue;
            if(visit[nxtX][nxtY]) continue;
            
            auto board = place[nxtX][nxtY];
            
            if(board == 'X') continue;
            
            visit[nxtX][nxtY] = 1;
            
            Q.push({nxtX, nxtY, cnt+1});
        }
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    // P는 응시자가 앉아있는 자리를 의미합니다.
    // O는 빈 테이블을 의미합니다.
    // X는 파티션을 의미합니다.
    int TC = places.size();
    
    rep(tc,0,TC){
        isSafe = true;
        vector<string>& place = places[tc];
        
        rep(i,0,5){
            rep(j,0,5){
                if(place[i][j] == 'P'){
                    bfs(i, j, place);
                    fill(&visit[0][0], &visit[0][0] + 5*5, false);
                }
            }
        }
        
        answer.push_back(isSafe);
    }
    
    return answer;

}