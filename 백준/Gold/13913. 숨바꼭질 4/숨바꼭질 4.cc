#include <bits/stdc++.h>
#define visit VISIT
#define X first
#define Y second

using namespace std;

int visit[200005];


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    stack<int> S;
    queue<pair<int,int>> Q;
    int N, M;
    for (int i =0; i < 200005;i++)
        visit[i] = -1;
    cin>>N>>M;
    if (N == M)
    {
        cout<<0<<'\n'<<N; return 0;
    }

    Q.push({-1,N});
    bool IsFind = false;
    visit[N] = 1;
    int Npos;
    while (!Q.empty())
    {
        auto pos = Q.front(); Q.pop();
        for (int dir =0; dir <3;dir++){
            if (dir == 0)
                Npos = pos.Y -1;
            else if(dir == 1)
                Npos = pos.Y +1;
            else    
                Npos = 2*pos.Y;
            if (Npos <= -3 || Npos >= 140000 || visit[Npos] != -1) continue;
            Q.push({pos.Y,Npos}); visit[Npos] = pos.Y;
        }
    }
    int cur = M;
    S.push(M);
    while(visit[cur] != N){
        S.push(visit[cur]); cur = visit[cur];
    }
    S.push(N);
    cout<<S.size()-1<<'\n';

    while(!S.empty()){
        cout<<S.top()<<' '; S.pop();
    }
    return 0;
}