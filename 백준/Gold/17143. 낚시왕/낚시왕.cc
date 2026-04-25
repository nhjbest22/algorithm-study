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

int R, C, M, ans;
// vector<tuple<int, int, int>> board[105][105];
optional<tuple<int, int, int>> board[105][105];
vector<tuple<int, int, int>> dummy[105][105];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> R >> C >> M;
  rep(i, 0, M) {
    // r,c 속력, 이동방향, 크기
    int r, c, s, d, z;
    cin >> r >> c >> s >> d >> z;
    board[r - 1][c - 1] = (make_tuple(s, d - 1, z));
  }

  rep(yPos, 0, C) {
    rep(xPos, 0, R) {
      if (!board[xPos][yPos].has_value()) continue;

      int s, d, z;
      tie(s, d, z) = board[xPos][yPos].value();
      ans += z;
      board[xPos][yPos] = nullopt;

      break;
    }

    rep(r, 0, R) {
      rep(c, 0, C) {
        if (!board[r][c].has_value()) continue;

        int s, d, z, diff;
        tie(s, d, z) = board[r][c].value();

        int x(r), y(c);

        if (d < 2) {
          diff = s % (2 * R - 2);
          while (diff) {
            int move;
            if (d == 0) {
              // 위로 움직이기
              move = min(x, diff);
              x -= move;
            } else {
              // 아래로 움직이기
              move = min(R - x - 1, diff);
              x += move;
            }
            diff -= move;
            if (x == R - 1 || x == 0) d = (d == 0 ? 1 : 0);
          }
        } else {
          diff = s % (2 * C - 2);
          while (diff) {
            int move;
            if (d == 2) {
              // 오른쪽으로 움직이기
              move = min(C - 1 - y, diff);
              y += move;
            } else {
              move = min(y, diff);
              y -= move;
              // 왼쪽으로 움직이기
            }
            diff -= move;
            if (y == 0 || y == C - 1) d = (d == 2 ? 3 : 2);
          }
        }

        dummy[x][y].push_back(make_tuple(s, d, z));
      }
    }

    rep(i, 0, R) {
      rep(j, 0, C) {
        board[i][j] = nullopt;

        if (!dummy[i][j].size()) continue;

        auto shark = max_element(
            dummy[i][j].begin(), dummy[i][j].end(),
            [](const auto &a, const auto &b) { return get<2>(a) < get<2>(b); });

        board[i][j] = *shark;
        dummy[i][j].clear();
      }
    }
  }
  cout << ans;
  return 0;
}
