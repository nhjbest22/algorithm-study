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

// X 1 X
// 2 X 4
// X 3 X

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};

// 위, 왼쪽, 아래, 오른쪽

const int dz[6] = {0, 0, 0, 0, -1, 1};

// const int ddx[8] = { 0,0,1,1,1,-1,-1,-1 }, ddy[8] = { 1,-1,1,0,-1,1,0,-1
// };

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

int N, ans;
int board[25][25];
bool isMerge[25][25];

// 테스트 하면서 전진 or 병합
void proceed() {
  fill(&isMerge[0][0], &isMerge[0][0] + 25 * 25, 0);
  int dx = -1;

  rep(i, 0, N) {
    rep(j, 0, N) {
      int x = i;
      bool isMerged = false;
      if (!board[i][j]) continue;
      while (1) {
        if (x - 1 < 0) {
          isMerge[x][j] = isMerged;
          break;
        }
        // if (board[x - 1][j] > 0 && (board[x - 1][j] != board[x][j])) {
        //   isMerge[x][j] = merge;
        //   break;
        // }
        // if (isMerge[x - 1][j]) {
        //   isMerge[x][j] = merge;
        //   break;
        // }

        // if (board[x - 1][j] > 0 && merge) {
        //   isMerge[x][j] = merge;
        //   break;
        // }

        if (board[x - 1][j] > 0) {
          if (board[x - 1][j] != board[x][j] || isMerged || isMerge[x - 1][j]) {
            isMerge[x][j] = isMerged;
            break;
          }
        }

        if (board[x - 1][j] > 0) isMerged = true;
        board[x - 1][j] += board[x][j];
        board[x][j] = 0;

        x += dx;
      }
    }
  }
}

// boardCopy를 돌리자.
void rotate(int boardCopy[][25]) {
  int tmp[25][25];

  rep(i, 0, N) {
    rep(j, 0, N) { tmp[i][j] = boardCopy[i][j]; }
  }

  rep(i, 0, N) {
    rep(j, 0, N) { boardCopy[i][j] = tmp[N - 1 - j][i]; }
  }
}

void backtrack(int k) {
  if (k == 5) {
    rep(i, 0, N) {
      rep(j, 0, N) { ans = max(ans, board[i][j]); }
    }
    return;
  }

  int boardCopy[25][25];
  rep(i, 0, N) {
    rep(j, 0, N) { boardCopy[i][j] = board[i][j]; }
  }

  rep(rot, 0, 4) {
    // 함수 진행 부분

    proceed();

    backtrack(k + 1);

    rotate(boardCopy);
    rep(i, 0, N) {
      rep(j, 0, N) { board[i][j] = boardCopy[i][j]; }
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  rep(i, 0, N) {
    rep(j, 0, N) { cin >> board[i][j]; }
  }

  backtrack(0);

  cout << ans;

  return 0;
}