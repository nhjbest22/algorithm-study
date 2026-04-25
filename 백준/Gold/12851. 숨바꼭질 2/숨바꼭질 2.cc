#include <bits/stdc++.h>
using namespace std;

#define visit VISIT

int visit[100002];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>>Q;
    int x,y, count,ans = 0;
    bool Isfind = false;
    cin>>x>>y;
    Q.push({x,0}); visit[x] = 0;
    if (x > y){cout<<x-y<<'\n'<<1; return 0;}
    while(!Q.empty()){
        auto pos = Q.front(); Q.pop();
        if (pos.first == y){cout<<"0\n1"; return 0;}
        for (int nidx : {pos.first-1, pos.first+1, pos.first*2}){
            //cout<<nidx<<' '<<pos.second+1<<'\n';
            if (nidx == y){
                if (!Isfind) {
                    Isfind = true; cout<<pos.second+1<<'\n';
                    count = pos.second; ans++; continue;
                }
                if (Isfind && pos.second == count){ans++; continue;} 
            }
            if (Isfind && pos.second != count) {cout<<ans; return 0;}
            if (nidx < 0 || nidx > 100000 || (visit[nidx] != 0 && pos.second+1 > visit[nidx])) continue;
            if (!visit[nidx]) visit[nidx] = pos.second+1;
            Q.push({nidx, pos.second+1}); 
        }
    }
    return 0;
}