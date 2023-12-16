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

i64 tr[maxn];
void solve() {
  i64 n, k; std::cin >> n >> k;
  vector<array<i64, 3>>w(n + 1);
  i64 cnt = 0; vector<array<i64, 5>>A(n + 1);
  for (i64 i = 1; i <= n; i++)cin >> w[i][0] >> w[i][1] >> w[i][2];
  std::sort(w.begin() + 1, w.begin() + 1 + n, [&](auto w, auto t)->bool{
    if (w[0] != t[0])return w[0] < t[0];
    if (w[1] != t[1])return w[1] < t[1];
    return w[2] < t[2];
  });
  for (i64 i = 1; i <= n; i++) {
    i64 l = i;
    while (i + 1 <= n and w[i + 1] == w[i])i++;
    array<i64, 5>tmp = {w[i][0], w[i][1], w[i][2], i - l + 1, 0};
    A[++cnt] = tmp;
  }
  auto add = [&](i64 x, i64 v) {
    for (; x <= k; x += (x & -x))tr[x] += v;
  };
  auto query = [&](i64 idx) {
    i64 ret = 0;
    for (; idx >= 1; idx -= (idx & -idx))ret += tr[idx];
    return ret;
  };
  function<void(i64, i64)>cdq = [&](i64 l, i64 r) {
    if (l == r)return;
    i64 mid = (l + r) >> 1;
    cdq(l, mid); cdq(mid + 1, r);
    auto f = [&](array<i64, 5>x, array<i64, 5>y)->bool{
      if (x[1] != y[1])return x[1] < y[1];
      return x[2] < y[2];
    };
    std::sort(A.begin() + l, A.begin() + mid + 1, f);
    std::sort(A.begin() + mid + 1, A.begin() + r + 1, f);
    i64 i = l, j = mid + 1;
    while (j <= r) {
      while (i <= mid and A[i][1] <= A[j][1]) {
        add(A[i][2], A[i][3]);
        i++;
      }
      A[j][4] += query(A[j][2]);
      j++;
    }
    for (i64 k = l; k < i; k++)add(A[k][2], -A[k][3]);
    return;
  };
  vector<i64>ans(n + 1, 0);
  cdq(1, cnt);
  for (i64 i = 1; i <= cnt; i++)ans[A[i][4] + A[i][3] - 1] += A[i][3];
  for (i64 i = 0; i < n; i++)cout << ans[i] << endl;
}
signed main() {
  solve();
}