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

// const int dx[4] = {1, 0, -1, 0};
// const int dy[4] = {0, 1, 0, -1};

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

const int dz[6] = {0, 0, 0, 0, -1, 1};

ll POW(ll a, ll b, ll MMM) {
  ll ret = 1;
  for (; b; b >>= 1, a = (a * a) % MMM)
    if (b & 1) ret = (ret * a) % MMM;
  return ret;
}
ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
ll LCM(ll a, ll b) {
  if (a == 0 || b == 0) return a + b;
  return a / GCD(a, b) * b;
}
ll INV(ll a, ll m) {
  ll m0 = m, y = 0, x = 1;
  if (m == 1) return 0;
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
  if (b == 0) return {1, 0};
  auto t = EXGCD(b, a % b);
  return {t.second, t.first - t.second * (a / b)};
}
bool OOB(ll x, ll y, ll N, ll M) { return 0 > x || x >= N || 0 > y || y >= M; }
#define visit VISIT
#define X first
#define Y second
#define rep(i, a, b) for (int i = a; i < b; i++)
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(a) ((int)(a.size()))
#define sf1(a) cin >> a
#define sf2(a, b) cin >> a >> b
#define sf3(a, b, c) cin >> a >> b >> c
#define sf4(a, b, c, d) cin >> a >> b >> c >> d
#define sf5(a, b, c, d, e) cin >> a >> b >> c >> d >> e
#define sf6(a, b, c, d, e, f) cin >> a >> b >> c >> d >> e >> f
#define pf1(a) cout << (a) << ' '
#define pf2(a, b) cout << (a) << ' ' << (b) << ' '
#define pf3(a, b, c) cout << (a) << ' ' << (b) << ' ' << (c) << ' '
#define pf4(a, b, c, d) \
  cout << (a) << ' ' << (b) << ' ' << (c) << ' ' << (d) << ' '
#define pf5(a, b, c, d, e) \
  cout << (a) << ' ' << (b) << ' ' << (c) << ' ' << (d) << ' ' << (e) << ' '
#define pf6(a, b, c, d, e, f)                                                \
  cout << (a) << ' ' << (b) << ' ' << (c) << ' ' << (d) << ' ' << (e) << ' ' \
       << (f) << ' '
#define pf0l() cout << '\n';
#define pf1l(a) cout << (a) << '\n'
#define pf2l(a, b) cout << (a) << ' ' << (b) << '\n'
#define pf3l(a, b, c) cout << (a) << ' ' << (b) << ' ' << (c) << '\n'
#define pf4l(a, b, c, d) \
  cout << (a) << ' ' << (b) << ' ' << (c) << ' ' << (d) << '\n'
#define pf5l(a, b, c, d, e) \
  cout << (a) << ' ' << (b) << ' ' << (c) << ' ' << (d) << ' ' << (e) << '\n'
#define pf6l(a, b, c, d, e, f)                                               \
  cout << (a) << ' ' << (b) << ' ' << (c) << ' ' << (d) << ' ' << (e) << ' ' \
       << (f) << '\n'
#define pfvec(V) \
  for (auto const &t : V) pf1(t)
#define pfvecl(V)                 \
  for (auto const &t : V) pf1(t); \
  pf0l()
#define debug(x) cout << #x << " is " << x << '\n'
#define endl '\n'

string board[15];
int ans;
bool visit[15][10];

bool bfs(int x, int y) {
  char type = board[x][y];
  int cnt = 0;

  queue<pair<int, int>> Q, route;
  visit[x][y] = 1;
  Q.push({x, y});

  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    route.push(cur);
    cnt++;

    rep(i, 0, 4) {
      int xPos = cur.X + dx[i];
      int yPos = cur.Y + dy[i];

      if (xPos < 0 || xPos >= 12 | yPos < 0 || yPos >= 6) continue;
      if (visit[xPos][yPos]) continue;
      if (board[xPos][yPos] != type) continue;

      visit[xPos][yPos] = 1;
      Q.push({xPos, yPos});
    }
  }

  if (cnt >= 4) {
    while (!route.empty()) {
      auto cur = route.front();
      route.pop();
      board[cur.X][cur.Y] = '.';
    }
  }

  return cnt >= 4;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  rep(i, 0, 12) cin >> board[i];

  while (1) {
    bool isBomb = false;

    // 일단 bfs로 탐색하면서 터뜨리기
    rep(i, 0, 12) {
      rep(j, 0, 6) {
        if (board[i][j] == '.' || visit[i][j]) continue;
        isBomb = bfs(i, j) || isBomb;
      }
    }

    // 모두 터뜨린 후, 안 터졌으면 end
    if (!isBomb) {
      cout << ans;
      return 0;
    }

    ans++;
    for (int i = 11; i >= 0; i--) {
      for (int j = 0; j < 6; j++) {
        if (board[i][j] == '.') continue;

        int x = i;
        while (1) {
          if (x + 1 >= 12 || board[x + 1][j] != '.') break;
          board[x + 1][j] = board[x][j];
          board[x][j] = '.';
          x++;
        }
      }
    }

    // visit 초기화
    fill(&visit[0][0], &visit[0][0] + 15 * 10, false);
  }
  return 0;
}