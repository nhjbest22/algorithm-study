#include <string>
#include <vector>

using namespace std;

bool visit[205];
int N;

void dfs(int cur, vector<vector<int>>& computers){
    visit[cur] = true;
    
    for(int i = 0; i < N; i++){
        if(visit[i]) continue;
        if(!computers[cur][i]) continue;
        
        dfs(i, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int ans = 0;
    N = n;
    
    for(int i = 0; i < n; i++){
        if(visit[i]) continue;
        
        ans++;
        dfs(i, computers);
    }
    
    return ans;
}