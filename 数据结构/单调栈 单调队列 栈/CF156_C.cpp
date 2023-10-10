#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
  string s; ll pos; std::cin >> s >> pos;
  int n = s.size();
  s = " " + s;
  ll l = 1, r = n; ll m = 0;
  while (l <= r) {
    ll mid = (l + r) >> 1;
    if ((n + n - mid + 1) * (mid) / 2 < pos) {
      l = mid + 1, m = mid;
    } else r = mid - 1;
  }
  vector<char>st;
  pos -= (n + n - m + 1) * m / 2;
  for (ll i = 1; i <= n; i++) {
    while (st.size() and m and st.back() > s[i]) {
      st.pop_back(); m--;
    }
    st.push_back(s[i]);
  }
  putchar(st[pos - 1]);
}
signed main() {
  ll T; std::cin >> T;
  while (T--)
    solve();
}