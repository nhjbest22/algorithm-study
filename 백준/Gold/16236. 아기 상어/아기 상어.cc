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

const int dx[4] = {0, -1, 0, 1};  // 동, 북, 서, 남
const int dy[4] = {1, 0, -1, 0};  // 동, 북, 서, 남

// const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
// const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

// 1 2 3
// 4 0 5
// 6 7 8

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

int N, ans, shark(2), feed;

int board[22][22];
int dist[22][22];

// 가장 가까운 먹이를 찾고, 해당 위치로 cur 수정 + board 판 0으로 만들기
// 본인 크기와 같은 먹이를 먹을 경우 feed + 1
bool bfs(pair<int, int> &cur) {
  queue<pair<int, int>> Q;
  dist[cur.X][cur.Y] = 0;
  Q.push({cur});

  int curDist = INT32_MAX;
  pair<int, int> fish = {30, 30};

  while (!Q.empty()) {
    auto now = Q.front();
    Q.pop();

    rep(i, 0, 4) {
      int x = now.X + dx[i];
      int y = now.Y + dy[i];

      if (x < 0 || x >= N | y < 0 || y >= N) continue;
      if (dist[x][y] != -1) continue;
      if (board[x][y] > shark) continue;

      dist[x][y] = dist[now.X][now.Y] + 1;

      if (dist[x][y] > curDist) continue;

      if (!board[x][y] || board[x][y] == shark) {
        Q.push({x, y});
        continue;
      }

      if (dist[x][y] <= curDist) {
        curDist = dist[x][y];
        if (x <= fish.X && y <= fish.Y) fish = {x, y};
      }
    }
  }

  if (curDist == INT32_MAX) return false;

  cur = fish;
  board[cur.X][cur.Y] = 0;
  ans += curDist;

  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  pair<int, int> pos;

  cin >> N;
  rep(i, 0, N) {
    rep(j, 0, N) {
      cin >> board[i][j];
      if (board[i][j] == 9) {
        pos = {i, j};
        board[i][j] = 0;
      }
    }
  }

  while (1) {
    fill(&dist[0][0], &dist[0][0] + 22 * 22, -1);

    if (!bfs(pos)) {
      cout << ans;
      return 0;
    }

    feed = (feed + 1) % shark;
    shark = feed ? shark : shark + 1;
  }

  return 0;
}