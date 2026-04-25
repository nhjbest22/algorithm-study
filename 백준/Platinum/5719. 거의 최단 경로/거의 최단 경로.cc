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

// 북 서 동 남
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

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

int edge[505][505];
int dist[505];
int state[505];

int S, D;
int N, M;

void init_route(int from, int to) {
  edge[from][to] = 0;

  if (state[from]) return;

  if (from == S) {
    state[from] = true;
    return;
  }

  rep(i, 0, N) {
    if (edge[i][from] == 0) continue;
    if (edge[i][from] + dist[i] != dist[from]) continue;

    init_route(i, from);
  }

  state[from] = true;
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  while (1) {
    cin >> N >> M;
    // 0에서 N-1까지

    if (!N && !M) return 0;

    fill(&edge[0][0], &edge[0][0] + 505 * 505, 0);
    fill(dist, dist + 505, INT32_MAX);
    fill(state, state + 505, false);

    cin >> S >> D;
    rep(i, 0, M) {
      int u, v, c;
      cin >> u >> v >> c;

      edge[u][v] = c;
    }

    dist[S] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, S});

    while (!pq.empty()) {
      auto [cur_cost, cur_idx] = pq.top();
      pq.pop();

      if (dist[cur_idx] != cur_cost) continue;

      rep(nxt, 0, N) {
        if (edge[cur_idx][nxt] == 0) continue;

        auto nxt_cost = edge[cur_idx][nxt];

        if (dist[nxt] <= cur_cost + nxt_cost) continue;

        dist[nxt] = cur_cost + nxt_cost;

        pq.push({dist[nxt], nxt});
      }
    }

    rep(i, 0, N) {
      if (edge[i][D] == 0) continue;
      if (dist[i] + edge[i][D] > dist[D]) continue;

      init_route(i, D);
    }

    fill(dist, dist + 505, INT32_MAX);

    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
      auto [cur_cost, cur_idx] = pq.top();
      pq.pop();

      if (dist[cur_idx] != cur_cost) continue;

      rep(nxt, 0, N) {
        if (edge[cur_idx][nxt] == 0) continue;

        auto nxt_cost = edge[cur_idx][nxt];

        if (dist[nxt] <= cur_cost + nxt_cost) continue;

        dist[nxt] = cur_cost + nxt_cost;

        pq.push({dist[nxt], nxt});
      }
    }

    cout << (dist[D] == INT32_MAX ? -1 : dist[D]) << endl;
  }

  return 0;
}
