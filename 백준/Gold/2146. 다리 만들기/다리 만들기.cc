#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef tuple<int, int, int> ti3;
typedef tuple<int, int, int, int> ti4;
typedef stack<int> si;
typedef queue<int> qi;
typedef priority_queue<int> pqi;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef tuple<ll, ll, ll> tl3;
typedef tuple<ll, ll, ll, ll> tl4;
typedef stack<ll> sl;
typedef queue<ll> ql;
typedef priority_queue<ll> pql;

const int dx[4] = { 1,0,-1,0 };
const int dy[4] = { 0,1,0,-1 };
const int ddx[8] = { 0,0,1,1,1,-1,-1,-1 }, ddy[8] = { 1,-1,1,0,-1,1,0,-1 };
ll POW(ll a, ll b, ll MMM) { ll ret = 1; for (; b; b >>= 1, a = (a*a) % MMM)if (b & 1)ret = (ret*a) % MMM; return ret; }
ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
ll LCM(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a / GCD(a, b) * b; }
ll INV(ll a, ll m) {
  ll m0 = m, y = 0, x = 1;
  if (m == 1)	return 0;
  while (a > 1) {
    ll q = a / m;
    ll t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}
pll EXGCD(ll a, ll b) {
  if (b == 0) return { 1,0 };
  auto t = EXGCD(b, a%b);
  return { t.second,t.first - t.second*(a / b) };
}
bool OOB(ll x, ll y, ll N, ll M) { return 0 > x || x >= N || 0 > y || y >= M; }
#define visit VISIT
#define X first
#define Y second
#define rep(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sf1(a) cin >> a
#define sf2(a,b) cin >> a >> b
#define sf3(a,b,c) cin >> a >> b >> c
#define sf4(a,b,c,d) cin >> a >> b >> c >> d
#define sf5(a,b,c,d,e) cin >> a >> b >> c >> d >> e
#define sf6(a,b,c,d,e,f) cin >> a >> b >> c >> d >> e >> f
#define pf1(a) cout << (a) << ' '
#define pf2(a,b) cout << (a) << ' ' << (b) << ' '
#define pf3(a,b,c) cout << (a) << ' ' << (b) << ' '<< (c) << ' '
#define pf4(a,b,c,d) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '
#define pf5(a,b,c,d,e) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << ' '
#define pf6(a,b,c,d,e,f) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << ' ' << (f) << ' '
#define pf0l() cout << '\n';
#define pf1l(a) cout << (a) << '\n'
#define pf2l(a,b) cout << (a) << ' ' << (b) << '\n'
#define pf3l(a,b,c) cout << (a) << ' ' << (b) << ' '<< (c) << '\n'
#define pf4l(a,b,c,d) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << '\n'
#define pf5l(a,b,c,d,e) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << '\n'
#define pf6l(a,b,c,d,e,f) cout << (a) << ' ' << (b) << ' '<< (c) << ' '<< (d) << ' '<< (e) << ' ' << (f) << '\n'
#define pfvec(V) for(auto const &t : V) pf1(t)
#define pfvecl(V) for(auto const &t : V) pf1(t); pf0l()
#define debug(x) cout << #x << " is " << x << '\n'
#define endl '\n'

bool vis[105][105];
bool board[105][105];
int part[105][105];
int ans = 10005;
int N;

void bfs(int x, int y){
  bool route[105][105];
  int team = part[x][y];
  rep(i,0,N){
    rep(j,0,N){
      route[i][j] = false;
    }
  }
  queue<pair<pair<int, int>, int>> Q;
  rep(i,0,4){
    int xx = x + dx[i];
    int yy = y + dy[i];
    if(xx<0 || xx>=N || yy<0 ||yy >=N) continue;
    if(!board[xx][yy]) Q.push({{xx, yy}, 1}); route[xx][yy] = true;
  }
  while(!Q.empty()){
    auto cur = Q.front().first;
    int len = Q.front().second; Q.pop();
    rep(i,0,4){
      int xx = cur.first + dx[i];
      int yy = cur.second + dy[i];
      if(xx<0 || xx>=N || yy<0 || yy>=N) continue;
      if(route[xx][yy]) continue;
      if(!board[xx][yy]){
        Q.push({{xx,yy}, len+1});
        route[xx][yy] = true;
        // if(x == 3 && y == 4){
        //   debug(xx); debug(yy); debug(len+1);
        // }
      }
      if(board[xx][yy] && part[xx][yy] != team){
        // if(len == 1){
        //   debug(x); debug(y);
        //   debug(xx); debug(yy);
        // }
        ans = min(ans, len);
        return;
      }
    }
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  cin>>N;
  rep(i,0,N){
    rep(j,0,N){
      cin>>board[i][j];
    }
  }
  int team = 0;
  rep(i,0,N){
    rep(j,0,N){
      if(board[i][j] && !vis[i][j]){
        team++;
        part[i][j] = team;
        queue<pair<int, int>>Q;
        Q.push({i,j}); vis[i][j] = true;
        while(!Q.empty()){
          auto cur = Q.front(); Q.pop();
          rep(i,0,4){
            int x = cur.first + dx[i];
            int y = cur.second + dy[i];
            if(x < 0 || x>= N || y < 0 || y>= N) continue;
            if(vis[x][y] || !board[x][y]) continue;
            Q.push({x,y}); vis[x][y] = true; part[x][y] = team;
          }
        }
      }
    }
  }
  rep(i,0,N){
    rep(j,0,N){
      vis[i][j] = false;
    }
  }

  rep(i,0,N){
    rep(j,0,N){
      if(board[i][j]){
      bool isEdge = false;
      rep(k,0,4){
        int x = i + dx[k];
        int y = j + dy[k];
        if(x < 0 || x>= N || y<0 || y>=N) continue;
        if(!board[x][y]) isEdge = true;
      }
      if(isEdge) bfs(i,j);
      }
    }
  }
  cout<<ans;
  return 0;
}