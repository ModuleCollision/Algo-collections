#include<bits/stdc++.h>
using i8 = signed char;
using u8 = unsigned char;
using i16 = signed short int;
using u16 = unsigned short int;
using i32 = signed int;
using u32 = unsigned int;
using f32 = float;
using i64 = signed long long;
using u64 = unsigned long long;
using f64 = double;
using i128 = __int128_t;
using u128 = __uint128_t;
using f128 = long double;
using namespace std;
const i64 mod = 1e9 + 7;
const i64 maxn = 1e6 + 5;
const i64 inf = 0x3f3f3f3f3f3f3f3f;
pair<i64, i64>wv[maxn]; i64 L[maxn], R[maxn], be[maxn], len, n, tot;
pair<i64, i64>w[maxn];
i64 pre[maxn];
void build() {
  i64 len = sqrt(n); tot = (n + len - 1) / len;
  for (i64 i = 1; i <= n; i++) {
    be[i] = (i + len - 1) / len;
  }
  for (i64 i = 1; i <= tot; i++) {
    L[i] = (i - 1) * len + 1, R[i] = i * len;
  }
  R[tot] = n;
  for (i64 i = 1; i <= tot; i++) {
    sort(wv + L[i], wv + R[i] + 1, [&](auto x, auto y)->bool{
      return x.first < y.first;
    });
  }
  for (i64 i = 1; i <= n; i++) {
    pre[i] = pre[i - 1] + wv[i].second;
  }
}
i64 query(i64 x, i64 y, i64 k) {
  i64 ret = 0;
  if (be[x] == be[y]) {
    i64 cnt = 0, q = 0;
    for (i64 i = x; i <= y; i++) {
      if (w[i].first >= k)cnt++, q += w[i].second;
    }
    return cnt * q;
  } else {
    i64 cnt = 0, q = 0;
    for (i64 i = x; i <= R[be[x]]; i++) {
      if (w[i].first >= k)q += w[i].second, cnt++;
    }
    for (i64 i = L[be[y]]; i <= y; i++) {
      if (w[i].first >= k)q += w[i].second, cnt++;
    }
    for (i64 i = be[x] + 1; i <= be[y] - 1; i++) {
      i64 l = L[i], r = R[i]; i64 idx = -1;
      while (l <= r) {
        i64 mid = (l + r) >> 1;
        if (wv[mid].first < k)l = mid + 1, idx = mid;
        else r = mid - 1;
      }
      if (idx != -1) {
        cnt += R[i] - idx;
        q += pre[R[i]] - pre[idx];
      }
    }
    return cnt * q;
  }
}
void solve() {
  i64 m, s; cin >> n >> m >> s;
  for (i64 i = 1; i <= n; i++) {
    cin >> wv[i].first >> wv[i].second;
    w[i] = wv[i];
  }
  build();
  vector<pair<i64, i64>>p(m + 1);
  for (i64 i = 1; i <= m; i++) {
    cin >> p[i].first >> p[i].second;
  }
  cout << query(1, 4, 3) << endl;
  i64 l = 0, r = 1e10;
  i64 ans = inf;
  while (l <= r) {
    i64 mid = (l + r) >> 1;
    i64 cur = 0;
    for (i64 i = 1; i <= m; i++)cur += query(p[i].first, p[i].second, mid);
    if (cur > s) {
      l = mid + 1;
    } else {
      r = mid - 1;
    }
    ans = min(ans, mid);
  }
  cout << ans << "\n";
}
signed main() {
  solve();
}