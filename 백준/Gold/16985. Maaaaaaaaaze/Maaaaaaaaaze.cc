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

const int dz[6] = {0, 0, 0, 0, -1, 1};
const int dx[6] = {-1, 0, 1, 0, 0, 0};
const int dy[6] = {0, -1, 0, 1, 0, 0};

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

bool board[5][5][5];
int visit[5][5][5];
int ans(INT32_MAX);

void rotate(int height) {
  bool tmp[5][5];
  rep(i, 0, 5) {
    rep(j, 0, 5) { tmp[i][j] = board[height][4 - j][i]; }
  }

  rep(i, 0, 5) {
    rep(j, 0, 5) { board[height][i][j] = tmp[i][j]; }
  }
}

void bfs() {
  int order[] = {0, 1, 2, 3, 4};
  do {
    fill(&visit[0][0][0], &visit[0][0][0] + 5 * 5 * 5, -1);

    if (!board[order[0]][0][0]) continue;

    queue<tuple<int, int, int>> Q;
    visit[order[0]][0][0] = 0;
    Q.push(make_tuple(0, 0, 0));

    while (!Q.empty()) {
      auto cur = Q.front();
      Q.pop();

      int x, y, z;
      tie(z, x, y) = cur;

      if (x == 4 && y == 4 && z == 4) {
        break;
      }

      rep(i, 0, 6) {
        int xPos = x + dx[i];
        int yPos = y + dy[i];
        int zPos = z + dz[i];

        if (xPos < 0 || xPos >= 5 || yPos < 0 || yPos >= 5 || zPos < 0 ||
            zPos >= 5)
          continue;
        if (visit[order[zPos]][xPos][yPos] != -1) continue;
        if (!board[order[zPos]][xPos][yPos]) continue;

        visit[order[zPos]][xPos][yPos] = visit[order[z]][x][y] + 1;
        Q.push(make_tuple(zPos, xPos, yPos));
      }
    }

    if (visit[order[4]][4][4] != -1) ans = min(ans, visit[order[4]][4][4]);
  } while (next_permutation(order, order + 5));
}

void backtrack(int k) {
  if (k == 5) {
    bfs();
    return;
  }

  // 높이 k에 대해서 회전 및 backtracking 수행
  // 0이면 1층 backtracking 실행 + 0층 회전
  rep(i, 0, 4) {
    backtrack(k + 1);
    rotate(k);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  rep(i, 0, 5) {
    rep(j, 0, 5) {
      rep(k, 0, 5) { cin >> board[i][j][k]; }
    }
  }

  backtrack(0);
  cout << (ans == INT32_MAX ? -1 : ans);

  return 0;
}