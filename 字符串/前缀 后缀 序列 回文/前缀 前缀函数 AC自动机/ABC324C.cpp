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
  ll n; string f; std::cin >> n >> f;
  vector<string>ss(n + 1);
  vector<bool>vis(n + 1, false);
  for (ll i = 1; i <= n; i++) {
    cin >> ss[i];
  }
  auto check = [&](string s, string t) {
    if (abs((ll)s.size() - (ll)t.size()) > 1)return false;
    ll cnt = 0;
    if (s.size() == t.size()) {
      for (ll i = 0; i < t.size(); i++)if (s[i] != t[i])cnt++;
      return cnt <= 1;
    }
    ll l = 0;
    for (ll i = 0; i < t.size(); i++) {
      if (l < s.size() and s[l] == t[i])l++;
    }
    if (l == s.size())return true;
    l = 0;
    for (ll i = 0; i < s.size(); i++) {
      if (l < t.size() and t[l] == s[i])l++;
    }
    if (l == t.size())return true;
    return false;
  }; ll cnt = 0;
  for (ll i = 1; i <= n; i++) {
    if (check(ss[i], f))cnt++, vis[i] = 1;
  }
  cout << cnt << endl;
  for (ll i = 1; i <= n; i++)if (vis[i])cout << i << " ";
}
signed main() {
  solve();
}