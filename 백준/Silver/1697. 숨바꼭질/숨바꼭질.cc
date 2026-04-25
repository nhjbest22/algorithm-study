#include <bits/stdc++.h>
using namespace std;

#define visit VISIT

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int dist[100002];

int main (){
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    int x,y; // x = 수빈 , y = 동생
    cin>>x>>y;
    queue <int> Q; Q.push(x); 
    fill(dist, dist+100002,-1); dist[x] = 0;
    while (dist[y] == -1)
    {
        auto cur = Q.front(); Q.pop();
        for (int nidx : {cur-1,cur+1,2*cur}){
            if(nidx < 0 || nidx > 100000 || dist[nidx] != -1) continue;
            Q.push(nidx); dist[nidx] = dist[cur]+1;
        }
    }
    cout<<dist[y];    
    return 0;
}