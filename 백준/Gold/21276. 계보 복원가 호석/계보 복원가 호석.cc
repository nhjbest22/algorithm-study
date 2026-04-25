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
// const int dx[4] = {-1, 0, 0, 1};
// const int dy[4] = {0, -1, 1, 0};

// 북 남 동 서
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

// const int dx2[4] = {0, 1, 0, -1};
// const int dy2[4] = {1, 0, -1, 0};
// const int dx[6] = {-1, 0, 1, 0, 0, 0};
// const int dy[6] = {0, -1, 0, 1, 0, 0};
// const int dz[6] = {0, 0, 0, 0, -1, 1};

// const int ddx[8] = {0, 0, 1, 1, 1, -1, -1, -1},
// ddy[8] = {1, -1, 1, 0, -1, 1, 0, -1};

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

unordered_map<string, int> S2I;  // name -> idx;
unordered_map<int, string> I2S;
int in[1005];
vector<int> adj[1005];
vector<string> child[1005];
vector<string> names;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  rep(i, 1, N + 1) {
    string name;
    cin >> name;

    names.push_back(name);

    S2I[name] = i;
    I2S[i] = name;
  }

  int E;
  cin >> E;
  rep(i, 0, E) {
    string cur, ance;
    cin >> cur >> ance;

    int ance_idx = S2I[ance];
    int cur_idx = S2I[cur];

    in[cur_idx]++;
    adj[ance_idx].push_back(cur_idx);
  }

  vector<string> ances;
  queue<int> Q;
  rep(i, 1, N + 1) if (!in[i]) {
    Q.push(i);
    ances.push_back(I2S[i]);
  }

  sort(ances.begin(), ances.end());

  cout << ances.size() << endl;
  for (auto& str : ances) cout << str << ' ';
  cout << endl;

  while (!Q.empty()) {
    auto cur = Q.front();
    Q.pop();

    for (auto& nxt : adj[cur]) {
      in[nxt]--;

      if (!in[nxt]) {
        child[cur].push_back(I2S[nxt]);
        Q.push(nxt);
      }
    }
  }

  sort(names.begin(), names.end());
  for (const auto& name : names) {
    int idx = S2I[name];
    cout << name << ' ' << child[idx].size() << ' ';

    sort(child[idx].begin(), child[idx].end());
    for (auto& c : child[idx]) cout << c << ' ';
    cout << endl;
  }

  return 0;
}
