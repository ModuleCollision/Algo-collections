#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e6 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  std::unordered_set<ll>st;
  std::unordered_map<ll, ll>cnt1, cnt2;
  ll n; cin >> n; vector<ll>a1(n + 1), b1(n + 1);
  for (ll i = 1; i <= n; i++) {
    cin >> a1[i]; st.insert(a1[i]);
  }
  for (ll i = 1; i <= n; i++)cin >> b1[i];
  ll m; cin >> m; vector<ll>a2(m + 1), b2(m + 1);
  for (ll i = 1; i <= m; i++) {
    cin >> a2[i]; st.insert(a2[i]);
  }
  for (ll i = 1; i <= m; i++)cin >> b2[i];
  for (ll i = 1; i <= n; i++)cnt1[a1[i]] = b1[i];
  for (ll i = 1; i <= m; i++)cnt2[a2[i]] = b2[i];
  ll ans = 1;
  for (auto c : st) {
    ll r = cnt1[c], l = cnt2[c];
    if (r < l) {
      puts("0"); return;
    }
    ll d = r - l + 1;
    ll cur = d;
    if (cur != 1)
      ans = (ans % mod * 2) % mod;
  }
  cout << ans % mod << endl;
}
signed main() {
  solve();
}

