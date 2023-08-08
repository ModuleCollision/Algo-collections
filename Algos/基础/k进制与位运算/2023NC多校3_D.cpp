#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
  ll n; std::cin >> n;
  vector<string>s(n + 5);
  std::set<string>st1, st2;
  for (ll i = 0; i < n; i++) {
    std::cin >> s[i];
    st1.insert(s[i]);
  }
  for (ll i = 0; i < n; i++) {
    string k;
    for (ll j = 0; j < n; j++) {
      k += s[j][i];
    }
    st2.insert(k);
  }
  ll ans = inf;
  if (st1.size() == 1) {
    ll cnt = 0;
    for (ll j = 0; j < n; j++) {
      if (s[0][j] == '1')cnt++;
    }
    ans = min({ans, cnt, n - cnt});
  }
  if (st2.size() == 1) {
    ll cnt = 0;
    for (ll i = 0; i < n; i++) {
      if (s[i][0] == '1')cnt++;
    }
    ans = min({ans, cnt, n - cnt});
  }
  if (st1.size() == 2) {
    ll cnt = 0;
    bool f = 1;
    string s1 = s[0], s2;
    for (ll i = 1; i < n; i++) {
      if (s[i] != s1) {
        s2 = s[i]; break;
      }
    }
    for (ll i = 0; i < n; i++) {
      ll f1 = s1[i] - '0';
      ll f2 = s2[i] - '0';
      if ((f1 ^ f2) == 0) {
        f = 0; break;
      }
    }
    ll cnt1 = 0; ll cnt2 = 0;
    if (f) {
      for (ll i = 0; i < n; i++) {
        if (s[i] == s1)cnt1++;
      }
      for (ll j = 0; j < n; j++) {
        if (s[0][j] == '1')cnt2++;
      }
      ans = min({ans, cnt1 + cnt2, cnt1 + n - cnt2});
      ans = min({ans, n - cnt1 + cnt2, n - cnt1 + n - cnt2});
    }
  }
  if (ans == inf) {
    puts("-1"); return;
  }
  cout << ans << endl;
}
signed main() {
  solve();
}