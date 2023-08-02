#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
  string s; std::cin >> s;
  ll len = s.size();
  vector<ll>p(len + 5, 0);
  for (ll i = 1; i < len; i++) {
    ll j = p[i - 1];
    while (j > 0 and s[i] != s[j])j = p[j - 1];
    if (s[i] == s[j])j++;
    p[i] = j;
  }//KMP函数板题
  cout << len - p[len - 1] << endl;
}
signed main() {
  ll T; std::cin >> T;
  while (T--)solve();
}