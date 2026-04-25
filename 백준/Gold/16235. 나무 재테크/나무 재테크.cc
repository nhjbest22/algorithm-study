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

// const int dx[4] = {0, -1, 0, 1};  // 동, 북, 서, 남
// const int dy[4] = {1, 0, -1, 0};  // 동, 북, 서, 남

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

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

int N, M, K, ans;
int prey[12][12];
int board[12][12];
int baby[12][12];
deque<int> tree[12][12];

void solve(int x, int y) {
  auto &cur = tree[x][y];
  int idx(0), sum(0);
  for (auto &height : cur) {
    if (height > board[x][y]) {
      sum += height / 2;
      continue;
    }

    board[x][y] -= height;

    height += 1;
    if (!(height % 5)) baby[x][y]++;

    idx++;
  }
  board[x][y] += sum;

  if (cur.begin() + idx < cur.end()) cur.erase(cur.begin() + idx, cur.end());
}

void breed(int x, int y) {
  auto &cur = tree[x][y];

  rep(dir, 0, 8) {
    int curX = x + dx[dir];
    int curY = y + dy[dir];

    if (curX < 0 || curX >= N || curY < 0 || curY >= N) continue;
    if (!baby[curX][curY]) continue;

    rep(i, 0, baby[curX][curY]) cur.push_front(1);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;
  rep(i, 0, N) { rep(j, 0, N) cin >> prey[i][j]; }
  rep(i, 0, M) {
    int x, y, z;
    cin >> x >> y >> z;
    tree[x - 1][y - 1].push_front(z);
  }
  fill(&board[0][0], &board[0][0] + 12 * 12, 5);

  while (K--) {
    // 1. 양분 먹이기
    // 2. 죽은 나무 양분으로 바꾸기
    // 3. 나무 번식시키기 (8방향)
    rep(i, 0, N) {
      rep(j, 0, N) { solve(i, j); }
    }

    rep(i, 0, N) {
      rep(j, 0, N) { breed(i, j); }
    }

    rep(i, 0, N) {
      rep(j, 0, N) {
        board[i][j] += prey[i][j];
        baby[i][j] = 0;
      }
    }
  }

  rep(i, 0, N) {
    rep(j, 0, N) { ans += tree[i][j].size(); }
  }
  cout << ans;
  return 0;
}