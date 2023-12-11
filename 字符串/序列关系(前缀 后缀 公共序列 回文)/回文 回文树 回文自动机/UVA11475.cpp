#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e6 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
/*Manacher板题*/
string s;
void solve() {
  ll len = s.size();
  string st(len * 2 + 5, ' ');
  for (ll i = 0; i < len; i++) {
    st[i * 2] = '#'; st[i * 2 + 1] = s[i];
  }
  st[len * 2] = '#';
  vector<ll>d(2 * len + 5);
  for (ll i = 0, l = 0, r = -1; i < len * 2 + 1; i++) {
    ll k = (i > r) ? 1 : min(d[l + r - i], r - i + 1);
    while (i - k >= 0 and i + k < 2 * len + 1 and st[i - k] == st[i + k])k++;
    d[i] = k--;
    if (i + k > r) {
      l = i - k; r = i + k;
    }
  }//维护的是st串的最长回文半径
  //st串'#'位对应s偶回文串 idx -> idx / 2 - 1
  //st串字母位对应s奇回文串 idx -> idx / 2
  //st回文半径对应s回文半径 d -> d / 2
  ll idx = 0;
  for (ll i = 1; i <= len * 2 - 1; i++) {
    if (i + d[i] - 1 == 2 * len) {
      idx = i; break;
    }
  }
  ll r = idx - d[idx] + 1;
  for (ll j = r - 1; j >= 1; j--) {
    if (isalpha(st[j]))s += st[j];
  }
  cout << s << endl;
}
signed main() {
  while (cin >> s) {
    solve();
  }
}