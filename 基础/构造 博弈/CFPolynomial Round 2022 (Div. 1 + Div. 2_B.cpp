#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 2e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
char s[maxn];
void solve() {
  ll n, m, k; std::cin >> n >> m >> k;
  pair<ll, ll>q[m + 5];
  for (ll i = 1; i <= m; i++) {
    std::cin >> q[i].second;
    q[i].first = i;
  }
  ll cur = 0;
  for (ll i = 1; i <= m; i++) {
    if (q[i].second == (n + k - 1) / k)++cur;
    if (q[i].second > (n + k - 1) / k) {
      puts("NO"); return;
    }
  }
  ll tmp = (n % k); if (not tmp)tmp = k;
  if (cur <= tmp) {
    puts("YES");
  } else puts("NO");
}
signed main() {
  ll T; std::cin >> T;
  while (T--)
    solve();
}