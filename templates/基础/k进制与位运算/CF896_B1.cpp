#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 2e5 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
void solve() {
  ll n; std::cin >> n;
  vector<ll>A(n + 5, 0);
  for (ll i = 1; i <= n; i++)cin >> A[i];
  ll tot = accumulate(A.begin() + 1, A.begin() + 1 + n, 0ll);
  if (tot % n) {
    puts("No"); return;
  }
  ll av = tot / n;
  auto lowbit = [&](ll x) {
    return x & -x;
  };
  vector<ll>cnt(35, 0);

  for (ll i = 1; i <= n; i++) {
    if (A[i] == av)continue;
    ll d = av - A[i];//偏差
    ll t = abs(d); ll e = lowbit(t);
    ll q = t + e; if (lowbit(q) != q) {
      puts("No"); return;
    }
    ll cnt1 = 0, cnt2 = 0;
    for (ll j = 0; e >> j; j++)cnt1++;
    cnt1--;
    for (ll j = 0; q >> j; j++)cnt2++;
    cnt2--;
    if (d > 0) {
      cnt[cnt1]++; cnt[cnt2]--;
    } else {
      cnt[cnt1]--; cnt[cnt2]++;
    }
  }
  for (ll i = 0; i <= 33; i++)if (cnt[i] != 0) {
      puts("No"); return;
    }
  puts("Yes");
}
signed main() {
  ll T; std::cin >> T;
  while (T--)
    solve();
}