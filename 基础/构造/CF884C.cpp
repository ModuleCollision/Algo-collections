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
  i64 pre; i64 nxt; i64 v;
} tr[maxn];
struct cmp {
  bool operator()(const pair<i64, i64>x, const pair<i64, i64>y)const {
    return x.first < y.first;
  }
};
void solve() {
  i64 n; std::cin >> n;
  vector<i64>A(n + 5, 0);
  for (i64 i = 1; i <= n; i++)cin >> A[i];
  i64 pos = 0;
  for (i64 i = 1; i <= n; i++) {
    if (A[i] > 0) {
      pos = i; break;
    }
  }
  if (not pos) {
    std::sort(A.begin() + 1, A.begin() + 1 + n);
    cout << A[n] << endl;
  } else {
    i64 s1 = 0, s2 = 0;
    for (i64 i = 1; i <= n; i++) {
      if (A[i] > 0) {
        if (i & 1) {
          s1 += A[i];
        } else {
          s2 += A[i];
        }
      }
    }
    cout << max(s1, s2) << endl;
  }
}
signed main() {
  i64 T; std::cin >> T;
  while (T--)
    solve();
}