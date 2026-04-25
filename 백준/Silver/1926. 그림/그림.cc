#include <bits/stdc++.h>
using namespace std;

#define visit VISIT

int arr[502][502];
int visit[502][502];

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x,y;
    cin>>x>>y;

    queue<pair<int,int>> Q;
    pair<int,int> p;
    int area = 0, maxarea = 0, numofpic = 0;
    for (int i=1;i<=x;i++){
        for(int j= 1;j<=y;j++){
            cin>>arr[i][j];
        }
    }
    for (int i=1;i<=x;i++){
        for(int j= 1;j<=y;j++){
            if(visit[i][j] == 1 || arr[i][j] == 0) continue;
            Q.push({i,j}); visit[i][j] = 1;
            area = 0;
            while (!Q.empty()){
                p = Q.front(); Q.pop(); area++;
                for (int i= 0; i < 4;i++){
                    int nx = p.first + dx[i];
                    int ny = p.second + dy[i];
                    if (nx < 1 || nx > x || ny <1 || ny > y) continue;
                    if (arr[nx][ny] == 0 || visit[nx][ny] == 1) continue;
                    Q.push({nx,ny}); visit[nx][ny] = 1;
                }
            }
            numofpic++;
            if (maxarea < area) maxarea = area;
        }
    }
    cout<<numofpic<<'\n'<<maxarea;
    return 0;
}