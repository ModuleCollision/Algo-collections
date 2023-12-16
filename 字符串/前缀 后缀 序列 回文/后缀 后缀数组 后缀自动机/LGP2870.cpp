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

char s[maxn];
i64 sa[maxn], rk[maxn], oldrk[maxn << 1], id[maxn], key1[maxn], cnt[maxn];
void solve() {
  i64 n; std::cin >> n;
  auto re = [&]() {
    char c = getchar();
    while (not isalpha(c))c = getchar();
    return c;
  };
  i64 l = 1, r = n;
  for (i64 i = 1; i <= n; i++) {
    s[i] = re();
    s[(n << 1) + 2 - i] = s[i];
  }
  s[n + 1] = 0;
  n = 2 * n + 1;
  auto cmp = [&](i64 x, i64 y, i64 w) {
    return oldrk[x] == oldrk[y] and oldrk[x + w] == oldrk[y + w];
  };
  i64 m = 127; i64 p, w, i;
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
  i64 cnt = 0;
  while (l <= r) {
    putchar(rk[l] < rk[n + 1 - r] ? s[l++] : s[r--]);
    cnt++; if (cnt % 80 == 0)putchar('\n');
  }
}
signed main() {
  solve();
}