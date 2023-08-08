#include<bits/stdc++.h>
using namespace std;
typedef double db;
typedef long long ll;
typedef long double lb;
const ll maxn = 1e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
  ll n, k, a, b; std::cin >> n >> k >> a >> b;
  vector<char>t = {'G', 'B'};
  vector<ll>cnt = {a, b};
  if (a < b) {
    swap(cnt[0], cnt[1]);
    swap(t[0], t[1]);
  }
  string ans = ""; bool f = 1;
  ll cur = 0, pre = 0;
  for (ll i = 0; i < n; i++) {
    if (pre == k) {
      cur ^= 1;
      if (cnt[cur] == 0) {
        puts("NO"); return;
      }
      cnt[cur]--;
      ans += t[cur];
      pre = 1;
    } else {
      if (n - i > k) {
        if (cnt[cur ^ 1] > cnt[cur]) {
          cur ^= 1;
          pre = 0;
        }
      }
      if (cnt[cur] == 0) {
        cur ^= 1; pre = 0;
        if (cnt[cur] == 0) {
          puts("NO"); return;
        }
      }
      ans += t[cur];
      pre++;
      cnt[cur]--;
    }
  }
  cout << ans << endl;
}
signed main() {
  //ll T; std::cin >> T;
  //while (T--)
  solve();
}