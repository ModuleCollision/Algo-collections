#include<bits/extc++.h>

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

constexpr i64 mod = 998244353;
constexpr i64 maxn = 4e6 + 5;
constexpr i64 inf = 0x3f3f3f3f3f3f3f3f;

struct sq {
  i64 l; i64 r; i64 mn;
} tr[maxn * 4]; i64 a[maxn]; i64 dp[maxn];
void pushup(i64 p) {
  tr[p].mn = min(tr[p << 1].mn, tr[p << 1 | 1].mn);
}
void build(i64 p, i64 l, i64 r) {
  tr[p].l = l; tr[p].r = r;
  if (l == r) {
    tr[p].mn = dp[l]; return;
  }
  i64 mid = (tr[p].l + tr[p].r) >> 1;
  build(p << 1, l, mid); build(p << 1 | 1, mid + 1, r);
  pushup(p);
}
void update(i64 p, i64 idx, i64 v) {
  if (tr[p].l == tr[p].r) {
    tr[p].mn = v; return;
  }
  i64 mid = (tr[p].l + tr[p].r) >> 1;
  if (idx <= mid)update(p << 1, idx, v);
  if (idx > mid)update(p << 1 | 1, idx, v);
  pushup(p);
}
i64 query_min(i64 p, i64 l, i64 r) {
  if (l > r)return inf;
  if (tr[p].l >= l and tr[p].r <= r) {
    return tr[p].mn;
  }
  i64 ret = inf; i64 mid = (tr[p].l + tr[p].r) >> 1;
  if (l <= mid)
    ret = min(ret, query_min(p << 1, l, r));
  if (r > mid)ret = min(ret, query_min(p << 1 | 1, l, r));
  return ret;
}
void solve() {
  i64 n, s, l; cin >> n >> s >> l;
  for (i64 i = 1; i <= n; i++)cin >> a[i];
  std::multiset<i64>st1;
  std::fill(dp + 1, dp + 1 + n, inf);
  build(1, 1, n);
  auto check = [&]() {
    return (*(--st1.end())) - (*st1.begin()) > s;
  };
  for (i64 q = 1, x = 1; x <= n; x++) {
    st1.insert(a[x]);
    while (check()) {
      st1.erase(st1.find(a[q]));
      q++;
    }
    if (x - q + 1 < l) {
      dp[x] = n + 1;
    } else {
      //s - 1 到 t - l
      if (q - 1 == 0)dp[x] = 1;
      else {
        i64 cur = query_min(1, q - 1, x - l);
        dp[x] = cur + 1;
      }
    }
    update(1, x, dp[x]);
  }
  if (dp[n] >= n + 1) {
    puts("-1");
  } else cout << dp[n] << "\n";
}
signed main() {
  solve();
}