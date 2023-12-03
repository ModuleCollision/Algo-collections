#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 5e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
  ll n, m; std::cin >> n >> m; ll l = 0, r = -1;
  vector<ll>A(n + 1, 0); for (ll i = 1; i <= n; i++) {
    cin >> A[i]; A[i]++;
  }
  auto check = [&](ll mid) {
    ll cnt = 1; ll cur = 0;
    for (ll i = 1; i <= n; i++) {
      cur += A[i];
      if (cur - 1 > mid) {
        cnt++; cur = A[i]; continue;
      }//往下一排放
    }
    return cnt <= m;
  };
  r = accumulate(A.begin() + 1, A.begin() + 1 + n, 0) + n - 1;
  l = *max_element(A.begin() + 1, A.begin() + 1 + n);
  while (l < r) {
    ll mid = (l + r) >> 1;
    if (check(mid))r = mid;
    else l = mid + 1;
  }
  cout << r << endl;
}
signed main() {
  solve();
}