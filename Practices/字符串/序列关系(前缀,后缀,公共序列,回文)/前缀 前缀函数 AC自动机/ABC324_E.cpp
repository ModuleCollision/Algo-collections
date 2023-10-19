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
const ll p = 233;
void solve() {
  int n; string t;
  std::cin >> n >> t;
  vector<string> s(n + 1);
  for (ll i = 1; i <= n; i++)cin >> s[i];
  vector<ll> st(n + 1), en(n + 1);
  for (int i = 1; i <= n; ++i) {
    int hoge = 0;
    for (int j = 0; j < s[i].size(); ++j) {
      if (s[i][j] == t[hoge]) {
        ++hoge;
        if (t.size() <= hoge) break;
      }
    }
    st[i] = hoge;
    hoge = 0;
    for (int j = s[i].size() - 1; j >= 0; j--) {
      if (s[i][j] == t[t.size() - 1 - hoge]) {
        ++hoge;
      }
    }
    en[i] = hoge;
  }
  sort(st.begin() + 1, st.end()); sort(en.begin() + 1, en.end());
  ll ans = 0;

  for (int i = 1; i <= n; i++) {
    ll cur = st[i];
    int kore = t.size() - cur;
    ll num = en.end() - lower_bound(en.begin() + 1, en.end(), kore);

    ans += num;
  }

  cout << ans << endl;
}
signed main() {
  solve();
}
