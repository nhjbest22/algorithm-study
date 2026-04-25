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

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
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

int W, H;

string board[25];
pair<int, int> robot;
vector<pair<int, int>> dirt;
int sequence[12];

int dist[12][12];
int bfs_dist[22][22];

void bfs(int index) {
  queue<pair<int, int>> Q;
  fill(&bfs_dist[0][0], &bfs_dist[0][0] + 22 * 22, -1);

  pair<int, int> st;
  if (!index)
    st = robot;
  else
    st = dirt[index - 1];

  bfs_dist[st.X][st.Y] = 0;
  Q.push(st);

  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    rep(i, 0, 4) {
      int x = cur.X + dx[i];
      int y = cur.Y + dy[i];

      if (x < 0 || x >= H || y < 0 || y >= W) continue;
      if (bfs_dist[x][y] > -1) continue;
      if (board[x][y] == 'x') continue;

      bfs_dist[x][y] = bfs_dist[cur.X][cur.Y] + 1;
      Q.push({x, y});
    }
  }

  dist[index][0] = bfs_dist[robot.X][robot.Y];
  rep(i, 0, dirt.size()) dist[index][i + 1] = bfs_dist[dirt[i].X][dirt[i].Y];
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  while (1) {
    cin >> W >> H;
    if (W == 0 && H == 0) return 0;

    int ans(INT32_MAX);
    dirt.clear();

    rep(i, 0, H) {
      cin >> board[i];
      rep(j, 0, W) {
        if (board[i][j] == '*') dirt.push_back({i, j});
        if (board[i][j] == 'o') robot = {i, j};
      }
    }

    rep(i, 0, dirt.size() + 1) { bfs(i); }

    rep(i, 0, dirt.size()) sequence[i] = i;

    bool isPossible = true;

    do {
      int d = 0;
      int cur = 0;
      rep(i, 0, dirt.size()) {
        int curDist = dist[cur][sequence[i] + 1];

        if (curDist == -1) {
          isPossible = false;
          break;
        }

        d += curDist;
        cur = sequence[i] + 1;
      }

      if (!isPossible) break;
      ans = min(d, ans);
    } while (next_permutation(sequence, sequence + dirt.size()));

    cout << (isPossible ? ans : -1) << endl;
  }
  return 0;
}