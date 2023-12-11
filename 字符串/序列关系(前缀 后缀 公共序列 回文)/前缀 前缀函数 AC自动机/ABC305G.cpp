#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 305;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
ll fail[maxn]; bool idx[maxn];
ll tr[maxn][2]; ll tot = 0;
void insert(string s) {
  ll u = 0; idx[u] = 0;
  for (ll i = 0; i < s.size(); i++) {
    if (not tr[u][s[i] - 'a']) {
      tr[u][s[i] - 'a'] = ++tot;
      idx[tot] = 0;
    }
    u = tr[u][s[i] - 'a'];
  }
  idx[u] = 1;
}
void build() {
  queue<ll>q;
  for (ll i = 0; i <= 1; i++) {
    if (tr[0][i])q.push(tr[0][i]);
  }
  while (q.size()) {
    ll u = q.front(); q.pop();
    for (ll i = 0; i <= 1; i++) {
      if (tr[u][i]) {
        fail[tr[u][i]] = tr[fail[u]][i];
        q.push(tr[u][i]);
      } else {
        tr[u][i] = tr[fail[u]][i];
      }
      idx[tr[u][i]] |= idx[fail[tr[u][i]]];
    }
  }
}
struct mat {
public:
  ll n; ll a[300][300];
  mat(ll t) {
    n = t; for (ll i = 0; i < n; i++) {
      for (ll j = 0; j < n; j++) {
        a[i][j] = 0;
      }
    }
  }
  mat operator*(const mat&b) {
    mat tmp(n);
    for (ll i = 0; i < n; i++) {
      for (ll j = 0; j < n; j++) {
        for (ll k = 0; k < n; k++) {
          tmp.a[i][j] = (tmp.a[i][j] % mod + a[i][k] % mod * b.a[k][j]) % mod;
        }
      }
    }
    return tmp;
  }
};
mat ksm(mat a, ll b) {
  mat tmp(a.n);
  for (ll i = 0; i < a.n; i++) {
    tmp.a[i][i] = 1;
  }
  while (b) {
    if (b & 1)tmp = tmp * a;
    a = a * a;
    b >>= 1;
  }
  return tmp;
}
void solve() {
  ll n, m; string s;
  cin >> n >> m;
  for (ll i = 0; i < m; i++) {
    cin >> s; insert(s);
  }
  build();
  mat ma(tot + 1);
  for (ll i = 0; i <= tot; i++) {
    for (ll j = 0; j <= 1; j++)
      ++ma.a[i][tr[i][j]];
  }
  ll cnt = 0;
  for (ll i = 0; i <= tot; i++)if (not idx[i])++cnt;
  mat tmp(cnt);
  ll x = -1, y = 0;
  for (ll i = 0; i <= tot; i++) {
    if (idx[i])continue;
    y = 0; x++;
    for (ll j = 0; j <= tot; j++) {
      if (idx[j])continue;
      tmp.a[x][y] = ma.a[i][j];
      y++;
    }
  }
  auto res = ksm(tmp, n);
  ll ans = 0;
  for (ll i = 0; i < cnt; i++) {
    ans = (ans % mod + res.a[0][i]) % mod;
  }
  cout << ans << endl;
}
signed main() {
  solve();
}