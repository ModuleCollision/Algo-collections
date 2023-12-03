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
void solve() {
  ll n; cin >> n; std::map<ll, ll>cnt;
  for (ll i = 1; i <= n; i++) {
    ll s, c; cin >> s >> c;
    cnt[s] += c;
  }
  ll ans = 0;
  for (auto [x, y] : cnt) {
    ans += (y & 1);
    cnt[x * 2] += (y / 2);
  }
  cout << ans << endl;
}
signed main() {
  solve();
}