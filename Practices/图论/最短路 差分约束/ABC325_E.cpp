#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  ll n; cin >> n;
  ll a, b, c; cin >> a >> b >> c;
  vector d(n + 1, vector<ll>(n + 1, 0));
  vector dis(n + 1, vector (n + 1, array<ll, 2> {0, 0}));
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= n; j++) {
      cin >> d[i][j]; if (i == j)continue;
      dis[i][j][0] = d[i][j] * a;
      dis[i][j][1] = d[i][j] * b + c;
    }
  }
  ll ans = inf;
  for (ll k = 1; k <= n; k++) {
    for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= n; j++) {
        dis[i][j][0] = min(dis[i][j][0], dis[i][k][0] + dis[k][j][0]);
        dis[i][j][1] = min(dis[i][j][1], dis[i][k][1] + dis[k][j][1]);
      }
    }
  }
  for (ll i = 1; i <= n; i++)ans = min(ans, dis[1][i][0] + dis[i][n][1]);
  cout << ans << endl;
}
signed main() {
  solve();
}