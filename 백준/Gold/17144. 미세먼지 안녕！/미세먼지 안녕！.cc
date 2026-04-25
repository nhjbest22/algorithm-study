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

// 동, 북, 서, 남
// 동, 남, 서, 북

// 북 동 남 서
// 남 동 북 서
const int dx[8] = {-1, 0, 1, 0, 1, 0, -1, 0};
const int dy[8] = {0, 1, 0, -1, 0, 1, 0, -1};

// const int dx2[4] = {0, 1, 0, -1};
// const int dy2[4] = {1, 0, -1, 0};
// const int dx[6] = {-1, 0, 1, 0, 0, 0};
// const int dy[6] = {0, -1, 0, 1, 0, 0};
// const int dz[6] = {0, 0, 0, 0, -1, 1};

// const int ddx[8] = { 0,0,1,1,1,-1,-1,-1 }, ddy[8] = { 1,-1,1,0,-1,1,0,-1 };

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
  for (auto const& t : V) pf1(t)
#define pfvecl(V)                 \
  for (auto const& t : V) pf1(t); \
  pf0l()
#define debug(x) cout << #x << " is " << x << '\n'
#define endl '\n'

int R, C, T;

int board[55][55];
// int spreadArr[55][55];
pair<int, int> cleaner[2];

void spread() {
  int spreadArr[55][55] = {};
  // fill(&spreadArr[0][0], &spreadArr[0][0] + 55*55, 0);
  rep(i, 0, R) {
    rep(j, 0, C) {
      if (board[i][j] == -1 || !board[i][j]) continue;

      int dirt = board[i][j];
      int cnt = 0;

      rep(dir, 0, 4) {
        int x = i + dx[dir];
        int y = j + dy[dir];

        if (x < 0 || x >= R || y < 0 || y >= C) continue;
        if (board[x][y] == -1) continue;

        spreadArr[x][y] += (dirt) / 5;
        cnt++;
      }

      if (cnt) board[i][j] -= (dirt / 5) * cnt;
    }
  }

  rep(i, 0, R) {
    rep(j, 0, C) {
      if (board[i][j] == -1) continue;

      board[i][j] += spreadArr[i][j];
    }
  }
}

void clean(int idx) {
  auto pos = cleaner[idx];
  board[pos.X][pos.Y] = 0;

  // clean 작업
  int st = idx ? 4 : 0;
  auto cur = make_pair(pos.X + dx[st], pos.Y + dy[st]);
  for (int i = st; i < st + 4; i++) {
    while (1) {
      auto nxt = make_pair(cur.X + dx[i], cur.Y + dy[i]);

      if (nxt.X < 0 || nxt.X >= R || nxt.Y < 0 || nxt.Y >= C) break;
      if (idx == 0 && nxt.X > pos.X) break;
      if (idx == 1 && nxt.X < pos.X) break;

      board[cur.X][cur.Y] = board[nxt.X][nxt.Y];
      cur = nxt;

      if (nxt.X == pos.X && nxt.Y == pos.Y) break;
    }
  }

  board[pos.X][pos.Y] = -1;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> R >> C >> T;

  int idx(0);
  rep(i, 0, R) {
    rep(j, 0, C) {
      cin >> board[i][j];
      if (board[i][j] == -1) cleaner[idx++] = {i, j};
    }
  }

  while (T--) {
    // 1. 미세먼지 확산
    spread();

    // 2. 공기청정기 작동
    clean(0);
    clean(1);
  }

  int ans(0);
  rep(i, 0, R) {
    rep(j, 0, C) {
      if (board[i][j] == -1) continue;
      ans += board[i][j];
    }
  }

  cout << ans;
  return 0;
}