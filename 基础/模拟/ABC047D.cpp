#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 2e5 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
  ll n, t; std::cin >> n >> t;
  vector<ll>A(n + 1, 0); for (ll i = 1; i <= n; i++)cin >> A[i];
  vector<ll>suf(n + 1, 0);
  suf[n] = A[n];
  for (ll i = n - 1; i >= 1; i--) {
    suf[i] = max(A[i], suf[i + 1]);
  }
  ll d = 0;
  for (ll i = 1; i <= n - 1; i++) {
    d = max(suf[i + 1] - A[i], d);
  }
  std::map<ll, ll>cnt; ll ans = 0;
  for (ll i = 1; i <= n; i++)cnt[A[i]]++;
  for (ll i = 1; i <= n; i++) {
    cnt[A[i]]--; if (cnt[A[i]] == 0)cnt.erase(A[i]);
    ans += cnt[A[i] + d];
  }
  cout << ans << endl;
}
signed main() {
  solve();
}