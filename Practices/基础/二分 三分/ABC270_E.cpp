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
  ll n, k; std::cin >> n >> k;
  vector<ll>A(n + 1, 0);
  for (ll i = 1; i <= n; i++)cin >> A[i];
  ll l = 0, r = *max_element(A.begin() + 1, A.begin() + 1 + n);
  auto check = [&](ll x) {
    ll res = 0;
    for (ll i = 1; i <= n; i++) {
      res += min(A[i], x);
    }
    return res <= k;
  };
  ll d = 0;
  while (l < r) {
    ll mid = (l + r + 1) >> 1;
    if (check(mid))l = mid;
    else r = mid - 1;
  }
  for (ll i = 1; i <= n; i++) {
    ll t = min(l, A[i]);
    A[i] -= t; k -= t;
  }
  for (ll i = 1; i <= n; i++) {
    if (A[i] and k)A[i]--, k--;
  }
  for (ll i = 1; i <= n; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
}
signed main() {
  solve();
}