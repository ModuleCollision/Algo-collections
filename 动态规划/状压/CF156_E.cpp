#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
struct sq {
  ll a; ll idx;
};
void solve() {
  ll n, m; std::cin >> n >> m;
  vector<sq>p(n + 1);
  for (ll i = 1; i <= n; i++) {
    cin >> p[i].a; p[i].idx = i;
  }
  sort(p.begin() + 1, p.end(), [&](auto x, auto y)->bool{
    return x.a > y.a;
  });
  vector<ll>b(m + 1); vector f(m + 1, vector<ll>(n + 1, 0));
  for (ll i = 0; i < m; i++)cin >> b[i];
  for (ll i = 0; i < m; i++) {
    ll l = 0, r = 0;
    for (l = 0, r = 0; l <= n; l++) {
      while ((r - l)*p[r].a < b[i] and r <= n)r++;
      f[i][l] = r;
    }
  }
  vector<ll>dp((1 << m) + 5, 0); auto pre = dp;
  for (ll i = 1; i < (1 << m); i++)dp[i] = n + 1;
  for (ll i = 0; i < (1 << m); i++) {
    if (dp[i] != n + 1) {
      for (ll j = 0; j < m; j++) {
        if (((i >> j) & 1) == 0) {
          if (dp[i | (1 << j)] > f[j][dp[i]]) {
            dp[i | (1 << j)] = f[j][dp[i]];
            pre[i | (1 << j)] = j;
          }
        }
      }
    }
  }
  if (dp[(1 << m) - 1] != n + 1) {
    puts("YES");
  } else {
    puts("NO"); return;
  }
  vector<ll>num(m + 5, 0);
  for (ll i = (1 << m) - 1; i; i -= (1 << pre[i])) {
    num[pre[i]] = dp[i - (1 << pre[i])];
  }
  for (ll i = 0; i < m; i++) {
    cout << f[i][num[i]] - num[i] << " ";
    for (ll j = num[i] + 1; j <= f[i][num[i]]; j++) {
      cout << p[j].idx << " ";
    }
    cout << endl;
  }
}
signed main() {
  solve();
}