#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1000005;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 998244353;
void solve() {
  ll n; std::cin >> n;
  ll idx = 0;
  for (ll i = 2; i <= 26; i++) {
    if (n % i != 0) {
      idx = i; break;
    }
  }
  string buf = "";
  for (ll i = 0; i <= 25; i++) {
    buf += char('a' + i);
  }
  //cout << buf << endl;
  for (ll i = 0; i < n; i++) {
    putchar(buf[i % idx]);
  }
  cout << endl;
}
signed main() {
  ll T; std::cin >> T;
  while (T--)
    solve();
}