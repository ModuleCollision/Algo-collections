#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef double db;
typedef long long ll;
typedef long double lb;
typedef unsigned long long ull;
const ll maxn = 1e6 + 10;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9 + 7;
char s[maxn];
ll sa[maxn], rk[maxn], oldrk[maxn << 1], id[maxn], key1[maxn], cnt[maxn];
void solve() {
  ll n; std::cin >> n;
  auto re = [&]() {
    char c = getchar();
    while (not isalpha(c))c = getchar();
    return c;
  };
  ll l = 1, r = n;
  for (ll i = 1; i <= n; i++) {
    s[i] = re();
    s[(n << 1) + 2 - i] = s[i];
  }
  s[n + 1] = 0;
  n = 2 * n + 1;
  auto cmp = [&](ll x, ll y, ll w) {
    return oldrk[x] == oldrk[y] and oldrk[x + w] == oldrk[y + w];
  };
  ll m = 127; ll p, w, i;
  for (i = 1; i <= n; i++)++cnt[rk[i] = s[i]];
  for (i = 1; i <= m; i++)cnt[i] += cnt[i - 1];
  for (i = n; i >= 1; i--)sa[cnt[rk[i]]--] = i;//计数排序
  for (w = 1;; w <<= 1, m = p) {
    for (p = 0, i = n; i > n - w; --i)id[++p] = i;
    for (i = 1; i <= n; i++) {
      if (sa[i] > w)id[++p] = sa[i] - w;
    }
    memset(cnt, 0, sizeof(cnt));
    for (i = 1; i <= n; i++) {
      ++cnt[key1[i] = rk[id[i]]];
    }
    for (i = 1; i <= m; i++)cnt[i] += cnt[i - 1];
    for (i = n; i >= 1; i--)sa[cnt[key1[i]]--] = id[i];
    for (i = 1; i <= n; i++) {
      oldrk[i] = rk[i];
    }
    for (p = 0, i = 1; i <= n; i++) {
      rk[sa[i]] = cmp(sa[i], sa[i - 1], w) ? p : ++p;
    }
    if (p == n) {
      for (i = 1; i <= n; i++)sa[rk[i]] = i;
      break;
    }
  }
  ll cnt = 0;
  while (l <= r) {
    putchar(rk[l] < rk[n + 1 - r] ? s[l++] : s[r--]);
    cnt++; if (cnt % 80 == 0)putchar('\n');
  }
}
signed main() {
  solve();
}