class Solution {
public:
    const int INF = 0x3f3f3f3f;

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    int minTimeToReach(vector<vector<int>>& moveTime) {
        int N = moveTime.size(), M = moveTime[0].size();
        
        int visit[755][755][2];
        fill(&visit[0][0][0], &visit[0][0][0] + 755*755*2, INF);

        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;
        visit[0][0][0] = 0;
        pq.push({0, 0, 0, 0}); //dist, x, y, step

        while(!pq.empty()){
            auto [dist, curX, curY, step] = pq.top();
            pq.pop();

            if(dist != visit[curX][curY][step]) continue;

            for(int dir = 0; dir < 4; dir++){
                int nxtX = curX + dx[dir];
                int nxtY = curY + dy[dir];

                if(nxtX < 0 || nxtX >= N || nxtY < 0 || nxtY >= M) continue;
                
                int startTime = max(visit[curX][curY][step], moveTime[nxtX][nxtY]);
                if(startTime + step + 1 >= visit[nxtX][nxtY][1-step]) continue;
                
                visit[nxtX][nxtY][1-step] = startTime + step + 1;
                pq.push({visit[nxtX][nxtY][1-step], nxtX, nxtY, 1-step});
            }
        }

        return min(visit[N-1][M-1][0], visit[N-1][M-1][1]);
    }
};