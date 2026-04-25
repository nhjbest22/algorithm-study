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

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

// const int dx[] = {0, 1};
// const int dy[] = {1, 0};

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
  for (auto const& t : V) pf1(t)
#define pfvecl(V)                 \
  for (auto const& t : V) pf1(t); \
  pf0l()
#define debug(x) cout << #x << " is " << x << '\n'
#define endl '\n'
#define rep(i, a, b) for (int i = a; i < b; i++)

int R, C;
string board[1505];
pair<int, int> swan;
int day = 1;
bool visit_ice[1505][1505], visit_swan[1505][1505];
queue<pair<int, int>> IQ, IQ2, SQ, SQ2;

void bfs() {
  visit_swan[swan.X][swan.Y] = 1;
  board[swan.X][swan.Y] = '.';
  SQ.push(swan);

  while (1) {
    // 얾음 녹이기
    while (!IQ.empty()) {
      auto [x, y] = IQ.front();
      IQ.pop();

      rep(dir, 0, 4) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if (visit_ice[nx][ny]) continue;

        visit_ice[nx][ny] = 1;
        if (board[nx][ny] == 'X') IQ2.push({nx, ny});
      }
    }

    while (!IQ2.empty()) {
      auto cur = IQ2.front();
      board[cur.X][cur.Y] = '.';
      IQ.push(cur);
      IQ2.pop();
    }

    while (!SQ.empty()) {
      auto [x, y] = SQ.front();
      SQ.pop();

      if (board[x][y] == 'L') {
        cout << day;
        return;
      }

      rep(dir, 0, 4) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if (visit_swan[nx][ny]) continue;

        visit_swan[nx][ny] = 1;
        board[nx][ny] == 'X' ? SQ2.push({nx, ny}) : SQ.push({nx, ny});
      }
    }

    while (!SQ2.empty()) {
      SQ.push(SQ2.front());
      SQ2.pop();
    }

    day++;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> R >> C;
  rep(i, 0, R) cin >> board[i];
  rep(i, 0, R) {
    rep(j, 0, C) {
      if (board[i][j] == 'L') swan = {i, j};
      if (board[i][j] != 'X') {
        visit_ice[i][j] = 1;
        IQ.push({i, j});
      }
    }
  }

  bfs();

  return 0;
}