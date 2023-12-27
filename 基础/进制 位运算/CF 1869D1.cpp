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

void solve() {
  i64 n; std::cin >> n;
  vector<i64>A(n + 5, 0);
  for (i64 i = 1; i <= n; i++)cin >> A[i];
  i64 tot = accumulate(A.begin() + 1, A.begin() + 1 + n, 0i64);
  if (tot % n) {
    puts("No"); return;
  }
  i64 av = tot / n;
  auto lowbit = [&](i64 x) {
    return x & -x;
  };
  vector<i64>cnt(35, 0);

  for (i64 i = 1; i <= n; i++) {
    if (A[i] == av)continue;
    i64 d = av - A[i];//偏差
    i64 t = abs(d); i64 e = lowbit(t);
    i64 q = t + e; if (lowbit(q) != q) {
      puts("No"); return;
    }
    i64 cnt1 = 0, cnt2 = 0;
    for (i64 j = 0; e >> j; j++)cnt1++;
    cnt1--;
    for (i64 j = 0; q >> j; j++)cnt2++;
    cnt2--;
    if (d > 0) {
      cnt[cnt1]++; cnt[cnt2]--;
    } else {
      cnt[cnt1]--; cnt[cnt2]++;
    }
  }
  for (i64 i = 0; i <= 33; i++)if (cnt[i] != 0) {
      puts("No"); return;
    }
  puts("Yes");
}
signed main() {
  i64 T; std::cin >> T;
  while (T--)
    solve();
}